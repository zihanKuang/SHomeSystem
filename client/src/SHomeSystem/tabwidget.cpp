#include "tabwidget.h"
#include "ui_tabwidget.h"


TabWidget::TabWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabWidget)
{
    ui->setupUi(this);

    // 初始化空调实例
    hostAir = new AirConditioner();
    livingAir = new AirConditioner();
    secondAir = new AirConditioner();

    //添加空调模式选项到ComboBox
    QStringList airModeOptions = { "制热", "制冷", "除湿", "节能", "睡眠", "送风" };
    ui->hostAirMode->addItems(airModeOptions);
    ui->livingAirMode->addItems(airModeOptions);
    ui->secondAirMode->addItems(airModeOptions);

    // 设置 QLabel 的初始内容
    ui->hostAirShow->setText("设备状态：关闭");
    ui->livingAirShow->setText("设备状态：关闭");
    ui->secondAirShow->setText("设备状态：关闭");

    //初始化加湿器实例
    livingHumidity = new Humidifier();
    hostHumidity = new Humidifier();

    // 设置 QLabel 的初始内容
    ui->hostHumidityShow->setText("设备状态：关闭");
    ui->livingHumidityShow->setText("设备状态：关闭");

    //设置湿度滑动条的范围
    ui->hostHumiditySlider->setRange(0, 100);
    ui->livingHumiditySlider->setRange(0, 100);

    //设置湿度旋钮的范围
    ui->hostHumiditySpin->setRange(0, 100);
    ui->livingHumiditySpin->setRange(0, 100);

    //初始化灯实例
    livingLight = new Light();
    hostLight = new Light();
    secondLight = new Light();

    // 设置 QLabel 的初始内容
    ui->hostLightShow->setText("设备状态：关闭");
    ui->livingLightShow->setText("设备状态：关闭");
    ui->secondLightShow->setText("设备状态：关闭");

    //添加空调模式选项到ComboBox
    QStringList LightModeOptions = { "冷光", "暖光" };
    ui->hostLightMode->addItems(LightModeOptions);
    ui->livingLightMode->addItems(LightModeOptions);
    ui->secondLightMode->addItems(LightModeOptions);

//    // 初始化网络访问管理器
//    networkAccessManager = new QNetworkAccessManager(this);
//    // 测试与服务器的连接状态
//    QNetworkRequest request(QUrl("http://127.0.0.1:8080")); // 修改为您的服务器地址
//    QNetworkReply* reply = networkAccessManager->get(request);

//    // 连接请求完成信号到槽函数
//    connect(reply, &QNetworkReply::finished, this, &TabWidget::onServerConnectionFinished);


    // 当tabwidget的页面的index切到1时，客户端就会像服务端发送耗电量计算的请求
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &TabWidget::handleTabChange);

    //空调模式
    connect(ui->hostAirMode, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TabWidget::onHostAirModeChanged);
    connect(ui->livingAirMode, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TabWidget::onLivingAirModeChanged);
    connect(ui->secondAirMode, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TabWidget::onSecondAirModeChanged);

    // 空调温度编辑
    connect(ui->hostAirEdit, &QLineEdit::editingFinished,
            this, &TabWidget::onHostAirEditEditingFinished);
    connect(ui->livingAirEdit, &QLineEdit::editingFinished,
            this, &TabWidget::onLivingAirEditEditingFinished);
    connect(ui->secondAirEdit, &QLineEdit::editingFinished,
            this, &TabWidget::onSecondAirEditEditingFinished);

    // 空调定时关闭和开启
    connect(ui->livingAirTimeBtn, &QPushButton::clicked,
                this, &TabWidget::onLivingAirTimeButtonClicked);
    connect(ui->hostAirTimeBtn, &QPushButton::clicked,
                this, &TabWidget::onHostAirTimeButtonClicked);
    connect(ui->secondAirTimeBtn, &QPushButton::clicked,
                this, &TabWidget::onSecondAirTimeButtonClicked);

//    connect(ui->hostAirTime, &QTimeEdit::timeChanged,
//            this, &TabWidget::onHostAirTimerTimeChanged);
//    connect(ui->livingAirTime, &QTimeEdit::timeChanged,
//            this, &TabWidget::onLivingAirTimerTimeChanged);
//    connect(ui->secondAirTime, &QTimeEdit::timeChanged,
//            this, &TabWidget::onSecondAirTimerTimeChanged);


    //空调开关
    connect(ui->hostAirBtn, &QPushButton::clicked,
                this, &TabWidget::onHostAirPowerButtonClicked);
    connect(ui->livingAirBtn, &QPushButton::clicked,
                this, &TabWidget::onLivingAirPowerButtonClicked);
    connect(ui->secondAirBtn, &QPushButton::clicked,
                this, &TabWidget::onSecondAirPowerButtonClicked);

    // 加湿器——连接湿度滑动条和旋钮的信号槽
    connect(ui->hostHumiditySlider, &QSlider::valueChanged, this, &TabWidget::onHostHumiditySliderChanged);
    connect(ui->livingHumiditySlider, &QSlider::valueChanged, this, &TabWidget::onLivingHumiditySliderChanged);
    connect(ui->hostHumiditySpin, QOverload<int>::of(&QSpinBox::valueChanged), this, &TabWidget::onHostHumiditySpinChanged);
    connect(ui->livingHumiditySpin, QOverload<int>::of(&QSpinBox::valueChanged), this, &TabWidget::onLivingHumiditySpinChanged);

    // 加湿器——连接加湿器开关按钮的信号槽
    connect(ui->hostHumidityBtn, &QPushButton::clicked, this, &TabWidget::onHostHumidityBtnClicked);
    connect(ui->livingHumidityBtn, &QPushButton::clicked, this, &TabWidget::onLivingHumidityBtnClicked);

    // 连接灯光定时时间改变的信号槽
    connect(ui->livingLightAuto, &QTimeEdit::timeChanged,
            this, &TabWidget::onLivingLightTimerTimeChanged);
    connect(ui->hostLightAuto, &QTimeEdit::timeChanged,
            this, &TabWidget::onHostLightTimerTimeChanged);
    connect(ui->secondLightAuto, &QTimeEdit::timeChanged,
            this, &TabWidget::onSecondLightTimerTimeChanged);

    //灯光模式设置
    connect(ui->hostLightMode, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabWidget::onHostLightModeChanged);
    connect(ui->livingLightMode, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabWidget::onLivingLightModeChanged);
    connect(ui->secondLightMode, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabWidget::onSecondLightModeChanged);

    // 灯光开关按钮连接
    connect(ui->hostLightBtn, &QPushButton::clicked,
            this, &TabWidget::onHostLightButtonClicked);
    connect(ui->livingLightBtn, &QPushButton::clicked,
            this, &TabWidget::onLivingLightButtonClicked);
    connect(ui->secondLightBtn, &QPushButton::clicked,
            this, &TabWidget::onSecondLightButtonClicked);
}

//如果有网络连接，则启用环境监测和数据分析页面。
//如果没有网络连接，则禁用这两个页面，并将QTabWidget切换到控制页面
//void TabWidget::onServerConnectionFinished()
//{
//    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
//    if (reply) {
//        if (reply->error() == QNetworkReply::NoError) {
//        // 连上服务器，有网络
//        // 启用需要网络连接的功能
//        ui->tabWidget->setTabEnabled(1, true); // EnviromentPage
//        ui->tabWidget->setTabEnabled(2, true); // DataAnalyticsPage
//    } else {
//        // 没有网络连接
//        // 禁用需要网络连接的功能
//        ui->tabWidget->setTabEnabled(1, false);
//        ui->tabWidget->setTabEnabled(2, false);
//        ui->tabWidget->setCurrentIndex(0); // 切换到第一页
//    }
//        // 释放资源
//        reply->deleteLater();
//    }
//}

// 处理页面切换信号的槽函数
void TabWidget::handleTabChange(int newIndex)
{
    if (newIndex == 1) {
        // 切换到索引为1的页面，发送相关请求
        sendDeviceTotalPowerRequest("http://your-server-url.com/data/airTotalPower");
        sendDeviceTotalPowerRequest("http://your-server-url.com/data/lightTotalPower");
        sendDeviceTotalPowerRequest("http://your-server-url.com/data/humidityTotalPower");
    }
    if (newIndex == 2) {
        //室内温度和天气折线图处理
    }
}

// 发送设备耗电量请求的函数
void TabWidget::sendDeviceTotalPowerRequest(const QString& url)
{
    QNetworkRequest request(url);
    QNetworkAccessManager manager;
    QNetworkReply* reply = manager.get(request);

    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 处理服务器响应的数据
            QString response = reply->readAll();

            // 解析 JSON 响应，获取耗电量信息
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response.toUtf8());
            if (!jsonResponse.isNull() && jsonResponse.isObject()) {
                QJsonObject jsonObject = jsonResponse.object();
                if (jsonObject.contains("totalPower")) {
                    double totalPower = jsonObject["totalPower"].toDouble();

                    // 在这里进行数据渲染或其他操作
                    //
                    //未实现
                    processDeviceTotalPowerResponse(response);
                }
            }

        } else {
            // 处理错误
            qDebug() << "Error: " << reply->errorString();
        }

        reply->deleteLater();
    });
}

void TabWidget::sendAirDataToServer(Device::State state, double temperature,
                                    QDateTime &timestamp, AirConditioner::AirMode mode)
{
    // 构建HTTP请求，将空调的设备状态、温度、定时类型和模式等数据传递给服务器
    // 请根据实际情况修改服务器URL和参数
    QUrl url("http://your-server-url.com/update_air_device_status");
    QUrlQuery query;

    query.addQueryItem("state", state == Device::State::ON ? "on" : "off");
    query.addQueryItem("temperature", QString::number(temperature));
    query.addQueryItem("timestamp", timestamp.toString(Qt::ISODate));
    query.addQueryItem("mode", QString::number(static_cast<int>(mode))); // 或者发送模式的枚举值

    url.setQuery(query);

    QNetworkRequest request(url);
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);

    // 处理服务器的响应
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 处理服务器响应的数据
            QString response = reply->readAll();

            // 解析 JSON 响应
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response.toUtf8());
            QJsonObject jsonObject = jsonResponse.object();

            if (jsonObject.contains("success") && jsonObject["success"].toBool()) {
                // 添加成功
                qDebug() << "Device status updated successfully.";
            } else {
                // 添加失败
                qDebug() << "Failed to update device status.";
            }

        } else {
            // 处理错误
            qDebug() << "Error: " << reply->errorString();
        }

        reply->deleteLater();
    });
}

void TabWidget::sendLightDataToServer(Device::State state, QDateTime &timestamp, Light::LightMode mode)
{
    // 构建HTTP请求，将灯光的设备状态、定时类型和模式等数据传递给服务器
    // 请根据实际情况修改服务器URL和参数
    QUrl url("http://your-server-url.com/update_light_device_status");
    QUrlQuery query;

    query.addQueryItem("state", state == Device::State::ON ? "on" : "off");
    query.addQueryItem("timestamp", timestamp.toString(Qt::ISODate));
    query.addQueryItem("mode", QString::number(static_cast<int>(mode))); // 或者发送模式的枚举值

    url.setQuery(query);

    QNetworkRequest request(url);
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);

    // 处理服务器的响应
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 处理服务器响应的数据
            QString response = reply->readAll();

            // 解析 JSON 响应
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response.toUtf8());
            QJsonObject jsonObject = jsonResponse.object();

            if (jsonObject.contains("success") && jsonObject["success"].toBool()) {
                // 添加成功
                qDebug() << "Device status updated successfully.";
            } else {
                // 添加失败
                qDebug() << "Failed to update device status.";
            }

        } else {
            // 处理错误
            qDebug() << "Error: " << reply->errorString();
        }

        reply->deleteLater();
    });
}

void TabWidget::sendHumidityDataToServer(Device::State state, double humidity, QDateTime &timestamp)
{
    // 构建HTTP请求，将加湿器的设备状态、湿度、定时类型等数据传递给服务器
    // 请根据实际情况修改服务器URL和参数
    QUrl url("http://your-server-url.com/update_humidity_device_status");
    QUrlQuery query;

    query.addQueryItem("state", state == Device::State::ON ? "on" : "off");
    query.addQueryItem("humidity", QString::number(humidity));
    query.addQueryItem("timestamp", timestamp.toString(Qt::ISODate));

    url.setQuery(query);

    QNetworkRequest request(url);
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);

    // 处理服务器的响应
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 处理服务器响应的数据
            QString response = reply->readAll();

            // 解析 JSON 响应
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response.toUtf8());
            QJsonObject jsonObject = jsonResponse.object();

            if (jsonObject.contains("success") && jsonObject["success"].toBool()) {
                // 添加成功
                qDebug() << "Device status updated successfully.";
            } else {
                // 添加失败
                qDebug() << "Failed to update device status.";
            }

        } else {
            // 处理错误
            qDebug() << "Error: " << reply->errorString();
        }

        reply->deleteLater();
    });

}

// 更新主卧空调的 QLabel
void TabWidget::updateHostAirStatusLabel()
{
    QString statusText;
    if (hostAir->getState() == Device::State::ON) {
        statusText = "设备状态：开启\n"
                     "温度：" + QString::number(hostAir->getTemperature()) + "\n";
        if(hostAir->getTimerType() == Device::TimerType::NOT_SET) {
            statusText += "定时：未设置\n";
        }
        else {
            statusText += "定时：" + QString::number(hostAir->getTimerHours()) + " 小时 " +
            QString::number(hostAir->getTimerMinutes()) + " 分钟后关闭\n";
        }
        statusText += QString("模式：%1\n").arg(hostAir->modeToString(hostAir->getMode()));
    } else {
        statusText = "设备状态：关闭\n";
        if(hostAir->getTimerType() == Device::TimerType::NOT_SET) {
            statusText += "定时：未设置\n";
        }
        else {
            statusText += "定时：" + QString::number(hostAir->getTimerHours()) + " 小时 " +
            QString::number(hostAir->getTimerMinutes()) + " 分钟后开启\n";
        }
    }
    ui->hostAirShow->setText(statusText);

    // 获取当前时间戳
    QDateTime currentTimestamp = QDateTime::currentDateTime();
    // 将更新后的状态数据发送到服务器
    sendAirDataToServer(hostAir->getState(), hostAir->getTemperature(),
                        currentTimestamp, hostAir->getMode());
}

void TabWidget::updateLivingAirStatusLabel()
{
    QString statusText;
    if (livingAir->getState() == Device::State::ON) {
        statusText = "设备状态：开启\n"
                     "温度：" + QString::number(livingAir->getTemperature()) + "\n";
        if(livingAir->getTimerType() == Device::TimerType::NOT_SET) {
            statusText += "定时：未设置\n";
        }
        else {
            statusText += "定时：" + QString::number(livingAir->getTimerHours()) + " 小时 " +
            QString::number(livingAir->getTimerMinutes()) + " 分钟后关闭\n";
        }
        statusText += QString("模式：%1\n").arg(livingAir->modeToString(livingAir->getMode()));
    } else {
        statusText = "设备状态：关闭\n";
        if(livingAir->getTimerType() == Device::TimerType::NOT_SET) {
            statusText += "定时：未设置\n";
        }
        else {
            statusText += "定时：" + QString::number(livingAir->getTimerHours()) + " 小时 " +
            QString::number(livingAir->getTimerMinutes()) + " 分钟后开启\n";
        }
    }
    ui->livingAirShow->setText(statusText);

    // 获取当前时间戳
    QDateTime currentTimestamp = QDateTime::currentDateTime();
    // 将更新后的状态数据发送到服务器
    sendAirDataToServer(livingAir->getState(), livingAir->getTemperature(),
                        currentTimestamp, livingAir->getMode());
}

void TabWidget::updateSecondAirStatusLabel()
{
    QString statusText;
    if (secondAir->getState() == Device::State::ON) {
        statusText = "设备状态：开启\n"
                     "温度：" + QString::number(secondAir->getTemperature()) + "\n";
        if(secondAir->getTimerType() == Device::TimerType::NOT_SET) {
            statusText += "定时：未设置\n";
        }
        else {
            statusText += "定时：" + QString::number(secondAir->getTimerHours()) + " 小时 " +
            QString::number(secondAir->getTimerMinutes()) + " 分钟后关闭\n";
        }
        statusText += QString("模式：%1\n").arg(secondAir->modeToString(secondAir->getMode()));
    } else {
        statusText = "设备状态：关闭\n";
        if(secondAir->getTimerType() == Device::TimerType::NOT_SET) {
            statusText += "定时：未设置\n";
        }
        else {
            statusText += "定时：" + QString::number(secondAir->getTimerHours()) + " 小时 " +
            QString::number(secondAir->getTimerMinutes()) + " 分钟后开启\n";
        }
    }
    ui->secondAirShow->setText(statusText);
    // 获取当前时间戳
    QDateTime currentTimestamp = QDateTime::currentDateTime();
    // 将更新后的状态数据发送到服务器
    sendAirDataToServer(secondAir->getState(), secondAir->getTemperature(),
                        currentTimestamp, secondAir->getMode());
}

// 空调温度编辑完成槽函数
void TabWidget::onHostAirEditEditingFinished()
{
    double temperature = ui->hostAirEdit->text().toDouble();
    hostAir->setTemperature(temperature);
    updateHostAirStatusLabel();
}
void TabWidget::onLivingAirEditEditingFinished()
{
    double temperature = ui->livingAirEdit->text().toDouble();
    livingAir->setTemperature(temperature);
    updateLivingAirStatusLabel();

}
void TabWidget::onSecondAirEditEditingFinished()
{
    double temperature = ui->secondAirEdit->text().toDouble();
    secondAir->setTemperature(temperature);
    updateSecondAirStatusLabel();
}

//空调定时
void TabWidget::onLivingAirTimeButtonClicked() {
    int hours = ui->livingAirTime->time().hour();
    int minutes = ui->livingAirTime->time().minute();

    int idx = startTimer(1000);
    TimerIndex2MyTimerMap[idx] = new myTimer("LivingAir", 0, hours);

    if (livingAir->getState() == Device::State::ON) {
        livingAir->setTimer(hours, minutes, Device::TimerType::OFF);
    } else {
        livingAir->setTimer(hours, minutes, Device::TimerType::ON);
    }
    updateLivingAirStatusLabel();
}

void TabWidget::onHostAirTimeButtonClicked() {
    int hours = ui->hostAirTime->time().hour();
    int minutes = ui->hostAirTime->time().minute();

    int idx = startTimer(1000);
    TimerIndex2MyTimerMap[idx] = new myTimer("hostAir", 0, hours);

    if (hostAir->getState() == Device::State::ON) {
        hostAir->setTimer(hours, minutes, Device::TimerType::OFF);
    } else {
        hostAir->setTimer(hours, minutes, Device::TimerType::ON);
    }
    updateHostAirStatusLabel();
}

void TabWidget::onSecondAirTimeButtonClicked() {
    int hours = ui->secondAirTime->time().hour();
    int minutes = ui->secondAirTime->time().minute();

    int idx = startTimer(1000);
    TimerIndex2MyTimerMap[idx] = new myTimer("secondAir", 0, hours);

    if (hostAir->getState() == Device::State::ON) {
        hostAir->setTimer(hours, minutes, Device::TimerType::OFF);
    } else {
        hostAir->setTimer(hours, minutes, Device::TimerType::ON);
    }
    updateSecondAirStatusLabel();
}

void TabWidget::timerEvent(QTimerEvent* event) {
    //如果timer已经结束
    if(visSet.find(event->timerId()) != visSet.end()) {
        return;
    }
    //计时结束
    if(TimerIndex2MyTimerMap[event->timerId()]->current == TimerIndex2MyTimerMap[event->timerId()]->target - 1) {
        //发送给执行器
        qDebug() << "yes" << endl;
        visSet.insert(event->timerId());
    }
    else {
        TimerIndex2MyTimerMap[event->timerId()]->current++;
        qDebug() << "no" << endl;
    }
}


//void TabWidget::onHostAirTimerTimeChanged(const QTime &time)
//{
//    if (!time.isValid()) {
//        return; // Invalid time, do nothing
//    }

//    int hours = time.hour();
//    int minutes = time.minute();

//    Device::State airState = hostAir->getState();

//    if (airState == Device::State::ON) {
//        hostAir->setTimer(hours, minutes, Device::TimerType::OFF);
//    } else {
//        hostAir->setTimer(hours, minutes, Device::TimerType::ON);
//    }
//    updateHostAirStatusLabel();
//}

//void TabWidget::onLivingAirTimerTimeChanged(const QTime &time)
//{
//    if (!time.isValid()) {
//        return; // Invalid time, do nothing
//    }

//    int hours = time.hour();
//    int minutes = time.minute();
//    Device::State airState = livingAir->getState();

//    if (airState == Device::State::ON) {
//        livingAir->setTimer(hours, minutes, Device::TimerType::OFF);
//    } else {
//        livingAir->setTimer(hours, minutes, Device::TimerType::ON);
//    }
//    updateLivingAirStatusLabel();
//}
//void TabWidget::onSecondAirTimerTimeChanged(const QTime &time)
//{
//    if (!time.isValid()) {
//        return; // Invalid time, do nothing
//    }

//    int hours = time.hour();
//    int minutes = time.minute();
//    Device::State airState = secondAir->getState();

//    if (airState == Device::State::ON) {
//        secondAir->setTimer(hours, minutes, Device::TimerType::OFF);
//    } else {
//        secondAir->setTimer(hours, minutes, Device::TimerType::ON);
//    }

//    updateSecondAirStatusLabel();
//}


// 空调开关按钮点击槽函数
void TabWidget::onHostAirPowerButtonClicked()
{
    hostAir->togglePower();
    updateHostAirStatusLabel();
}
void TabWidget::onLivingAirPowerButtonClicked()
{
    livingAir->togglePower();
    updateLivingAirStatusLabel();
}
void TabWidget::onSecondAirPowerButtonClicked()
{
    secondAir->togglePower();
    updateSecondAirStatusLabel();
}

//空调模式设置槽函数
void TabWidget::onHostAirModeChanged(int index)
{
    AirConditioner::AirMode newMode = static_cast<AirConditioner::AirMode>(index);
    hostAir->setMode(newMode);
    updateHostAirStatusLabel();
}
void TabWidget::onLivingAirModeChanged(int index)
{
    AirConditioner::AirMode newMode = static_cast<AirConditioner::AirMode>(index);
    livingAir->setMode(newMode);
    updateLivingAirStatusLabel();
}
void TabWidget::onSecondAirModeChanged(int index)
{
    AirConditioner::AirMode newMode = static_cast<AirConditioner::AirMode>(index);
    secondAir->setMode(newMode);
    updateSecondAirStatusLabel();
}

// 更新主卧加湿器状态Label
void TabWidget::updateHostHumidityStatusLabel() {
    QString statusText = "状态：";
    if (hostHumidity->getState() == Device::State::ON) {
        statusText += "开启";
        statusText += "，湿度：" + QString::number(hostHumidity->getHumidity()) + "%";
        ui->hostHumidityShow->setText(statusText);
    } else {
        statusText += "关闭";
        ui->hostHumidityShow->setText(statusText);
    }
    ui->hostHumidityShow->setText(statusText);

    // 获取当前时间戳
    QDateTime currentTimestamp = QDateTime::currentDateTime();

    // 在更新标签的同时发送数据到服务器
    sendHumidityDataToServer(hostHumidity->getState(), hostHumidity->getHumidity(), currentTimestamp);
}

// 更新客厅加湿器状态Label
void TabWidget::updateLivingHumidityStatusLabel() {
    QString statusText = "状态：";
    if (livingHumidity->getState() == Device::State::ON) {
        statusText += "开启";
        statusText += "，湿度：" + QString::number(livingHumidity->getHumidity()) + "%";
        ui->livingHumidityShow->setText(statusText);
    } else {
        statusText += "关闭";
        ui->livingHumidityShow->setText(statusText);
    }
    ui->livingHumidityShow->setText(statusText);

    QDateTime currentTimestamp = QDateTime::currentDateTime();

    // 在更新标签的同时发送数据到服务器
    sendHumidityDataToServer(livingHumidity->getState(), livingHumidity->getHumidity(), currentTimestamp);
}

// 加湿器开关按钮点击槽函数
void TabWidget::onHostHumidityBtnClicked() {
    if (hostHumidity->getState() == Device::State::ON) {
        hostHumidity->turnOff(); // 关闭加湿器
        ui->hostHumiditySlider->setValue(0); // 设置湿度滑动条为0
    } else {
        hostHumidity->setHumidity(50); // 设置湿度为50%
        hostHumidity->turnOn(); // 打开加湿器
        ui->hostHumiditySlider->setValue(50); // 设置湿度滑动条为50
    }
    updateHostHumidityStatusLabel();
}

void TabWidget::onLivingHumidityBtnClicked() {
    if (livingHumidity->getState() == Device::State::ON) {
        livingHumidity->turnOff(); // 关闭加湿器
        ui->livingHumiditySlider->setValue(0); // 设置湿度滑动条为0
    } else {
        livingHumidity->setHumidity(50); // 设置湿度为50%
        livingHumidity->turnOn(); // 打开加湿器
        ui->livingHumiditySlider->setValue(50); // 设置湿度滑动条为50
    }
    updateLivingHumidityStatusLabel();
}

// 湿度滑动条值变化槽函数
void TabWidget::onHostHumiditySliderChanged(int value) {
    if (value == 0) {
        hostHumidity->turnOff();
    } else {
        hostHumidity->setHumidity(value);
        hostHumidity->turnOn();
    }
    updateHostHumidityStatusLabel();
}

void TabWidget::onLivingHumiditySliderChanged(int value) {
    if (value == 0) {
        livingHumidity->turnOff();
    } else {
        livingHumidity->setHumidity(value);
        livingHumidity->turnOn();
    }
    updateLivingHumidityStatusLabel();
}

// 湿度旋钮值变化槽函数
void TabWidget::onHostHumiditySpinChanged(int value) {
    ui->hostHumiditySlider->setValue(value);
    hostHumidity->setHumidity(value);
    updateHostHumidityStatusLabel();
}

void TabWidget::onLivingHumiditySpinChanged(int value) {
    ui->livingHumiditySlider->setValue(value);
    livingHumidity->setHumidity(value);
    updateLivingHumidityStatusLabel();
}

//灯
//灯
//灯
void TabWidget::updateHostLightStatusLabel()
{
    QString hostLightStatusText;
    if (hostLight->getState() == Device::State::ON) {
        hostLightStatusText = "设备状态：开启\n";
        if(hostLight->getTimerType() == Device::TimerType::NOT_SET) {
            hostLightStatusText += "定时：未设置\n";
        }
        else {
            hostLightStatusText += "定时：" + QString::number(hostLight->getTimerHours()) + " 小时 " +
                                   QString::number(hostLight->getTimerMinutes()) + " 分钟后关闭\n";
        }
        hostLightStatusText += QString("模式：%1\n").arg(hostLight->modeToString(hostLight->getMode()));
    } else {
        hostLightStatusText = "设备状态：关闭\n";
        if(hostLight->getTimerType() == Device::TimerType::NOT_SET) {
            hostLightStatusText += "定时：未设置\n";
        }
        else {
            hostLightStatusText += "定时：" + QString::number(hostLight->getTimerHours()) + " 小时 " +
                                   QString::number(hostLight->getTimerMinutes()) + " 分钟后开启\n";
        }
    }
    ui->hostLightShow->setText(hostLightStatusText);

    // 获取当前时间戳
    QDateTime currentTimestamp = QDateTime::currentDateTime();

    // 将更新后的状态数据发送到服务器
    sendLightDataToServer(hostLight->getState(), currentTimestamp, hostLight->getMode());
}

void TabWidget::updateLivingLightStatusLabel()
{
    QString livingLightStatusText;
    if (livingLight->getState() == Device::State::ON) {
        livingLightStatusText = "设备状态：开启\n";
        if(livingLight->getTimerType() == Device::TimerType::NOT_SET) {
            livingLightStatusText += "定时：未设置\n";
        }
        else {
            livingLightStatusText += "定时：" + QString::number(livingLight->getTimerHours()) + " 小时 " +
                                   QString::number(livingLight->getTimerMinutes()) + " 分钟后关闭\n";
        }
        livingLightStatusText += QString("模式：%1\n").arg(livingLight->modeToString(livingLight->getMode()));
    } else {
        livingLightStatusText = "设备状态：关闭\n";
        if(livingLight->getTimerType() == Device::TimerType::NOT_SET) {
            livingLightStatusText += "定时：未设置\n";
        }
        else {
            livingLightStatusText += "定时：" + QString::number(livingLight->getTimerHours()) + " 小时 " +
                                   QString::number(livingLight->getTimerMinutes()) + " 分钟后开启\n";
        }
    }
    ui->livingLightShow->setText(livingLightStatusText);

    // 获取当前时间戳
    QDateTime currentTimestamp = QDateTime::currentDateTime();

    // 将更新后的状态数据发送到服务器
    sendLightDataToServer(livingLight->getState(), currentTimestamp, livingLight->getMode());
}

void TabWidget::updateSecondLightStatusLabel()
{
    QString secondLightStatusText;
    if (secondLight->getState() == Device::State::ON) {
        secondLightStatusText = "设备状态：开启\n";
        if(secondLight->getTimerType() == Device::TimerType::NOT_SET) {
            secondLightStatusText += "定时：未设置\n";
        }
        else {
            secondLightStatusText += "定时：" + QString::number(secondLight->getTimerHours()) + " 小时 " +
                                   QString::number(secondLight->getTimerMinutes()) + " 分钟后关闭\n";
        }
        secondLightStatusText += QString("模式：%1\n").arg(secondLight->modeToString(secondLight->getMode()));
    } else {
        secondLightStatusText = "设备状态：关闭\n";
        if(secondLight->getTimerType() == Device::TimerType::NOT_SET) {
            secondLightStatusText += "定时：未设置\n";
        }
        else {
            secondLightStatusText += "定时：" + QString::number(secondLight->getTimerHours()) + " 小时 " +
                                   QString::number(secondLight->getTimerMinutes()) + " 分钟后开启\n";
        }
    }
    ui->secondLightShow->setText(secondLightStatusText);

    // 获取当前时间戳
    QDateTime currentTimestamp = QDateTime::currentDateTime();

    // 将更新后的状态数据发送到服务器
    sendLightDataToServer(secondLight->getState(), currentTimestamp, secondLight->getMode());
}

// 灯光定时时间改变槽函数
void TabWidget::onLivingLightTimerTimeChanged(const QTime &time)
{
    int hours = time.hour();
    int minutes = time.minute();

    livingLight->setTimerHours(hours);
    livingLight->setTimerMinutes(minutes);

    Device::State LightState = livingLight->getState();

    if (LightState == Device::State::ON) {
        livingLight->setTimer(hours, minutes, Device::TimerType::ON);
    } else {
        livingLight->setTimer(hours, minutes, Device::TimerType::OFF);
    }

    // 更新显示
    updateLivingLightStatusLabel();
}

void TabWidget::onHostLightTimerTimeChanged(const QTime &time)
{
    int hours = time.hour();
    int minutes = time.minute();

    hostLight->setTimerHours(hours);
    hostLight->setTimerMinutes(minutes);

    Device::State LightState = hostLight->getState();

    if (LightState == Device::State::ON) {
        hostLight->setTimer(hours, minutes, Device::TimerType::ON);
    } else {
        hostLight->setTimer(hours, minutes, Device::TimerType::OFF);
    }

    updateHostLightStatusLabel();
}

void TabWidget::onSecondLightTimerTimeChanged(const QTime &time)
{
    int hours = time.hour();
    int minutes = time.minute();

    secondLight->setTimerHours(hours);
    secondLight->setTimerMinutes(minutes);

    Device::State LightState = secondLight->getState();

    if (LightState == Device::State::ON) {
        secondLight->setTimer(hours, minutes, Device::TimerType::ON);
    } else {
        secondLight->setTimer(hours, minutes, Device::TimerType::OFF);
    }

    updateSecondLightStatusLabel();
}

// 灯光模式设置槽函数
void TabWidget::onHostLightModeChanged(int index)
{
    Light::LightMode newMode = static_cast<Light::LightMode>(index);
    hostLight->setMode(newMode);
    updateHostLightStatusLabel();
}

void TabWidget::onLivingLightModeChanged(int index)
{
    Light::LightMode newMode = static_cast<Light::LightMode>(index);
    livingLight->setMode(newMode);
    updateLivingLightStatusLabel();
}

void TabWidget::onSecondLightModeChanged(int index)
{
    Light::LightMode newMode = static_cast<Light::LightMode>(index);
    secondLight->setMode(newMode);
    updateSecondLightStatusLabel();
}

// 灯的开关按钮点击槽函数
void TabWidget::onHostLightButtonClicked()
{
    hostLight->togglePower();
    updateHostLightStatusLabel();
}

void TabWidget::onLivingLightButtonClicked()
{
    livingLight->togglePower();
    updateLivingLightStatusLabel();
}

void TabWidget::onSecondLightButtonClicked()
{
    secondLight->togglePower();
    updateSecondLightStatusLabel();
}



TabWidget::~TabWidget()
{
    delete ui;
    // 清理资源
    //delete networkAccessManager;
}
