#ifndef H_MOTOR
#define H_MOTOR

//#include "../pid/pid.h"

using namespace std;

class Motor {
    public:
        Motor(int pin);

        void initialize();
        void stop();

        void control(float setPoint, float input);
		void setPin(int pin);
		void setPWM(int value);
     
    private:
        int pin;

};

#endif