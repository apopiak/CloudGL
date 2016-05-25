#include <iostream>
#include <QApplication>
#include <QMainWindow>

#include <CloudGLClient.h>

int main(int argc, char* argv[])
{
    std::cout << "Client here, wishing you a bright day" << std::endl;

    QApplication app(argc, argv);

    CloudGLClient cloudGLClient;
    cloudGLClient.show();

    return app.exec();
}

