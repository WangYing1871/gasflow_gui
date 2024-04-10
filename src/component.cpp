#include <utility>
#include <thread>
#include <bitset>

#include "modbus/modbus.h"
#include "component.h"
#include "mainwindow.h"

namespace{

std::string get_str(uint16_t const* addr){
  char buf[16];
  sprintf(buf,"%3d",addr[0]);
  uint32_t fv = uint32_t(addr[1]<<16)+addr[2];
  sprintf(buf+3,"%03d",fv);
  return std::string(buf,buf+3)+"."+std::string(buf+3);
}
}

component::component(){
}
//---------------------------------------------------------------------
BMP280::BMP280(QWidget* parent): QWidget(parent){
  ui.setupUi(this);
  this->setGeometry(100,100,500,80);
  ui.lineEdit_2->setText("--.------");
  ui.lineEdit->setText("--.------");

  connect(ui.pushButton_2,&QAbstractButton::clicked,this,&BMP280::T);
  connect(ui.pushButton,&QAbstractButton::clicked,this,&BMP280::P);
};

void BMP280::T(){
  modbus_t* mbs_ctx = m_parent->m_modbus->m_modbus_context;
  if (modbus_write_register(mbs_ctx,1,1)!=1){
    std::string info = "ask for temperature (write addr 1) command failed";
    m_parent->recive_text(2,info);
    return;
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  auto* view = new uint16_t[16];
  if (modbus_read_registers(mbs_ctx,2,3,view)!=3){
    std::string info = "ask for temperature (read addr 2,3,4) data failed";
    m_parent->recive_text(2,info);
    return;
  }
  std::string t = get_str(view) + ""; //TODO
  ui.lineEdit_2->setText(t.c_str());
  std::stringstream sstr; sstr<<"Get Temperature: "<<get_str(view);
  m_parent->recive_text(0,sstr.str().c_str());
  delete[] view;
}

void BMP280::P(){
  modbus_t* mbs_ctx = m_parent->m_modbus->m_modbus_context;
  if (modbus_write_register(mbs_ctx,5,1)!=1){
    std::string info = "ask for pressure (write addr 5) command failed";
    m_parent->recive_text(2,info);
    return;
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  auto* view = new uint16_t[16];
  if (modbus_read_registers(mbs_ctx,6,3,view)!=3){
    std::string info = "ask for pressure (read addr 6,7,8) data failed";
    m_parent->recive_text(2,info);
    return;
  }
  std::string p = get_str(view) + "kpa";
  ui.lineEdit->setText(p.c_str());
  std::stringstream sstr; sstr<<"Get Pressure: "<<get_str(view);
  m_parent->recive_text(0,sstr.str().c_str());
  delete[] view;


}
//---------------------------------------------------------------------


AHT20::AHT20(QWidget* parent): QWidget(parent){
  ui.setupUi(this);
  this->setGeometry(100,100,270,50);
  ui.lineEdit_2->setText("--.------");
  connect(ui.pushButton_2,&QAbstractButton::clicked,this,&AHT20::H);
}

void AHT20::H(){
  modbus_t* __attribute__((unused)) mbs_ctx = m_parent->m_modbus->m_modbus_context;
  m_parent->recive_text(1,"Humidity is not Support now");
}


//---------------------------------------------------------------------


Valve::Valve(QWidget* parent): QWidget(parent){
  ui.setupUi(this);
  this->setGeometry(100,100,270,50);
  ui.radioButton_4->setChecked(true);
  connect(ui.radioButton_4,&QAbstractButton::clicked,this,&Valve::Switch0);
  connect(ui.radioButton_3,&QAbstractButton::clicked,this,&Valve::Switch1); }

void Valve::Switch0(){
  modbus_t* mbs_ctx = m_parent->m_modbus->m_modbus_context;
  if (modbus_write_register(mbs_ctx,18,1)==1){
    m_parent->recive_text(0,"valve_switch set to 1 Ok, gas will dump");
    return; }
  m_parent->recive_text(2,"valve_switch set to 1 Failed, May need redo");
}
void Valve::Switch1(){
  modbus_t* mbs_ctx = m_parent->m_modbus->m_modbus_context;
  if (modbus_write_register(mbs_ctx,18,0)==1){
    m_parent->recive_text(0,"valve_switch set to 0 Ok, gas will recycle");
    return; }
  m_parent->recive_text(2,"valve_switch set to 0 Failed, May need redo");
}


//---------------------------------------------------------------------


Pump::Pump(QWidget* parent): QWidget(parent){
  ui.setupUi(this);
  this->setGeometry(100,100,610,50);
  //connect(ui.lineEdit,SIGNAL(textEdited(QString const&))
  //    ,this,SLOT(sync_slider_le(QString const&)));
  ui.toolButton_2->setIcon(QIcon("/home/wangying/software/test/findfiles/images/zero.png"));
  connect(ui.lineEdit,SIGNAL(editingFinished())
      ,this,SLOT(sync_slider_le()));
  connect(ui.horizontalSlider,&QSlider::valueChanged,this,&Pump::display_slider);
  connect(ui.horizontalSlider,&QSlider::sliderReleased,this,&Pump::set_pwm);
  connect(ui.toolButton_2,&QAbstractButton::clicked,this,&Pump::reset);
}

void Pump::set_pwm(){
  uint16_t value = ui.horizontalSlider->value();
  ui.lineEdit->setText(QString::number(ui.horizontalSlider->value()));
  modbus_t* mbs_ctx = m_parent->m_modbus->m_modbus_context;

  std::stringstream sstr;
  if (modbus_write_register(mbs_ctx,19,value)==1){
    sstr<<"set pwm Pump Ok. valve "<<value<<"%";
    m_parent->recive_text(0,sstr.str().c_str());
    return;
  }
  sstr<<"set pwm Pump failed";
  m_parent->recive_text(2,sstr.str().c_str());
}

void Pump::reset(){
  modbus_t* mbs_ctx = m_parent->m_modbus->m_modbus_context;
  if (modbus_write_register(mbs_ctx,19,0)==1){
    m_parent->recive_text(0,"Reset (set pwm to 0) Pump Ok");
    return;
  }
  ui.horizontalSlider->setValue(12);
  ui.lineEdit->setText(QString::number(12));
  m_parent->recive_text(2,"Reset (set pwm to 0) Pump Failed"); }

void Pump::sync_slider_le(QString const& str){
  std::cout<<str.toStdString()<<std::endl;
}
void Pump::sync_slider_le(){
  int value = std::stoi(ui.lineEdit->text().toStdString().c_str());
  std::stringstream sstr;
  if (value<12 || value>100){
    sstr<<"Please set Pump in range [12,100], your set: "<<value<<" do nothing ~_~";
    m_parent->recive_text(1,sstr.str().c_str());
    return; }
  ui.horizontalSlider->setValue(value);

  modbus_t* mbs_ctx = m_parent->m_modbus->m_modbus_context;
  if (modbus_write_register(mbs_ctx,19,value)==1){
    sstr<<"set pwm Pump Ok. valve "<<value<<"%";
    m_parent->recive_text(0,sstr.str().c_str());
    return;
  }
  sstr<<"set pwm Pump failed";
  m_parent->recive_text(2,sstr.str().c_str());
}
//---------------------------------------------------------------------

MFC::MFC(QWidget* parent): QWidget(parent){
  ui.setupUi(this);
  connect(ui.pushButton_3,&QAbstractButton::clicked,this,&MFC::current);
  connect(ui.pushButton_8,&QAbstractButton::clicked,this,&MFC::total);
  connect(ui.lineEdit,SIGNAL(editingFinished()),this,SLOT(set_curr()));
  connect(ui.pushButton_10,&QAbstractButton::clicked,this,&MFC::zero_total);

  //ui.lineEdit->setText("0.0");
  //set_curr();
}

void MFC::current(){
  modbus_t* mbs_ctx = m_parent->m_modbus->m_modbus_context;
  std::stringstream sstr;
  if(modbus_write_register(mbs_ctx,9,0)!=1){
    sstr<<"ask for MFC current (write addr 9(0)) command Failed.";
    m_parent->recive_text(2,sstr.str());
    return;
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(800));
  auto* view = new uint16_t[16];
  if (modbus_read_registers(mbs_ctx,10,2,view)!=2){
    sstr<<"read for MFC current (read addr 10,11) data Failed.";
    m_parent->recive_text(2,sstr.str());
    return;
  }
  uint32_t v10 = std::bitset<32>{std::bitset<16>{view[1]}.to_string()+
    std::bitset<16>{view[0]}.to_string()}.to_ulong();
  float* curr_f = reinterpret_cast<float*>(&v10);
  sstr<<*curr_f<<" mL/min";
  ui.label_11->setText(sstr.str().c_str());
  sstr.clear();
  sstr<<"MFC current flow is "<<ui.label_11->text().toStdString();
  m_parent->recive_text(0,sstr.str());
  delete[] view;
}

void MFC::total(){
  modbus_t* mbs_ctx = m_parent->m_modbus->m_modbus_context;
  std::stringstream sstr;
  if(modbus_write_register(mbs_ctx,9,1)!=1){
    sstr<<"ask for MFC total (write addr 9(1)) command Failed.";
    m_parent->recive_text(2,sstr.str());
    return;
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(800));
  auto* view = new uint16_t[16];
  if (modbus_read_registers(mbs_ctx,12,2,view)!=2){
    sstr<<"Read for MFC total(read addr 10,11) data Failed.";
    m_parent->recive_text(2,sstr.str());
    return;
  }
  uint32_t v10 = std::bitset<32>{std::bitset<16>{view[1]}.to_string()+
    std::bitset<16>{view[0]}.to_string()}.to_ulong();
  float* curr_f = reinterpret_cast<float*>(&v10);
  sstr<<*curr_f<<" mL/min";
  ui.label_13->setText(sstr.str().c_str());
  sstr.clear();
  sstr<<"MFC total flow is "<<ui.label_13->text().toStdString();
  m_parent->recive_text(0,sstr.str());
}

void MFC::set_curr(){
  modbus_t* mbs_ctx = m_parent->m_modbus->m_modbus_context;
  std::string text_str = ui.lineEdit->text().toStdString();
  float value = std::stof(text_str.c_str());
  std::stringstream sstr;
  m_parent->recive_text(0,sstr.str().c_str());
  uint16_t* addr = reinterpret_cast<uint16_t*>(&value);
  uint16_t zero[3] = {addr[0],addr[1],0};
  
  sstr<<"target flow value set for MFC: "<<value<<" Hex: "<<std::hex<<
    addr[0]<<" | "<<addr[1] <<std::dec;
  m_parent->recive_text(0,sstr.str().c_str());
  sstr.clear();
  if (modbus_write_registers(mbs_ctx,15,3,zero)!=3){
    sstr<<"MFC set to "<<value<<" Failed" << "modbus_strerror(error): "<<modbus_strerror(errno);
    m_parent->recive_text(2,sstr.str().c_str());
    return;
  }
  sstr<<"MFC set to "<<value<<" ok";
  m_parent->recive_text(0,sstr.str().c_str()); }

void MFC::zero_total(){
  modbus_t* mbs_ctx = m_parent->m_modbus->m_modbus_context;
  if (modbus_write_register(mbs_ctx,17,1)!=1){
    m_parent->recive_text(2,"Reset(to zero) total flow Failed");
    return;
  }
  m_parent->recive_text(0,"Reset(to zero) total flow Ok");
}

//---------------------------------------------------------------------

Modbus_setting::Modbus_setting(QWidget* parent): QDialog(parent){
  ui.setupUi(this);
  connect(ui.applyButton,&QAbstractButton::clicked,this,&Modbus_setting::set);

   
 // connect(this,SIGNAL(send_text()), m_parent,SLOT(recive_text()));


  
}

void Modbus_setting::set(){
  std::string parity_str = ui.parityCombo->currentText().toStdString();
  if (parity_str=="No") m_params.parity='N';
  else if(parity_str=="Even") m_params.parity='E';
  else if(parity_str=="Odd") m_params.parity='O';
  else{
    std::stringstream sstr; sstr<<"Modbus_setting parity to '"<<
      parity_str<<"' not support now. Set to No";
    m_parent->recive_text(1,sstr.str());
    m_parent->ui.textEdit->update();
    m_params.parity='N'; }

  m_params.baud = std::stoi(ui.baudCombo->currentText().toStdString().c_str());
  m_params.data_bit = std::stoi(ui.dataBitsCombo->currentText().toStdString());
  m_params.stop_bit= std::stoi(ui.stopBitsCombo->currentText().toStdString());
  std::stringstream sstr; sstr<<"Set Serial parameters"
    <<"\n  baud: "<<m_params.baud
    <<"\n  parit: "<<m_params.parity
    <<"\n  data_bit: "<<m_params.data_bit
    <<"\n  stop_bit: "<<m_params.stop_bit;
  m_parent->recive_text(0,sstr.str());
  this->close();
}
//---------------------------------------------------------------------
int Modbus_setting::read_register(uint16_t pos, uint16_t count, uint16_t* dest){
  //std::stringstream sstr; sstr<<"pos: "<<pos<<", count: "<<count;
  //m_parent->recive_text(0,sstr.str(),1);
  if (!link())
    m_parent->recive_text(2,"May be shoule link first",1);
  return modbus_read_registers(m_modbus_context,pos,count,dest);
}
