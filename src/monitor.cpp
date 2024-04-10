#include <cmath>
#include <sstream>
#include <fstream>
#include "monitor.h"
#include <QFont>
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

monitor::monitor(
    QGraphicsItem* parent
    ,Qt::WindowFlags wFlags):
  QChart(QChart::ChartTypeCartesian,parent,wFlags)
  ,m_series(0)
  ,m_axisX(new QValueAxis())
  ,m_axisY(new QValueAxis())
  ,m_step(0) {
  m_x = 0; m_y = 0;
}


void monitor::format(){
  m_series = new QSplineSeries(this);
  QPen green(Qt::blue);
  green.setWidth(1);
  m_series->setPen(green);
  addSeries(m_series);
  addAxis(m_axisX,Qt::AlignBottom); addAxis(m_axisY,Qt::AlignLeft);
  m_series->attachAxis(m_axisX);
  m_series->attachAxis(m_axisY);
  m_axisX->setTickCount(5);
  m_axisX->setRange(0,128);

  QObject::connect(&m_timer,&QTimer::timeout,this,&monitor::handleTimeout);
}

void monitor::start(){
  m_timer.setInterval(2000);
  m_timer.start();
}

monitor::~monitor() {}

void monitor::handleTimeout(){
  if (m_cache.size()>=2048) m_cache.clear();
  m_series->append(m_x,m_y);
  m_cache.emplace_back(std::array<qreal,2>{m_x,m_y});
  m_axisX->setRange(m_x-90<=0 ? 0 : m_x-90,m_x+38);
  //m_axisY->setRange(0,100);

  qreal x = plotArea().width() / m_axisX->tickCount();
  scroll(x/10,0);
}
void monitor::mousePressEvent(QGraphicsSceneMouseEvent *event){
  //std::cout<<"wangying0 "<<event->lastPos().x()<<" "<<event->lastPos().y()
  //  <<" "<<event->pos().x()<<" "<<event->pos().y()
  //  <<" |"<<m_axisX->min()<<"| "<<m_axisY->max()<<std::endl;
  _is_button = true;
  
}
void monitor::mouseMoveEvent(QGraphicsSceneMouseEvent* event){
  //if (is_button==true){
  //std::cout<<"ground"<<std::endl;
  //return;
  //}
  //std::cout<<"fly"<<std::endl;
}
void monitor::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
  //std::cout<<"wangying1 "<<event->lastPos().x()<<" "<<event->lastPos().y()
  //  <<" "<<event->pos().x()<<" "<<event->pos().y()<<std::endl;
  _is_button = false;
}
