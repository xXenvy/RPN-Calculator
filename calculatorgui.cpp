#include "calculatorgui.h"
#include "./ui_calculatorgui.h"

#include "backend/calculator.h"

RPNCalculator calculator{};

CalculatorGui::CalculatorGui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorGui)
{
    ui->setupUi(this);
}

CalculatorGui::~CalculatorGui()
{
    delete ui;
}

void append_string_to_output(const Ui::CalculatorGui *ui, const std::string& text) {
    std::string input = ui->input->text().toStdString();
    input.append(text);
    ui->input->setText(QString::fromStdString(input));
}

void remove_last_char_from_output(const Ui::CalculatorGui *ui) {
    std::string input = ui->input->text().toStdString();
    if(!input.empty()) {
        input.pop_back();
        ui->input->setText(QString::fromStdString(input));
    }
}

void CalculatorGui::on_button_process_clicked()
{
    const std::string input = ui->input->text().toStdString();
    try{
        const QString result = QString::number(calculator.process(input));
        ui->input->setText(result);
    } catch(const std::exception& err) {
        ui->input->setText(QString::fromStdString(err.what()));
    }
}

void CalculatorGui::on_button_0_clicked()
{
    append_string_to_output(ui, "0");
}

void CalculatorGui::on_button_1_clicked()
{
    append_string_to_output(ui, "1");
}

void CalculatorGui::on_button_2_clicked()
{
    append_string_to_output(ui, "2");
}

void CalculatorGui::on_button_3_clicked()
{
    append_string_to_output(ui, "3");
}

void CalculatorGui::on_button_4_clicked()
{
    append_string_to_output(ui, "4");
}

void CalculatorGui::on_button_5_clicked()
{
    append_string_to_output(ui, "5");
}

void CalculatorGui::on_button_6_clicked()
{
    append_string_to_output(ui, "6");
}

void CalculatorGui::on_button_7_clicked()
{
    append_string_to_output(ui, "7");
}

void CalculatorGui::on_button_8_clicked()
{
    append_string_to_output(ui, "8");
}

void CalculatorGui::on_button_9_clicked()
{
    append_string_to_output(ui, "9");
}

void CalculatorGui::on_button_add_clicked()
{
    append_string_to_output(ui, "+");
}

void CalculatorGui::on_button_multiply_clicked()
{
    append_string_to_output(ui, "*");
}

void CalculatorGui::on_button_sub_clicked()
{
    append_string_to_output(ui, "-");
}

void CalculatorGui::on_button_divide_clicked()
{
    append_string_to_output(ui, "/");
}

void CalculatorGui::on_button_power_clicked()
{
    append_string_to_output(ui, "^");
}

void CalculatorGui::on_button_obracket_clicked()
{
    append_string_to_output(ui, "(");
}

void CalculatorGui::on_button_cbracket_clicked()
{
    append_string_to_output(ui, ")");
}

void CalculatorGui::on_button_dot_clicked()
{
    append_string_to_output(ui, ".");
}

void CalculatorGui::on_button_clear_clicked()
{
    remove_last_char_from_output(ui);
}

void CalculatorGui::on_button_all_clear_clicked()
{
    while(!ui->input->text().isEmpty()) {
        remove_last_char_from_output(ui);
    }
}
