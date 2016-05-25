#include <iostream>
#include <string>
#include <vector>

#include <SharedMemoryDevice.h>

#include <QDebug>
#include <QTextStream>

using namespace common;

int main(int /*argc*/, char* /*argv*/[]) {
    std::cout << "Hello World, this is Broker" << std::endl;

    SharedMemoryDevice mem(static_cast<size_t>(512));
    if (mem.open(QIODevice::ReadWrite)) {
        QTextStream stream(&mem);
        QString mystr("test");
        stream << mystr;
        stream.flush();
        QString readstr = stream.read(mystr.size());
        qDebug() << readstr;
    }
    return 0;
}
