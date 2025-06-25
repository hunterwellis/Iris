#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QWidget>
#include "widgets/logo_widget.hpp"

class MainWindow: public QWidget{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);

private:
  logoWidget logo();

};

#endif
