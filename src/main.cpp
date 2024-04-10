#include <QApplication>
#include <thread>
#include <iostream>
#include "monitor.h"
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QGraphicsLayout>
QT_CHARTS_USE_NAMESPACE
#include "mainwindow.h"
int main(int argc, char *argv[]){
  QApplication app(argc, argv);
  mainwindow window;
  window.setGeometry(0,0,770,830);
  window.show();
  return app.exec();
}
