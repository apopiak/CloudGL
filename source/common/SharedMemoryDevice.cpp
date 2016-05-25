#include "SharedMemoryDevice.h"

#include <QDebug>

namespace common
{

struct Guard {
    Guard(QSharedMemory * mem)
        : locked(false)
        , m_mem(mem)
    {
        if (m_mem)
            locked = m_mem->lock();
    }

    ~Guard()
    {
        if (m_mem) {
            m_mem->unlock();
            locked = false;
        }
    }

    bool locked;
    QSharedMemory * m_mem;
};

SharedMemoryDevice::SharedMemoryDevice(size_t size)
    : m_size(size)
    , m_sharedMem(new QSharedMemory(QString("sharedmemory") + QString::number(m_size)))
{
    if (!m_sharedMem->create(m_size)) {
        if (m_sharedMem->error() == QSharedMemory::AlreadyExists) {
            if (!m_sharedMem->attach()) {
                qCritical() << "Could not attach to shared memory: " << m_sharedMem->errorString();
            }
            qDebug() << "shared mem already exists with size: " << m_sharedMem->size();
        } else {
            qCritical() << "Could not create shared memory: " << m_sharedMem->errorString();
        }
    }
}

bool SharedMemoryDevice::isSequential() const
{
    return false;
}

qint64 SharedMemoryDevice::readData(char *data, qint64 maxlen)
{
    if (maxlen > 0) {
        Guard guard(m_sharedMem.get());
        if (!guard.locked) {
            qCritical() << "lock error " << m_sharedMem->errorString();
            return -1;
        }
        qint64 readlen = maxlen > m_sharedMem->size() ? m_sharedMem->size() : maxlen;
        memcpy((void*) data, m_sharedMem->data(), readlen);
        return readlen;
    }
    return 0;
}

qint64 SharedMemoryDevice::writeData(const char *data, qint64 len)
{
    Guard guard(m_sharedMem.get());
    if (!guard.locked) {
        qCritical() << "lock error " << m_sharedMem->errorString();
        return -1;
    }
    qint64 writelen = len > m_sharedMem->size() ? m_sharedMem->size() : len;
    memcpy(m_sharedMem->data(), (const void*) data, writelen);
    return writelen;
}

}


