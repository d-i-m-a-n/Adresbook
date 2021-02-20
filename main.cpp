#include "adressbook.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    adressbook w;
    w.show();
    return a.exec();
}
