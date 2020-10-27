#include "mythread.h"
#include <QDebug>
#include "QString"

mythread::mythread(ViSession &pnInstrHandle)
{
    this->pnInstrHandle = pnInstrHandle;
    this->state = 0;
}
void mythread::run()
{
    while (1) {
        mutex.lock();
        if(state){
            condition.wait(&mutex);
            qDebug()<<"开始等待";
        }
        qDebug()<<"读数中";
        nReturnStatus = viQueryf(this->pnInstrHandle, "CRDG? 1\n", "%s", rdBuf);
        qDebug("%s",rdBuf);
        char *str_char = (char *)rdBuf;
        temp = QString(QLatin1String(str_char)).toFloat();
        emit Sig(temp);
        mutex.unlock();
    }

}

void mythread::resume(){
    this->state = 0;
    condition.wakeAll();
    qDebug()<<"成功唤醒";
}

void mythread::pause(){
    this->state = 1;
    msleep(500);
    qDebug()<<"进入睡眠";
}
