#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QCalendarWidget>
#include <QWidget>

#include "include/widgets/digital_clock.hpp"
#include "include/widgets/habit_tracker.hpp"
#include "include/widgets/logo.hpp"
#include "include/widgets/habit_tracker.hpp"

class MainWindow : public QWidget {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

private:
  // logoWidget *lg;
  digitalClock *dc;
  // habitTracker *ht;
};

#endif
