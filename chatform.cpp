#include "chatform.h"
#include "ui_chatform.h"

#include <QPropertyAnimation>
#include <QScrollBar>

chatform::chatform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatform)
{
    ui->setupUi(this);

    //界面样式设置
    this->move(400,400);

    ui->stackedWidget->setStyleSheet("QStackedWidget {background-image: url(:/images/background1.jpg);}");

    //setWindowFlags(Qt::FramelessWindowHint);//无边框
    setAttribute(Qt::WA_TranslucentBackground);//背景透明


    //消息显示框
    ui->messageBrowser->verticalScrollBar()->setStyleSheet(
        "QScrollBar:vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:9px;padding-bottom:9px;}"//留9px给上下箭头
        "QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%);border-radius:4px;min-height:20;}"//上下设置为椭圆
        "QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%);border-radius:4px;min-height:20;}"//鼠标悬浮颜色变深
        "QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/bottom.png);subcontrol-position:bottom;}"//下箭头
        "QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/top.png);subcontrol-position:top;}"//上箭头
        "QScrollBar::add-line:vertical:hover{height:7px;width:6px;border-image:url(:/images/bottom.png);border:1px;subcontrol-position:bottom;}"//鼠标悬浮下箭头
        "QScrollBar::sub-line:vertical:hover{height:7px;width:6px;border-image:url(:/images/top.png);border:1px;subcontrol-position:top;}"//鼠标悬浮上箭头
        "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;}" //滚动时部分
    );
    //消息编辑框
    ui->MessageEdit->verticalScrollBar()->setStyleSheet(
        "QScrollBar:vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:9px;padding-bottom:9px;}"//留9px给上下箭头
        "QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%);border-radius:4px;min-height:20;}"//上下设置为椭圆
        "QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%);border-radius:4px;min-height:20;}"//鼠标悬浮颜色变深
        "QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/bottom.png);subcontrol-position:bottom;}"//下箭头
        "QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/top.png);subcontrol-position:top;}"//上箭头
        "QScrollBar::add-line:vertical:hover{height:7px;width:6px;border-image:url(:/images/bottom.png);border:1px;subcontrol-position:bottom;}"//鼠标悬浮下箭头
        "QScrollBar::sub-line:vertical:hover{height:7px;width:6px;border-image:url(:/images/top.png);border:1px;subcontrol-position:top;}"//鼠标悬浮上箭头
        "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;}"//滚动时部分
     );


    //设置发送按钮-------------------------------
    ui->sendmessbutton->setFocus();    //设置默认焦点
    ui->sendmessbutton->setShortcut( QKeySequence::InsertParagraphSeparator );  //设置快捷键为键盘的“回车”键
    ui->sendmessbutton->setShortcut(Qt::Key_Enter);  //设置快捷键为enter键
    ui->sendmessbutton->setShortcut(Qt::Key_Return); //设置快捷键为小键盘上的enter键
    ui->sendmessbutton->setDefault(true);  //设置默认按钮，设置了这个属性，当用户按下回车的时候，就会按下该按钮



    //设置消息显示框
    ui->messageBrowser->setTextColor(Qt::gray);
    ui->messageBrowser->setCurrentFont(QFont("黑体",10));
    ui->messageBrowser->append(tr("%1 在线！").arg("小西"));

    //消息发送
    connect(ui->sendmessbutton,&QPushButton::clicked,this,&chatform::sendmess);
}


void chatform::Init()
{

}


void chatform::sendmess()
{
    QString msg=ui->MessageEdit->toHtml();
    ui->MessageEdit->clear();
    ui->MessageEdit->setFocus();
}


chatform::~chatform()
{
    delete ui;
}
