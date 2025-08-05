#include "include/widgets/digital_clock.hpp"

#include <QTime>
#include <QTimer>
#include <QVBoxLayout>

digitalClock::digitalClock(int fontSize)
    : fontSize(fontSize), QWidget(nullptr) {
  auto *layout = new QVBoxLayout(this);
  label = new QLabel(this);
  layout->addWidget(label);
  this->setStyleSheet("padding: 25px; padding-top: 5px");
  setLayout(layout);

  label->setAlignment(Qt::AlignCenter);
  QFont font("Times");
  font.setPointSize(fontSize);
  label->setFont(font);
  label->setStyleSheet("color: white; background-color: transparent;");

  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &digitalClock::updateTime);
  timer->start(1000); // ms

  updateTime();
}

QSize digitalClock::sizeHint() const { return QSize(150, 150); }

void digitalClock::updateTime() {
  QTime time = QTime::currentTime();

  int hour = time.hour() % 12;
  if (hour == 0) {
    hour = 12;
  }

  constexpr int fieldWidth = 2;
  constexpr int decimalBase = 10;
  constexpr QChar padChar('0');

  QString timeString =
      QString("<span style='font-size:" + QString::number(fontSize) +
              "pt;'>%1:%2</span>"
              "<span style='font-size:" +
              QString::number(fontSize * .75) +
              "pt; vertical-align: super;'>%3</span>")
          .arg(hour)
          .arg(time.minute(), fieldWidth, decimalBase, padChar)
          .arg(time.second(), fieldWidth, decimalBase, padChar);
  // .arg(time.hour() > 12 ? "AM" : "PM");

  label->setTextFormat(Qt::RichText);
  label->setText(timeString);
}
