#include "calculatorgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorGui w;
    w.setWindowTitle("RPN Calculator.");
    w.show();
    return a.exec();
}
