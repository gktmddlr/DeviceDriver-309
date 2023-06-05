#include "DeviceDriver.h"
#include "CustomException.h"
#include <windows.h>

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}

void DeviceDriver::readException(unsigned char read_data, unsigned char data)
{
	if(read_data != data) {
		throw ReadFailException();
	}
}

int DeviceDriver::read(long address)
{
    unsigned char read_data = 0;
    for(int i = 0; i < 5; i++)
    {
        auto data = m_hardware->read(address);
        Sleep(200);
        if (i != 0)
            readException(read_data, data);
        read_data = data;
    }
    return (int)read_data;
}

void DeviceDriver::writeException(long address)
{
	if(read(address) != 0xFF)
	{
		throw WriteFailException();
	}
}

void DeviceDriver::write(long address, int data)
{
    writeException(address);
    m_hardware->write(address, (unsigned char)data);
}
