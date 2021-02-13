#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

//cpp header
#include <string>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    int sendlogininfo(std::string userid,std::string passwd);

public slots:
    void checklogin();

private:
    Ui::login *ui;

    std::string id;        //接收输入框里的id
    std::string passwd;    //输入框里的passwd
};

#endif // LOGIN_H
