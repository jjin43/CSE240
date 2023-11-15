exe: Jin_Justin_assn4.o WordEntry.o
	g++ -g -Wall Jin_Justin_assn4.o WordEntry.o -o exe

Jin_Justin_assn4.o: Jin_bst.h WordEntry.h
	g++ -g -Wall -c Jin_Justin_assn4.cpp

WordEntry.o: WordEntry.h
	g++ -g -Wall -c WordEntry.cpp

clean:
	rm *.o *~ exe -v
