#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>

using namespace std;

int main()
{
	int fd, sanity, revision;
		
	// Initialize the interface by giving it an external device ID
	// It returns a standard file descriptor
	// A sanity check is then undertaken

	fd = wiringPiI2CSetup(0x57);
	
	cout << "Init result: "<< fd << endl;
	
	sanity = wiringPiI2CReadReg8(fd, 0xFF); // of working should return 0x15
	
	std::cout << "Sanity result: " << std::hex << sanity << endl;
	
	revision = wiringPiI2CReadReg8(fd, 0xFE); // to find revision
	
	std::cout << "Revision: " << std::hex << revision << endl;

}
