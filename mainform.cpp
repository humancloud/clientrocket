#include "mainform.h"
#include "chatform.h"
#include "ui_mainform.h"

#include <QDebug>


//程序图标设计为Go的吉祥物拥抱着Qt或Cpp的小火箭,  程序美化的时候下载一些Qt源码，来写
mainform::mainform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainform)
{
    ui->setupUi(this);


    // 界面样式设置..........
    this->move(400,400);
    ui->friends->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //关闭竖直滚动条


    //=========================设置双击好友与之聊天的功能================================//
    ui->friends->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->friends->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->friends->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置表格QTableWidget只读
    // 双击表格某一行时，会触发信号，连接到槽函数，给槽函数双击的元素的行和列,与这行这列的好友聊天
    connect(ui->friends,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(chatwith(int,int)));


    //按显示好友列表按钮，触发显示好友功能
    connect(ui->friendlist,&QPushButton::clicked,this,&mainform::showfriends);

    //按显示群聊按钮，触发显示群聊功能
    connect(ui->grouplist,&QPushButton::clicked,this,&mainform::showgroups);

    //读取好友列表存到本地，排序，然后显示好友
    showfriends();
}



//显示好友,这里可改一下字体，太小了太丑了
void mainform::showfriends()
{
    //1. 先清空tablewidget,删除所有行
    int tablewidgetitemcount = ui->friends->rowCount();
    for(int i=0; i<tablewidgetitemcount; ++i)
    {
        ui->friends->removeRow(0);   //每次循环都删除第1行，这样才能准确删除全部Item
    }

    //2. 然后向服务器查询好友信息，添加到tableWidget
    for (int i=0; i<20; ++i) {
        QTableWidgetItem *friend1=new QTableWidgetItem("小明");
        friend1->setTextAlignment(Qt::AlignCenter);   //居中显示
        ui->friends->insertRow(i);
        ui->friends->setItem(i,0,friend1);
    }
}

//显示群聊
void mainform::showgroups()
{
    //1. 先清空tablewidget,删除所有行
    int tablewidgetitemcount = ui->friends->rowCount();
    for(int i=0; i<tablewidgetitemcount; ++i)
    {
        ui->friends->removeRow(0);   //删除第i行
    }

    //2. 然后向服务器查询好友信息，添加到tableWidget
    for (int i=0; i<6; ++i) {
        QTableWidgetItem *friend1=new QTableWidgetItem("群组");
        friend1->setTextAlignment(Qt::AlignCenter);   //居中显示
        ui->friends->insertRow(i);
        ui->friends->setItem(i,0,friend1);
    }
}


//row为行， column为列, 选中这用户与其聊天
void mainform::chatwith(int row,int column)
{
    qDebug() << row << column;
    qDebug() << ui->friends->item(row,column)->text();

    std::string item = ui->friends->item(row,column)->text().toStdString();

    //显示聊天界面
    chatform *chat = new chatform;
    chat->Init();
    chat->show();
}


mainform::~mainform()
{
    delete ui;
}
