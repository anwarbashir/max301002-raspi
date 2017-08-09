#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>

//I2C Write Address, found using i2cdetect -y 1
#define I2C_DEVICE_ADDR 0x57

//Table 17 Slave ID Description
#define REG_SLAVE_WRITE 0xAE
#define REG_SLAVE_READ  0xAF

//register addresses
#define REG_INTR_STATUS_1 0x00
#define REG_INTR_STATUS_2 0x01
#define REG_INTR_ENABLE_1 0x02
#define REG_INTR_ENABLE_2 0x03
#define REG_FIFO_WR_PTR 0x04
#define REG_OVF_COUNTER 0x05
#define REG_FIFO_RD_PTR 0x06
#define REG_FIFO_DATA 0x07
#define REG_FIFO_CONFIG 0x08
#define REG_MODE_CONFIG 0x09
#define REG_SPO2_CONFIG 0x0A
#define REG_LED1_PA 0x0C
#define REG_LED2_PA 0x0D
#define REG_PILOT_PA 0x10
#define REG_MULTI_LED_CTRL1 0x11
#define REG_MULTI_LED_CTRL2 0x12
#define REG_TEMP_INTR 0x1F
#define REG_TEMP_FRAC 0x20
#define REG_TEMP_CONFIG 0x21
#define REG_PROX_INT_THRESH 0x30
#define REG_REV_ID 0xFE
#define REG_PART_ID 0xFF

using namespace std;

int main()
{
	int fd, sanity, revision, i2c_start;
		
	// Initialize the interface by giving it an external device ID
	// It returns a standard file descriptor
	// A sanity check is then undertaken

	fd = wiringPiI2CSetup(I2C_DEVICE_ADDR);
	
	std::cout << "Init result: " << std::hex << fd << endl;
	
	sanity = wiringPiI2CReadReg8(fd, REG_PART_ID); // if working should return 0x15
	
	std::cout << "Sanity result: " << std::hex << sanity << endl;
	
	revision = wiringPiI2CReadReg8(fd, REG_REV_ID); // to find revision
	
	std::cout << "Revision: " << std::hex << revision << endl;
	
	//objective - Get the FIFO_WR_PTR 
	//START
	//Send device address + write mode
	//write address 0xAE and read address 0xAF
	
	//i2c_start = wiringPiI2C(WriteReg8(fd, REG_SLAVE_WRITE);
	

}
