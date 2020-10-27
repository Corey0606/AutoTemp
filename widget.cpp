#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include "QString"
#include "QThread"
#include "QApplication"
#include "QMessageBox"
#include "QCloseEvent"
#include "QTimer"
#include "QSettings"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->ds_temp_goal->setValue(20);
    ui->ds_temp_display->setEnabled(0);
    ui->le_addr_gpib->setEnabled(false);
    setWindowTitle("自动控温系统");
    connect(ui->pb_start, &QPushButton::clicked, [=](){
        speed_level = ui->cb_speed->currentIndex()+1;
        startTemp(speed_level);
    });
    connect(ui->pb_stop, &QPushButton::clicked, [=](){
        stopTemp();
    });
    QTimer::singleShot(200, this, [=](){
        state = initVisa();
        if(state == 1){
        my_thread = new mythread(pnInstrHandle);
        my_thread->start();
        connect(my_thread, &mythread::Sig, [=](float temp){
            ui->ds_temp_display->setValue(temp);
        });}


    });


}



char* Widget::initGpib(){

    QSettings *pIni = new QSettings("./static/inst.ini", QSettings::IniFormat);
    addr = pIni->value("/GPIB/addr").toString().trimmed();
    qDebug()<<"addr"<<metaObject()<<addr;
    delete pIni;
    strcpy(addr_inst,addr.toLocal8Bit().data());
    return addr_inst;
}


void Widget::closeEvent(QCloseEvent *event){
    int ret = QMessageBox::question(this,"信息提示","确认是否退出页面",QMessageBox::Yes|QMessageBox::No, QMessageBox::No);
    if(ret == QMessageBox::Yes){
        event->accept();
    }else{
        event->ignore();
    }
}

Widget::~Widget()
{
    viClose(pnInstrHandle);
    viClose(rmSession);
    delete ui;
}


int Widget::initVisa()
{

    nReturnStatus = viOpenDefaultRM(&rmSession);
    addr_inst = initGpib();

    ui->le_addr_gpib->setText(addr);
    if(nReturnStatus != VI_SUCCESS){
        QMessageBox::warning(this, "错误提示","打开visa失败");
        this->setEnabled(0);
        return 0;
    }
    nReturnStatus = viOpen(rmSession, addr_inst, VI_NULL, VI_NULL, &pnInstrHandle);
    if(nReturnStatus != VI_SUCCESS){
        QMessageBox::warning(this, "错误提示","连接仪表失败");
        this->setEnabled(0);
        return 0;
    }
    /*- Configure VISA Formatted I/O ----------------------------------------*/
    nReturnStatus = viSetAttribute(pnInstrHandle, VI_ATTR_TMO_VALUE, DEFAULT_TIMEOUT);        // 设置超时
    nReturnStatus = viSetAttribute(pnInstrHandle, VI_ATTR_SUPPRESS_END_EN, VI_FALSE);        // 不发送终止符
    nReturnStatus = viSetAttribute(pnInstrHandle, VI_ATTR_SEND_END_EN, VI_FALSE);        // 不接收终止符
   
    viPrintf(pnInstrHandle, "RST\n");
    viPrintf(pnInstrHandle, "CLS\n");

    viPrintf(pnInstrHandle, "DISPFLD 1,1,2\n");
    viPrintf(pnInstrHandle, "DISPFLD 2,2,2\n");
    viPrintf(pnInstrHandle, "DISPFLD 3,3,2\n");
    viPrintf(pnInstrHandle, "DISPFLD 4,4\n");
    viPrintf(pnInstrHandle, "CMODE 1,4\n");
    viPrintf(pnInstrHandle, "CSET 1,A,2,0\n");
    return 1;
}


void Widget::startTemp(int speed){
    ui->pb_stop->setEnabled(1);
    ui->pb_start->setEnabled(0);
    QApplication::processEvents();
    my_thread->pause();
    qDebug()<<"写入设置";
    temp = ui->ds_temp_goal->value();
    speed = ui->cb_speed->currentIndex() + 1;
    qDebug("SETP 1,%.2f\n",temp);
    qDebug("RANGE 1,%d\n", speed);
    viPrintf(pnInstrHandle, "SETP 1,%f\n", temp);
    viPrintf(pnInstrHandle, "RANGE 1,%d\n", speed);
    my_thread->resume();

}


void Widget::stopTemp(){
    ui->pb_stop->setEnabled(0);
    QApplication::processEvents();
    my_thread->pause();
    qDebug()<<"写入设置";
    viPrintf(pnInstrHandle, "RANGE 1,0\n");
    my_thread->state = 1;
    ui->pb_start->setEnabled(1);
    ui->pb_stop->setEnabled(1);
    my_thread->resume();
    QApplication::processEvents();
}



