#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMutex>
#include <visa.h>
#include <QWaitCondition>

class mythread : public QThread
{
    Q_OBJECT
public:
    mythread(ViSession&pnInstrHandle);
    void run();
    void resume();
    void pause();
    ViSession pnInstrHandle;
    ViByte rdBuf[255];                      // 读缓冲区
    ViStatus nReturnStatus;
    float temp;
    int state;
    QMutex mutex;
    QWaitCondition condition;


signals:
    void Sig(float);

};

#endif // MYTHREAD_H
