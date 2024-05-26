#include "prostopadloscian.hh"


const double& prostopadloscian::getW(){return wysokosc;}
const double& prostopadloscian::getD(){return dlugosc;}
const double& prostopadloscian::getS(){return szerokosc;}


std::array<Wektor3D,8> prostopadloscian::przeliczwierzcholki(){

std::array<Wektor3D,8> wspolrzedne;
Wektor3D przemieszczenie;


Wektor3D tmp1(przemieszczenie[0]-(dlugosc/2),przemieszczenie[1]-(szerokosc/2),przemieszczenie[2]);
Wektor3D tmp2(przemieszczenie[0]+(dlugosc/2),przemieszczenie[1]-(szerokosc/2),przemieszczenie[2]);
Wektor3D tmp3(przemieszczenie[0]-(dlugosc/2),przemieszczenie[1]+(szerokosc/2),przemieszczenie[2]);
Wektor3D tmp4(przemieszczenie[0]+(dlugosc/2),przemieszczenie[1]+(szerokosc/2),przemieszczenie[2]);
Wektor3D tmp5(przemieszczenie[0]-(dlugosc/2),przemieszczenie[1]-(szerokosc/2),przemieszczenie[2]+wysokosc);
Wektor3D tmp6(przemieszczenie[0]+(dlugosc/2),przemieszczenie[1]-(szerokosc/2),przemieszczenie[2]+wysokosc);
Wektor3D tmp7(przemieszczenie[0]-(dlugosc/2),przemieszczenie[1]+(szerokosc/2),przemieszczenie[2]+wysokosc);
Wektor3D tmp8(przemieszczenie[0]+(dlugosc/2),przemieszczenie[1]+(szerokosc/2),przemieszczenie[2]+wysokosc);


wspolrzedne[0]=tmp1;
wspolrzedne[1]=tmp2;
wspolrzedne[2]=tmp3;
wspolrzedne[3]=tmp4;
wspolrzedne[4]=tmp5;
wspolrzedne[5]=tmp6;
wspolrzedne[6]=tmp7;
wspolrzedne[7]=tmp8;



return wspolrzedne;
}

