homework: main.o crew.o plane.o flight.o crews.o crews.o flights.o
	g++ -o homework main.cpp crew.cpp plane.cpp flight.cpp crews.cpp planes.cpp flights.cpp
main.o: main.cpp crew.h plane.h flight.h crews.h planes.h flights.h
	g++ -c main.cpp
crew.o: crew.cpp crew.h
	g++ -c crew.cpp
plane.o: plane.cpp plane.h
	g++ -c plane.cpp
flight.o: flight.cpp flight.h
	g++ -c flight.cpp
crews.o: crews.cpp crews.h crew.h
	g++ -c crews.cpp 
planes.o: planes.cpp planes.h plane.h
	g++ -c planes.cpp
flights.o: flights.cpp flights.h flight.h crews.h crew.h planes.h plane.h
	g++ -c flights.cpp
clean:
	rm *o homework
run:
	./homework
