#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.hh"
#include <iostream>
#include <array>
#include <math.h>
#include <initializer_list>
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  
  std::array<double,ROZMIAR>tab;

  public:
  //konstruktory
  Wektor(){for(double &elem : this->tab)elem=0;}; 
 
  Wektor (Wektor &W) = default; //domyslny konstruktor kopiujący
 
  
  Wektor(std::initializer_list <double> lista);
  
 // Wektor(double x, double y, double z) : tab{x,y,z} {};
 //Wektor(double x, double y, double z){tab[0]=x;tab[1]=y;tab[2]=z;};
  
  //seter
  double & operator[](const int ind);
  //geter 
  const double & operator[](const int ind)const;
  
  std::array<double,ROZMIAR> & operator~();

  Wektor operator +(const Wektor &NR2)const;
  Wektor operator -(const Wektor &NR2)const;

  double dlugosc()const;

  double operator *(const Wektor &NR2)const;
  
  Wektor ilowektorowy(const Wektor &NR2)const;

  Wektor operator *(double mnoznik)const;
  
  bool zerowy()const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &strm, const Wektor &Wek);

#endif
