FLAGS= -Wall -pedantic -std=c++17 -iquote inc

__start__: ./test_arytm_zesp
	./test_arytm_zesp test-arytmetyka.txt 

./test_arytm_zesp: obj obj/main.o obj/LZespolona.o\
                     obj/WyrazenieZesp.o obj/Statystyka.o
	g++ -o ./test_arytm_zesp obj/main.o obj/LZespolona.o\
                     obj/WyrazenieZesp.o obj/Statystyka.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/LZespolona.hh inc/WyrazenieZesp.hh inc/Statystyka.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${FLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/WyrazenieZesp.o: src/WyrazenieZesp.cpp inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o obj/WyrazenieZesp.o src/WyrazenieZesp.cpp
obj/Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh
	g++ -c ${FLAGS} -o obj/Statystyka.o src/Statystyka.cpp

clean:
	rm -f ./test_arytm_zesp obj/*
