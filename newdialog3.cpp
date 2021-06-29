#include "newdialog3.h"
#include "ui_newdialog3.h"

newDialog3::newDialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newDialog3)
{
    ui->setupUi(this);
}

newDialog3::~newDialog3()
{
    delete ui;
}

void newDialog3::on_pushButton_clicked()
{
    close();
}

