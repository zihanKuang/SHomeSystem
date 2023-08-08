#ifndef REGISTERVIEW_H
#define REGISTERVIEW_H

#include <QWidget>
#include "userdb.h"

namespace Ui {
class RegisterView;
}

class RegisterView : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterView(QWidget *parent = nullptr);
    ~RegisterView();

private slots:
    void onRegisterButtonClicked();

private:
    Ui::RegisterView *ui;
    //UserDB userDB; // UserDB对象作为类成员

    // validate input
    bool validateInput();

    // register API
    void callRegisterAPI();
};

#endif // REGISTERVIEW_H
