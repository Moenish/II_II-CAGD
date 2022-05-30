#include "ArcMergeWindow.h"
#include "ui_ArcMergeWindow.h"

ArcMergeWindow::ArcMergeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArcMergeWindow)
{
    ui->setupUi(this);
}

ArcMergeWindow::~ArcMergeWindow()
{
    delete ui;
}
