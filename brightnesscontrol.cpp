#include "brightnesscontrol.h"
#include "ui_brightnesscontrol.h"
#include "mainwindow.h"
#include <QMessageBox>

static bool frontBrightness = false;
static bool midBrightness = false;
static bool backBrightness = false;
static int headBrightnessLvl = 0;
static int frontBrightnessLvl = 0;
static int midBrightnessLvl = 0;
static int backBrightnessLvl = 0;

static MainWindow *mainWindow;

BrightnessControl::BrightnessControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessControl)
{
    ui->setupUi(this);
    this->setWindowTitle("Brightness Settings");
    ui->checkBox->setChecked(frontBrightness);
    ui->checkBox_2->setChecked(midBrightness);
    ui->checkBox_3->setChecked(backBrightness);
    ui->horizontalSlider->setValue(headBrightnessLvl);
    ui->horizontalSlider_2->setValue(frontBrightnessLvl);
    ui->horizontalSlider_3->setValue(midBrightnessLvl);
    ui->horizontalSlider_4->setValue(backBrightnessLvl);
    ui->progressBar->setValue(headBrightnessLvl);
    ui->progressBar_2->setValue(frontBrightnessLvl);
    ui->progressBar_3->setValue(midBrightnessLvl);
    ui->progressBar_4->setValue(backBrightnessLvl);

    if (frontBrightness)
    {
        ui->horizontalSlider_2->show();
        ui->progressBar_2->show();
    }
    else
    {
        ui->horizontalSlider_2->hide();
        ui->progressBar_2->hide();
    }
    if (midBrightness)
    {
        ui->horizontalSlider_3->show();
        ui->progressBar_3->show();
    }
    else
    {
        ui->horizontalSlider_3->hide();
        ui->progressBar_3->hide();
    }
    if (backBrightness)
    {
        ui->horizontalSlider_4->show();
        ui->progressBar_4->show();
    }
    else
    {
        ui->horizontalSlider_4->hide();
        ui->progressBar_4->hide();
    }
}

BrightnessControl::~BrightnessControl()
{
    delete ui;
}

// Returns to the main window
void BrightnessControl::on_pushButton_2_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}


// Enables/disables the ability to adjust the front light's brightness
void BrightnessControl::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        frontBrightness = false;
    }
    else
    {
        frontBrightness = true;
    }

    if (frontBrightness)
    {
        ui->horizontalSlider_2->show();
        ui->progressBar_2->show();
    }
    else
    {
        ui->horizontalSlider_2->hide();
        ui->progressBar_2->hide();
    }
}

// Enables/disables the ability to adjust the middle light's brightness
void BrightnessControl::on_checkBox_2_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        midBrightness = false;

    }
    else
    {
        midBrightness = true;
    }

    if (midBrightness)
    {
        ui->horizontalSlider_3->show();
        ui->progressBar_3->show();
    }
    else
    {
        ui->horizontalSlider_3->hide();
        ui->progressBar_3->hide();
    }
}

// Enables/disables the ability to adjust the back light's brightness
void BrightnessControl::on_checkBox_3_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        backBrightness = false;
    }
    else
    {
        backBrightness = true;
    }

    if (backBrightness)
    {
        ui->horizontalSlider_4->show();
        ui->progressBar_4->show();
    }
    else
    {
        ui->horizontalSlider_4->hide();
        ui->progressBar_4->hide();
    }
}

// Changes the head light's brightness
void BrightnessControl::on_horizontalSlider_valueChanged(int value)
{
    headBrightnessLvl = value;
    ui->progressBar->setValue(headBrightnessLvl);
}

// Changes the front light's brightness
void BrightnessControl::on_horizontalSlider_2_valueChanged(int value)
{
    frontBrightnessLvl = value;
    ui->progressBar_2->setValue(frontBrightnessLvl);
}

// Changes the middle light's brightness
void BrightnessControl::on_horizontalSlider_3_valueChanged(int value)
{
    midBrightnessLvl = value;
    ui->progressBar_3->setValue(midBrightnessLvl);
}

// Changes the back light's brightness
void BrightnessControl::on_horizontalSlider_4_valueChanged(int value)
{
    backBrightnessLvl = value;
    ui->progressBar_4->setValue(backBrightnessLvl);
}

// Reset button
void BrightnessControl::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton reset = QMessageBox::question(this, "Reset", "Are you sure you want to reset the brightness for all lights? (This action cannot be undone.)", QMessageBox::Yes | QMessageBox::No);
    if (reset == QMessageBox::Yes)
    {
        if (headBrightnessLvl == 0 && frontBrightnessLvl == 0 && midBrightnessLvl == 0 && backBrightnessLvl == 0)
        {
            QMessageBox::critical(this, "Error", "This command does not need to continue as all values are already default.");
        }
        else
        {
            headBrightnessLvl = 0;
            frontBrightnessLvl = 0;
            midBrightnessLvl = 0;
            backBrightnessLvl = 0;
            QMessageBox::information(this, "Success", "Values were reset. Reopen this page for the changes to take effect.");
        }
    }
}

