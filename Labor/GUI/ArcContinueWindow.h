#ifndef ARCCONTINUEWINDOW_H
#define ARCCONTINUEWINDOW_H

#include <QDialog>

namespace Ui {
class ArcContinueWindow;
}

class ArcContinueWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ArcContinueWindow(QWidget *parent = nullptr);
    ~ArcContinueWindow();

private:
    Ui::ArcContinueWindow *ui;
};

#endif // ARCCONTINUEWINDOW_H
