#include "Macierz.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
 
 Wektor Macierz::operator*(const Wektor & wek)const{
  
  Wektor Wynik;

  for(int i=0;i<ROZMIAR;i++){
   
   Wynik[i]=this->tab[i]*wek;

  }
  return Wynik;
 }


 Wektor & Macierz::operator[](const int ind){
 
 
   if(ind>(ROZMIAR-1)||ind<0){
  std::cerr<<"Błąd przy podanym indeksie wektora w funkcji typu seter";
  exit(1);
  }

  return this->tab[ind];

 }

  const Wektor & Macierz::operator[](const int ind)const{


  if(ind>(ROZMIAR-1)||ind<0){
  std::cerr<<"Błąd przy podanym indeksie wektora w funkcji typu geter";
  exit(1);
  }
  
  return this->tab[ind];

}

Macierz::Macierz(){

for(int i=0;i<ROZMIAR;i++){
  Wektor W1;  //inicjuje sie samymi zerami, bo jest bez parametrow
  this->tab[i]=W1;
}

}

std::istream& operator >> (std::istream &strm, Macierz &Mac){

for(int w=0;w<ROZMIAR;w++){
   
   for(int k=0;k<ROZMIAR;k++){

     strm>>Mac[k][w];    //wczytanie do programu wersji 
                        //transponowanej ale jako zwykla macierz

   }
}
if(strm.fail()){
  std::cerr<<"Blad wczytywania macierzy"<<std::endl;
  exit(1);
}
return strm;

}


std::ostream& operator << (std::ostream &strm, const Macierz &Mac){

for(int i=0;i<ROZMIAR;i++){

  strm<<Mac[i]<<'\n';
}

return strm;

}


const Macierz  Macierz::transponowanie()const{

Macierz tmp;

for(int w=0;w<ROZMIAR;w++){
   
   for(int k=0;k<ROZMIAR;k++){

     tmp[w][k]=this->tab[k][w];

   }
}

return tmp;
}

double Macierz::det()const{
double Wynik=1;

for(int i=0;i<ROZMIAR;i++)
 Wynik=Wynik*this->tab[i][i];

return Wynik;
}

Macierz Macierz::macschodkowa()const{

Macierz kopia;
double mnoznik;
int pozwolenie=1;

for(int w=0;w<ROZMIAR;w++){

    for(int k=0;k<ROZMIAR;k++)
    kopia[w][k]=this->tab[w][k];

}

for(int i=0;i<(ROZMIAR-1);i++){
    
   
    for(int j=i+1;j<ROZMIAR;j++){
        if(abs(kopia[i][i]-0)<DOKLZMIENNOPRZECINKOWA){
          int k=0;

          while(pozwolenie){
      
          
          if(k==ROZMIAR-1){
            std::cerr<<"<Nie mozna doprowadzic macierzy do postaci schodkowej"<<std::endl;
            exit(1);
          }
          std::swap(~kopia[i],~kopia[i+k]);
          k++;
          pozwolenie=(abs(kopia[i][i]-0)<DOKLZMIENNOPRZECINKOWA);
          }
          mnoznik=kopia[j][i]/kopia[i][i];
        
          kopia[j]=kopia[j]-kopia[i]*mnoznik;
          
        }
        else{
        mnoznik=kopia[j][i]/kopia[i][i];
        
        kopia[j]=kopia[j]-kopia[i]*mnoznik;
        }
  
    }
      
}
  return kopia;

}