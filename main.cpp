#include <QtWidgets/QApplication>
#include <QtStartWindowClass.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtStartWindowClass *w = new QtStartWindowClass();
    w->show();
    return a.exec();
}
