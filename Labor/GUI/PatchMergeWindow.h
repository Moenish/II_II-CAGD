#ifndef PATCHMERGEWINDOW_H
#define PATCHMERGEWINDOW_H

#include <QDialog>
#include "ui_PatchMergeWindow.h"

namespace cagd
{
    class PatchMergeWindow : public QDialog, public Ui::PatchMergeWindow
    {
        Q_OBJECT

    public:
        explicit PatchMergeWindow(QWidget *parent = nullptr);
    };
}

#endif // PATCHMERGEWINDOW_H
