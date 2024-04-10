#ifndef component_H
#define component_H 1 
#include <string>
#include <sstream>
#include <cctype>
#include <map>

#include <QObject>
#include <QWidget>
#include <QDialog>

#include "util.h"

#include "ui_BMP280.h"
#include "ui_AHT20.h"
#include "ui_Valve.h"
#include "ui_Pump.h"
#include "ui_MFC.h"
#include "ui_setting_modbus.h"

QT_BEGIN_NAMESPACE
class QDialog;
QT_END_NAMESPACE

class mainwindow;



class component{

public:
  component();
  ~component() noexcept = default;


  std::map<std::string,QWidget*> m_components;

public:
  template <class _tp>
  component* insert(std::string const& name,_tp* value){
    auto iter = m_components.find(name);
    if (iter != m_components.end()){
      std::string nn = util::rename(name);
      m_components.insert({nn,value});
      return this; }
    return m_components.insert({name,value}), this; }

  QWidget* at(std::string const& name) const{
    auto iter = m_components.find(name);
    return iter == m_components.end() ? nullptr : m_components.at(name);
  }


};


class BMP280 : public QWidget{
  Q_OBJECT

public:
  BMP280(QWidget* parent=0);
  ~BMP280() noexcept = default;

  inline QSize sizeHint() const override {return QSize(500,80);}


  Ui::BMP280 ui;

  void parent(mainwindow* value) {m_parent = value;}

public slots:
  void T();
  void P();


private:
  mainwindow* m_parent;

  
};

class AHT20 : public QWidget{
  Q_OBJECT
public:
  AHT20(QWidget* parent=0);
  ~AHT20() noexcept = default;
  inline QSize sizeHint() const override {return QSize(270,50);}

  Ui::AHT20 ui;

  void parent(mainwindow* value) {m_parent = value;}
private:
  mainwindow* m_parent;

public slots:
  void H();

};

class Valve : public QWidget{
  Q_OBJECT
public:
  Valve(QWidget* parent=0);
  ~Valve() noexcept = default;
  inline QSize sizeHint() const override {return QSize(270,50);}

  Ui::Valve ui;

  void parent(mainwindow* value) {m_parent = value;}
private:
  mainwindow* m_parent;

public slots:
  void Switch0();
  void Switch1();

};

class Pump : public QWidget{
  Q_OBJECT
public:
  Pump(QWidget* parent=0);
  ~Pump() noexcept = default;

  inline QSize sizeHint() const override {return QSize(610,50);}

  Ui::Pump ui;
  void parent(mainwindow* value) {m_parent = value;}
private:
  mainwindow* m_parent;

public slots:
  void display_slider() {ui.lineEdit->setText(QString::number(ui.horizontalSlider->value()));}
  void set_pwm();
  void reset();
  void sync_slider_le();
  void sync_slider_le(QString const&);



};

class MFC : public QWidget{
  Q_OBJECT;
public:
  MFC(QWidget* parent=0);
  ~MFC() noexcept = default;

  inline QSize sizeHint() const override {return QSize(340,240);}

  Ui::MFC ui;

  void parent(mainwindow* value) {m_parent = value;}
private:
  mainwindow* m_parent;

public slots:
  void current();
  void total();
  void set_curr();
  void zero_total();
};

#include "modbus/modbus.h"

class Modbus_setting : public QDialog{
  Q_OBJECT
public:
  Modbus_setting(QWidget* parent=0);
  ~Modbus_setting() noexcept = default;

  Ui::modbus_setting ui;
  modbus_t* m_modbus_context;

  util::modbus_parameters_t& modbus_parameters()  {return m_params;}

  void parent(mainwindow* value) {m_parent = value;}

  int read_register(uint16_t,uint16_t,uint16_t*);

  bool link() const{return _is_linked;}
  void link(bool value) {_is_linked = value;}

signals:
  void send_text();


private:
  bool _is_linked = false;
  mainwindow* m_parent;
  util::modbus_parameters_t m_params;

public slots:
  void set();
  
};


#endif
