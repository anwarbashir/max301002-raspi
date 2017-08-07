#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>

using namespace std;

int main()
{
	int fd, result;
	
	// Initialize the interface by giving it an external device ID
	// Running the command 'ic2detect -y 1' reveals the device address 57 and 0x57 reveals init result 3
	// **need to check is this is correct before proceeding because the program reveals the same result irrespective of power
	// It returns a standard file descriptor
	
	fd = wiringPiI2CSetup(0x57);
	
	cout << "Init result: "<< fd << endl;
	
	result = wiringPiI2CReadReg16(fd, 0xFF);
	
	cout << "Read result: "<< result << endl;

}
