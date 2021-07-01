#include "volumecontrol.h"
#include "ui_volumecontrol.h"
#include "mainwindow.h"
#include <QMessageBox>

static MainWindow *mainWindow;
static bool on = false;
static int volumeLevel = 0;

VolumeControl::VolumeControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VolumeControl)
{
    ui->setupUi(this);
    this->setWindowTitle("Volume Settings");
    ui->horizontalSlider->setValue(volumeLevel);
    ui->progressBar->setValue(volumeLevel);

    if (!on)
    {
        ui->pushButton_2->setText("Turn on ???");
        ui->pushButton_2->setStyleSheet("background-color: #c6c6c6");
        ui->label->hide();
        ui->progressBar->hide();
        ui->horizontalSlider->hide();
    }
    else
    {
        ui->pushButton_2->setText("Turn off ???");
        ui->pushButton_2->setStyleSheet("background-color: #2bfc32");
        ui->label->show();
        ui->progressBar->show();
        ui->horizontalSlider->show();
    }
}

VolumeControl::~VolumeControl()
{
    delete ui;
}

// Return to the main window
void VolumeControl::on_pushButton_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}



// Turn on button
void VolumeControl::on_pushButton_2_clicked()
{
    if (!on)
    {
        ui->pushButton_2->setText("Turn off ???");
        ui->pushButton_2->setStyleSheet("background-color: #2bfc32");
        on = true;
    }
    else
    {
        ui->pushButton_2->setText("Turn on ???");
        ui->pushButton_2->setStyleSheet("background-color: #c6c6c6");
        on = false;
    }

    if (!on)
    {
        ui->label->hide();
        ui->progressBar->hide();
        ui->horizontalSlider->hide();
    }
    else
    {
        ui->label->show();
        ui->progressBar->show();
        ui->horizontalSlider->show();
    }
}

// Slider to set volume
void VolumeControl::on_horizontalSlider_valueChanged(int value)
{
    volumeLevel = value;
    ui->progressBar->setValue(volumeLevel);
}


// Reset volume button
void VolumeControl::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reset = QMessageBox::question(this, "Reset", "Are you sure you want to reset the volume? (This action cannot be undone.)", QMessageBox::Yes | QMessageBox::No);
    if (reset == QMessageBox::Yes)
    {
        if (volumeLevel == 0)
        {
            QMessageBox::critical(this, "Error", "This command does not need to continue as the volume value is already default.");
        }
        else
        {
            volumeLevel = 0;
            ui->progressBar->setValue(volumeLevel);
            ui->horizontalSlider->setValue(volumeLevel);
            QMessageBox::information(this, "Success", "Successfully reset values.");
        }
    }
}

