#include <QtCore/QCoreApplication>
#include <QtGui/QImage>

#include <cstring>
#include <string>

int main(int argc, char *argv[])
{
    std::string s;
    QImage img;

    QCoreApplication app(argc, argv);

    return app.exec();
}
