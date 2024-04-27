#include "widget.h"
#include <QApplication>
#include "device.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    AirConditioner hostAir;  // 主卧空调
//    AirConditioner livingAir;  // 客厅空调
//    AirConditioner secondAir;  // 次卧空调

//    Humidifier livingHumidity; //客厅加湿器
//    Humidifier hostHumidity; //主卧加湿器

//    Light livingLight; //客厅灯
//    Light hostLight; //主卧灯
//    Light secondLight; //次卧灯

    Widget w;
    w.show();

    return a.exec();
}
