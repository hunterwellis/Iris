#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QWidget>
#include <QCalendarWidget>

#include "widgets/habit_tracker.hpp"
#include "widgets/logo.hpp"
#include "widgets/analog_clock.hpp"
#include "widgets/digital_clock.hpp"

class MainWindow: public QWidget{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);

private:
  logoWidget *logo;
  analogClock *ac;
  digitalClock *dc;
  habitTracker *ht;
};

#endif
