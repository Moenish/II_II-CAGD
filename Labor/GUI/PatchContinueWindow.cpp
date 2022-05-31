#include "PatchContinueWindow.h"
#include "ui_PatchContinueWindow.h"

PatchContinueWindow::PatchContinueWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatchContinueWindow)
{
    ui->setupUi(this);
}

PatchContinueWindow::~PatchContinueWindow()
{
    delete ui;
}
