#include "UWspolrzednych.hh"

const Wektor3D UWspolrzednych::przeliczdorodzica(const Wektor3D& punkt){

   Wektor3D tmp;
   
   tmp=this->orientacja*punkt+this->przesuniecie;
   
   return tmp;
}