#ifndef monitor_H
#define monitor_H 1 
#include <QtCharts/QChart>
#include <QtCore/QTimer>
#include <QGraphicsSceneMouseEvent>
#include <vector>
#include <array>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class monitor : public QChart{
  Q_OBJECT
public:
  monitor(QGraphicsItem* parent = 0, Qt::WindowFlags wFlags=0);
  virtual ~monitor();

  void format();
  void start();

  template <class _tp, class _up>
  inline monitor* setxy(_tp const& x, _up const& y) {m_x = x, m_y = y; return this;}

  QValueAxis* AxisX() const {return m_axisX;}
  QValueAxis* AxisY() const {return m_axisY;}

public slots:
  void handleTimeout();

private:
  QTimer m_timer;
  QSplineSeries* m_series,*m_series0;
  std::string m_title;
  QValueAxis* m_axisX,* m_axisY;
  qreal m_step, m_x, m_y;
  bool _is_button = false;
  std::vector<std::array<qreal,2>> m_cache;
  std::string m_file;

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};
#endif
