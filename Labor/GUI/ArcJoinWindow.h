#ifndef ARCJOINWINDOW_H
#define ARCJOINWINDOW_H

#include <QDialog>
#include "ui_ArcJoinWindow.h"

namespace cagd
{
    class ArcJoinWindow : public QDialog, public Ui::ArcJoinWindow
    {
        Q_OBJECT

    public:
        explicit ArcJoinWindow(QWidget *parent = nullptr);
    };
}

#endif // ARCJOINWINDOW_H
