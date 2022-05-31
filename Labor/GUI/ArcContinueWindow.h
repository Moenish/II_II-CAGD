#ifndef ARCCONTINUEWINDOW_H
#define ARCCONTINUEWINDOW_H

#include <QDialog>
#include "ui_ArcContinueWindow.h"

namespace cagd
{
    class ArcContinueWindow : public QDialog, public Ui::ArcContinueWindow
    {
        Q_OBJECT

    public:
        explicit ArcContinueWindow(QWidget *parent = nullptr);
    };
}

#endif // ARCCONTINUEWINDOW_H
