#ifndef T3_AF_MAINWINDOW_H
#define T3_AF_MAINWINDOW_H

#include "t3_af_config.h"
#include <QDialog>

#include "t3_af_confirmexit.h"
#include "t3_af_face.h"
#include "t3_af_weatherforecast.h"
#include "t3_af_map.h"
#include "t3_af_robotinfo.h"

namespace Ui {
class T3_AF_mainWindow;
}

class T3_AF_mainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit T3_AF_mainWindow(QDialog *welcome, QWidget *parent = 0);
    ~T3_AF_mainWindow();

    void exitToWelcome();
    void toFace();
    void toWeatherForecast();
    void toMap();
    void toRobotInfo();

private slots:
    void timeUpdate();
    void weatherUpdate(Today today);

private:
    Ui::T3_AF_mainWindow *ui;
    QDialog *_welcome;
    void paintEvent(QPaintEvent *event);
   T3_AF_getWeather *_weather;
};

#endif // T3_AF_MAINWINDOW_H
