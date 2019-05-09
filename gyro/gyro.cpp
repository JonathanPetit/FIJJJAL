#include <iostream>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "struct.h"
#include "gyro.h"

using namespace std;

Gyro::Gyro() {
    
}

//Initialise Gyroscope
void Gyro::initialise() {
	// Get I2C device, L3G4200D I2C address is 0x69
    this->i2cInitialise("/dev/i2c-1", 0x69);

    char config[2] = {0};
    config[0] = 0x20;
    config[1] = 0x0F;
    write(this->file, config, 2);

    // Full scale range, 2000 dps(0x30)
    config[0] = 0x23;
    config[1] = 0x30;
    write(this->file, config, 2);
    sleep(1);
}

//Initialise I2C
void Gyro::i2cInitialise(char *bus, char address) {
    this->file = open(bus, O_RDWR);
    ioctl(this->file, I2C_SLAVE, address);
}

//Read X and Y
XY Gyro::readXY() {
	XY xy;
	// Read xGyro lsb, msb data from register(0x28, 0x29)
	xy.x = this->readAxis(0x28, 0x29);
	// Read yGyro lsb, msb data from register(0x2A, 0x2B)
	xy.y = this->readAxis(0x2A, 0x2B);
	return xy;
}

//Read Axis
int Gyro::readAxis(char lsb_add, char msb_add){
	char res[1] = {0};
	char reg[1] = {lsb_add};

	
	write(this->file, reg, 1);
	read(this->file, res, 1);
	char lsb_res = res[0];

	reg[0] = msb_add;
	write(this->file, reg, 1);
	read(this->file, res, 1);
	char msb_res = res[0];

	int axis = (lsb_res + msb_add);
	if(axis > 180)
	{
		axis -= 360;
	}

	return axis;
}