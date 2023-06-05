#pragma once
#include "FlashMemoryDevice.h"

class DeviceDriver
{
public:
    DeviceDriver(FlashMemoryDevice* hardware);
    void readException(unsigned char read_data, unsigned char data);
    int read(long address);
    void writeException(long address);
    void write(long address, int data);

protected:
    FlashMemoryDevice* m_hardware;
};