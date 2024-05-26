#ifndef MACIERZROTACJI_HH
#define MACIERZROTACJI_HH

#include "SMacierz.hh"
#include <cmath> 
#include "Wektor3D.hh"

typedef Wektor<double,ROZMIAR3D> Wektor3D;
typedef Macierz<double,ROZMIAR3D> Macierz3D;

class MacierzRotacji : public Macierz3D{

public:
MacierzRotacji();
MacierzRotacji(char os,double kat);

};

#endif
