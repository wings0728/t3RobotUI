#ifndef T3_AF_FACE_H
#define T3_AF_FACE_H

#include "t3_af_config.h"
#include <QDialog>

namespace Ui {
class T3_AF_face;
}

class T3_AF_face : public QDialog
{
    Q_OBJECT

public:
    explicit T3_AF_face(QDialog *mainWindow, QWidget *parent = 0);
    ~T3_AF_face();

    void exitToMainWindow();

private slots:
    void timeUpdate();

private:
    Ui::T3_AF_face *ui;
    QDialog *_mainWindow;
    void paintEvent(QPaintEvent *event);
};

#endif // T3_AF_FACE_H
