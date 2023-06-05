#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Project15/FlashMemoryDevice.h"
#include "../Project15/DeviceDriver.cpp"

using namespace testing;

class FlashMemoryDeviceMock : public FlashMemoryDevice
{
public:
	MOCK_METHOD(unsigned char, read, (long address), (override));
	MOCK_METHOD(void, write, (long address, unsigned char data), (override));
};

TEST(DeviceDriver, ReadTest) {
	FlashMemoryDeviceMock mock;

	EXPECT_CALL(mock, read).Times(5).WillRepeatedly(Return(0x03));

	DeviceDriver device_driver(&mock);

	EXPECT_THAT(device_driver.read(0x0), Eq(0x3));
}