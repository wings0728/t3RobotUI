#include "t3_af_confirmexit.h"
#include "ui_t3_af_confirmexit.h"

//界面构造函数
T3_AF_confirmExit::T3_AF_confirmExit(QDialog *welcome, QDialog *mainWindow, QWidget *parent) :
    QDialog(parent),
    _welcome(welcome),
    _mainWindow(mainWindow),
    ui(new Ui::T3_AF_confirmExit)
{
    //界面布局初始化
    ui->setupUi(this);
    this->move(0, 0);
    this->resize(800, 450);
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->_yesPushBtn_->setText("");
    ui->_yesPushBtn_->setStyleSheet("border-image:url(:/Pictures/confirmExit_yes.png)");
    ui->_noPushBtn_->setText("");
    ui->_noPushBtn_->setStyleSheet("border-image:url(:/Pictures/confirmExit_no.png)");
    ui->_confirmLabel_->setText("");
    ui->_confirmLabel_->setStyleSheet("border-image:url(:/Pictures/confirmExit_label.png)");
    //界面浮现动画
    QPropertyAnimation *animation_ = new QPropertyAnimation(this, "windowOpacity");
    animation_->setDuration(200);
    animation_->setStartValue(0);
    animation_->setEndValue(0.9);
    animation_->start();
    //链接ui部件与功能
    connect(ui->_yesPushBtn_, &QPushButton::clicked, this, &T3_AF_confirmExit::confirmExit);
    connect(ui->_noPushBtn_, &QPushButton::clicked, this, &T3_AF_confirmExit::doNotExit);
    //日志
    T3LOG("4+ 退出确认界面构造");
}

//界面背景绘制
void T3_AF_confirmExit::paintEvent(QPaintEvent *)
{
    QPainter paint_(this);
    paint_.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/Pictures/confirmExit_background.png"));
}

//返回welcome
void T3_AF_confirmExit::confirmExit()
{
    _welcome->show();
    this->close();
    _mainWindow->close();
    delete this;
    delete _mainWindow;
}

//返回mainWindow
void T3_AF_confirmExit::doNotExit()
{
    this->close();
    delete this;
}

//界面析构函数
T3_AF_confirmExit::~T3_AF_confirmExit()
{
    delete ui;
    //日志
    T3LOG("4- 退出确认界面析构");
}
