#include "SWektor.hh"
#include "rozmiar.hh"
#include "LZespolona.hh"
#include "SMacierz.hh"
#include "SUkladRownanLiniowych.hh"


using namespace std;

template<class Type, int size>
void blad(std::ostream& strm,const UkladRownanLiniowych<Type,size> & UklRown,const Wektor<Type,size> & Rozwiazanie){
  
  Wektor<Type,size> epsilon;

  epsilon=(UklRown.getM()*Rozwiazanie)-UklRown.getW();

  strm<<"Wektor błedu Ax-B:"<<endl;
  strm<<"|" << scientific << setprecision(1)<<epsilon<<"|"<<endl;
  strm<<"Dlugosc wektora bledu:"<<endl;
  strm<<epsilon.dlugosc()<<endl;
}



template<class Type, int size>
void wykonaj(std::ostream& strm, const UkladRownanLiniowych<Type,size> & UklRown,Wektor<Type,size> &Rozwiazania){

bool prawda;




prawda=(UklRown.getM().macschodkowa().det()==0);


if(!(prawda)){
strm<<UklRown<<endl;

Rozwiazania=(UklRown.uklschodkowy()).Oblicz();

strm<<"To są rozwiązania dla układu:"<<endl;

for(int i=0;i<ROZMIAR;i++){

strm<<'X'<<i<<'='<<std::fixed << std::setprecision(PRECYZJA)<<Rozwiazania[i]<<endl;

}
strm<<endl;


}
else{

strm<<"Brak rozwiazan ukladu";

}

}


template<class Type, int size>
void wczytajuklad(std::istream & strm, UkladRownanLiniowych<Type,size> &UklRown){

strm>>UklRown;

}



string rozpoznajtyp(std::istream &strm){

char literka;


strm>>literka;

if(literka=='r'){
     cout<<"Uklad rownan liniowych o wspolczynnikach rzeczywistych"<<endl<<endl;
     return "double";

}
else{
     if(literka=='z'){
          cout<<"Uklad rownan liniowych o wspolczynnikach zespolonych"<<endl<<endl;
          return "LZespolona";
     }
     else{

     cerr<<"Blad przy rozpoznaniu typu ukladu rownan - zla literka";
     exit(1);

     }
}


}


int main()
{
   string NAZWATYPU=rozpoznajtyp(cin);
  

   if(NAZWATYPU=="LZespolona")
   {
   UkladRownanLiniowych<LZespolona,ROZMIAR> UkladZe;
   Wektor<LZespolona,ROZMIAR> WektorZe;
   wczytajuklad(cin,UkladZe);
   wykonaj(cout,UkladZe,WektorZe);
   blad(cout,UkladZe,WektorZe);
   } 
   else
   {
   UkladRownanLiniowych<double,ROZMIAR> Uklad;
   Wektor<double,ROZMIAR> Wektor;
   wczytajuklad(cin,Uklad);
   wykonaj(cout,Uklad,Wektor);
   blad(cout,Uklad,Wektor);
   }
}

