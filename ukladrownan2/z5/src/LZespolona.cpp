#include "LZespolona.hh"



/*
 * 
 * Argumenty:
 *    NR1 - pierwszy skladnik.
 *    NR2 - drugi skladnik.
 * Zwraca:
 *    Wynik dzialania na dwoch skladnikach przekazanych jako parametry.
 */


LZespolona& LZespolona::operator = (double liczba){

this->re=liczba;
this->im=0;
return *this;
}

double LZespolona::modul()const{

double wynik;

wynik=sqrt( (this->re*this->re) + (this->im*this->im) );

return wynik;

}

LZespolona LZespolona::sprzezenie()const{

LZespolona wynik;

wynik.im=this->im*(-1);
wynik.re=this->re;

return wynik;

}


LZespolona  LZespolona::operator + (const LZespolona & NR2)const
{
  LZespolona  Wynik;

  Wynik.re = this->re + NR2.re;
  Wynik.im = this->im + NR2.im;
  return Wynik;
}


LZespolona&  LZespolona::operator += (const LZespolona & NR2)
{
  

  this->re=this->re + NR2.re;
  this->im=this->im + NR2.im;
  
  return *this;
}

LZespolona  LZespolona::operator - (const LZespolona & NR2)const
{
  LZespolona  Wynik;

  Wynik.re = this->re - NR2.re;
  Wynik.im = this->im - NR2.im;
  return Wynik;
}

LZespolona  LZespolona::operator * (const LZespolona & NR2)const
{
  LZespolona  Wynik;

  Wynik.re = (this->re*NR2.re)-(this->im*NR2.im);
  Wynik.im = (this->im*NR2.re)+(this->re*NR2.im);
  return Wynik;
}


LZespolona LZespolona:: operator / (const double & dzielnik)const{

LZespolona wynik;
if(dzielnik==0){
  std::cerr<<"Nie dzielimy przez 0-Blad dzielenia liczby zespolonej przez liczbe";
  exit(1);
}
wynik.re = this->re / dzielnik;

wynik.im = this->im / dzielnik;

return wynik;

}

LZespolona  LZespolona::operator / (const LZespolona & NR2)const
{
  LZespolona Wynik;

  long double mianownik=( NR2.modul()*NR2.modul());

  Wynik=( *this * NR2.sprzezenie()  ) / mianownik;


  return Wynik;
}


LZespolona LZespolona::operator * (const double & mnoznik)const{

LZespolona wynik;

wynik.re = this->re * mnoznik;

wynik.im = this->im * mnoznik;

return wynik;

}

void LZespolona::tworz(const double & RZ,const double & IMA){

this->re=RZ;
this->im=IMA;

}

void LZespolona::zwrocdowyswietlenia(double & RZ,double & IMA)const{

RZ=this->re;
IMA=this->im;

}

std::ostream & operator <<(std::ostream&strm,const LZespolona & NR1) {

  double RZ;
  double IMA; 
  NR1.zwrocdowyswietlenia(RZ,IMA);

  strm << "(" <<RZ<<std::showpos <<IMA<<std::noshowpos << "i)"; 

  return strm;
}


std::istream & operator >>(std::istream&strm, LZespolona & NR1) {
  
  char znak;
  double retmp;
  double imtmp;
  
  strm>>znak;
  
  if(znak!='(')
  strm.setstate(std::ios::failbit);

  strm>> retmp;
  strm>> imtmp;
  
  strm>>znak;
  
  if(znak!='i')
  strm.setstate(std::ios::failbit);
  
  strm>>znak;
  if(znak!=')')
  strm.setstate(std::ios::failbit);
  
  NR1.tworz(retmp,imtmp);

  return strm;
}

bool LZespolona::operator == (const LZespolona & NR2)const
{

if(fabs(this->re - NR2.re) >= DOKLZMIENNOPRZECINKOWA)
return false;

if(fabs(this->im - NR2.im) >= DOKLZMIENNOPRZECINKOWA)
return false;


return true;


}


bool LZespolona::operator == (const double & NR2)const
{

if(fabs(this->re - NR2) >= DOKLZMIENNOPRZECINKOWA)
return false;

if(fabs(this->im - NR2) >= DOKLZMIENNOPRZECINKOWA)
return false;


return true;


}

bool LZespolona::operator != (const LZespolona & NR2)const
{

if(*this==NR2){
return true;
}
else
return false;

}
