#ifndef STARTFORM_H
#define STARTFORM_H


#include <QWidget>
//开始界面
namespace Ui {
    class StartForm;
}

class StartForm:public QWidget{
public:
    explicit StartForm(QWidget *parent=0);//防止隐形自动转换
    ~StartForm();
private:
    Ui::StartForm *ui;
};

#endif // STARTFORM_H
