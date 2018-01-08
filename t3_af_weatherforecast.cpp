#include "t3_af_weatherforecast.h"
#include "ui_t3_af_weatherforecast.h"

//界面构造函数
T3_AF_weatherForecast::T3_AF_weatherForecast(QDialog *mainWindow, QWidget *parent) :
    QDialog(parent),
    _mainWindow(mainWindow),
    ui(new Ui::T3_AF_weatherForecast)
{
    //界面布局初始化
    ui->setupUi(this);
    this->move(0, 0);
    this->resize(800, 450);
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    ui->_exitPushBtn_->setText("");
    ui->_exitPushBtn_->setStyleSheet("border-image:url(:/Pictures/weatherForecast_back.png)");
    ui->_dateTimeLabel_->setText("");
    ui->_dateTimeLabel_->setStyleSheet("color:rgb(7, 221, 225)");
    //界面浮现动画
    QPropertyAnimation *animation_ = new QPropertyAnimation(this, "windowOpacity");
    animation_->setDuration(300);
    animation_->setStartValue(0);
    animation_->setEndValue(1);
    animation_->start();
    //定时器
    QTimer *timer_ = new QTimer(this);
    timer_->start(200);
    //链接ui部件与功能
    connect(timer_, SIGNAL(timeout()), this, SLOT(timeUpdate()));
    connect(ui->_exitPushBtn_, &QPushButton::clicked, this, &T3_AF_weatherForecast::exitToMainWindow);
    //日志
    T3LOG("6+ 天气界面构造");
}

//显示时间
void T3_AF_weatherForecast::timeUpdate()
{
    QDateTime dateTime_ = QDateTime::currentDateTime();
    QString dateTimeStr_ = dateTime_.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->_dateTimeLabel_->setText(dateTimeStr_);
}

//界面背景绘制
void T3_AF_weatherForecast::paintEvent(QPaintEvent *)
{
    QPainter paint_(this);
    paint_.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/Pictures/weatherForecast_background.png"));
}

//退出
void T3_AF_weatherForecast::exitToMainWindow()
{
    _mainWindow->show();
    this->close();
    delete this;
}

//界面析构函数
T3_AF_weatherForecast::~T3_AF_weatherForecast()
{
    delete ui;
    //日志
    T3LOG("6- 天气界面析构");
}
