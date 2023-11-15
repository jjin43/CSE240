exe: Jin_Justin_main.o Jin_racer.o Jin_segment.o Jin_race.o
	g++ -g -Wall Jin_Justin_main.o Jin_racer.o Jin_segment.o Jin_race.o -o exe

Jin_Justin_main.o: Jin_racer.h Jin_segment.h Jin_race.h
	g++ -g -Wall -c Jin_Justin_main.cpp

Jin_race.o: Jin_racer.h Jin_segment.h Jin_race.h
	g++ -g -Wall -c Jin_race.cpp

Jin_racer.o: Jin_racer.h
	g++ -g -Wall -c Jin_racer.cpp

Jin_segment.o: Jin_segment.h
	g++ -g -Wall -c Jin_segment.cpp

clean:
	rm *.o *~ exe -v
