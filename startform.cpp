#include "startform.h"
#include "ui_StartForm.h"
#include "mainwindow.h"

StartForm::StartForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartForm)
{
    ui->setupUi(this);

    setWindowTitle("Start");

    //�����ؿ���ť��� ��һ��
    connect(ui->pushButton, &QPushButton::clicked, [=]()
    {
        //�����ť����ؿ�
        Mainwindow *mainwindow = new Mainwindow(0);

        mainwindow->show(); //�ؿ���ʾ
    });

    //�ڶ���
    connect(ui->pushButton_2, &QPushButton::clicked, [=]()
    {
        Mainwindow *mainwindow = new Mainwindow(1);
        mainwindow->show(); //�ؿ���ʾ
    });

    //������
    connect(ui->pushButton_3, &QPushButton::clicked, [=]()
    {
        Mainwindow *mainwindow = new Mainwindow(2);
        mainwindow->show(); //�ؿ���ʾ
    });

}

StartForm::~StartForm()
{
    delete ui;
}
