#ifndef ARCJOINWINDOW_H
#define ARCJOINWINDOW_H

#include <QDialog>

namespace Ui {
class ArcJoinWindow;
}

class ArcJoinWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ArcJoinWindow(QWidget *parent = nullptr);
    ~ArcJoinWindow();

private:
    Ui::ArcJoinWindow *ui;
};

#endif // ARCJOINWINDOW_H
