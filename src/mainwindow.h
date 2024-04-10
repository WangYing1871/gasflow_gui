#ifndef mainwindow_H
#define mainwindow_H 1 
#include <iostream>
#include <string>
#include <mutex>
#include <map>

#include <QObject>
#include <QMainWindow>
#include <QDialog>
#include <QCloseEvent>
#include <QChartView>

#include "component.h"
#include "run.h"
#include "ui_mainwindow.h"

#include "monitor.h"


QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMenuBar;
QT_END_NAMESPACE

class mainwindow : public QMainWindow{
  Q_OBJECT

public:

  friend class run;
  mainwindow();
  ~mainwindow() noexcept = default;

  inline QSize sizeHint() const override {return QSize(400,600);}
  void fill_ports_info();
  void init_monitors();

protected:
  void closeEvent(QCloseEvent* event) override;

  //void recive_text(size_t,std::string const&);

private:

public:
  //QMenuBar* menu_bar;
  //QMenu* menu_device, *menu_mode,* menu_tools;

  Ui::mainwindow_gui ui;
  component m_comps;
  Modbus_setting* m_modbus;
  run* m_runer;
  bool _is_connected = false;
  bool _is_thread_read = false;
  bool _is_moniting = false;

  std::mutex m_mutex;

  std::string fname;

  std::map<std::string,monitor*> m_monitors;
  std::vector<QChartView*> m_qcvs;


public slots:

  void recive_text(size_t,std::string const&,int pos=0);
  void Run();
  void exit();
  void browser();

  void modbus_mode(int);
  void modbus_connect_rtu();
  void modbus_disconnect_rtu();
  void Monitor();
  void Modbus_read_registers(int);
  void enable_browser(int);

  void About();



};



#endif
