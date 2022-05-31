#ifndef PATCHJOINWINDOW_H
#define PATCHJOINWINDOW_H

#include <QDialog>
#include "ui_PatchJoinWindow.h"

namespace cagd
{
    class PatchJoinWindow : public QDialog, public Ui::PatchJoinWindow
    {
        Q_OBJECT

    public:
        explicit PatchJoinWindow(QWidget *parent = nullptr);
    };
}

#endif // PATCHJOINWINDOW_H
