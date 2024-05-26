#include "WyrazenieZesp.hh"


std::istream & operator >>(std::istream&strm, Operator & Op){

  char znak;

  strm>>znak;

  switch(znak){
  
  case '+': Op=Op_Dodaj;
  break;
  case '-': Op=Op_Odejmij;
  break;
  case '*': Op=Op_Mnoz;
  break;
  case '/': Op=Op_Dziel;
  break;
  default: strm.setstate(std::ios::failbit);
  }

  return strm;

}

std::ostream & operator <<(std::ostream&strm,const Operator & Op){


switch(Op){

case Op_Dodaj: strm << '+';

break;
case Op_Odejmij: strm << '-';

break;
case Op_Mnoz: strm << '*';

break;
case Op_Dziel: strm << '/';

break;

default: strm.setstate(std::ios::failbit);

}
return strm;
}


std::istream & operator >> (std::istream & strm, WyrazenieZesp & WZesp){

LZespolona ARG1;
LZespolona ARG2;
Operator tmpOP;

strm>>ARG1>>tmpOP>>ARG2;

WZesp.tworz(ARG1,tmpOP,ARG2);

return strm;
}


std::ostream & operator <<(std::ostream & strm, WyrazenieZesp & WZesp){

LZespolona ARG1;
LZespolona ARG2;
Operator tmpOP;

WZesp.zwrocdowyswetlenia(ARG1,tmpOP,ARG2);

strm<<ARG1<<tmpOP<<ARG2;

return strm;


}


void WyrazenieZesp::tworz(const LZespolona & LZ1,const Operator & O,const LZespolona & LZ2){
 

 this->Arg1=LZ1;
 this->Arg2=LZ2;

 this->Op=O;

}

void WyrazenieZesp::zwrocdowyswetlenia(LZespolona & LZ1,Operator & O,LZespolona & LZ2)const{

LZ1=this->Arg1;
LZ2=this->Arg2;
O=this->Op;

}


LZespolona WyrazenieZesp::Oblicz()const{

LZespolona wynik;

switch(this->Op){

case Op_Dodaj: 

wynik=this->Arg1+this->Arg2;


break;

case Op_Odejmij: 

wynik=this->Arg1-this->Arg2;

break;

case Op_Mnoz: 

wynik=this->Arg1*this->Arg2;

break;

case Op_Dziel: 

wynik=this->Arg1/this->Arg2;

break;


}

return wynik;
}
