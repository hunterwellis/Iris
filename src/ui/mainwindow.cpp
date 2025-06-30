#include <QLayout>
#include <QtWidgets>

#include "main_window.hpp"
#include "widgets/digital_clock.hpp"

MainWindow::MainWindow(QWidget *parent): QWidget(parent){

  logo = new logoWidget(this);
  ac = new analogClock;
  dc = new digitalClock;

  QGridLayout *layout = new QGridLayout;
  layout->addWidget(logo, 2, 0, Qt::AlignCenter);
  layout->addWidget(ac, 1, 0, Qt::AlignCenter);
  layout->addWidget(dc, 0, 0, Qt::AlignCenter);
  
  setStyleSheet("background-color: #000000;");  // black background to keep mirror reflective
  setLayout(layout);
  setWindowTitle("Iris");
}
