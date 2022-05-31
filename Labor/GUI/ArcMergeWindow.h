#ifndef ARCMERGEWINDOW_H
#define ARCMERGEWINDOW_H

#include <QDialog>
#include "ui_ArcMergeWindow.h"

namespace cagd
{
    class ArcMergeWindow : public QDialog, public Ui::ArcMergeWindow
    {
        Q_OBJECT

    public:
        explicit ArcMergeWindow(QWidget *parent = nullptr);
    };
}

#endif // ARCMERGEWINDOW_H
