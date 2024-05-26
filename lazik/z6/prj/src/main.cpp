#include <iostream>
#include <fstream>

#include "lazik.hh"
#include "API3D.hh"
#include "scena.hh"

using namespace std;

void menu(){

Scena PLANETA;
char opcja='p';
int liczba=0;
double droga=0;
double predkosc=0;
double kat=0;
Wektor3D wektor;

cout<<"Wybierz lazik którym chcesz się poruszać na początku:\n1.Berlin\n2.Moskwa\n3.Waszyngton\n\n\n";
cin>>liczba;

switch(liczba){
case 1:
PLANETA.setwybor(1);
break;

case 2:
PLANETA.setwybor(2);
break;

case 3:
PLANETA.setwybor(3);
break;

default:
std::cerr<<"Zle wybrales lazik\n";
exit(1);

}

cout<<"Wybrales lazik nr:"<<liczba<<std::endl;

PLANETA.rysujwszystkielaziki();

while(opcja!='k'){
cout<<"<m-menu>\n";
cin>>opcja;
switch(opcja){

case 'j': 
cout<<"Podaj najpierw droge ktora lazik ma pokonac\n";
cin>>droga;
cout<<"Podaj predkosc z jaka ma sie poruszac lazik\n";
cin>>predkosc;

PLANETA.getwybor()->animujruch(droga,predkosc);

break;
case 'o':
cout<<"Podaj kat o jaki ma sie obrocic lazik\n";
cin>>kat;

PLANETA.getwybor()->animujobrot(kat);
break;
case 'z':
cout<<"Podaj na jakiego lazika chcesz zmienic:\n1.Berlin\n2.Moskwa\n3.Waszyngton\n\n\n";
cin>>liczba;
PLANETA.setwybor(liczba);
cout<<"Wybrano lazik NR: "<<liczba<<std::endl;
break;
case 'm':
cout<<"j-jedz do przodu lub do tylu\no-obroc lazikiem\nz-zmiana sterowania\ni-informacje o wybranym laziku\nk-koniec programu\nw-ilosc wektorow3D\n";
break;

case 'i':
PLANETA.wyswietlinformacje(*PLANETA.getwybor());
break;
case 'w':
wektor.info();
break;
case 'k':

break;

default:
cout<<"Wybierz jeszcze raz\n";
break;
}




}


}


int main()
{
menu();
}
