#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //添加菜单栏,并将菜单放进窗体中
    QMenuBar * menuMain = menuBar();
    setMenuBar(menuMain);
    // 添加文件菜单
    QMenu * fileMenu = menuMain->addMenu("文件");
    QAction * fileAction =  fileMenu->addAction("打开");
    QAction * newAction =  fileMenu->addAction("新建");
    // 菜单之间可以添加分割线
    fileMenu->addSeparator();
    fileMenu->addAction("最近");
    fileMenu->addAction("关闭");

    // 添加编辑菜单
    QMenu * editMenu = menuMain->addMenu("编辑");
    editMenu->addAction("打开");
    editMenu->addAction("新建");
    editMenu->addAction("最近");
    editMenu->addAction("关闭");

    //添加一个工具栏
    QToolBar * toolBar = new QToolBar(this);
    // 将工具栏添加到窗口中
    addToolBar(Qt::LeftToolBarArea, toolBar);
    // 为工具栏添加行为
    toolBar->addAction(fileAction);
    toolBar->addAction(newAction);

    // 设置工具栏属性
    toolBar->setMovable(false); // 不可以移动
    toolBar->setFloatable(false); // 设置不可以浮动

    // 添加横线，按钮等控件
    toolBar->addSeparator();

    QPushButton * btn2 = new QPushButton;
    btn2->setText("按钮2");
    // 因为QPushButton是widget的子类，所以可以加入
    toolBar->addWidget(btn2);

    // 状态栏:创建一个状态栏，并添加到窗体中
    QStatusBar * staBar = statusBar();
    setStatusBar(staBar);

    // 在状态栏中添加标签:
    QLabel * lab1 = new QLabel("提示信息:");
    staBar->addWidget(lab1);

    QLabel * lab2 = new QLabel("右侧的提示信息:");
    staBar->addPermanentWidget(lab2);

    // 设置浮动窗口（锚点），可以脱离窗口浮动
    QDockWidget * dockWid = new QDockWidget("浮动窗口", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWid);

    // 设置核心组件，也就是中心位置
    QTextEdit * textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

