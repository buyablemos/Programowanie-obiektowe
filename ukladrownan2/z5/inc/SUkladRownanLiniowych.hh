#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include"SWektor.hh"
#include"SMacierz.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */

template<class Type, int size>
class UkladRownanLiniowych {
  
  Macierz<Type,size> M;
  Wektor<Type,size> W;
  
  public:
  const Wektor<Type,size> Oblicz()const;

  UkladRownanLiniowych uklschodkowy()const;
  
  UkladRownanLiniowych(){Macierz<Type,size> tmp1; Wektor<Type,size> tmp2; this->M=tmp1; this->W=tmp2;}
  
  const Macierz<Type,size> & getM()const;
  const Wektor<Type,size> & getW() const;

  Macierz<Type,size> & setM();
  Wektor<Type,size> & setW();

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
//std::istream& operator >> (std::istream &Strm, SUkladRownanLiniowych &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
//std::ostream& operator << ( std::ostream &Strm,const SUkladRownanLiniowych &UklRown);
template<class Type, int size>
const Wektor<Type,size> UkladRownanLiniowych<Type,size>::Oblicz()const{
    
    Wektor<Type,size> Wynik;
    Type tmp;
    tmp=0;
    
    Wynik[size-1]=this->getW()[size-1]/this->getM()[size-1][size-1];
    
    for(int i=size-2;i>=0;i--){
      
      
      for(int k=size-1;k>i;k--){
       
       tmp+=(this->getM()[i][k]*Wynik[k]);
      }
      Wynik[i]=(this->getW()[i]-tmp)/getM()[i][i];
      tmp=0;
     
    }

    
    return Wynik;
}
template<class Type, int size>
const Macierz<Type,size> & UkladRownanLiniowych<Type,size>::getM()const{
return this->M;
}

template<class Type, int size>
const Wektor<Type,size> & UkladRownanLiniowych<Type,size>::getW() const{
return this->W;
}

template<class Type, int size>
Macierz<Type,size> & UkladRownanLiniowych<Type,size>::setM(){
return this->M;
}

template<class Type, int size>
Wektor<Type,size> & UkladRownanLiniowych<Type,size>::setW(){
return this->W;
}


template<class Type, int size>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<Type,size> &UklRown){

Strm>>UklRown.setM();
Strm>>UklRown.setW();

return Strm;
}
template<class Type, int size>
std::ostream& operator << (std::ostream &strm, const UkladRownanLiniowych<Type,size> &UklRown){


strm<<"To jest układ równań:"<<std::endl;


for(int i=0;i<size;i++){
  strm<<"|";
  strm<<UklRown.getM()[i];
  strm<<"|";
  strm<<'\t';

  strm<<"|";
  strm<<'X'<<i;
  strm<<"|";
  
  if(i==size/2){
      strm<<" =";
  }


  strm<<'\t';
  strm<<"|";
  strm<<UklRown.getW()[i];
  strm<<"|";
  strm<<'\n';
}

return strm;
}
template<class Type, int size>
UkladRownanLiniowych<Type,size> UkladRownanLiniowych<Type,size>::uklschodkowy()const{

UkladRownanLiniowych kopia;
Type mnoznik;
bool pozwolenie=true;

for(int w=0;w<size;w++){

    for(int k=0;k<size;k++)
    (kopia.setM())[w][k]=(this->getM())[w][k];

}

kopia.setW()=this->getW();



for(int i=0;i<(size-1);i++){
    
   
    for(int j=i+1;j<size;j++){
        if(przyrownajzero(kopia.getM()[i][i])){
          int k=0;

          while(pozwolenie){
      
          
          if(k==size-1){
            std::cerr<<"<Nie mozna doprowadzic macierzy do postaci schodkowej"<<std::endl;
            exit(1);
          }
          std::swap(~(kopia.setM())[i],~(kopia.setM())[i+k]);
          std::swap(kopia.setW()[i],kopia.setW()[i+k]);
          k++;
          pozwolenie=przyrownajzero((kopia.getM())[i][i]);
          }
          mnoznik=(kopia.getM())[j][i]/(kopia.getM())[i][i];
           
          (kopia.setM())[j]=(kopia.getM())[j]-((kopia.getM())[i]*mnoznik);
          (kopia.setW())[j]=kopia.getW()[j]-(kopia.getW()[i]*mnoznik);
        }
        else{
        mnoznik=(kopia.getM())[j][i]/(kopia.getM())[i][i];
        (kopia.setM())[j]=(kopia.setM())[j]-((kopia.setM())[i]*mnoznik);
        (kopia.setW())[j]=kopia.getW()[j]-(kopia.getW()[i]*mnoznik);
        
        }
  
    }
      
}

  return kopia;

}


#endif
