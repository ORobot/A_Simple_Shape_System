all:sss

sss: main.o Window.o Line.o Dot.o Rectangle.o Circle.o
	g++ main.o Window.o Line.o Dot.o Rectangle.o Circle.o -o sss

Window.o: Window.cpp Shape.hpp
	g++ -c -o Window.o Window.cpp

Line.o: Line.cpp Shape.hpp
	g++ -c -o Line.o Line.cpp

Dot.o: Dot.cpp Shape.hpp
	g++ -c -o Dot.o Dot.cpp

Rectangle.o: Rectangle.cpp Shape.hpp
	g++ -c -o Rectangle.o Rectangle.cpp

Circle.o: Circle.cpp Shape.hpp
	g++ -c -o Circle.o Circle.cpp

main.o: main.cpp Shape.hpp
	g++ -c -o main.o main.cpp

clean:
	rm main.o Window.o Line.o Circle.o Rectangle.o Dot.o

