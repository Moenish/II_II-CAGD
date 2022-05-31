#ifndef PATCHJOINWINDOW_H
#define PATCHJOINWINDOW_H

#include <QDialog>

namespace Ui {
class PatchJoinWindow;
}

class PatchJoinWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PatchJoinWindow(QWidget *parent = nullptr);
    ~PatchJoinWindow();

private:
    Ui::PatchJoinWindow *ui;
};

#endif // PATCHJOINWINDOW_H
