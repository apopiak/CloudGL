
#pragma once

#include <memory>

#include <QIODevice>
#include <QSharedMemory>

namespace common
{

class SharedMemoryDevice : public QIODevice
{
    Q_OBJECT

public:
    SharedMemoryDevice(size_t size = 1024);
    virtual ~SharedMemoryDevice() = default;

    virtual bool isSequential() const override;

protected:
    virtual qint64 readData(char *data, qint64 maxlen) override;
    virtual qint64 writeData(const char *data, qint64 len) override;

    size_t m_size;
    std::unique_ptr<QSharedMemory> m_sharedMem;
};

}
