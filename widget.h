#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

private slots:
    void digit_pressed();
    void binary_operation_pressed();

    void on_btn_clear_released();
    void on_btn_equal_released();
    void on_btn_decimal_released();
};
#endif // WIDGET_H
