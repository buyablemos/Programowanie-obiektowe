#ifndef UWSPOLRZEDNYCH_HH
#define UWSPOLRZEDNYCH_HH

#include "MacierzRotacji.hh"
#include "Wektor3D.hh"

class UWspolrzednych{

 UWspolrzednych *rodzic; // (null)->ten pierwszy 

 MacierzRotacji orientacja;
 Wektor3D przesuniecie;

public:

void rotacja(const MacierzRotacji& druga){
    
    Macierz3D tmp;
    tmp=(druga*orientacja);

    this->orientacja[0]=tmp[0];
    this->orientacja[1]=tmp[1];
    this->orientacja[2]=tmp[2];

}

void translacja(const Wektor3D& W){
    this->przesuniecie=(W+this->przesuniecie);
}

const Wektor3D przeliczdorodzica(const Wektor3D &punkt);

UWspolrzednych(){MacierzRotacji M; Wektor3D W; rodzic=NULL; orientacja=M; przesuniecie=W;} //macierz i wektor domyslne
UWspolrzednych(MacierzRotacji przekazanaorientacja,Wektor3D przekazaneprzeuniecie,UWspolrzednych* adresrodzica){
this->orientacja=przekazanaorientacja; this->przesuniecie=przekazaneprzeuniecie;this->rodzic=adresrodzica;}

const UWspolrzednych* getrodzic(){return rodzic;};
UWspolrzednych** setrodzic(){return &rodzic;};

const MacierzRotacji& getmacierz(){return orientacja;};
MacierzRotacji& setmacierz(){return orientacja;};

const Wektor3D& getwektor(){return przesuniecie;};
Wektor3D& setwektor(){return przesuniecie;};

};




#endif