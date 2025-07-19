#include "logo.hpp"

#include <QVBoxLayout>
#include <QPixmap>
#include <QFile>

logoWidget::logoWidget(QWidget *parent)
    : QWidget(parent), logoLabel(new QLabel(this)) {

    auto *layout = new QVBoxLayout(this);
    logoLabel->setAlignment(Qt::AlignCenter);

    QPixmap logoPixmap(":/assets/logo.png");
    if (!logoPixmap.isNull()) {
        logoLabel->setPixmap(logoPixmap);
    } else {
        logoLabel->setText("Logo not found.");
    }

    layout->addWidget(logoLabel);

    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}

