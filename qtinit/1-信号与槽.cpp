#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 创建一个按钮对象
    QPushButton * btn = new QPushButton;

    // 设置按钮文字
    btn->setText("关闭窗口");

    // 设置按钮的父窗口
    btn->setParent(this);

    // 设置按钮大小
    btn->resize(80, 30);

    // 设置按钮位置
    btn->move(300, 300);

    // 设置窗体标题
    this->setWindowTitle("标题啊");

    // 按钮绑定点击事件，使用信号槽机制:信号发送者，信号（信号地址），目标接受者，接收处理方式（信号地址）
    //connect(btn, &QPushButton::clicked, this, &MainWindow::close);

    // 实现老师和学生的对象
    this->teacher = new Tracher(this);
    this->student = new Student(this);

//    connect(teacher, &Tracher::classIsOver, student, &Student::track);

//    // 触发信号
//    teacher->classIsOver();

    // 绑定信号与槽
    connect(teacher, &Tracher::hungry, student, &Student::chifan);

    // 使用带参数的信号
    // classIsOver();

    // 使用按钮触发下课信号
    connect(btn, &QPushButton::clicked, this, &MainWindow::classIsOver);

    // 让信号断开连接，disconnect
    // disconnect(btn, &QPushButton::clicked, this, &MainWindow::classIsOver);

    // 一个信号可以连接多个槽函数
    connect(btn, &QPushButton::clicked, this, &MainWindow::close);

    // lambda表达式定义：[](){};[]是lambda表达式标识，必须有，()是传递参数的，{}是写逻辑代码，最后使用的话，要加（）;
    // =表示通过值传递的方式，让lambda表达式可以使用局部变量，&表示引用传递的方式让表达式可以使用局部变量；
    [=](){
        btn->setText("lambda");
    }();

}

void MainWindow::classIsOver(){
    emit teacher->hungry("宫保鸡丁");
}

MainWindow::~MainWindow()
{
    delete ui;
}

