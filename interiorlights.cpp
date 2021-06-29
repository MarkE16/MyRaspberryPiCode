#include "interiorlights.h"
#include "ui_interiorlights.h"
#include "mainwindow.h"

static MainWindow *mainWindow;
static bool on = false;
static bool front = false;
static bool mid = false;
static bool back = false;


InteriorLights::InteriorLights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteriorLights)
{
    ui->setupUi(this);
    this->setWindowTitle("Interior Light Settings");
    ui->checkBox->hide();
    ui->checkBox_2->hide();
    ui->checkBox_3->hide();
    ui->checkBox->setChecked(front);
    ui->checkBox_2->setChecked(mid);
    ui->checkBox_3->setChecked(back);
    if (on)
    {
        ui->pushButton_3->setText("ON");
        ui->pushButton_3->setStyleSheet("background-color: #2bfc32");
        ui->checkBox->show();
        ui->checkBox_2->show();
        ui->checkBox_3->show();
    }
    else
    {
        ui->pushButton_3->setText("OFF");
        ui->pushButton_3->setStyleSheet("background-color: #c6c6c6");
        front = false;
        mid = false;
        back = false;
        ui->checkBox->hide();
        ui->checkBox_2->hide();
        ui->checkBox_3->hide();
    }
}

InteriorLights::~InteriorLights()
{
    delete ui;
}


// Returns to the main window
void InteriorLights::on_pushButton_2_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}


// Allows the lights to be turned on
void InteriorLights::on_pushButton_3_clicked()
{
    if (on)
    {
        on = false;
    }
    else
    {
        on = true;
    }

    if (on)
    {
        ui->pushButton_3->setText("ON");
        ui->pushButton_3->setStyleSheet("background-color: #2bfc32");
        ui->checkBox->show();
        ui->checkBox_2->show();
        ui->checkBox_3->show();
    }
    else
    {
        ui->pushButton_3->setText("OFF");
        ui->label->setText("Toggle Lights");
        ui->pushButton_3->setStyleSheet("background-color: #c6c6c6");
        ui->checkBox->hide();
        ui->checkBox_2->hide();
        ui->checkBox_3->hide();
        front = false;
        mid = false;
        back = false;
    }
}

// Turns on/off the front light
void InteriorLights::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        front = false;
        ui->label->setText("Turned off front light.");
    }
    else
    {
        front = true;
        ui->label->setText("Turned on front light.");
    }
}

// Turns on/off the middle light
void InteriorLights::on_checkBox_2_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        mid = false;
        ui->label->setText("Turned off middle light.");
    }
    else
    {
        mid = true;
        ui->label->setText("Turned on middle light.");
    }
}


// Turns on/off the back light
void InteriorLights::on_checkBox_3_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        back = false;
        ui->label->setText("Turned off back light.");
    }
    else
    {
        back = true;
        ui->label->setText("Turned on back light.");
    }
}

