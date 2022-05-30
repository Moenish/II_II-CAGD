#include "PatchJoinWindow.h"
#include "ui_PatchJoinWindow.h"

PatchJoinWindow::PatchJoinWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatchJoinWindow)
{
    ui->setupUi(this);
}

PatchJoinWindow::~PatchJoinWindow()
{
    delete ui;
}
