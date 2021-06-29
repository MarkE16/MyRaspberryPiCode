#ifndef NEWDIALOG3_H
#define NEWDIALOG3_H

#include <QDialog>

namespace Ui {
class newDialog3;
}

class newDialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit newDialog3(QWidget *parent = nullptr);
    ~newDialog3();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newDialog3 *ui;
    newDialog3 *newdialog3;
};

#endif // NEWDIALOG3_H
