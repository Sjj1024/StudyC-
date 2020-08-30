#include "choosepan.h"
#include <QPainter>
#include <QLabel>
#include <QDebug>

choosePan::choosePan(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("请选择关卡");
    setFixedSize(320, 588);

    // 将按钮变量赋值为一个返回按钮
    backbut = new myButton(":/resource/BackButton.png");
    backbut->setParent(this);
    backbut->move(this->width() - backbut->width(), this->height() - backbut->height());
    // 链接返回按钮
    connect(backbut, &QPushButton::clicked, [=](){
        emit this->backPress();
    });

    // 创建关卡选择按钮
    for (int i=0; i< 20; i++) {
        myButton * menubut = new myButton(":/resource/LevelIcon.png");
        menubut->setParent(this);
        menubut->move(25 + i%4 * 70, 130 + i/4 *70);
        // 创建一个lable显示关卡数字
        QLabel * menulable = new QLabel;
        menulable->setParent(this);
        menulable->setFixedSize(menubut->width(), menubut->height());
        menulable->setText(QString::number(i+1));
        menulable->move(25 + i%4 * 70, 130 + i/4 *70);
        // 设置文字对齐方式
        menulable->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        // 监听每个按钮的点击事件
        connect(menubut, &QPushButton::clicked, [=](){
            QString pressMenu = QString("你选择关卡是%1").arg(i+1);
            qDebug() << pressMenu;
        });
        // 设置label标签的穿透事件，不然的话按钮被label盖住了，就没有效果
        menulable->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}


void choosePan::paintEvent(QPaintEvent *){
    // 创建一个画家对象
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/resource/PlayLevelSceneBg.png"));

};
