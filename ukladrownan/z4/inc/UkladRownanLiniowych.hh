#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include"Wektor.hh"
#include"Macierz.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {
  
  Macierz M;
  Wektor W;
  
  public:
  const Wektor Oblicz()const;

  UkladRownanLiniowych uklschodkowy()const;
  
  UkladRownanLiniowych(){Macierz tmp1; Wektor tmp2; this->M=tmp1; this->W=tmp2;}
  
  const Macierz & getM()const;
  const Wektor & getW() const;

  Macierz & setM();
  Wektor & setW();


};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream &Strm,const UkladRownanLiniowych &UklRown);


#endif
