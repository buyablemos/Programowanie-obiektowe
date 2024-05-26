#ifndef SCENA_HH
#define SCENA_HH

#include "lazik.hh"

class Scena{

lazik NR1{"Berlin","blue"};
lazik NR2{"Moskwa","red"};
lazik NR3{"Waszyngton","black"};

lazik* aktualnywybor;

UWspolrzednych GLOWNY;

API3D gnuplot;
public:

void zmienlazik(lazik& wybor);
void wyswietlinformacje(lazik& wybor);
void rysujwszystkielaziki(){NR1.rysuj(&gnuplot);NR2.rysuj(&gnuplot);NR3.rysuj(&gnuplot);};

lazik* getwybor(){return aktualnywybor;};
void setwybor(int liczba);

Scena(){*NR1.setrodzicukladu()=&GLOWNY; *NR2.setrodzicukladu()=&GLOWNY; *NR3.setrodzicukladu()=&GLOWNY;prostopadloscian wym(DLUGOSC,SZEROKOSC,WYSOKOSC);
(NR2.setwymiary())=wym;(NR3.setwymiary())=wym;(NR1.setwymiary())=wym; aktualnywybor=nullptr;*NR1.setapiptr()=&gnuplot;*NR2.setapiptr()=&gnuplot;*NR3.setapiptr()=&gnuplot;};
};



#endif