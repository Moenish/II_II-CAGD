#ifndef ARCMERGEWINDOW_H
#define ARCMERGEWINDOW_H

#include <QDialog>

namespace Ui {
class ArcMergeWindow;
}

class ArcMergeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ArcMergeWindow(QWidget *parent = nullptr);
    ~ArcMergeWindow();

private:
    Ui::ArcMergeWindow *ui;
};

#endif // ARCMERGEWINDOW_H
