#include "startform.h"
#include "ui_StartForm.h"
#include "mainwindow.h"

StartForm::StartForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartForm)
{
    ui->setupUi(this);

    setWindowTitle("Start");

    //监听关卡按钮点击 第一关
    connect(ui->pushButton, &QPushButton::clicked, [=]()
    {
        //点击按钮进入关卡
        Mainwindow *mainwindow = new Mainwindow(0);

        mainwindow->show(); //关卡显示
    });

    //第二关
    connect(ui->pushButton_2, &QPushButton::clicked, [=]()
    {
        Mainwindow *mainwindow = new Mainwindow(1);
        mainwindow->show(); //关卡显示
    });

    //第三关
    connect(ui->pushButton_3, &QPushButton::clicked, [=]()
    {
        Mainwindow *mainwindow = new Mainwindow(2);
        mainwindow->show(); //关卡显示
    });

}

StartForm::~StartForm()
{
    delete ui;
}
