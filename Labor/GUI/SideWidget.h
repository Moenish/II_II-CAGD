#pragma once

#include <QWidget>
#include "ui_SideWidget.h"

namespace cagd
{
    class SideWidget: public QWidget, public Ui::SideWidget
    {
        Q_OBJECT
    public:
        // special and default constructor
        SideWidget(QWidget *parent = 0);

    public slots:
    };
}
