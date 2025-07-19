#include "digital_clock.hpp"

#include <QVBoxLayout>
#include <QTime>
#include <QTimer>

digitalClock::digitalClock(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);
    label = new QLabel(this);
    layout->addWidget(label);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    label->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPointSize(48);
    font.setBold(true);
    label->setFont(font);
    label->setStyleSheet("color: white; background-color: transparent;");

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &digitalClock::updateTime);
    timer->start(1000);

    updateTime();
}

QSize digitalClock::sizeHint() const {
    return QSize(150, 150);
}

void digitalClock::updateTime(){
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    label->setText(text);
}
