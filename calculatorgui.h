#ifndef CALCULATORGUI_H
#define CALCULATORGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CalculatorGui;
}
QT_END_NAMESPACE

class CalculatorGui : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorGui(QWidget *parent = nullptr);
    ~CalculatorGui();

private slots:
    void on_button_0_clicked();

    void on_button_process_clicked();

    void on_button_1_clicked();

    void on_button_2_clicked();

    void on_button_3_clicked();

    void on_button_4_clicked();

    void on_button_5_clicked();

    void on_button_6_clicked();

    void on_button_7_clicked();

    void on_button_8_clicked();

    void on_button_add_clicked();

    void on_button_multiply_clicked();

    void on_button_9_clicked();

    void on_button_sub_clicked();

    void on_button_divide_clicked();

    void on_button_power_clicked();

    void on_button_obracket_clicked();

    void on_button_cbracket_clicked();

    void on_button_dot_clicked();

    void on_button_clear_clicked();

    void on_button_all_clear_clicked();

private:
    Ui::CalculatorGui *ui;
};
#endif // CALCULATORGUI_H
