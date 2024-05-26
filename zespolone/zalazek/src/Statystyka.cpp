#include "Statystyka.hh"


void Statystyka::zerowanie(){

this->poprawne=0;
this->ilosc=0;

}
Statystyka::Statystyka()
{poprawne=0;
ilosc=0;}

void Statystyka::plus(){

this->poprawne++;

}

void Statystyka::plusilosc(){

this->ilosc++;

}

void Statystyka::wyswietlstatystyke(std::ostream&strm){

float procent;
if(this->ilosc!=0){
procent=((100*this->poprawne)/this->ilosc);
}
else{
std::cerr<<"Nie dzielimy przez 0-Blad dzielenia liczenia statystyki"<<"\n";
  exit(1);
}
strm<<"Ilosc poprawnych odpowiedzi: "<<this->poprawne<<"\n";
strm<<"Ilosc blednych odpowiedzi: "<<this->ilosc-this->poprawne<<"\n";
strm<<"\n";
strm<<"Procentowy wynik testu: "<<procent<<"%"<<"\n";


}