#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建定时器对象
    QTimer *timer = new QTimer(this);

    // 设置定时器时间
    timer->start(100);

    // 信号和槽关联起来
    connect(timer, &QTimer::timeout, [=](){
        static int numstr = 0;
        ui->label_1->setText(QString::number(numstr++));

    });

    //
    connect(ui->pushButton1, &QPushButton::clicked, [=](){
        static bool flag = true;
        if(flag){
            timer->stop();
            flag = false;
            ui->pushButton1->setText("开始");
        }else{
            timer->start(100);
            flag = true;
            ui->pushButton1->setText("暂停");
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

