#ifndef NEWDIALOG2_H
#define NEWDIALOG2_H

#include <QDialog>

namespace Ui {
class newDialog2;
}

class newDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit newDialog2(QWidget *parent = nullptr);
    ~newDialog2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::newDialog2 *ui;
};

#endif // NEWDIALOG2_H
