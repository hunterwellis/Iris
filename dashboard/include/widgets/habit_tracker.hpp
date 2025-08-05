#ifndef HABITTRACKER_H
#define HABITTRACKER_H

#include <QWidget>
#include <QVector>
#include <QDate>
#include <QColor>

class habitTracker: public QWidget {
    Q_OBJECT

public:
    explicit habitTracker(QString habitTitle);
    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    static constexpr int topMargin = 50;
    static constexpr int leftMargin = 30;

    static constexpr int rows = 7;
    static constexpr int cols = 52;
    static constexpr int maxLevel = 4;

    QString header;

    QVector<QVector<int>> data;  // intensity level [0-4]
    QDate startDate;

    QRect cellRect(int row, int col) const;
    QColor levelColor(int level) const;
    void drawMonthLabels(QPainter &painter);
    void drawWeekdayLabels(QPainter &painter);
    void drawHeader(QPainter &painter);
};

#endif
