#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QProgressDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 在桌面上显示按钮:颜色对话框
    QPushButton * but1 = new QPushButton(this);
    but1->setText("颜色对话框");
    but1->move(30, 50);
    connect(but1, &QPushButton::clicked, [=](){
        // 组建颜色对话框，并显示
        QColorDialog dialog(Qt::red, this); // 创建对象
        dialog.setOption(QColorDialog::ShowAlphaChannel);   // 显示 alpha 选项
        dialog.exec();  // 以模态方式运行对话框
        QColor color = dialog.currentColor();   // 获取颜色对话框当前颜色
        qDebug() <<"color:" <<color;    // 输出颜色信息
    });

    // 显示文件对话框
    QPushButton * but2 = new QPushButton(this);
    but2->setText("文件对话框");
    but2->move(30, 100);
    connect(but2, &QPushButton::clicked, [=](){
        // 组建文件对话框
        QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("文件对话框"), "F:",tr("图片文件(* png * jpg);;文本文件(* txt)"));
        qDebug() <<"files:" << fileNames;    // 输出文件信息
    });

    // 消息对话框
    QPushButton * but3 = new QPushButton(this);
    but3->setText("消息对话框");
    but3->move(30, 150);
    connect(but3, &QPushButton::clicked, [=](){
        // 问题对话框
        int ret1 = QMessageBox::question(this, tr("问题对话框"),tr("你了解Qt吗？"), QMessageBox::Yes, QMessageBox::No);
        if(ret1 == QMessageBox::Yes)
            qDebug() << tr("问题！");
    });

    // 提示对话框
    QPushButton * but4 = new QPushButton(this);
    but4->setText("提示对话框");
    but4->move(200, 50);
    connect(but4, &QPushButton::clicked, [=](){
        // 提示对话框
        int ret2 = QMessageBox::information(this, tr("提示对话框"),tr("这是Qt书籍！"), QMessageBox::Ok);
        if(ret2 == QMessageBox::Ok)
            qDebug() << tr("提示！");
    });

    // 警告对话框
    QPushButton * but5 = new QPushButton(this);
    but5->setText("警告对话框");
    but5->move(200, 100);
    connect(but5, &QPushButton::clicked, [=](){
        // 警告对话框
        int ret3 = QMessageBox::warning(this, tr("警告对话框"),tr("不能提前结束！"), QMessageBox::Abort);
        if(ret3 == QMessageBox::Abort)
            qDebug() << tr("警告！");
    });

    // 错误对话框
    QPushButton * but6 = new QPushButton(this);
    but6->setText("错误对话框");
    but6->move(200, 150);
    connect(but6, &QPushButton::clicked, [=](){
        // 错误对话框
        int ret4 = QMessageBox::critical(this, tr("严重错误对话框"),tr("发现一个严重错误！现在要关闭所有文件！"), QMessageBox::YesAll);
        if(ret4 == QMessageBox::YesAll)
            qDebug() << tr("错误");
    });

    // 关于对话框
    QPushButton * but7 = new QPushButton(this);
    but7->setText("关于对话框");
    but7->move(350, 50);
    connect(but7, &QPushButton::clicked, [=](){
        // 关于对话框
        QMessageBox::about(this, tr("关于对话框"),tr("yafeilinux致力于Qt及Qt Creator的普及工作！"));
    });

    // 进度对话框
    QPushButton * but8 = new QPushButton(this);
    but8->setText("进度对话框");
    but8->move(350, 100);
    connect(but8, &QPushButton::clicked, [=](){
        QProgressDialog dialog(tr("文件复制进度"), tr("取消"), 0, 50000, this);
        dialog.setWindowTitle(tr("进度对话框"));     // 设置窗口标题
        dialog.setWindowModality(Qt::WindowModal);  // 将对话框设置为模态
        dialog.show();

        // 演示复制进度
        for(int i=0; i<50000; i++)
        {
            dialog.setValue(i);                     // 设置进度条的当前值
            QCoreApplication::processEvents();      // 避免界面冻结
            if(dialog.wasCanceled()) // 按下取消按钮则中断
                break;
        }

        dialog.setValue(50000);    // 这样才能显示100%，因为for循环中少加了一个数
        qDebug() << tr("复制结束！");
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

