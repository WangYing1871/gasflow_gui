#ifndef gui_H
#define gui_H 1 
#include <QWidget>
#include "ui_gfui.h"

class gui : public QWidget{
  Q_OBJECT
public:
  gui(QWidget* parent = 0);
  ~gui();
  inline QSize sizeHint() const override {return QSize(342,786);}

public slots:
  //void getTemperature();


private:
  Ui::gfgui ui;
};

#endif
