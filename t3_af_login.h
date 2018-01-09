#ifndef T3_AF_LOGIN_H
#define T3_AF_LOGIN_H

#include "t3_af_config.h"
#include <QDialog>
#include <QMessageBox>

#include "t3_af_userdata.h"
#include "t3_af_mainwindow.h"

namespace Ui {
class T3_AF_logIn;
}

class T3_AF_logIn : public QDialog
{
    Q_OBJECT

public:
    explicit T3_AF_logIn(QDialog *welcome, QWidget *parent = 0);
    ~T3_AF_logIn();

    void backToWelcome();
    void logIn();
    QString getPassword(QString getUserName);

private slots:
    void timeUpdate();

private:
    Ui::T3_AF_logIn *ui;
    QDialog *_welcome;
    void paintEvent(QPaintEvent *event);
};

#endif // T3_AF_LOGIN_H
