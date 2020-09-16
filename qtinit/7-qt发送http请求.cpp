#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 构建及发送请求
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QString url = "http://localhost:8080/findUsers";
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkReply *pReply = manager->get(request);
    // 开启一个局部的事件循环，等待页面响应结束
    QEventLoop eventLoop;
    QObject::connect(manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();
    // 获取网页Body中的内容
    QByteArray bytes = pReply->readAll();
    QString reason = bytes;

//    QVariant reason = pReply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    qDebug() << "reason=" << reason;

}

MainWindow::~MainWindow()
{
    delete ui;
}

