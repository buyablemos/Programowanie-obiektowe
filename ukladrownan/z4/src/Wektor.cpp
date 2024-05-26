#include "Wektor.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

Wektor::Wektor(std::initializer_list <double> lista){
    int licznik=0;
    for(const double &i : lista){
      if(licznik>ROZMIAR-1){
        std::cerr<<"Zla inicjacja wektora w funkcji main"<<std::endl;
        exit(1);
      }
      this->tab[licznik]=i;
      licznik++;
    }
}


double & Wektor::operator[](int ind){
  
  if(ind>(ROZMIAR-1)||ind<0){
  std::cerr<<"Błąd przy podanym indeksie wektora w funkcji typu seter"<<'\n';
  exit(1);                                                                            //seter wektora
  }
  
  return this->tab[ind];
}

const double & Wektor::operator[](int ind)const{
  
  if(ind>(ROZMIAR-1)||ind<0){
  std::cerr<<"Błąd przy podanym indeksie wektora w funkcji typu geter"<<'\n';
  exit(1);
  }                                                                                   //geter wektora
  
  return this->tab[ind];
}


std::array<double,ROZMIAR> & Wektor::operator~(){
  
  return tab;
}

Wektor Wektor::operator +(const Wektor &NR2)const{

Wektor Wynik;

for(int i=0;i<ROZMIAR;i++){

Wynik.tab[i]=this->tab[i]+NR2.tab[i];
}
return Wynik;
}


Wektor Wektor::operator -(const Wektor &NR2)const{

Wektor Wynik;

for(int i=0;i<ROZMIAR;i++){

Wynik.tab[i]=this->tab[i]-NR2.tab[i];
}

return Wynik;
}

double Wektor::dlugosc()const{

double Wynik=0;

for(int i=0;i<ROZMIAR;i++){

Wynik+=this->tab[i]*this->tab[i];
}


return sqrt(Wynik);

}

double Wektor::operator *(const Wektor &NR2)const{
double Wynik;

for(int i=0;i<ROZMIAR;i++){

Wynik+=this->tab[i]*NR2.tab[i];
}

return Wynik;
}
  
Wektor Wektor::ilowektorowy(const Wektor &NR2)const{

Wektor Wynik;

Wynik.tab[0]=this->tab[1]*NR2.tab[2]-this->tab[2]*NR2.tab[1];
Wynik.tab[1]=-1*(this->tab[0]*NR2.tab[2]-this->tab[2]*NR2.tab[0]);
Wynik.tab[2]=this->tab[0]*NR2.tab[1]-this->tab[1]*NR2.tab[0];

return Wynik;
}

Wektor Wektor::operator *(double mnoznik)const{

Wektor Wynik;

for(int i=0;i<ROZMIAR;i++){

Wynik.tab[i]=this->tab[i]*mnoznik;
}

return Wynik;
}

std::ostream& operator << (std::ostream &strm, const Wektor &Wek){
  
  for(int i=0;i<ROZMIAR;i++){
  strm<<Wek[i];
  if(i!=ROZMIAR-1){
    strm<<'\t';
  }
}


return strm;
}



std::istream& operator >> (std::istream &strm, Wektor &Wek){

  for(int i=0;i<ROZMIAR;i++){

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

bool Wektor::zerowy()const{

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