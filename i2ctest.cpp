#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>

using namespace std;

int main()
{
	int fd, result;
	
	// Initialize the interface by giving it an external device ID
	// The MCP defaults to address 0x60
	//
	// It returns a standard file descriptor
	
	fd = wiringPiI2CSetup(0x57);
	
	cout << "Init result: "<< fd << endl;
	
	result = wiringPiI2CReadReg16(fd, 0xFF);
	
	cout << "Read result: "<< result << endl;

}
