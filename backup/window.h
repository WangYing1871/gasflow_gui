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

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QDir>
#include "modbus/modbus.h"

enum class e_dump_set_exit_state : uint8_t{
  k_unknow
  ,k_activation
  ,k_no_pump_zero
  ,k_no_set_mfc
  ,k_no_switch_switch
};
enum class e_recycle_set_exit_state : uint8_t{
  k_unknow
  ,k_activation
  ,k_no_switch_switch
  ,k_no_zero_mfc
  ,k_no_set_pump
};

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;
class QLineEdit;
class QTextEdit;
class QRadioButton;
class QSlider;
QT_END_NAMESPACE

//! [0]
//class Window : public QWidget
//{
//    Q_OBJECT
//
//public:
//    Window(QWidget *parent = 0);
//
//private slots:
//    void browse();
//    void find();
//    void animateFindClick();
//    void openFileOfItem(int row, int column);
//    void contextMenu(const QPoint &pos);
//
//private:
//    QStringList findFiles(const QStringList &files, const QString &text);
//    void showFiles(const QStringList &paths);
//    QComboBox *createComboBox(const QString &text = QString());
//    void createFilesTable();
///
//    QComboBox *fileComboBox;
//    QComboBox *textComboBox;
//    QComboBox *directoryComboBox;
//    QLabel *filesFoundLabel;
//    QPushButton *findButton;
//    QTableWidget *filesTable;
//
//    QDir currentDir;
//};
//! [0]

class window_demo : public QWidget{
  Q_OBJECT

public:
  window_demo(QWidget* parent=0);

  bool get_rb0() const;
  bool get_rb1() const;

  //template <class _tp>
  //m_info* operator<<()


private slots:
  void get_temp();
  void get_press();
  void get_fw_moment();
  void get_fw_sustain();
  void reset_sustain();
  void set_moment();
  void set_switch();
  void set_servo_motor();
  void viewer();
  void display_slider();

  void slider_pressd();
  void slider_released();
  void reset_sm();
  void set_gas_mode();






private:
  e_dump_set_exit_state dump_state;
  e_recycle_set_exit_state recycle_state;


  QLabel* m_label0, * m_label1;
  QLineEdit* m_lineedit0,* m_lineedit1;
  QPushButton* m_pushbutton0, * m_pushbutton1;
  modbus_t* m_modbus_context;

  QLabel* m_label2;
  QLineEdit* m_lineedit2,* m_lineedit3;
  QPushButton* m_pushbutton2, * m_pushbutton3;

  QTextEdit* m_info;

  QPushButton* m_pushbutton4,* m_pushbutton5;
  QLineEdit* m_lineedit4;

  QPushButton* m_pushbutton6;
  QLineEdit* m_lineedit5;

  QRadioButton* m_rbutton0,* m_rbutton1;

  QSlider* m_hslider0;
  QLabel* m_hslider0_text;
  QLineEdit* slider_set_lineedit;

  QComboBox* gas_flow_mode;
  QPushButton* gas_flow_mode_set;
  QLineEdit* gas_flow_mode_tv;

public:
  

};



#endif
