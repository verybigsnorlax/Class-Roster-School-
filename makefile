CC = g++ -Wall -pedantic -Wextra -std=c++11 -g

main: main.o roster.o student.o 
	$(CC) -o main main.o roster.o student.o
	
main.o: main.cpp roster.h student.h degree.h
	$(CC) -c main.cpp 

roster.o: roster.h student.h degree.h

student.o: student.h

# -----
# clean by removing object files.

clean:
	rm -f main.o roster.o student.o
