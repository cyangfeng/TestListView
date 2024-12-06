#include "TestListView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestListView w;
    w.show();
    return a.exec();
}
