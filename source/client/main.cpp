#include <iostream>
#include <QApplication>
#include <QMainWindow>

int main(int argc, char* argv[])
{
    std::cout << "Client here, wishing you a bright day" << std::endl;

    QApplication app(argc, argv);
    QMainWindow window;
    window.show();

    return app.exec();
}

