CFLAGS=-ansi -pedantic -O0 -Wall

main: 
	g++ -g -o main $(CFLAGS) providers_adt.cpp members_adt.cpp mainmenu.cpp

clean:
	rm -f *.o main 
