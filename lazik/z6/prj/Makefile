APP=MARSJANSKIELAZIKI
TRGDIR=./
OBJ=./obj
CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -I inc

__start__: obj ./${APP}
	./${APP}

# Tworzy katalog "obj" gdy go nie ma
# 
obj:
	mkdir obj

./${APP}: obj/main.o obj/lazik.o obj/MacierzRotacji.o obj/prostopadloscian.o obj/UWspolrzednych.o obj/Dr3D_gnuplot_api.o obj/scena.o
	g++ -o ./${APP} obj/main.o obj/lazik.o obj/prostopadloscian.o obj/scena.o \
                    obj/MacierzRotacji.o obj/UWspolrzednych.o obj/Dr3D_gnuplot_api.o -lpthread \


obj/main.o: src/main.cpp inc/lazik.hh inc/API3D.hh inc/scena.hh inc/SWektor.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/main.o src/main.cpp

obj/scena.o: src/scena.cpp inc/scena.hh inc/lazik.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/scena.o src/scena.cpp
	
obj/lazik.o: src/lazik.cpp inc/lazik.hh inc/API3D.hh inc/prostopadloscian.hh inc/Wektor3D.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/lazik.o src/lazik.cpp

obj/MacierzRotacji.o: src/MacierzRotacji.cpp inc/MacierzRotacji.hh inc/SMacierz.hh inc/SWektor.hh inc/rozmiar.hh inc/Wektor3D.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/MacierzRotacji.o src/MacierzRotacji.cpp 

obj/prostopadloscian.o: src/prostopadloscian.cpp inc/prostopadloscian.hh inc/UWspolrzednych.hh inc/Wektor3D.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/prostopadloscian.o src/prostopadloscian.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp 

obj/UWspolrzednych.o: src/UWspolrzednych.cpp inc/UWspolrzednych.hh inc/MacierzRotacji.hh inc/Wektor3D.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/UWspolrzednych.o src/UWspolrzednych.cpp

clean:
	rm -f obj/* ./${APP} core.*



help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make help   - wyswietla niniejsza informacje"
	@echo
