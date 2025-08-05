#ifndef LOGOWIDGET_H
#define LOGOWIDGET_H

#include <QWidget>
#include <QLabel>

class logoWidget : public QWidget {
    Q_OBJECT

public:
    explicit logoWidget();

private:
    QLabel *logoLabel;
};

#endif
