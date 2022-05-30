#ifndef PATCHCONTINUEWINDOW_H
#define PATCHCONTINUEWINDOW_H

#include <QDialog>

namespace Ui {
class PatchContinueWindow;
}

class PatchContinueWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PatchContinueWindow(QWidget *parent = nullptr);
    ~PatchContinueWindow();

private:
    Ui::PatchContinueWindow *ui;
};

#endif // PATCHCONTINUEWINDOW_H
