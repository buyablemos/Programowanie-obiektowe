#include "MacierzRotacji.hh"


MacierzRotacji::MacierzRotacji(char os,double kat){

int rozpoznano=0;
double radian=M_PI*kat/180;


if(os=='z'){
Wektor3D W1{cos(radian),-sin(radian),0};
Wektor3D W2{sin(radian),cos(radian),0}; 
Wektor3D W3{0,0,1};


settab()[0]=W1;
settab()[1]=W2;
settab()[2]=W3;


rozpoznano=1;
}

if(os=='y'){
Wektor3D W1{cos(radian),0,sin(radian)};
Wektor3D W2{0,1,0}; 
Wektor3D W3{-sin(radian),0,cos(radian)};


settab()[0]=W1;
settab()[1]=W2;
settab()[2]=W3;


rozpoznano=1;
}
if(os=='x'){
Wektor3D W1{1,0,0};
Wektor3D W2{0,cos(radian),-sin(radian)}; 
Wektor3D W3{0,sin(radian),cos(radian)};


settab()[0]=W1;
settab()[1]=W2;
settab()[2]=W3;


rozpoznano=1;
}
if(rozpoznano==0){
    std::cerr<<"Błąd przy inicjacji Macierzy Rotacji";
    exit(1);}


}

MacierzRotacji::MacierzRotacji(){

  
  Wektor3D W1{1,0,0};
  Wektor3D W2{0,1,0};  //inicjuje sie wektorami {1 0 0} 0 1 0 {0 0 1}
  Wektor3D W3{0,0,1};

  settab()[0]=W1;
  settab()[1]=W2;
  settab()[2]=W3;
}
