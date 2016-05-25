#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include <QSharedMemory>

int main(int /*argc*/, char* /*argv*/[]) {
    std::cout << "Client here, wishing you a bright day" << std::endl;

    auto mem = new QSharedMemory("sharedmemory");
    mem->attach();
    mem->lock();
    std::string s = "test";
    std::vector<char> readstring(20);
    memcpy(readstring.data(), mem->data(), s.size() + 1);
    mem->unlock();

    std::cout << "Client says: " << std::string(readstring.data(), readstring.size()) << std::endl;

    return 0;
}

