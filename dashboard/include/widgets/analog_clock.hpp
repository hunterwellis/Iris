// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>

class analogClock : public QWidget
{
    Q_OBJECT

public:
    explicit analogClock();

protected:
    void paintEvent(QPaintEvent *event) override;
    virtual QSize sizeHint() const override;
};

#endif
