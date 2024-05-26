#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */
void blad(std::ostream& strm,const UkladRownanLiniowych & UklRown,const Wektor & Rozwazanie){
  
  Wektor epsilon;

  epsilon=(UklRown.getM()*Rozwazanie)-UklRown.getW();

  strm<<"Wektor błedu Ax-B:"<<endl;
  strm<<"|"<<epsilon<<"|"<<endl;
  strm<<"Dlugosc wektora bledu:"<<endl;
  strm<<epsilon.dlugosc()<<endl;
}

void wykonaj(std::ostream& strm, const UkladRownanLiniowych & UklRown,Wektor &Rozwiazania){


if(UklRown.getM().macschodkowa().det()!=0){
strm<<UklRown<<endl;

Rozwiazania=(UklRown.uklschodkowy()).Oblicz();

strm<<"To są rozwiązania dla układu:"<<endl;

for(int i=0;i<ROZMIAR;i++){

strm<<'X'<<i<<'='<<Rozwiazania[i]<<endl;

}
strm<<endl;


}
else{

strm<<"Brak rozwiazan dla takiego układu: Wyznacznik=0"<<endl;

}

}
void wczytajuklad(std::istream & strm, UkladRownanLiniowych &UklRown){

strm>>UklRown;
}


int main()
{

UkladRownanLiniowych UklRown; 
Wektor Rozwiazania;  
  

wczytajuklad(cin,UklRown);
wykonaj(cout,UklRown,Rozwiazania);
blad(cout,UklRown,Rozwiazania);

}
