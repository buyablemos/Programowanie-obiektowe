#ifndef LAZIK_HH
#define LAZIK_HH

#include "prostopadloscian.hh"
#include <string>
#include "API3D.hh"
#include <thread>
#include <chrono>
#include <cmath>

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;



class lazik {

UWspolrzednych U;
API3D *gnuplotptr;
double obrot;
std::string nazwa;
std::string kolor;
int id;
//std::array<int,12> tablicakresek;
protected:
prostopadloscian wymiary;
public:

void jedz(double d);
void obroc(double kat);
void rysuj(API3D *gnuplot);

prostopadloscian& setwymiary(){return wymiary;};
UWspolrzednych** setrodzicukladu(){return (U.setrodzic());};

lazik(const std::string &name,const std::string &colour){MacierzRotacji domyslna; U.setmacierz()=domyslna; U.setwektor()=Wektor3D{0,0,0};obrot=0;nazwa=name;kolor=colour;};
lazik(const std::string &name){MacierzRotacji domyslna; U.setmacierz()=domyslna; U.setwektor()=Wektor3D{0,0,0};obrot=0;nazwa=name;};
lazik(){MacierzRotacji domyslna; U.setmacierz()=domyslna; U.setwektor()=Wektor3D{0,0,0};obrot=0;};

void animujobrot(double kat);
void animujruch(double droga,double prekosc);
API3D** setapiptr(){return &gnuplotptr;}
void pokazinfo();
};

void wait4key();


#endif