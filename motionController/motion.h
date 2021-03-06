#ifndef H_MOTION
#define H_MOTION

#include "../pid/pid.h"
#include "../motor/motor.h"
#include "../gyro/gyro.h"
#include "../gyro/struct.h"
#include "../ultrasound/ultrasound.h"

using namespace std;

class MotionController {

    public:
        MotionController();
        MotionController(Motor upRightMotor , Motor upLeftMotor
                        ,Motor downRightMotor , Motor downLeftMotor , 
                        Gyro gyro, Ultrasound ultrasound[4]);
        void setupMotors(int pin1 , int pin2 , int pin3, int pin4); 
        void setupPIDS(){     };

        void landing(float p1,float input1 ,
                                 float p2,float input2, float p3 , float input3,float p4 ,float input4);

        void takeOFf(float p1,float input1 ,
                                 float p2,float input2, float p3 , float input3,float p4 ,float input4);


        void move(string direction, float setpointp1 ,float input1 , 
                    float setpointp2,float input2, 
                    float setpointp3 , float input3,
                    float setpointp4 ,float input4);
        XY getGyroValue();
        double getDistance();


        /* void forward(float p1 ,float input1 ,
                                float p2,float input2, float p3 , float input3,float p4 ,float input4);
        void turnLeft(float p1 ,float input1 ,
                                 float p2,float input2, float p3 , float input3,float p4 ,float input4);
        void turnRight(float p1 ,float input1 ,
                                 float p2,float input2, float p3 , float input3,float p4 ,float input4); 
        void backward(float p1 ,float input1 ,
                                float p2,float input2, float p3 , float input3,float p4 ,float input4);

        void descend(float p1 ,float input1 ,
                                 float p2,float input2, float p3 , float input3,float p4 ,float input4);

        void ascend(float p1 ,float input1 ,
                                 float p2,float input2, float p3 , float input3,float p4 ,float input4);
        */
    
    private:

        Motor upRightMotor ;
        Motor upLeftMotor ;
        Motor downRightMotor ; 
        Motor downLeftMotor ;
        Gyro gyro ;
        Ultrasound ultrasound;
        
};

#endif