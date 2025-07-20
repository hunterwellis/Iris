#include "include/widgets/habit_tracker.hpp"
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <qnamespace.h>

habitTracker::habitTracker(QString habitTitle, QWidget *parent)
    : QWidget(parent), data(cols, QVector<int>(rows, 0)),
      startDate(QDate::currentDate().addDays(-364)) {
  header = habitTitle;
  setMinimumSize(150, 150);
}

QSize habitTracker::sizeHint() const {
  return QSize(leftMargin + cols * 14 + 10, topMargin + rows * 14 + 10);
}

QColor habitTracker::levelColor(int level) const {
  static const QVector<QColor> colors = {QColor("#ebedf0"), QColor("#c6e48b"),
                                         QColor("#7bc96f"), QColor("#239a3b"),
                                         QColor("#196127")};
  return colors[qBound(0, level, maxLevel)];
}

QRect habitTracker::cellRect(int row, int col) const {
  const int size = 12;
  return QRect(leftMargin + col * 14, topMargin + row * 14, size, size);
}

void habitTracker::drawMonthLabels(QPainter &painter) {
  QFont font = painter.font();
  font.setPointSize(8);
  painter.setFont(font);
  painter.setPen(Qt::white);

  QMap<int, QString> monthPositions;

  for (int col = 0; col < cols; ++col) {
    QDate date = startDate.addDays(col * 7);
    if (date.day() <= 7) {
      monthPositions[col] = date.toString("MMM");
    }
  }

  for (auto it = monthPositions.constBegin(); it != monthPositions.constEnd();
       ++it) {
    QRect rect = cellRect(0, it.key());
    painter.drawText(rect.x(), rect.y() - 6, it.value());
  }
}

void habitTracker::drawWeekdayLabels(QPainter &painter) {
  QFont font = painter.font();
  font.setPointSize(8);
  painter.setFont(font);
  painter.setPen(Qt::white);

  static const QMap<int, QString> weekdayLabels = {
      {1, "Mon"}, {3, "Wed"}, {5, "Fri"}};

  for (auto it = weekdayLabels.constBegin(); it != weekdayLabels.constEnd();
       ++it) {
    QRect rect = cellRect(it.key(), 0);
    painter.drawText(rect.x() - 28, rect.y() + 10, it.value());
  }
}

void habitTracker::drawHeader(QPainter &painter) {
  QFont font = painter.font();
  font.setPointSize(15);
  painter.setFont(font);
  painter.setPen(Qt::white);

  QRect rect(0, 0, this->width(), 30);
  painter.drawText(rect, Qt::AlignLeft, header);

  // QRect rect(0, 0, this->width(), 15);
  // painter.drawText(rect, Qt::AlignCenter, header);
}

void habitTracker::paintEvent(QPaintEvent *) {
  QPainter painter(this);
  drawMonthLabels(painter);
  drawWeekdayLabels(painter);
  drawHeader(painter);

  for (int col = 0; col < cols; ++col) {
    for (int row = 0; row < rows; ++row) {
      QRect rect = cellRect(row, col);
      painter.fillRect(rect, levelColor(data[col][row]));
    }
  }
}

void habitTracker::mousePressEvent(QMouseEvent *event) {
  for (int col = 0; col < cols; ++col) {
    for (int row = 0; row < rows; ++row) {
      QRect rect = cellRect(row, col);
      if (rect.contains(event->pos())) {
        if (event->button() == Qt::LeftButton) {
          data[col][row] = (data[col][row] + 1) % (maxLevel + 1);
        } else if (event->button() == Qt::RightButton) {
          data[col][row] = 0;
        }
        update();
        return;
      }
    }
  }
}
