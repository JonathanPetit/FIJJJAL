# FIJJJAL
Drone project for ECAM Brussels school. 
All Documentation is written in Markdown, please check the repository [Github](https://github.com/JonathanPetit/FIJJJAL) for a better reading.

## Project
The project is delivery a package from a point A to a point B. 

The package is secured by a box with an electo-magnet. We use the RFID technology to control the box. 

The motor are controlled by a PID regulator and a motion controller to move the drone. The PID use a Gyroscope to regulate the motors.

The drone include a GPS module to locatate it. It have also a Pathfinding code to find a way to delivery the package. 

To detect obstacles, the drone have four ultrasound sensor. When it detect an object, it communicate with the pathfinding module to find an other path. 

Please check each module (table of contents) to have more informations about the drone.

## Structure of the project
![picture alt](doc/fijjal.png)

## Makers
Julien BEARD </br>
Fatine BEN MOUSSA </br>
Maxime DESAINTJEAN </br>
Ilias EL ABBASSI </br>
Ludovic MEREL </br>
Adrien PETIT </br>
Jonathan PETIT </br>

## Table of contents
[RFID](./rfid/readme.md) </br>
[PID regulator](./pid/README.md) </br>
[GPS](./gps/README.md) </br>
[Pathfinding](./pathfinding/README.md)</br>
[Motion Controller](./motionController/README.md)</br>
[Motor](./motor/README.md)</br>
[Ultrasound](./ultrasound/README.md)</br>
[Gyroscope](./gyro/README.md)</br>