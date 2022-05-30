#include "PatchMergeWindow.h"
#include "ui_PatchMergeWindow.h"

PatchMergeWindow::PatchMergeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatchMergeWindow)
{
    ui->setupUi(this);
}

PatchMergeWindow::~PatchMergeWindow()
{
    delete ui;
}
