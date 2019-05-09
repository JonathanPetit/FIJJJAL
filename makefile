all : drone.exe

CC = g++

drone.exe: main.o fijjal.o motor.o ultrasound.o pid.o gyro.o gps.o
	$(CC) -o drone.exe main.o fijjal.o ./motor/motor.o ./ultrasound/ultrasound.o ./pid/pid.o ./gyro/gyro.o ./gps/gps.o ./pathfinding/pathfinding.o -lpigpio -lpthread

main.o: main.cpp fijjal.h ./motor/motor.h ./ultrasound/ultrasound.h ./pid/pid.h ./gyro/gyro.h ./gps/gps.h ./pathfinding/pathfinding.h
	$(CC) -o main.o -c main.cpp


#Fijjal
fijjal.o: fijjal.cpp fijjal.h
	$(CC) -o fijjal.o -c fijjal.cpp 


#Motor
motor.o: ./motor/motor.cpp ./motor/motor.h ./pid/pid.h
	$(CC) -o ./motor/motor.o -c ./motor/motor.cpp -lpigpio -lpthread


#Ultrasound
ultrasound.o: ./ultrasound/ultrasound.cpp ./ultrasound/ultrasound.h
	$(CC) -o ./ultrasound/ultrasound.o -c ./ultrasound/ultrasound.cpp -lpigpio -lpthread


#PID
pid.o: ./pid/pid.cpp ./pid/pid.h
	$(CC) -o ./pid/pid.o -c ./pid/pid.cpp

#gyroscope
gyro.o: ./gyro/gyro.cpp ./gyro/gyro.h
	$(CC) -o ./gyro/gyro.o -c ./gyro/gyro.cpp

#gps
gps.o: ./gps/gps.cpp ./gps/gps.h
	$(CC) -o ./gps/gps.o -c ./gps/gps.cpp

#gps
pathfinding.o: ./pathfinding/pathfinding.cpp ./pathfinding/pathfinding.h
	$(CC) -o ./pathfinding/pathfinding.o -c ./pathfinding/pathfinding.cpp


clean:
	rm ./*.o
	rm ./fijjal/*.o
	rm ./motor/*.o
	rm ./ultrasound/*.o
	rm ./pid/*.o
	rm ./gyro/*.o
	rm ./gps/*.o