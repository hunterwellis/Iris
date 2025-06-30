#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QLabel>

class digitalClock : public QWidget
{
    Q_OBJECT

public:
    digitalClock(QWidget *parent = nullptr);

protected:
    virtual QSize sizeHint() const override;

private slots:
    void updateTime();

private:
    QLabel *label;

};

#endif
