#include "UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


const Wektor UkladRownanLiniowych::Oblicz()const{
    
    Wektor Wynik;
    double tmp=0;
    
    Wynik[ROZMIAR-1]=this->getW()[ROZMIAR-1]/this->getM()[ROZMIAR-1][ROZMIAR-1];
    
    for(int i=ROZMIAR-2;i>=0;i--){
      
      
      for(int k=ROZMIAR-1;k>i;k--){
       
       tmp+=this->getM()[i][k]*Wynik[k];

      }
      Wynik[i]=(this->getW()[i]-tmp)/getM()[i][i];
      tmp=0;
    }

    
    return Wynik;
}

const Macierz & UkladRownanLiniowych::getM()const{
return this->M;
}

const Wektor & UkladRownanLiniowych::getW() const{
return this->W;
}

Macierz & UkladRownanLiniowych::setM(){
return this->M;
}
  
Wektor & UkladRownanLiniowych::setW(){
return this->W;
}



std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown){

Strm>>UklRown.setM();
Strm>>UklRown.setW();

return Strm;
}

std::ostream& operator << (std::ostream &strm, const UkladRownanLiniowych &UklRown){


strm<<"To jest układ równań:"<<std::endl;


for(int i=0;i<ROZMIAR;i++){
  strm<<"|";
  strm<<UklRown.getM()[i];
  strm<<"|";
  strm<<'\t';

  strm<<"|";
  strm<<'X'<<i;
  strm<<"|";
  
  if(i==ROZMIAR/2){
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

UkladRownanLiniowych UkladRownanLiniowych::uklschodkowy()const{

UkladRownanLiniowych kopia;
double mnoznik;
int pozwolenie=1;

for(int w=0;w<ROZMIAR;w++){

    for(int k=0;k<ROZMIAR;k++)
    (kopia.setM())[w][k]=(this->getM())[w][k];

}

kopia.setW()=this->getW();

for(int i=0;i<(ROZMIAR-1);i++){
    
   
    for(int j=i+1;j<ROZMIAR;j++){
        if(abs((kopia.getM())[i][i]-0)<DOKLZMIENNOPRZECINKOWA){
          int k=0;

          while(pozwolenie){
      
          
          if(k==ROZMIAR-1){
            std::cerr<<"<Nie mozna doprowadzic macierzy do postaci schodkowej"<<std::endl;
            exit(1);
          }
          std::swap(~(kopia.setM())[i],~(kopia.setM())[i+k]);
          std::swap(kopia.setW()[i],kopia.setW()[i+k]);
          k++;
          pozwolenie=(abs((kopia.getM())[i][i]-0)<DOKLZMIENNOPRZECINKOWA);
          }
          mnoznik=(kopia.getM())[j][i]/(kopia.getM())[i][i];
           
          (kopia.setM())[j]=(kopia.getM())[j]-(kopia.getM())[i]*mnoznik;
          (kopia.setW())[j]=kopia.getW()[j]-kopia.getW()[i]*mnoznik;
        }
        else{
        mnoznik=(kopia.getM())[j][i]/(kopia.getM())[i][i];
        (kopia.setW())[j]=kopia.getW()[j]-kopia.getW()[i]*mnoznik;
        (kopia.setM())[j]=(kopia.setM())[j]-(kopia.setM())[i]*mnoznik;
        }
  
    }
      
}
  return kopia;

}