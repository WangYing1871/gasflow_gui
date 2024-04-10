// /home/wangying/work/zephyr/modbus_copy2/
/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."

**
** $QT_END_LICENSE$
**
****************************************************************************/

#define _MODBUS_INTERVAL_ 200
#include <errno.h>

#include <ctime>
#include <QtWidgets>
#include <QColor>
#include <bitset>
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <thread>
namespace{


std::string time_stamp(){
  char buffer[80]; time_t timer = time(0);
  struct tm* tt = localtime(&timer);
  strftime(buffer,81,"%Y-%m-%d %H:%M:%s",tt);
  return "["+std::string{buffer}+"]";
}
std::string get_str(uint16_t const* addr){
  char buf[16];
  sprintf(buf,"%3d",addr[0]);
  uint32_t fv = uint32_t(addr[1]<<16)+addr[2];
  sprintf(buf+3,"%03d",fv);
  return std::string(buf,buf+3)+"."+std::string(buf+3);
}

void k_msleep(uint32_t v){
  std::this_thread::sleep_for(std::chrono::milliseconds(v));
  return; }

uint16_t stoh(std::string const& _str){
  if (_str.length()>6) return 1234;
  size_t j = 0;
  uint16_t rt = 0;
  if (_str[0]=='0' && (_str[1]=='x' || _str[1]=='X')){
    for (int i=_str.length()-1; i>=2; --i){
      std::cout<<rt<<std::endl;
      rt += ((uint16_t)_str[i]-48)*std::pow(16,j++); } }
  return rt; }

 

}

#include "window.h"

////! [17]
//enum { absoluteFileNameRole = Qt::UserRole + 1 };
////! [17]
//
////! [18]
//static inline QString fileNameOfItem(const QTableWidgetItem *item)
//{
//    return item->data(absoluteFileNameRole).toString();
//}
////! [18]
//
////! [14]
//static inline void openFile(const QString &fileName)
//{
//    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
//}
////! [14]
//
////! [0]
//Window::Window(QWidget *parent)
//    : QWidget(parent)
//{
//    setWindowTitle(tr("Find Files"));
//    QPushButton *browseButton = new QPushButton(tr("&Browse..."), this);
//    connect(browseButton, &QAbstractButton::clicked, this, &Window::browse);
//    findButton = new QPushButton(tr("&Find"), this);
//    connect(findButton, &QAbstractButton::clicked, this, &Window::find);
//
//    fileComboBox = createComboBox(tr("*"));
//    connect(fileComboBox->lineEdit(), &QLineEdit::returnPressed,
//            this, &Window::animateFindClick);
//    textComboBox = createComboBox();
//    connect(textComboBox->lineEdit(), &QLineEdit::returnPressed,
//            this, &Window::animateFindClick);
//    directoryComboBox = createComboBox(QDir::toNativeSeparators(QDir::currentPath()));
//    connect(directoryComboBox->lineEdit(), &QLineEdit::returnPressed,
//            this, &Window::animateFindClick);
//
//    filesFoundLabel = new QLabel;
//
//    createFilesTable();
//
//    QGridLayout *mainLayout = new QGridLayout(this);
//    mainLayout->addWidget(new QLabel(tr("Named:")), 0, 0);
//    mainLayout->addWidget(fileComboBox, 0, 1, 1, 2);
//    mainLayout->addWidget(new QLabel(tr("Containing text:")), 1, 0);
//    mainLayout->addWidget(textComboBox, 1, 1, 1, 2);
//    mainLayout->addWidget(new QLabel(tr("In directory:")), 2, 0);
//    mainLayout->addWidget(directoryComboBox, 2, 1);
//    mainLayout->addWidget(browseButton, 2, 2);
//    mainLayout->addWidget(filesTable, 3, 0, 1, 3);
//    mainLayout->addWidget(filesFoundLabel, 4, 0, 1, 2);
//    mainLayout->addWidget(findButton, 4, 2);
////! [0]
//
////! [1]
//    connect(new QShortcut(QKeySequence::Quit, this), &QShortcut::activated,
//        qApp, &QApplication::quit);
////! [1]
//}
//
////! [2]
//void Window::browse()
//{
//    QString directory =
//        QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Find Files"), QDir::currentPath()));
//
//    if (!directory.isEmpty()) {
//        if (directoryComboBox->findText(directory) == -1)
//            directoryComboBox->addItem(directory);
//        directoryComboBox->setCurrentIndex(directoryComboBox->findText(directory));
//    }
//}
////! [2]
//
//static void updateComboBox(QComboBox *comboBox)
//{
//    if (comboBox->findText(comboBox->currentText()) == -1)
//        comboBox->addItem(comboBox->currentText());
//}
//
////! [3]
//void Window::find()
//{
//    filesTable->setRowCount(0);
//
//    QString fileName = fileComboBox->currentText();
//    QString text = textComboBox->currentText();
//    QString path = QDir::cleanPath(directoryComboBox->currentText());
//    currentDir = QDir(path);
////! [3]
//
//    updateComboBox(fileComboBox);
//    updateComboBox(textComboBox);
//    updateComboBox(directoryComboBox);
//
////! [4]
//WINDOW_H
//    QStringList filter;
//    if (!fileName.isEmpty())
//        filter << fileName;
//    QDirIterator it(path, filter, QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
//    QStringList files;
//    while (it.hasNext())
//        files << it.next();
//    if (!text.isEmpty())
//        files = findFiles(files, text);
//    files.sort();
//    showFiles(files);
//}
////! [4]
//
//void Window::animateFindClick()
//{
//    findButton->animateClick();
//}
//
////! [5]
//QStringList Window::findFiles(const QStringList &files, const QString &text)
//{
//    QProgressDialog progressDialog(this);
//    progressDialog.setCancelButtonText(tr("&Cancel"));
//    progressDialog.setRange(0, files.size());
//    progressDialog.setWindowTitle(tr("Find Files"));
//
////! [5] //! [6]
//    QMimeDatabase mimeDatabase;
//    QStringList foundFiles;
//
//    for (int i = 0; i < files.size(); ++i) {
//        progressDialog.setValue(i);
//        progressDialog.setLabelText(tr("Searching file number %1 of %n...", 0, files.size()).arg(i));
//        QCoreApplication::processEvents();
////! [6]
//
//        if (progressDialog.wasCanceled())
//            break;
//
////! [7]
//        const QString fileName = files.at(i);
//        const QMimeType mimeType = mimeDatabase.mimeTypeForFile(fileName);
//        if (mimeType.isValid() && !mimeType.inherits(QStringLiteral("text/plain"))) {
//            qWarning() << "Not searching binary file " << QDir::toNativeSeparators(fileName);
//            continue;
//        }
//        QFile file(fileName);
//        if (file.open(QIODevice::ReadOnly)) {
//            QString line;
//            QTextStream in(&file);
//            while (!in.atEnd()) {
//                if (progressDialog.wasCanceled())
//                    break;
//                line = in.readLine();
//                if (line.contains(text, Qt::CaseInsensitive)) {
//                    foundFiles << files[i];
//                    break;
//                }
//            }
//        }
//    }
//    return foundFiles;
//}
////! [7]
//
////! [8]
//void Window::showFiles(const QStringList &paths)
//{
//    for (const QString &filePath : paths) {
//        const QString toolTip = QDir::toNativeSeparators(filePath);
//        const QString relativePath = QDir::toNativeSeparators(currentDir.relativeFilePath(filePath));
//        const qint64 size = QFileInfo(filePath).size();
//        QTableWidgetItem *fileNameItem = new QTableWidgetItem(relativePath);
//        fileNameItem->setData(absoluteFileNameRole, QVariant(filePath));
//        fileNameItem->setToolTip(toolTip);
//        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);
//        QTableWidgetItem *sizeItem = new QTableWidgetItem(QLocale().formattedDataSize(size));
//        sizeItem->setData(absoluteFileNameRole, QVariant(filePath));
//        sizeItem->setToolTip(toolTip);
//        sizeItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
//        sizeItem->setFlags(sizeItem->flags() ^ Qt::ItemIsEditable);
//
//        int row = filesTable->rowCount();
//        filesTable->insertRow(row);
//        filesTable->setItem(row, 0, fileNameItem);
//        filesTable->setItem(row, 1, sizeItem);
//    }
//    filesFoundLabel->setText(tr("%n file(s) found (Double click on a file to open it)", 0, paths.size()));
//    filesFoundLabel->setWordWrap(true);
//}
////! [8]
//
////! [10]
//QComboBox *Window::createComboBox(const QString &text)
//{
//    QComboBox *comboBox = new QComboBox;
//    comboBox->setEditable(true);
//    comboBox->addItem(text);
//    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
//    return comboBox;
//}
////! [10]
//
////! [11]
//void Window::createFilesTable()
//{
//    filesTable = new QTableWidget(0, 2);
//    filesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
//
//    QStringList labels;
//    labels << tr("Filename") << tr("Size");
//    filesTable->setHorizontalHeaderLabels(labels);
//    filesTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
//    filesTable->verticalHeader()->hide();
//    filesTable->setShowGrid(false);
////! [15]
//    filesTable->setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(filesTable, &QTableWidget::customContextMenuRequested,
//            this, &Window::contextMenu);
//    connect(filesTable, &QTableWidget::cellActivated,
//            this, &Window::openFileOfItem);
////! [15]
//}
////! [11]
//
//
////! [12]
//
//void Window::openFileOfItem(int row, int /* column */)
//{
//    const QTableWidgetItem *item = filesTable->item(row, 0);
//    openFile(fileNameOfItem(item));
//}
//
////! [12]
//
////! [16]
//void Window::contextMenu(const QPoint &pos)
//{
//    const QTableWidgetItem *item = filesTable->itemAt(pos);
//    if (!item)
//        return;
//    QMenu menu;
//#ifndef QT_NO_CLIPBOARD
//    QAction *copyAction = menu.addAction("Copy Name");
//#endif
//    QAction *openAction = menu.addAction("Open");
//    QAction *action = menu.exec(filesTable->mapToGlobal(pos));
//    if (!action)
//        return;
//    const QString fileName = fileNameOfItem(item);
//    if (action == openAction)
//        openFile(fileName);
//#ifndef QT_NO_CLIPBOARD
//    else if (action == copyAction)
//        QGuiApplication::clipboard()->setText(QDir::toNativeSeparators(fileName));
//#endif
//}
////! [16]
//---------------------------------------------------------------------
window_demo::window_demo(QWidget* parent) : QWidget(parent){
  this->setGeometry(100,100,600,400);
  QGridLayout* mainLayout = new QGridLayout(this);
  m_label0 = new QLabel(tr("T"));
  m_label1 = new QLabel(tr("P"));
  mainLayout->addWidget(m_label0,0,0);
  mainLayout->addWidget(m_label1,1,0);
  mainLayout->addWidget(m_lineedit0 = new QLineEdit());
  mainLayout->addWidget(m_lineedit1 = new QLineEdit());
  mainLayout->addWidget(m_lineedit0,0,1);
  mainLayout->addWidget(m_lineedit1,1,1);
  mainLayout->addWidget(m_pushbutton0=new QPushButton(tr("get")),0,2);
  mainLayout->addWidget(m_pushbutton1=new QPushButton(tr("get")),1,2);

  m_label2 = new QLabel("F");
  mainLayout->addWidget(m_label2,2,0);
  mainLayout->addWidget(new QLabel(tr("moment")),2,1,1,1);
  mainLayout->addWidget(new QLabel(tr("sustain")),3,1,1,1);
  mainLayout->addWidget((m_lineedit2=new QLineEdit()),2,2);
  mainLayout->addWidget((m_lineedit3=new QLineEdit()),3,2);
  mainLayout->addWidget((m_pushbutton2 = new QPushButton(tr("get"))),2,3);
  mainLayout->addWidget((m_pushbutton3 = new QPushButton(tr("get"))),3,3);

  connect(m_pushbutton0,&QAbstractButton::clicked,this,&window_demo::get_temp);
  connect(m_pushbutton1,&QAbstractButton::clicked,this,&window_demo::get_press);
  connect(m_pushbutton2,&QAbstractButton::clicked,this,&window_demo::get_fw_moment);
  connect(m_pushbutton3,&QAbstractButton::clicked,this,&window_demo::get_fw_sustain);

  mainLayout->addWidget(new QLabel("sustain"),4,0);
  mainLayout->addWidget((m_pushbutton4 = new QPushButton("reset")) ,4,1);
  mainLayout->addWidget(new QLabel("moment"),5,0);
  mainLayout->addWidget((m_lineedit4 = new QLineEdit),5,1);
  mainLayout->addWidget((m_pushbutton5 = new QPushButton("set")),5,2);

  connect(m_pushbutton4,&QAbstractButton::clicked,this,&window_demo::reset_sustain);
  connect(m_pushbutton5,&QAbstractButton::clicked,this,&window_demo::set_moment);

  mainLayout->addWidget(m_pushbutton6 = new QPushButton("view"),6,0);
  mainLayout->addWidget(m_lineedit5 = new QLineEdit,7,0,1,4);
  connect(m_pushbutton6,&QAbstractButton::clicked,this,&window_demo::viewer);


  //QHBoxLayout* hl = new QHBoxLayout;/
  m_rbutton0 = new QRadioButton("INACTIVE"); m_rbutton0->setChecked(true);
  m_rbutton1 = new QRadioButton("ACTIVE");

  //mainLayout->addWidget(hl);
  mainLayout->addWidget(new QLabel("VS"),8,0);
  mainLayout->addWidget(m_rbutton0,8,1);
  mainLayout->addWidget(m_rbutton1,8,2);



  auto* newbt = new QPushButton();


  QWidget::setStyleSheet("QPushButton#pushButton {" " color: white;"
    " border-radius: 20px;" " border-style: solid;"
    " border-color: black;" " border-width: 2px;"
    " background-color: blue;" "}");
  newbt->setFlat(true);
  newbt->setStyleSheet("background-color: transparent;");
  newbt->setText(QString{});

  newbt->setIcon(QIcon("/home/wangying/work/software/qt5/qtbase/examples/widgets/mainwindows/application/images/save.png"));

  newbt->setFixedSize(QSize(20,20));
  mainLayout->addWidget(newbt,8,3);

  QObject::connect(newbt,&QAbstractButton::clicked,this,&window_demo::set_switch);

  m_hslider0 = new QSlider;
  m_hslider0->setOrientation(Qt::Horizontal);
  m_hslider0->setMinimum(12);
  m_hslider0->setMaximum(100);
  m_hslider0->setValue(12);
  m_hslider0->setSingleStep(1);
  m_hslider0->setTickPosition(QSlider::TicksBelow);

  mainLayout->addWidget(new QLabel("SM"),9,0,1,1);
  mainLayout->addWidget(m_hslider0,9,1,1,1);

  //m_hslider0_text = new QLabel(this);
  //m_hslider0_text->setText(QString::number(m_hslider0->value()));
  //m_hslider0_text->show();
  connect(m_hslider0,&QSlider::valueChanged ,this,&window_demo::display_slider);

  //connect(m_hslider0,&QSlider::sliderPressed,this,&window_demo::slider_pressd);
  connect(m_hslider0,&QSlider::sliderReleased,this,&window_demo::slider_released);


  //mainLayout->addWidget(m_hslider0_text,9,2,1,1);


  auto* newbt0 = new QPushButton();
  newbt0->setFlat(true);
  newbt0->setStyleSheet("background-color: transparent;");
  newbt0->setText(QString{});
  newbt0->setIcon(QIcon("/home/wangying/work/software/qt5/qtbase/examples/widgets/mainwindows/application/images/save.png"));
  newbt0->setFixedSize(QSize(20,20));
  mainLayout->addWidget(newbt0,9,3,1,1);
  slider_set_lineedit = new QLineEdit(); 
  mainLayout->addWidget(slider_set_lineedit,9,2,1,1);
  slider_set_lineedit->setText(QString::number(m_hslider0->value()));

  auto* sm_reset_bt = new QPushButton("reset");
  mainLayout->addWidget(sm_reset_bt,9,4,1,1);
  connect(sm_reset_bt,&QAbstractButton::clicked,this,&window_demo::reset_sm);

  std::string modenams[]{
    "liuqi"
     ,"biqi"
     ,"xunhuan"
  };
  gas_flow_mode = new QComboBox; //gas_flow_mode->setEditable(false);
  for (int i=0; i<3; ++i) gas_flow_mode->addItem(QString{modenams[i].c_str()});
  gas_flow_mode->setCurrentIndex(0);
  gas_flow_mode_set = new QPushButton(); gas_flow_mode_set->setText("set");
  gas_flow_mode_tv = new QLineEdit(); gas_flow_mode_tv->setText("20");

  mainLayout->addWidget(gas_flow_mode,10,1,1,1);
  mainLayout->addWidget(gas_flow_mode_set,10,3,1,1);
  mainLayout->addWidget(gas_flow_mode_tv,10,2,1,1);
  mainLayout->addWidget(new QLabel("MODE"),10,0,1,1);
  
  connect(gas_flow_mode_set,&QAbstractButton::clicked,this,&window_demo::set_gas_mode);

  m_info = new QTextEdit();
  mainLayout->addWidget(m_info,11,0,2,4);
  m_info->setTextColor(QColor(0,0,255,127));




  connect(newbt0,&QAbstractButton::clicked,this,&window_demo::set_servo_motor);




  


  char const* device = "/dev/ttyUSB0";
  int baud = 19200;
  char parity = 'N';
  int data_bit = 8;
  int stop_bit = 2;
  int const slave_addr = 1;
  m_modbus_context = modbus_new_rtu(device,baud,parity,data_bit,stop_bit);
  modbus_set_slave(m_modbus_context,slave_addr);

  //modbus_set_response_timeout(m_modbus_context,2,0);
  modbus_set_response_timeout(m_modbus_context,0,500000);
  uint32_t timeout_buffer[2];
  modbus_get_response_timeout(m_modbus_context, &timeout_buffer[0], &timeout_buffer[1]);
  std::stringstream sstr; sstr<<timeout_buffer[0]<<"s ."<<timeout_buffer[1]<<"us";
  m_info->append(sstr.str().c_str());


  modbus_set_debug(m_modbus_context,1);
  modbus_set_error_recovery(m_modbus_context,
      modbus_error_recovery_mode(MODBUS_ERROR_RECOVERY_LINK | MODBUS_ERROR_RECOVERY_PROTOCOL));

  modbus_write_register(m_modbus_context,18,1);




}

void window_demo::set_servo_motor(){
  //uint16_t value = m_hslider0->value();
  std::string vstr = slider_set_lineedit->text().toStdString();
  uint16_t value = std::stoi(vstr.c_str());
  std::cout<<"value: "<<value<<std::endl;
  if (value<10 || value>100){
    std::cerr<<"invalid speed for pump! failed\n";
    exit(0);
  }
  m_hslider0->setValue(value);
  m_hslider0->update();

  modbus_write_register(m_modbus_context,19,value);
  
  //for (i=0; i<5; ++i){
  //  if(modbus_write_register(m_modbus_context,19,value)==1){
  //    std::cout<<"set_servo_motor::uc as for mc ok "<<i<<std::endl;
  //    return;
  //  }
  //  k_msleep(2000);
  //}
  //std::cout<<"set_servo_motor::uc as for mc failed"<<std::endl;
}

void window_demo::display_slider(){
  //m_hslider0_text->setText(QString::number(m_hslider0->value()));
  slider_set_lineedit->setText(QString::number(m_hslider0->value()));
}


bool window_demo::get_rb0() const{return m_rbutton0->isChecked();}
bool window_demo::get_rb1() const{return m_rbutton1->isChecked();}

void window_demo::get_temp(){
  modbus_write_register(m_modbus_context,1,1);
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  auto* view = new uint16_t[16];
  modbus_read_registers(m_modbus_context,2,3,view);
  m_lineedit0->setText(tr(get_str(view).c_str()));
  uint32_t count = m_info->document()->lineCount();
  if (count>=30) m_info->clear();
  std::stringstream sstr; sstr<<time_stamp()<<"Get temperature: "<<get_str(view);
  m_info->append(sstr.str().c_str());

  delete[] view;
}
void window_demo::get_press(){
  modbus_write_register(m_modbus_context,5,1);
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  auto* view = new uint16_t[16];
  modbus_read_registers(m_modbus_context,6,3,view);
  m_lineedit1->setText(tr(get_str(view).c_str()));
  delete[] view;
}
void window_demo::get_fw_moment(){

    if (modbus_write_register(m_modbus_context,9,0)!= 1){
      std::cout<<"error: uc ask for mc cmd\n";
      m_info->append(modbus_strerror(errno));
      return; }

  k_msleep(_MODBUS_INTERVAL_);
  auto* view = new uint16_t[16];
    if (modbus_read_registers(m_modbus_context,10,2,view)!=2){
      std::cout<<"error: uc ask for mc value\n";
      return;
       }

  uint32_t v10 = std::bitset<32>{std::bitset<16>{view[1]}.to_string()+
    std::bitset<16>{view[0]}.to_string()}.to_ulong();
  float* curr_f = reinterpret_cast<float*>(&v10);
  std::cout<<*curr_f<<std::endl;
  std::stringstream sstr;
  sstr<<*curr_f;
  m_lineedit2->setText(sstr.str().c_str());
  delete[] view;
}

void window_demo::get_fw_sustain(){
  size_t j;
  for (j=0; j<10; ++j){
    if (modbus_write_register(m_modbus_context,9,1)==1){
      std::cout<<"get_fw_sustain: ask for cmd ok "<<j<<"\n";
      break; }
    k_msleep(2000); }
  if (j==9){
    std::cout<<"get_fw_sustain: ask for cmd failed"<<j<<"\n";
    return; }
  k_msleep(1000);
  auto* view = new uint16_t[16];

  size_t i;
  for (i=0; i<10; ++i){
    if (modbus_read_registers(m_modbus_context,12,2,view) == 2){
      std::cout<<"get_fw_sustain read ok in: "<<i<<std::endl;
      break; }
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }
  if (i==9){
    std::cout<<"get_fw_sustain read failed"<<std::endl;
    m_lineedit3->setText("ERROR");
    return;
  }
  uint32_t v10 = std::bitset<32>{std::bitset<16>{view[1]}.to_string()+
    std::bitset<16>{view[0]}.to_string()}.to_ulong();
  float* totf_f = reinterpret_cast<float*>(&v10);
  std::stringstream sstr;
  sstr<<*totf_f;
  m_lineedit3->setText(sstr.str().c_str());
  delete[] view;
}

void window_demo::reset_sustain(){
  for (int i=0; i<5; ++i){
    if(modbus_write_register(m_modbus_context,15,1)==1){
      std::cout<<"reset sustain to zero, ok\n";
      return;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  std::cout<<"reset sustain to zero, fail\n";
  return; }

void window_demo::set_moment(){

  std::string text_str = m_lineedit4->text().toStdString();
  float value = std::stof(m_lineedit4->text().toStdString().c_str());
  std::cout<<value<<std::endl;
  uint16_t* addr = reinterpret_cast<uint16_t*>(&value);
  uint16_t zero[3] = {addr[0],addr[1],0};
  std::cout<<zero[0]<<" "<<zero[1]<<" "<<zero[2]<<std::endl;

  int ec = modbus_write_registers(m_modbus_context,15,3,zero);
  m_info->append(QString::number(ec));

  if (ec!=3){
    m_info->clear();
    std::stringstream sstr;
    sstr<<"[ERROR] libmodbus: modbus_write_registers(...) failed\n"<<"exit";
    sstr<<modbus_strerror(errno);
    m_info->setText(QString{sstr.str().c_str()});
    return;
  }
  m_info->clear();
  std::stringstream sstr;
  sstr<<"[INFO] libmodbus: modbus_write_registers(...) ok, value: "<<value<<"\n";
  m_info->setText(QString{sstr.str().c_str()});
  



  //std::string text_str = m_lineedit4->text().toStdString();
  ////std::string str0 = text_str.substr(0,text_str.find_first_of(' '));
  ////std::string str1 = text_str.substr(text_str.find_last_of(' ')+1);
  //float value = std::stof(m_lineedit4->text().toStdString().c_str());
  //std::cout<<value<<std::endl;
  //uint16_t* addr = reinterpret_cast<uint16_t*>(&value);
  ////std::cout<<value<<" ("<<std::hex<<value<<")"
  ////  <<" "<<addr[0]<<" "<<addr[1]<<
  ////  std::dec<<" | "<<
  ////  addr[0]<<" "<<addr[1]<<
  ////  std::endl;
  ////uint16_t zero[2] = {addr[1],addr[0]};
  //uint16_t zero[2] = {addr[0],addr[1]};
  //std::cout<<zero[0]<<" "<<zero[1]<<std:current :endl;

  //size_t i, j;
  //if (modbus_write_registers(m_modbus_context,16,2,zero)!=2){
  //  m_lineedit4->setText("error write args");

  //  return;
  //}
  //std::cout<<"set moment value, ok\n";
  //k_msleep(_MODBUS_INTERVAL_);

  //  if(modbus_write_register(m_modbus_context,15,0)!=1){
  //  m_lineedit4->setText("error set value");
  //  return;
  //  }
  //    std::cout<<"set curr ok "<<j<<"\n";

  //return;

}

void window_demo::viewer(){
  m_lineedit5->setText("");
  k_msleep(1000);
  size_t i;
  uint16_t view[24];
  for (i=0; i<10; ++i){
    if (modbus_read_registers(m_modbus_context,0,24,view)==24){
      std::cout<<" registers value get ok "<<i<<"\n";
      std::stringstream sstr;
      for (auto&& x : view){ 
        sstr<<std::hex<<x<<","<<std::dec<<"\n"; }
      m_lineedit5->setText(sstr.str().c_str());
      return;
    }
    k_msleep(2000);
  }
  m_lineedit5->setText("ERROR XX XX XX XX XX XX XX XX");
  return;
}
//---------------------------------------------------------------------
void window_demo::set_switch(){
  if (m_rbutton0->isChecked()){
    if (modbus_write_register(m_modbus_context,18,1)==1){
      std::cout<<"valve_switch set to 1 ok"<<std::endl;
      return;
    }
    std::cout<<"valve_switch set to 1 failed"<<std::endl;
  }else if(m_rbutton1->isChecked()){
    if (modbus_write_register(m_modbus_context,18,0)==1){
      std::cout<<"valve_switch set to 0 ok"<<std::endl;
      return;
    }
    std::cout<<"valve_switch set to 0 failed"<<std::endl;
  }
}
//---------------------------------------------------------------------
void window_demo::slider_pressd(){
 // std::cout<<"wangying: slider_pressd"<<std::endl;

}


void window_demo::slider_released(){
  uint16_t value = m_hslider0->value();
  slider_set_lineedit->setText(QString::number(m_hslider0->value()));
  modbus_write_register(m_modbus_context,19,value);

}
void window_demo::reset_sm(){ modbus_write_register(m_modbus_context,19,0); }

void window_demo::set_gas_mode(){
  //std::cout<<gas_flow_mode->currentText().toStdString()<<std::endl;
  std::string mode_name = gas_flow_mode->currentText().toStdString();

  if (mode_name=="biqi"){

    if (recycle_state==e_recycle_set_exit_state::k_activation){
      m_info->append("Recycle mode already");
      return;
    }
    //gas_flow_mode_tv->setEnabled(false);

    uint16_t data[3] = {0,0,0};
    int ec = modbus_write_registers(m_modbus_context,15,3,data);
    if (ec != 3){
      //TODO
      std::stringstream sstr;
      sstr<<time_stamp()<<" [ERROR] Mode set: failed when set MFC to zero";
      m_info->append(sstr.str().c_str());
      m_info->update();
      //set exit status
      return;
    }

    uint16_t cmd[2] = {0,14};
    ec = modbus_write_registers(m_modbus_context,18,2,cmd);
    m_info->append(QString::number(ec));
    //modbus_write_register(m_modbus_context,18,0);
    //k_msleep(1000); 
    //modbus_write_register(m_modbus_context,19,18);

    //std::stringstream sstr;
    //sstr<<time_stamp()<<" [INFO] Mode set to biqi ok";
    //m_info->append(sstr.str().c_str());
    //m_info->update();

    //dump_state = e_dump_set_exit_state::k_activation;

    return;
  }else if(mode_name=="liuqi"){
    //check exit satus //TODO
    

    k_msleep(_MODBUS_INTERVAL_);

    float value = std::stof(gas_flow_mode_tv->text().toStdString().c_str());
    uint16_t* addr = reinterpret_cast<uint16_t*>(&value);
    uint16_t data[3] = {addr[0],addr[1],0};
    int ec = modbus_write_registers(m_modbus_context,15,3,data);
    if (ec != 3){
      //TODO

      std::stringstream sstr;
      sstr<<time_stamp()<<" [ERROR] Mode set to liuqi failed";
      m_info->append(sstr.str().c_str());
      m_info->update();

      //set exit status
      return;
    }

    uint16_t cmd[2] = {1,0};
    int ec1 = modbus_write_registers(m_modbus_context,18,2,cmd);
    m_info->append(QString::number(ec1));

    //int ec1 = modbus_write_register(m_modbus_context,18,1);
    //k_msleep(500);

    //m_info->append(QString::number(modbus_write_register(m_modbus_context,19,0)));


    std::stringstream sstr;
    sstr<<time_stamp()<<" [INFO] Mode set to biqi ok, flow value: "<<value;
    m_info->append(sstr.str().c_str());
    m_info->update();

    //set exit status
    return;
  }else if(mode_name=="xunhuan"){
//    //1. check status //TODO
//    
//    //2. discharge before gas
//    {
//      uint16_t zero[0] = {0,0,0};
//      modbus_write_registers(m_modbus_context,15,3,zero);
//      k_msleep(_MODBUS_INTERVAL_);
//      modbus_write_register(m_modbus_context,18,1);
//      std::this_thread::sleep_for(std::chrono::milliseconds(??));
//    }
//
//    //3. input gas
//    {
//      modbus_write_register(m_modbus_context,18,0);
//      k_msleep(_MODBUS_INTERVAL_);
//      uint16_t data[3] = {?,?,0};
//      modbus_write_registers(m_modbus_context,15,3,data);
//      std::this_thread::sleep_for(std::chrono::milliseconds(??));
//    }
//
//    //4. self loop
//
//    {
//      for(;;){
//        if (??){ // 
//          liuqi();
//        }else{
//          biqi();
//        }
//        std::this_thread::sleep_for(std::chrono::milliseconds(??));
//      }
//    }
//
//    /* XXX TODO!!
//    //4(or)
//    std::mutex mtx;
//    uint8_t tag_byte = 0;
//    auto const& minitor_fc = [&](){
//      mtx.lock()
//      std::lock_guard<std:mutex>(mtx,std::grolock);
//      tag_byte = 1; };
//
//   for (;;){
//     if (tag_byte == 1){
//       liuqi();
//       std::this_thread::sleep_for(std::chrono::milliseconds(??));
//       biqi();
//      mtx.lock()
//      std::lock_guard<std:mutex>(mtx,std::grolock);
//      tag_byte = 0;
//     }
//   }
//
//    std::thread minitor(...,detach);
//
//    //minitor.join(); ?? detach()?? lanch();
//  */
//
//
//
  }
//
}
