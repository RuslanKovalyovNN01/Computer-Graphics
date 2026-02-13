#include <QtCore/QCoreApplication>
#include <QtGui/QImage>

#include <cstring>
#include <string>

int main(int argc, char *argv[])
{
    std::string s;
    QImage img;
    for (int i = 0; i < argc; i++) {
        if (!strcmp(argv[i], "-p") && (i + 1 <  argc)) {
            s = argv[i + 1];
        }
    }
    img.load(QString(s.c_str()));
    img.save("C:/Users/black/Desktop/Images/img1.jpg");
    QCoreApplication app(argc, argv);

    return app.exec();
}
