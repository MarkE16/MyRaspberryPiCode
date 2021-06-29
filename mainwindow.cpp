#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "interiorlights.h"
#include "brightnesscontrol.h"
#include <QMessageBox>

static bool headerOn = false;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Raspberry Pi");
    ui->statusbar->setStyleSheet("color: rgb(255, 255, 255);");

    if (headerOn)
    {
        ui->pushButton_5->setStyleSheet("background-color: #2bfc32");
        ui->pushButton_5->setText("Head Lights ON");
    }
    else
    {
        ui->pushButton_5->setStyleSheet("background-color: #c6c6c6");
        ui->pushButton_5->setText("Head Lights OFF");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Closes the program
void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton confirm = QMessageBox::question(this, "Confirm", "Close the program?", QMessageBox::Yes | QMessageBox::No);
    if (confirm == QMessageBox::Yes)
    {
        close();
    }
}


// Opens the about information
void MainWindow::on_pushButton_3_clicked()
{
    hide();
    about = new About(this);
    about->show();
}


// Opens the interior light settings
void MainWindow::on_pushButton_clicked()
{
    hide();
    interiorLights = new InteriorLights(this);
    interiorLights->show();
}


// Opens the brightness settings
void MainWindow::on_pushButton_4_clicked()
{
    hide();
    brightnessControl = new BrightnessControl(this);
    brightnessControl->show();
}

// Turns on/off the header lights
void MainWindow::on_pushButton_5_clicked()
{
    if (headerOn)
    {
        headerOn = false;
    }
    else
    {
        headerOn = true;
    }

    if (headerOn)
    {
        ui->pushButton_5->setStyleSheet("background-color: #2bfc32");
        ui->pushButton_5->setText("Head Lights ON");
        ui->statusbar->showMessage("+ Turned on headlights.", 2000);
    }
    else
    {
        ui->pushButton_5->setStyleSheet("background-color: #c6c6c6");
        ui->pushButton_5->setText("Head Lights OFF");
        ui->statusbar->showMessage("+ Turned off headlights.", 2000);
    }
}


// Opens the volume settings
void MainWindow::on_pushButton_6_clicked()
{
    hide();
    volumeControl = new VolumeControl(this);
    volumeControl->show();
}

