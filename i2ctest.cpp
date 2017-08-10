
#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>

#include "MAX30102.h"

using namespace std;

int main()
{
	int fd, partID, revisionID, intr_1;
		
	// Obtain fd by sending I2C device ID, i.e. 57

	fd = wiringPiI2CSetup(0x57);
	
	std::cout << "fd: " << std::hex << fd << endl;
	
	partID = wiringPiI2CReadReg8(fd, REG_PART_ID); // if working should return 0x15
	
	std::cout << "PartID: " << std::hex << partID << endl;
	
	revisionID = wiringPiI2CReadReg8(fd, REG_REV_ID); // to find revision
	
	std::cout << "RevisionID: " << std::hex << revisionID << endl;
	
	
	//Initialise the MAX30102
	
	intr_1 = wiringPiI2CWriteReg8(fd, REG_INTR_ENABLE_1, 0xc0);
	
	std::cout << "INTR_1: " << std::hex << intr_1 << endl;
	
	

}
