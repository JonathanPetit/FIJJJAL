#ifndef H_ULTRASOUND
#define H_ULTRASOUND

#include <iostream>
#include <tuple>

using namespace std;

class Ultrasound {
    public:
        Ultrasound(int echo, int trig);
        
        void initialize();
        double getDistance();

    private:
        int echo;
        int trig;

        volatile long end;
        volatile long start;

        void pulse();
};

#endif

