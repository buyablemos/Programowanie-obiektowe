#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH


#include <iostream>
#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator {Op_Dodaj,Op_Odejmij,Op_Mnoz,Op_Dziel};



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
class WyrazenieZesp {
  private:
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
  
  public:
  void tworz(const LZespolona & LZ1,const Operator & O,const LZespolona & LZ2); //tworzy wyrazenie zespolone
  
  LZespolona Oblicz()const; //funkcja która oblicza wyrazenie zespolone
  
  void zwrocdowyswetlenia(LZespolona & LZ1,Operator & O,LZespolona & LZ2)const; //zwraca argumenty wyrazenia zespolonego zeby je wyswietlic

};

//przeciazenia operatorow dla wyrazen zespolonych i operatorow arytmetycznych

std::istream & operator >>(std::istream&strm, Operator & Op);

std::ostream & operator <<(std::ostream&strm,const  Operator & Op);
                                                                          
std::istream & operator >>(std::istream&strm, WyrazenieZesp & WZesp);

std::ostream & operator <<(std::ostream&strm, WyrazenieZesp & WZesp);

#endif 
