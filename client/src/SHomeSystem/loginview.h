#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include <QtNetwork>
#include <QMessageBox>

namespace Ui {
class LoginView;
}

class LoginView : public QWidget
{
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = nullptr);
    ~LoginView();

private:
    Ui::LoginView *ui;

    // 定义验证用户登录输入信息的函数
    bool validateInput();

    // 定义调用后端HTTP API登录接口的函数
    void callLoginAPI(const QString&, const QString&);

signals:
    void loginSuccessful();

private slots:
    void onLoginButtonClicked();

};

#endif // LOGINVIEW_H
