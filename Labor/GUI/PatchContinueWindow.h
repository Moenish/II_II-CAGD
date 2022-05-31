#ifndef PATCHCONTINUEWINDOW_H
#define PATCHCONTINUEWINDOW_H

#include <QDialog>
#include "ui_PatchContinueWindow.h"

namespace cagd
{
    class PatchContinueWindow : public QDialog, public Ui::PatchContinueWindow
    {
        Q_OBJECT

    public:
        explicit PatchContinueWindow(QWidget *parent = nullptr);
    };
}

#endif // PATCHCONTINUEWINDOW_H
