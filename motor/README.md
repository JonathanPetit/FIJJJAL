# Motors #

The drone we want to build here is a quadcopter, which mean that it need 4 Motors.
We choose 4 Brushless DC Motor, because they are more efficient both in speed and in power consuming. The problem is that they are more expansive that brushed motors and they need an ESC to work properly. Despite of that, Brushless DC motors were chosen because they are a too important part of the project.

To design the right motor, you need to pay attention to 2 main characteristics : Thrust and Kv

The thrust of a motor can be found on the documentation, but it depends on the propellers you will use on your quadcopter.
The Kv is the value which represent the number or Rotation per minute per Volt (RPM/V) the bigger your Kv is, the faster your motor will rotate.

Having a high Kv value on your motor means that they will rotate faster, but they will only fit with small propeller, which will decrease the thrust of the motors.

![picture alt](https://scontent.fbru1-1.fna.fbcdn.net/v/t1.15752-9/60094587_315442519124379_7267681935869083648_n.png?_nc_cat=102&_nc_ht=scontent.fbru1-1.fna&oh=3ff838e9238983a9baa4c6eb1c8befbf&oe=5D5FC84A)

We need to find a compromise between the size of the propeller and the Kv value of the motors.
We use motors of 900Kv value to have a big thrust with the propeller without a lot of speed.

# ESC #


The ESC is a controller that is used to control the brushless motors of the drone.
The ESC and the motors work with a battery, which must be appropriate for the motor you want to use. Here we use a Lipo battery of 14.8V / 20A
It's working by sending basically a 3 phase AC power to run the brushless motors.
It also use a variable frequency to be able to control the speed of the brushless motors.

![picture alt](https://scontent-bru2-1.xx.fbcdn.net/v/t1.15752-9/60308439_2475259019152170_3126621094954401792_n.png?_nc_cat=102&_nc_ht=scontent-bru2-1.xx&oh=dc6f9b92772155a9ffe241a4f7824669&oe=5D2A9C36)

The ESC must be calibrated to know what are the minimum and the maximum throttle to control the motors properly.
For example 1000 as minimum value and 2000 as maximum value
the control of the motors will be done by following the table :

Throttle Value  | Motor Speed
------------- | -------------
1000  | 0%
1500  | 50%
2000  | 100%


It's possible to use a throttle controller to simplify the calibration and the use of the motors by just putting the throttle controller to the max position to get the maximum value of the throttle.

But here we don't use a throttle controller, the value of the maximum and minimum throttle are send by the C++ code.

The ESC and the motors work with a battery, which must be appropriate for the motor you want to use. Here, we use a Lipo battery of 14.8V / 20A

## Library ##

To use the ESC and the motors, we must install the library PiGPIO

```
sudo apt-get install pigpio
```

## Connection ##

The ESC can be connected to maximum 4 motors (M1, M2, M3, and M4).

Each of them use 1 pin to be connected on the raspberry, this is the pin with which we will send the amount of speed we want on the motor.
All the connection on the pin of the motors must be connected on 1 Pin GPIO to be able to control each motor.

The motor 3 (M3) is the only one that possesses 3 pins : The data is the white cable, the Ground is the black one, and the red one is the Vcc. But you must NEVER connect the red one, because you already have power by using the battery.

So, for the Motor 3, only connect The white cable to the pin GPIO and the black cable to the Ground of the raspberry pi.

The ESC must be calibrate to give appropriate value to all the motors.


## Calibration ##

To give a value to your GPIO Pin, you have to use the function **gpioServo** from the PiGPIO Library.

To calibrate the ESC, you must follow step by step this tutorial :

	1) Connect all the motors to the ESC and connect the ESC to the raspberry pi
	   Do not connect the battery for the moment
       
	2) REMOVE THE PROPELLERS of the motors, it can be higly dangerous
    
	3) Send to each Pin GPIO the value of the maximum throttle your motor will work with,
       for the ESC we have, its recommended to put as maximum throttle a value near 1800 
       (If you change ESC, you will need to find in the documentation of the new ESC what are the recommended values).
       
	4) Connect the battery 
    
	5) Wait for the ESC to make a little music
    
	6) Send to each Pin GPIO the value of the minimum throttle, which is also recommended for the ESC
       In our case, we use 1000
       
	7) Wait about 8 seconds
    
	8) Calibration Done ! REMOVE THE BATTERY THEN PUT IT BACK
<br>
In the code, we use this function in **main.cpp** :
```
void Calibration()
```
/!\ Don't forget to add each motor you use in the function

## Author
* **Ilias EL ABBASSI** - *Initial work* - [Babassi](https://github.com/Babassi)
* **Jonathan Petit** - *Help to write code in c++* - [JonathanPetit](https://github.com/JonathanPetit)