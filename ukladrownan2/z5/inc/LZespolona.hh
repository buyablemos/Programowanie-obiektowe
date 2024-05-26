#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <ostream>
#include <iostream>
#include <cmath>
#include "rozmiar.hh"
#include <iomanip>
/*!
 *  Plik zawiera definicje struktury LZespolona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class LZespolona {
  private:
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  
  public:
  LZespolona(){this->re=0;this->im=0;};

  void tworz(const double & RZ,const double & IMA);
  void zwrocdowyswietlenia(double & RZ,double & IMA)const;
  
  double & RE(){return this->re;};
  double & IM(){return this->im;};
  const double  RE()const{return this->re;};
  const double  IM()const{return this->im;};

  double      modul()const; //wylicza modul z liczby zespolonej
  
  LZespolona  sprzezenie()const; //sprzezenie liczby zespolonej

  LZespolona  operator + ( const LZespolona & NR2)const;

  LZespolona  operator - ( const LZespolona & NR2)const;

  LZespolona  operator * ( const LZespolona & NR2)const;

  LZespolona  operator / ( const LZespolona & NR2)const;

  LZespolona&  operator += ( const LZespolona & NR2);

  LZespolona  operator * (const double & mnoznik)const;
  
  LZespolona  operator / (const double & dzielnik)const;
  
  LZespolona&  operator = (double liczba);

  //porównanie dwóch liczb zespolonych
  bool operator == (const LZespolona & NR2)const;
  
  bool operator == (const double & NR2)const;

  bool operator != (const LZespolona & NR2)const;
  

  
};

 /*
 * Definicje przeciazen operatorow arytmetycznych dla liczb zespolonych.
 */
  std::ostream & operator <<(std::ostream & strm,const LZespolona & NR1);
  
  std::istream & operator >>(std::istream & strm,LZespolona & NR1);

#endif
