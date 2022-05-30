#ifndef PATCHMERGEWINDOW_H
#define PATCHMERGEWINDOW_H

#include <QDialog>

namespace Ui {
class PatchMergeWindow;
}

class PatchMergeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PatchMergeWindow(QWidget *parent = nullptr);
    ~PatchMergeWindow();

private:
    Ui::PatchMergeWindow *ui;
};

#endif // PATCHMERGEWINDOW_H
