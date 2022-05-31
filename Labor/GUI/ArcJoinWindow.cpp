#include "ArcJoinWindow.h"
#include "ui_ArcJoinWindow.h"

ArcJoinWindow::ArcJoinWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArcJoinWindow)
{
    ui->setupUi(this);
}

ArcJoinWindow::~ArcJoinWindow()
{
    delete ui;
}
