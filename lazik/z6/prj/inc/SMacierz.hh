#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include "rozmiar.hh"
#include <iostream>
#include "SWektor.hh"
#include <iomanip>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */



template<class Type, int size>
class Macierz {
 
  std::array<Wektor<Type,size>,size>tab;

  public:
  
  Macierz();
  Macierz (Macierz &M) = default;

  Wektor<Type,size> & operator[](int ind);

  const Wektor<Type,size> & operator[](int ind)const;
  
  const Macierz transponowanie()const;
  
  Wektor<Type,size> operator *(const Wektor<Type,size> & wek)const;

  Macierz<Type,size> operator *(const Macierz<Type,size>& M)const;

  Type det()const;

  Macierz macschodkowa()const;

  const Macierz getM()const{return this;}
  Macierz setM(){return this;}

  std::array<Wektor<Type,size>,size>& settab(){return tab;}
  const std::array<Wektor<Type,size>,size>& gettab(){return tab;}
 
};

template<class Type, int size>
Macierz<Type,size>::Macierz(){

for(int i=0;i<size;i++){
  Wektor<Type,size> W1;  //inicjuje sie samymi zerami, bo jest bez parametrow
  this->tab[i]=W1;
}
}


template<class Type, int size>
Wektor<Type,size> Macierz<Type,size>::operator*(const Wektor<Type,size> & wek)const{
  
  Wektor<Type,size> Wynik;

  for(int i=0;i<size;i++){
   
   Wynik[i]=this->tab[i]*wek;

  }
  return Wynik;
 }

 template<class Type, int size>
 Macierz<Type,size>  Macierz<Type,size>::operator *(const Macierz<Type,size> &M)const{
 
 Macierz<Type,size> Wynik;

 Macierz<Type,size>tmp;
 tmp=M.transponowanie();

 for(int w=0;w<size;w++){
   
  for(int k=0;k<size;k++){

    Wynik[w][k]= tab[w]*tmp[k];
    

  }
   
 }
    return Wynik; 
}

template<class Type, int size>
 Wektor<Type,size> & Macierz<Type,size>::operator[](const int ind){
 
 
   if(ind>(size-1)||ind<0){
  std::cerr<<"Błąd przy podanym indeksie macierzy w funkcji typu seter";
  exit(1);
  }

  return this->tab[ind];

 }
template<class Type, int size>
const Wektor<Type,size> & Macierz<Type,size>::operator[](const int ind)const{


  if(ind>(size-1)||ind<0){
  std::cerr<<"Błąd przy podanym indeksie macierzy w funkcji typu geter";
  exit(1);
  }
  
  return this->tab[ind];

}


template<class Type, int size>
std::istream& operator >> (std::istream &strm, Macierz<Type,size> &Mac){

for(int w=0;w<size;w++){
   
   for(int k=0;k<size;k++){

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

template<class Type, int size>
std::ostream& operator << (std::ostream &strm, const Macierz<Type,size> &Mac){

for(int i=0;i<size;i++){

  strm<<Mac[i]<<'\n';
}

return strm;

}

template<class Type, int size>
const Macierz<Type,size>  Macierz<Type,size>::transponowanie()const{

Macierz tmp;

for(int w=0;w<size;w++){
   
   for(int k=0;k<size;k++){

     tmp[w][k]=this->tab[k][w];

   }
}

return tmp;
}

template<class Type, int size>
Type Macierz<Type,size>::det()const{
Type Wynik;

Wynik=this->tab[1][1];

for(int i=1;i<size;i++)
 Wynik=Wynik*this->tab[i][i];

return Wynik;
}

template<class Type>
bool przyrownajzero(const Type& arg){

if(fabs(arg-0)<DOKLZMIENNOPRZECINKOWA){
  return true;
}
else
return false;

}
/*
template<>
bool przyrownajzero(const LZespolona& arg){

if((fabs(arg.RE()-0))<DOKLZMIENNOPRZECINKOWA){
  if((fabs(arg.IM()-0))<DOKLZMIENNOPRZECINKOWA){
                                                             //// true to bardzo bliski zera
  return true;

  }
  else
  return false;
}
else
return false;

}
*/
template<class Type, int size>
Macierz<Type,size> Macierz<Type,size>::macschodkowa()const{

Macierz kopia;
Type mnoznik;
int pozwolenie=1;

for(int w=0;w<size;w++){

    for(int k=0;k<size;k++)
    kopia[w][k]=this->tab[w][k];

}

for(int i=0;i<(size-1);i++){
    
   
    for(int j=i+1;j<size;j++){
        if(przyrownajzero(kopia[i][i])){
          int k=0;

          while(pozwolenie){
      
          
          if(k==size-1){
            std::cerr<<"<Nie mozna doprowadzic macierzy do postaci schodkowej"<<std::endl;
            exit(1);
          }
          std::swap(~kopia[i],~kopia[i+k]);
          k++;
          pozwolenie=(przyrownajzero(kopia[i][i]));
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




#endif
