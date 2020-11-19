#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

//globle variables
double firstNum;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btn0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->btn_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->btn_sub,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->btn_div,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->btn_mul,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->btn_add->setCheckable(true);
    ui->btn_sub->setCheckable(true);
    ui->btn_mul->setCheckable(true);
    ui->btn_div->setCheckable(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if(ui->btn_add->isChecked() ||ui->btn_sub->isChecked() ||ui->btn_mul->isChecked() ||
            ui->btn_div->isChecked())
    {
         labelNumber = button->text().toDouble();
    }
    else
    {
        labelNumber = (ui->label->text() + button->text()).toDouble();
    }


    newLabel = QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);






}

void Widget::on_btn_clear_released()
{
    ui->label->setText("0");
}

void Widget::on_btn_equal_released()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->label->text().toDouble();

    if(ui->btn_add->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->btn_add->setChecked(false);
    }
    else if(ui->btn_sub->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->btn_sub->setChecked(false);
    }
    else if(ui->btn_mul->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->btn_mul->setChecked(false);
    }
    else if(ui->btn_div->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->btn_div->setChecked(false);
    }
}


void Widget::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    firstNum = ui->label->text().toDouble();
    button->setChecked(true);
}




void Widget::on_btn_decimal_released()
{

    if(ui->label->text().contains(".")==false)
    {
    ui->label->setText(ui->label->text() + ".");
    }

}
