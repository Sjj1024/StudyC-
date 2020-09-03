#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("服务端端口8888");

    qtsocket = NULL;

    // 创建监听套接字, 允许任意ip链接
    qtcpserver = new QTcpServer(this);
    qtcpserver->listen(QHostAddress::Any, 8888);
    // 当有新的链接建立时，会出发一个newconnect信号
    connect(qtcpserver, &QTcpServer::newConnection, [=](){
        ui->textRead->setText("有新的链接建立:");
        // 当有新的链接是，从下一个挂起的连接中获取通讯连接套接字
        qtsocket = qtcpserver->nextPendingConnection();
        // 获取链接的客户端地址和端口
        QString info=qtsocket->peerAddress().toString()+":"+QString("%1").arg(qtsocket->peerPort());
        ui->textRead->append(info);
        // 向客户端发送数据
        qtsocket->write(QString("OK").toUtf8());

        // 接受客户端发送过来的数据，当有数据过来时，会触发一个readyread信号
        connect(qtsocket, &QTcpSocket::readyRead, [=](){
            // 读取接收到的所有数据
             QString tag = qtsocket->readAll();
             ui->textRead->append(tag);
        });
    });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_sendButton_clicked()
{
    if(NULL != qtsocket){
        QString writeStr = ui->textWrite->toPlainText();
        qtsocket->write(writeStr.toUtf8());
    }
}

void Widget::on_closeButton_clicked()
{
    if(qtsocket != NULL){
        qtsocket->disconnectFromHost();
        qtsocket = NULL;
    }
}
