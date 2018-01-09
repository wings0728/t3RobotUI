#include "t3_af_welcome.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T3_AF_welcome w;
    w.show();

    return a.exec();
}



//#include "t3_af_userdata.h"
//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    T3_AF_userData w;
//    w.show();

//    return a.exec();
//}
