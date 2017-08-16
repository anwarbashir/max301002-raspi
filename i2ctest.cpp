#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>
#include <wiringPi.h>

#include "MAX30102.h"

#define MAX_BRIGHTNESS 255

unsigned int aun_ir_buffer[500];  //IR LED sensor data
int n_ir_buffer_length;            //data length
unsigned int aun_red_buffer[500]; //Red LED sensor data
int n_sp02;                        //SP02 value
signed char ch_spo2_valid;        //indicator to show if the SP02 calculation is valid
int n_heart_rate;                  //heart rate value
signed char ch_hr_valid;          //indicator to show if the heart rate calculation is valid
unsigned char uch_dummy;          //??

using namespace std;

//declare INTERUPT pin here currently INT of MAX30102 is connected to GPIO17
const int irqPin = 0;

//declare switch that will be used to start the readings
const int butPin = 3;


/**
void testing(int fd)
{
	int intr_1, modeReg, led1Pulse, led2Pulse;
	//check interupt power ready register
	intr_1 = wiringPiI2CWriteReg8(fd, REG_INTR_STATUS_1, 0x00);
	std::cout << "INTR_1: " << std::hex << intr_1 << endl;
	
	modeReg = wiringPiI2CWriteReg8(fd, REG_MODE_CONFIG, 0x09);
	std::cout << "INTR_1: " << std::hex << modeReg << endl;
	
	led1Pulse = wiringPiI2CWriteReg8(fd, REG_MULTI_LED_CTRL1, 0x7F);
	std::cout << "INTR_1: " << std::hex << led1Pulse << endl;
	
	led2Pulse= wiringPiI2CWriteReg8(fd, REG_MULTI_LED_CTRL2, 0x7F);
	std::cout << "INTR_1: " << std::hex << led2Pulse << endl;
	
}
**/

bool maxim_max30102_reset(int fd)
{
	if(!wiringPiI2CWriteReg8(fd, REG_MODE_CONFIG, 0x40))
		return false;
	else
		return true;
}


int main()
{
	unsigned int un_min, un_max, un_prev_data; //variables to calculate the on-board LED brightness that reflects the heartbeats
	int i;
	int n_brightness;
	float f_temp;
	
	wiringPiSetup();	
	pinMode(butPin, INPUT);
	pinMode(irqPin, INPUT);	
	int fd, partID, revisionID, reset, intr_1, modeReg, led1Pulse, led2Pulse;	
	// Obtain fd by sending I2C device ID, i.e. 57
	fd = wiringPiI2CSetup(0x57); 
	std::cout << "fd: " << std::hex << fd << endl;
	partID = wiringPiI2CReadReg8(fd, REG_PART_ID); // if working should return 0x15
	std::cout << "PartID: " << std::hex << partID << endl;
	revisionID = wiringPiI2CReadReg8(fd, REG_REV_ID); // to find revision	
	std::cout << "RevisionID: " << std::hex << revisionID << endl;
	
	//now try to copy the main functionality
	//reset the MAX30102
	if (maxim_max30102_reset(fd) == true) {		
		printf("TRUE?\n");
		}
	else {
		printf("FALSE?\n");
		}
	
	//reset = wiringPiI2CWriteReg8(fd, REG_MODE_CONFIG,0x40);
	//std::cout << "Reset: " << std::hex << reset << endl;
	
	//read and clear status register
    //maxim_max30102_read_reg(0,&uch_dummy);
	//wait until user presses a button on GPIO butPin 
	printf("Press button to begin scan\n");
	while(digitalRead(butPin)) {delay(75);}
		
	//Initialise the MAX30102
	//intr_1 = wiringPiI2CWriteReg8(fd, REG_INTR_ENABLE_1, 0xc0);
	//std::cout << "INTR_1: " << std::hex << intr_1 << endl;
	//declare variables to calculate the on-board LED brightness that reflects the heartbeats
	
	//return 0;
}


