#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
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

    labelNumber = (ui->label->text() + button->text()).toDouble();

    newLabel = QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);






}

void Widget::on_btn_clear_released()
{
    ui->label->setText("0");
}

void Widget::on_btn_equal_released()
{

}


void Widget::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
}




void Widget::on_btn_decimal_released()
{

    if(ui->label->text().contains(".")==false)
    {
    ui->label->setText(ui->label->text() + ".");
    }

}
