all:main.cpp PreProcess.o LightRecognition.o ourarea.o scanLight.o FloodFill.o BlackBoard.o
	g++ main.cpp PreProcess.o LightRecognition.o ourarea.o scanLight.o FloodFill.o BlackBoard.o -o main `pkg-config --libs opencv --cflags`

PreProcess.o:
	g++ -c PreProcess.cpp -o PreProcess.o

LightRecognition.o:
	g++ -c LightRecognition.cpp

ourarea.o:
	g++ -c ourarea.cpp

scanLight.o:
	g++ -c scanLight.cpp

FloodFill.o:
	g++ -c FloodFill.cpp
BlackBoard.o:
	g++ -c Representation/BlackBoard.cpp
clean:
	rm *.o main