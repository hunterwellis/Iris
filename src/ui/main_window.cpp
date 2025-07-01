#include <QLayout>
#include <QtWidgets>

#include "main_window.hpp"
#include "widgets/habit_tracker.hpp"

MainWindow::MainWindow(QWidget *parent): QWidget(parent){

  // logo = new logoWidget(this);
  ac = new analogClock;
  // dc = new digitalClock;
  ht = new habitTracker("Habit Title", this);

  QGridLayout *layout = new QGridLayout;
  // layout->addWidget(logo, 0, 0, Qt::AlignCenter);
  // layout->addWidget(ac, 0, 0, Qt::AlignCenter);
  // layout->addWidget(dc, 1, 1, Qt::AlignCenter);
  layout->addWidget(ht, 1, 0, Qt::AlignCenter);
  
  setStyleSheet("background-color: #000000;");  // black background to keep mirror reflective
  setLayout(layout);
  setWindowTitle("Iris");
}
