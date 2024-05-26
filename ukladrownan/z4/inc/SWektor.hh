#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <array>
#include <math.h>
#include <initializer_list>
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<class Type, int size>
class Wektor {
  
  std::array<Type,size>tab;

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
  
  std::array<Type,size> & operator~();

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
 *
std::istream& operator >> (std::istream &strm, Wektor &Wek);
*/
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 *
std::ostream& operator << (std::ostream &strm, const Wektor &Wek);
*/

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
template<class Type, int size>
Wektor<Type,size>::Wektor(std::initializer_list <double> lista){
    int licznik=0;
    for(const double &i : lista){
      if(licznik>size-1){
        std::cerr<<"Zla inicjacja wektora w funkcji main"<<std::endl;
        exit(1);
      }
      this->tab[licznik]=i;
      licznik++;
    }
}

template<class Type, int size>
double & Wektor<Type,size>::operator[](int ind){
  
  if(ind>(size-1)||ind<0){
  std::cerr<<"Błąd przy podanym indeksie wektora w funkcji typu seter"<<'\n';
  exit(1);                                                                            //seter wektora
  }
  
  return this->tab[ind];
}
template<class Type, int size>
const double & Wektor<Type,size>::operator[](int ind)const{
  
  if(ind>(size-1)||ind<0){
  std::cerr<<"Błąd przy podanym indeksie wektora w funkcji typu geter"<<'\n';
  exit(1);
  }                                                                                   //geter wektora
  
  return this->tab[ind];
}

template<class Type, int size>
std::array<Type,size> & Wektor<Type,size>::operator~(){
  return tab;
}


template<class Type, int size>
Wektor<Type,size> Wektor<Type,size>::operator +(const Wektor<Type,size> &NR2)const{

Wektor Wynik;

for(int i=0;i<size;i++){

Wynik.tab[i]=this->tab[i]+NR2.tab[i];
}
return Wynik;
}

template<class Type, int size>
Wektor<Type,size> Wektor<Type,size>::operator -(const Wektor<Type,size> &NR2)const{

Wektor Wynik;

for(int i=0;i<size;i++){

Wynik.tab[i]=this->tab[i]-NR2.tab[i];
}

return Wynik;
}


template<class Type, int size>
double Wektor<Type,size>::dlugosc()const{

double Wynik=0;

for(int i=0;i<size;i++){

Wynik+=this->tab[i]*this->tab[i];
}


return sqrt(Wynik);

}

template<class Type, int size>
double Wektor<Type,size>::operator *(const Wektor<Type,size> &NR2)const{
double Wynik;

for(int i=0;i<size;i++){

Wynik+=this->tab[i]*NR2.tab[i];
}

return Wynik;
}


template<class Type, int size>
Wektor<Type,size> Wektor<Type,size>::ilowektorowy(const Wektor<Type,size> &NR2)const{

Wektor Wynik;

Wynik.tab[0]=this->tab[1]*NR2.tab[2]-this->tab[2]*NR2.tab[1];
Wynik.tab[1]=-1*(this->tab[0]*NR2.tab[2]-this->tab[2]*NR2.tab[0]);
Wynik.tab[2]=this->tab[0]*NR2.tab[1]-this->tab[1]*NR2.tab[0];

return Wynik;
}


template<class Type, int size>
Wektor<Type,size> Wektor<Type,size>::operator *(double mnoznik)const{

Wektor Wynik;

for(int i=0;i<size;i++){

Wynik.tab[i]=this->tab[i]*mnoznik;
}

return Wynik;
}


template<class Type, int size>
std::ostream& operator << (std::ostream &strm, const Wektor<Type,size> &Wek){
  
  for(int i=0;i<size;i++){
  strm<<Wek[i];
  if(i!=size-1){
    strm<<'\t';
  }
}


return strm;
}


template<class Type, int size>
std::istream& operator >> (std::istream &strm, Wektor<Type,size> &Wek){

  for(int i=0;i<size;i++){

  if(strm>>Wek[i]){

  }
  else{
  strm.setstate(std::ios::failbit);
  std::cerr<<"Blad wczytywania wektora"<<std::endl;
  exit(1);
  }
}

return strm;
}



template<class Type, int size>
bool Wektor<Type,size>::zerowy()const{

int Wynik=0;

for(int elem : this->tab){
 
  Wynik+=elem;

}
if(Wynik==0){
return true;
}
else
return false;
}


#endif
