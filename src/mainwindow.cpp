#include <stdio.h>
#include <errno.h>
#include <dirent.h>

#include <filesystem>
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <map>
#include <ctime>
#include <tuple>
#include <chrono>
#include <thread>
#include <cstdint>
#include <vector>
#include <bitset>
#include <type_traits>

//#include <boost/filesystem.hpp>
//namespace bst_ft = boost::filesystem;

#include <QtWidgets>
#include <QDialog>
#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QDir>
#include <QValueAxis>
#include <QSerialPortInfo>
#include <QMessageBox>

#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QGraphicsLayout>

#include "modbus/modbus.h"
#include "mainwindow.h"
#include "run.h"
namespace util{
auto const& pwd = []()->std::string{ char buff[FILENAME_MAX]; getcwd(buff,FILENAME_MAX); return {buff}; };

auto const& to_float = [](uint16_t* view)->float{
  uint32_t v10 = std::bitset<32>{std::bitset<16>{view[1]}.to_string()+
    std::bitset<16>{view[0]}.to_string()}.to_ulong();
  float* curr_f = reinterpret_cast<float*>(&v10);
  return curr_f[0]; };

static const char blank_str[] = QT_TRANSLATE_NOOP("mainwindow", "N/A");

void t_msleep(size_t value){
  std::this_thread::sleep_for(std::chrono::milliseconds(value)); }

std::pair<modbus_t*,bool> connect_modbus(char const* device
    ,int baud
    ,int parity
    ,int data_bit
    ,int stop_bit
    ,int const slave_addr){
  std::pair<modbus_t*,bool> rt;
  auto* modbus_ctx = modbus_new_rtu(device,baud,parity,data_bit,stop_bit);
  modbus_set_slave(modbus_ctx,slave_addr);
  modbus_set_response_timeout(modbus_ctx,0,500000);
  modbus_set_debug(modbus_ctx,1);
  modbus_set_error_recovery(modbus_ctx,
      modbus_error_recovery_mode(MODBUS_ERROR_RECOVERY_LINK | MODBUS_ERROR_RECOVERY_PROTOCOL));
  int ec = modbus_connect(modbus_ctx);
  bool status = (ec==0); if(!status) return {nullptr,false};
  status &= (modbus_write_register(modbus_ctx,0,0)==1);
  t_msleep(100);
  status &= (modbus_write_register(modbus_ctx,0,1)==1);
  t_msleep(100);
  if (!status){
    modbus_free(rt.first);
    rt.first = nullptr;
  }
  return {modbus_ctx,true};
}

//struct modbus_parameters_t{
//  int baud = 19200;
//  char parity = 'N';
//  int data_bit = 8;
//  int stop_bit = 2;
//};

template <class _tp, class... args>
void to_stream(_tp& os,args&&... params){
  auto const& to_stream_impl = []<class _sp, class _tup>(_sp& os, _tup const& tup){
    constexpr std::size_t NN = std::tuple_size_v<_tup>;

    [&]<size_t... I>(std::index_sequence<I...>){
      auto* addr = std::addressof(os);
      (...,(*addr<<" "<<std::get<I>(tup)));
    }(std::make_index_sequence<NN>()); };
  to_stream_impl(os,std::make_tuple(std::forward<args>(params)...)); }

std::string timestamp(){
  char buffer[80]; time_t timer = time(0);
  struct tm* tt = localtime(&timer);
  strftime(buffer,81,"%Y-%m-%d %H:%M:%s",tt);
  return "["+std::string{buffer}+"]"; }

auto const& HighResTimer = []->int64_t{
  return std::chrono::duration_cast<std::chrono::steady_clock::duration>(
      std::chrono::steady_clock::now().time_since_epoch()
      ).count(); };


static std::array<QColor,3> color_palette = {
  QColor{"#07B2FC"}, QColor{"#534F02"}, QColor{"#F80F05"} };

enum class log_mode : size_t{
  k_info = 0
  ,k_warning
  ,k_error
};

template <class _tp=QTextEdit, log_mode _ev=log_mode::k_info,class... args>
_tp* info_to(_tp* qtext, args&&... params){
  if (qtext->document()->lineCount() >= 101) qtext->clear();
  qtext->setTextColor(color_palette[(size_t)_ev]);
  std::stringstream sstr;
  to_stream(sstr
      ,_ev==log_mode::k_info ? "[INFO] " : _ev==log_mode::k_warning ? "[WARN] " : "[ERROR]"
#ifdef WIN32
      ,'[',HighResTimer,']'
#else
      ,util::timestamp()
#endif
      //,get_time()
      ,std::forward<args>(params)...);
  qtext->append(QString{sstr.str().c_str()});
  return qtext; } }
//---------------------------------------------------------------------
mainwindow::mainwindow():
  QMainWindow(){
  ui.setupUi(this);

  connect(ui.action_About,&QAction::triggered,this,&mainwindow::About);
  connect(ui.action_About_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

  connect(ui.action_exit,&QAction::triggered,this,&mainwindow::exit);

  ui.comboBox_13->setCurrentIndex(0);
  connect(ui.comboBox_13,SIGNAL(currentIndexChanged(int)),this,SLOT(modbus_mode(int)));

  fill_ports_info();

  if (ui.comboBox_13->currentText().toStdString()=="RTU"){
    ui.spinBox_7->setMinimum(1); ui.spinBox_7->setMaximum(255);
    ui.spinBox_7->setValue(1); ui.spinBox_7->setSingleStep(1);
    ui.spinBox_7->setStepType(QAbstractSpinBox::DefaultStepType); }

  connect(ui.pushButton_2,&QAbstractButton::clicked,this,&mainwindow::browser);
  ui.pushButton_2->setEnabled(false);

  connect(ui.comboBox_12,SIGNAL(currentIndexChanged(int))
      ,this
      ,SLOT(enable_browser(int)));

  std::string dc_icon_name = util::pwd()+"/images/disconnect.png";
  ui.toolButton_5->setIcon(QIcon{dc_icon_name.c_str()});
  connect(ui.toolButton_5,&QAbstractButton::clicked,this,&mainwindow::modbus_connect_rtu);

  std::array<QString,32> reg_count;
  std::cout<<ui.comboBox_3<<" "<<ui.comboBox_5<<std::endl;
  for (int i=0; i<32; ++i) reg_count[i] = QString(std::to_string(i+1).c_str());
  for (auto&& x : reg_count) ui.comboBox_3->addItem(x);
  for (auto&& x : reg_count) ui.comboBox_5->addItem(x);

  connect(ui.comboBox_3,SIGNAL(currentIndexChanged(int)),this,SLOT(Modbus_read_registers(int)));

  m_comps.insert("Temperature",new BMP280())
    ->insert("Humidity",new AHT20())
    ->insert("Valve-Switch",new Valve())
    ->insert("Pump",new Pump())
    ->insert("Micro-Flow-Meter",new MFC());
  dynamic_cast<BMP280*>(m_comps.at("Temperature"))->parent(this);
  dynamic_cast<AHT20*>(m_comps.at("Humidity"))->parent(this);
  dynamic_cast<Valve*>(m_comps.at("Valve-Switch"))->parent(this);
  dynamic_cast<Pump*>(m_comps.at("Pump"))->parent(this);
  dynamic_cast<MFC*>(m_comps.at("Micro-Flow-Meter"))->parent(this);


  connect(ui.action_run,&QAction::triggered,this,&mainwindow::Run);
  connect(ui.action_connect,&QAction::triggered,this,&mainwindow::modbus_connect_rtu);
  connect(ui.action_disconnect,&QAction::triggered,this,&mainwindow::modbus_disconnect_rtu);
  //auto* widget_bmp280 = new BMP280();
  connect(ui.actionBMP280,&QAction::triggered,m_comps.at("Temperature"),&QWidget::show);

  ////auto* widget_aht20 = new AHT20();
  connect(ui.actionAHT20,&QAction::triggered,m_comps.at("Humidity"),&QWidget::show);

  ////auto* widget_valve_0 = new Valve();
  connect(ui.action_Valve,&QAction::triggered,m_comps.at("Valve-Switch"),&QWidget::show);
  

  ////auto* widget_pwm_0 = new Pump();
  connect(ui.actionPump,&QAction::triggered,m_comps.at("Pump"),&QWidget::show);

  ////auto* widget_MFC_0 = new MFC();
  connect(ui.action_MCF,&QAction::triggered,m_comps.at("Micro-Flow-Meter"),&QWidget::show);

  m_modbus = new Modbus_setting();
  m_modbus->parent(this);
  connect(ui.action_serial,&QAction::triggered,m_modbus,&QDialog::show);

  m_runer = new run(); 
  m_runer->parent(this);
  
  connect(ui.actionmonitor,&QAction::triggered,this,&mainwindow::Monitor);

  init_monitors();

}
//---------------------------------------------------------------------
void mainwindow::init_monitors(){
  QString names[] = { "temperature" ,"pressure" ,"MFC-PV" };
  for (auto&& x : names)
    m_monitors[x.toStdString().c_str()] = new monitor;
  for (auto&& [_,x] : m_monitors)
    x->setTitle(_.c_str()), x->legend()->hide(),
    x->setAnimationOptions(QChart::AllAnimations),
    x->setMargins(QMargins(0,0,0,0)),
    x->layout()->setContentsMargins(0,0,0,0);
  for (auto&& [_,x] : m_monitors) x->format(); }

//---------------------------------------------------------------------
void mainwindow::recive_text(size_t mode, std::string const& value, int pos){
  typedef decltype(ui.textEdit) text_t;
  text_t active = 
    pos==0 ? ui.textEdit : pos==1 ? ui.textEdit_2 : pos==2 ? ui.textEdit_3 : ui.textEdit;
  //std::cout<<"wangying"<<std::endl;
  mode==0 ?  util::info_to<QTextEdit,util::log_mode::k_info>(active,value) : 
    mode==1 ?  util::info_to<QTextEdit,util::log_mode::k_warning>(active,value) : 
      mode==2 ?  util::info_to<QTextEdit,util::log_mode::k_error>(active,value) :
        util::info_to<QTextEdit,util::log_mode::k_error>(active,"unknow content mode, display as ERROR!");
}
//---------------------------------------------------------------------
void mainwindow::exit(){
  for (auto&& x : m_comps.m_components){
    if(x.second->isVisible()) x.second->close();
  }
  //auto* window = m_comps.m_components.at("Temperature");
  //for (int i=0; i<10; ++i){
  //  window->setGeometry(0+30*i,0+10*i,270,80);
  //  window->show();
  //  std::this_thread::sleep_for(std::chrono::mil/liseconds(10000000));
  //  window->close();
  //}
  if (this->isVisible()) this->close();
}

void mainwindow::modbus_mode(int __attribute__((unused)) mode){
  std::string modbus_name = ui.comboBox_13->currentText().toStdString();
  if (modbus_name=="RTU"){
    //bst_ft::path dev("/dev");
    //ui.comboBox_2->clear();
    //for (auto iter = bst_ft::directory_iterator( dev); iter!=bst_ft::directory_iterator{}; ++iter){
    //  std::string name = iter->path().string();
    //  if (name.find("USB") != std::string::npos) ui.comboBox_2->addItem(QString{name.c_str()}); }
    ui.spinBox_7->setMinimum(1);
    ui.spinBox_7->setMaximum(255);
    ui.spinBox_7->setValue(1);
    ui.spinBox_7->setSingleStep(1);
    ui.spinBox_7->setStepType(QAbstractSpinBox::DefaultStepType);
  }else{
    ui.comboBox_12->clear();
    util::info_to<QTextEdit,util::log_mode::k_warning>(ui.textEdit,"modbus-mode TCP Not Support!");
    ui.spinBox_7->setMinimum(0);
    ui.spinBox_7->setMaximum(255);
    ui.spinBox_7->setValue(0);
    ui.spinBox_7->setSingleStep(1);
    ui.spinBox_7->setStepType(QAbstractSpinBox::DefaultStepType);
  }
}

void mainwindow::modbus_connect_rtu(){
  std::string device = ui.comboBox_12->currentText().toStdString();
  int slave_addr = ui.spinBox_7->value();
  auto& p = m_modbus->modbus_parameters();

  auto cs = util::connect_modbus(device.c_str(),p.baud,p.parity,p.data_bit,p.stop_bit,slave_addr);
  std::cout<<cs.first<<" "<<cs.second<<std::endl;
  if (cs.second){
    std::string name = util::pwd()+"/images/connect.png";
    ui.toolButton_5->setIcon(QIcon(name.c_str()));
    m_modbus->m_modbus_context = cs.first;
    m_modbus->link(true);
    util::info_to<QTextEdit,util::log_mode::k_info>(ui.textEdit,
        "Link modbus device Ok.", " device: ", device
        ,"baud: ",p.baud
        ,"parity: ",p.parity
        ,"data_bit: ",p.data_bit
        ,"stop_bit: ",p.stop_bit
        ,"slave_addr: ",slave_addr
        );
    _is_connected = true;
  }else{
    m_modbus->link(false);
    modbus_close(m_modbus->m_modbus_context); modbus_free(m_modbus->m_modbus_context);
    util::info_to<QTextEdit,util::log_mode::k_error>(ui.textEdit,
        "Link modbus device Failed.", " device: ", device
        ,"baud: ",p.baud
        ,"parity: ",p.parity
        ,"data_bit: ",p.data_bit
        ,"stop_bit: ",p.stop_bit
        ,"slave_addr: ",slave_addr
        ,"Chcek PLease");
    _is_connected = false;
  }
}
void mainwindow::modbus_disconnect_rtu(){
  modbus_close(m_modbus->m_modbus_context); modbus_free(m_modbus->m_modbus_context);
  util::info_to<QTextEdit,util::log_mode::k_info>(ui.textEdit,"disconnect modbus serial, Bye");
  ui.toolButton_5->setIcon(QIcon(":/images/disconnect.png"));
  m_modbus->link(false);
  _is_connected = false;
}

void mainwindow::Run(){

  util::info_to<QTextEdit,util::log_mode::k_info>(ui.textEdit,"Run Mode");
  auto const& window_center = [](QWidget* p, QWidget* c)->void{
    QSize ps = p->size(), cs = c->size();
    p->setGeometry(0,0,ps.width(),ps.height()); p->update(); p->setEnabled(false);
    typedef decltype(ps.width()) pos_t;
    pos_t nx = (ps.width()-cs.width())/2;  nx = nx>=0 ? nx : 0;
    pos_t ny = (ps.height()-cs.height())/2;  ny = ny>=0 ? ny : 0;
    c->setGeometry(nx,ny,cs.width(),cs.height());
    return;
  };
  window_center(this,m_runer);

  for (auto&& x : m_comps.m_components){ x.second->close(); }
  //int ruler=100;


  ////Qt::FramelessWindowHint
  //for (auto&& x : m_comps.m_components){
  //  QSize ws = x.second->size();
  //  auto* wd = x.second; m_runer->m_childs.emplace_back(wd);
  //  wd->setGeometry(770,ruler,ws.width(),ws.height());
  //  wd->show(); wd->update();
  //  util::t_msleep(100);
  //  ruler += (40+ws.height());
  //  //x.second->setWindowFlags(Qt::FramelessWindowHint);
  //  //x.second->setWindowFlags(Qt::CustomizeWindowHint);
  //  wd->setEnabled(false);

  //  //std::cout<<x.first<<": "<<x.second->windowFlags()<<Qt::FramelessWindowHint<<std::endl;

  //  //std::cout<<x.first<<": "<<x.second->size().width()<<" "<<x.second->height()<<std::endl;
  //}
  //util::t_msleep(100);
  m_runer->show(); m_runer->update(); 

  
}

void mainwindow::closeEvent(QCloseEvent* e){
  (void)e;
  //auto const& maybesave = [this](){
  //  auto ret = QMessageBox::warning(this
  //      ,tr("wangying")
  //      ,tr("Wangying")
  //      ,QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
  //  return ret; };
  //maybesave();
  util::info_to<QTextEdit,util::log_mode::k_info>(ui.textEdit,"Exit!");
  for (auto&& x : m_comps.m_components)
    if (x.second->isVisible()) x.second->close();
  if (m_runer->isVisible()) m_runer->close();
  modbus_disconnect_rtu(); }

//---------------------------------------------------------------------
void mainwindow::Modbus_read_registers(int __attribute__((unused)) count){
  int count_number = std::stoi(ui.comboBox_3->currentText().toStdString().c_str());
  uint16_t* data = new uint16_t[count_number];
    int __attribute__((unused)) ec = m_modbus->read_register(
        ui.spinBox_2->value()
        ,std::stoi(ui.comboBox_3->currentText().toStdString().c_str())
        ,data
        );
    std::stringstream sstr; sstr<<count_number<<", value:"<<util::to_float(data);
    //util::info_to<QTextEdit,util::log_mode::k_info>(ui.textEdit,sstr.str(),1);
    this->recive_text(0,sstr.str(),1);
    //util::t_msleep(1000);
  //}


  delete[] data;
}
//---------------------------------------------------------------------
void mainwindow::browser(){
  QString const dev = QFileDialog::getOpenFileName(this);
  ui.comboBox_12->addItem(dev);
}

void mainwindow::fill_ports_info(){
  ui.comboBox_12->clear();
  auto const infos = QSerialPortInfo::availablePorts();
  QString description;
  QString manufacturer;
  QString serialNumber;
  for (auto&& x : infos){
    QStringList list;
    description = x.description();
    manufacturer = x.manufacturer();
    serialNumber = x.serialNumber();
    list << x.portName()
      <<(!description.isEmpty() ? description : util::blank_str)
      <<(!manufacturer.isEmpty() ? manufacturer : util::blank_str)
      << x.systemLocation()
      << (x.vendorIdentifier() ? QString::number(x.vendorIdentifier(), 16) : util::blank_str)
      << (x.productIdentifier() ? QString::number(x.productIdentifier(), 16) : util::blank_str);
#ifdef WIN32
    ui.comboBox_12->addItem(list.first(),list);
#else
    std::stringstream sstr;
    sstr<<"/dev/"<<list.first().toStdString().c_str();
    ui.comboBox_12->addItem(sstr.str().c_str());
#endif
  }
  ui.comboBox_12->addItem("custom");
  if(ui.comboBox_12->count()==1) ui.pushButton_2->setEnabled(true);
  //ui.comboBox_12

}
//---------------------------------------------------------------------
void mainwindow::enable_browser(int){
  std::string name = ui.comboBox_12->currentText().toStdString();
  if (name=="custom") ui.pushButton_2->setEnabled(true);
  else ui.pushButton_2->setEnabled(false);
  //if (name=="custom") ui.pushButton_2->setEnabled(true);
}

void mainwindow::Monitor(){
  if (_is_moniting){
    m_mutex.lock(); _is_thread_read = false; m_mutex.unlock();
    std::cout<<"Close monitors\n";
    _is_moniting = false;
    for (auto&& x : m_qcvs) x->close(); 
    m_qcvs.clear();
    resize(770,830);
    update();
//    QMessageBox msgBox;
//msgBox.setText("The document has been modified.");
//msgBox.setInformativeText("Do you want to save your changes?");
//msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
//msgBox.setDefaultButton(QMessageBox::Save);
//int ret = msgBox.exec();
    return;
  }
  if (!_is_connected){
    util::info_to<QTextEdit,util::log_mode::k_warning>(ui.textEdit,"no connect yet");
    return; }

  this->resize(this->size().width()+810,this->size().height());
  
  _is_thread_read = true;
  std::thread connect([this](){
    auto const& get_str = [](uint16_t const* addr)->std::string{
      char buf[16]; sprintf(buf,"%3d",addr[0]);
      uint32_t fv = uint32_t(addr[1]<<16)+addr[2];
      sprintf(buf+3,"%03d",fv);
      return std::string(buf,buf+3)+"."+std::string(buf+3); };
    time_t start_time = time(0);
    auto* modbus_ctx = this->m_modbus->m_modbus_context;
    uint16_t view[15];
    uint8_t failno;

    std::string of = std::to_string(util::HighResTimer());
    of += ".csv";
    std::ofstream fout(of.c_str());
    fout<<"# "<<"T(3)"<<"P(3) "<<"H(3) "<<"pump(1) "<<"valve-switch(1) "<<"MFC-PV(2) "
      <<"MFC_TV(2)"<<"\n";
    
    size_t index = 0;
    while(_is_thread_read){
      if (index++%20==0) fout.flush();
      int ec = modbus_read_registers(modbus_ctx,0,15,view);
      if (ec != 15){
        failno++;
        if (failno++==20){
          util::info_to<QTextEdit,util::log_mode::k_error>(this->ui.textEdit
              ,std::this_thread::get_id() ,"too much read error, return");
          fout.close();
          return;
        }
        util::info_to<QTextEdit,util::log_mode::k_warning>(this->ui.textEdit
              ,std::this_thread::get_id() ,"read error catched");
        continue;
      }
      for (int i=0; i<14; ++i) fout<<view[i]<<", ";
      fout<<view[14]<<"\n";
      this->m_monitors["temperature"]->setxy(time(0)-start_time,std::stof(
            get_str(view).c_str()))->AxisY()->setRange(0,40);
      this->m_monitors["pressure"]->setxy(time(0)-start_time,std::stof(
            get_str(view+3).c_str()))->AxisY()->setRange(90,150);
      this->m_monitors["MFC-PV"]->setxy(time(0)-start_time,util::to_float(view+11))
        ->AxisY()->setRange(-5,50);
      std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    fout<<close();
  });

  for (auto&& [_,x] : m_monitors) x->start();
  connect.detach();

  size_t const monitor_no = m_monitors.size();
  for (auto&& [_,x] : m_monitors) 
    m_qcvs.emplace_back(new QChartView{x,this}) 
    ,m_qcvs.back()->setRenderHint(QPainter::Antialiasing);
  for (size_t i=0; i<monitor_no; ++i)
    m_qcvs[i]->setGeometry(
        775,i*size().height()/monitor_no
        ,800,size().height()/monitor_no), m_qcvs[i]->show();
  update();
  _is_moniting = true;
}

void mainwindow::About(){
  QMessageBox::about(this, tr("About Spreadsheet"),
          tr("<h2>GasFlow GUI 0.0.1</h2>"
             "<p>Copyright &copy; 2024 Software Inc. JW company."
             "<p>GasFlow is a small application that use for Micro-Gas-Control"
             "<p>Author(s): Wang Ying; Zhou Yong"
            ));
}
