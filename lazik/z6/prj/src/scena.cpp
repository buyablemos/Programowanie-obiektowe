#include "scena.hh"

void Scena::wyswietlinformacje(lazik& wybor){

wybor.pokazinfo();

}

void Scena::zmienlazik(lazik& wybor){

*aktualnywybor=wybor;


}

void Scena::setwybor(int liczba){

switch(liczba){
case 1:
aktualnywybor=&NR1;
break;

case 2:
aktualnywybor=&NR2;
break;

case 3:
aktualnywybor=&NR3;
break;


default:
std::cerr<<"Zle wybrales lazik\n";
exit(1);
}


}