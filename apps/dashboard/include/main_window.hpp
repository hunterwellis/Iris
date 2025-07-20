#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QCalendarWidget>
#include <QWidget>

#include "include/widgets/analog_clock.hpp"
#include "include/widgets/digital_clock.hpp"
#include "include/widgets/habit_tracker.hpp"
#include "include/widgets/logo.hpp"

class MainWindow : public QWidget {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);

private:
  logoWidget *lg;
  digitalClock *dc;
  analogClock *ac;
  habitTracker *ht;
};

#endif
