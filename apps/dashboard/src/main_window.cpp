#include <QLayout>
#include <QtWidgets>

#include "include/main_window.hpp"
#include "include/widgets/habit_tracker.hpp"

typedef int row, col, rowspan, colspan;

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

  // lg = new logoWidget(this);
  // dc = new digitalClock;
  ac = new analogClock;
  // ht = new habitTracker("Habit Title", this);

  QGridLayout *layout = new QGridLayout;
  // layout->addWidget(lg, row{0}, col{0}, rowspan{1}, colspan{2},
  // Qt::AlignLeft);
  // layout->addWidget(dc, row{0}, col{0}, Qt::AlignBottom);
  layout->addWidget(ac, row{0}, col{0}, Qt::AlignTop);
  // layout->addWidget(ht, 1, 0, Qt::AlignCenter);

  setStyleSheet("background-color: #000000;"); // black background to keep
                                               // mirror reflective
  setLayout(layout);
  setWindowTitle("Iris");
}
