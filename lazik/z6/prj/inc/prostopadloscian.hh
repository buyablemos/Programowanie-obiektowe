#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include "UWspolrzednych.hh"


class prostopadloscian : public UWspolrzednych{

double wysokosc;
double dlugosc;
double szerokosc;

public:

prostopadloscian(){wysokosc=0;dlugosc=0;szerokosc=0;};
prostopadloscian(double d,double s,double w)
{wysokosc=w;dlugosc=d;szerokosc=s;};

std::array<Wektor3D,8> przeliczwierzcholki();
const double& getW();
const double& getD();
const double& getS();


};


#endif