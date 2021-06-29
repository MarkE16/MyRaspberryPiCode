#include "newdialog2.h"
#include "ui_newdialog2.h"

newDialog2::newDialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newDialog2)
{
    ui->setupUi(this);
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

newDialog2::~newDialog2()
{
    delete ui;
}

void newDialog2::on_pushButton_2_clicked()
{
    close();
}


void newDialog2::on_pushButton_clicked()
{
    close();
}

