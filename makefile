htest: main.o histogram.o
	g++ -Wall -Wextra -Wpedantic -g main.o histogram.o -o htest

histogramtest.o: main.cpp histogram.h
	g++ -Wall -Wextra -Wpedantic -g -c main.cpp -o main.o
histogram.o: histogram.cpp histogram.h
	g++ -Wall -Wextra -Wpedantic -g -c histogram.cpp -o histogram.o

clean:
	rm htest *.o