#ifndef STARTFORM_H
#define STARTFORM_H


#include <QWidget>
//��ʼ����
namespace Ui {
    class StartForm;
}

class StartForm:public QWidget{
public:
    explicit StartForm(QWidget *parent=0);//��ֹ�����Զ�ת��
    ~StartForm();
private:
    Ui::StartForm *ui;
};

#endif // STARTFORM_H
