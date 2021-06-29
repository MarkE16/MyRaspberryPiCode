#ifndef NEWDIALOG1_H
#define NEWDIALOG1_H

#include <QDialog>

namespace Ui {
class newDialog1;
}

class newDialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit newDialog1(QWidget *parent = nullptr);
    ~newDialog1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

private:
    Ui::newDialog1 *ui;
};

#endif // NEWDIALOG1_H
