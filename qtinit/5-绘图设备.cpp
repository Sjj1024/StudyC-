#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <mybutton.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置标题和窗体大小
    this->setWindowTitle("翻金币小游戏");
    this->setWindowIcon(QIcon(":/resource/Coin0001.png"));
    this->setFixedSize(320, 588);

    // 设置退出按钮事件
    connect(ui->actiontuichu, &QAction::triggered, [=](){
       this->close();
    });

    // 添加一个按钮
    myButton * startbut = new myButton(":/resource/MenuSceneStartButton.png");
    startbut->setParent(this);
    startbut->move(this->width()*0.5 - startbut->width()*0.5, this->height()*0.7);

    // 链接开始按钮
    connect(startbut, &QPushButton::clicked, [=](){
        qDebug() << "开始按钮点击了";
    });

}

void MainWindow::paintEvent(QPaintEvent *){
    // 创建一个画家
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/resource/MenuSceneBg.png"));
    
};

MainWindow::~MainWindow()
{
    delete ui;
}

