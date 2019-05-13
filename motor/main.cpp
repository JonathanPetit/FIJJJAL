#include <iostream>
#include <fstream>
#include <unistd.h>
#include <pigpio.h>

#include "motor.h"
void Calibration();
Motor mot1 = Motor(22);
Motor mot2 = Motor(18);

using namespace std;

int main() {
	
	if (gpioInitialise() < 0)
    {
		fprintf(stderr, "pigpio initialisation failed\n");
		return 1;
    }	
	char order;
	//Initialize the GPIO Pin
	mot1.initialize();
	mot2.initialize();
	
	//Choose what to do
	order = getchar();
	while (order != 'q'){
		if (order == 'c'){
			Calibration();
		}
		else{	
			//Test of low speed and high speed rotation of motors
			cout << "Démarrage";
			mot1.setPWM(1250);
			mot2.setPWM(1250);
			sleep(1);
			mot1.setPWM(1800);
			mot2.setPWM(1800);
			
		}
		
		order = getchar();
	}
	//Stop the motors
    mot1.stop();
    mot2.stop();
	
    return 0;
}

void Calibration(){
   char y;
   
   //Max Throttle
   mot1.setPWM(2000);
   mot2.setPWM(2000);
   printf("Connect the battery !, wait music\n");
   y = getchar();
   
   if (y != 'q')
   {
      getchar();
	  //Min Throttle
      mot1.setPWM(1000);
      mot2.setPWM(1000);
      printf("Servo Pulse on Min\n");
	  
	  //Wait for the ESC to complete calibration
      sleep(6);
      printf("Done Calibrating, REMOVE THE BATTERY THEN PUT IT BACK\n");
      getchar();
   }
}
