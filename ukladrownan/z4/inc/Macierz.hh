#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.hh"
#include <iostream>
#include "Wektor.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {
 
  std::array<Wektor,ROZMIAR>tab;

  public:
  
  Macierz();

  Wektor & operator[](int ind);

  const Wektor & operator[](int ind)const;
  
  const Macierz transponowanie()const;
  
  Wektor operator *(const Wektor & wek)const;

  double det()const;

  Macierz macschodkowa()const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &strm, const Macierz &Mac);


#endif
