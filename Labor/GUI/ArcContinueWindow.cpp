#include "ArcContinueWindow.h"
#include "ui_ArcContinueWindow.h"

ArcContinueWindow::ArcContinueWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArcContinueWindow)
{
    ui->setupUi(this);
}

ArcContinueWindow::~ArcContinueWindow()
{
    delete ui;
}
