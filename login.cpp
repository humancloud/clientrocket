#include "login.h"
#include "ui_login.h"
#include "mainform.h"

#include "cJSON.h"


#include <QLineEdit>
#include <QPushButton>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);


    //设置窗口弹出的位置
    this->move(400,400);

    //设置框内默认文字
    ui->userid->setPlaceholderText("用户id");
    ui->passwd->setPlaceholderText("密码");
    ui->passwd->setEchoMode(QLineEdit::Password);   //密码输入框(lineedit)设置输入的是密码，以隐藏显示文本

    //回车按登录按钮
    ui->Login->setShortcut( QKeySequence::InsertParagraphSeparator );  //设置快捷键为键盘的“回车”键
    ui->Login->setShortcut(Qt::Key_Enter);  //设置快捷键为enter键
    ui->Login->setShortcut(Qt::Key_Return); //设置快捷键为小键盘上的enter键
    ui->Login->setDefault(true);  //设置默认按钮，设置了这个属性，当用户按下回车的时候，就会按下该按钮

    //设置点击登录后的操作，触发槽函数checklogin
    connect(ui->Login,&QPushButton::clicked,this,&login::checklogin);
}

//检查用户id与密码是否正确
void login::checklogin()
{
    //把QString转为标准string
    this->id = ui->userid->text().toStdString();
    this->passwd = ui->passwd->text().toStdString();

    //向服务器发送信息，返回登录结果
    if (sendlogininfo(id,passwd)) { 
        //创建主窗口，显示主窗口, 还要把连接套接字给主界面
        mainform *form = new mainform;
        form->show();

        this->hide();   //隐藏此窗口，如果销毁此窗口，那么整个程序结束了，而且此窗口含有与服务器端的连接，不能销毁
                        //但要注意，如果这是最后一个窗口的话那么调用hide的时候会结束程序，如果想即使最后一个窗口关闭也不结束，main里面这样设置:   a.setQuitOnLastWindowClosed(false); //最后一个窗口隐藏时就不会把他销毁了
        return;
    }


    ui->userid->clear();
    ui->passwd->clear();
    ui->userid->setPlaceholderText("用户名或密码错误");
    ui->passwd->setPlaceholderText("用户名或密码错误");
    ui->userid->setFocus();   //设置光标焦点
}

//向服务器发送用户id和密码，返回结果
int login::sendlogininfo(std::string userid, std::string passwd)
{
    char *buf = new char[512];

    if (userid == "111" && passwd == "hello") {
        return 1;
    }


    //cJSON *root = cJSON_Parse(buf);

    delete[] buf;
    return 0;
}


login::~login()
{
    delete ui;
}
