#ifndef DATE_H
#define DATE_H

#include <QLabel>
#include <QWidget>

class date: public QWidget {
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
