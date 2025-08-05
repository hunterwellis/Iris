#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLabel>
#include <QWidget>

class digitalClock : public QWidget {
  Q_OBJECT

public:
  explicit digitalClock(int fontSize = 48);

protected:
  virtual QSize sizeHint() const override;

private slots:
  void updateTime();

private:
  int fontSize;
  QLabel *label;
};

#endif
