#include "newdialog1.h"
#include "ui_newdialog1.h"

static bool on = false;
static bool test1 = false;
static bool test2 = false;

newDialog1::newDialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newDialog1)
{
    ui->setupUi(this);
    ui->checkBox->setChecked(test1);
    ui->checkBox_2->setChecked(test2);
}

newDialog1::~newDialog1()
{
    delete ui;
}


void newDialog1::on_pushButton_2_clicked()
{
    close();
}


void newDialog1::on_pushButton_clicked()
{
    close();
}


void newDialog1::on_pushButton_4_clicked()
{
    if (!on)
    {
        on = true;
    }
    else if (on)
    {
        on = false;
    }
    else
    {
        on = false;
    }

    if (on)
    {
        ui->pushButton_4->setStyleSheet("background-color: #30fc03;");
        ui->pushButton_4->setText("ON");
    }
    else
    {
        ui->pushButton_4->setStyleSheet("background-color: #c6c6c6;");
        ui->pushButton_4->setText("OFF");
    }
}


void newDialog1::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        test1 = false;
    }
    else
    {
        test1 = true;
    }
}


void newDialog1::on_checkBox_2_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        test2 = false;
    }
    else
    {
        test2 = true;
    }
}

