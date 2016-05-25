#include <iostream>
#include <string>
#include <vector>

#include <common/SharedMemoryDevice.h>

#include <QDebug>
#include <QTextStream>

using namespace common;

int main(int /*argc*/, char* /*argv*/[]) {
    std::cout << "Hello World, this is Broker" << std::endl;

    SharedMemoryDevice mem(static_cast<size_t>(1024));
    if (mem.open(QIODevice::ReadWrite)) {
        QTextStream stream(&mem);
        stream << "this is a test";
        qDebug() << stream.readAll();
    }
    return 0;
}
