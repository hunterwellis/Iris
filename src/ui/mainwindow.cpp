#include <QLayout>
#include <QtWidgets>

#include "main_window.hpp"

MainWindow::MainWindow(QWidget *parent): QWidget(parent){

  logo = new logoWidget(this);
  ac = new analogClock;

  QGridLayout *layout = new QGridLayout;
  layout->addWidget(logo, 0, 0, Qt::AlignCenter);
  layout->addWidget(ac, 0, 1, Qt::AlignCenter);
  
  setStyleSheet("background-color: #000000;");  // black background to keep mirror reflective
  setLayout(layout);
  setWindowTitle("Iris");
}
