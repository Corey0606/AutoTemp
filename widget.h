#ifndef WIDGET_H
#include "visa.h"
#include <QWidget>
#include "mythread.h"
#define WIDGET_H
#define MAX_SCPI_LENGTH                 255                         // 最大的SCPI命令
#define DEFAULT_TIMEOUT                 5000                    // 超时:5000ms

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int initVisa();
    void startTemp(int speed);
    void stopTemp();
    void closeEvent(QCloseEvent *event);
    char* initGpib();


private:
    Ui::Widget *ui;
    ViStatus nReturnStatus = 0;                         // 保存返回数值
    ViSession rmSession = 0, pnInstrHandle;
    ViUInt32 retCnt = 0;
    ViByte wrtBuf[MAX_SCPI_LENGTH];                     // 写缓冲区
    ViByte rdBuf[MAX_SCPI_LENGTH];                      // 读缓冲区
    int Return_Count;
    int speed_level;
    float temp;
    int state;
    mythread* my_thread;
    char *addr_inst;
    QString addr;

};
#endif // WIDGET_H
