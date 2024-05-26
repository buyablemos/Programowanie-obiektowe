#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include<iostream>
/*
 * Modeluje statystyke testu
 */
class Statystyka {
private:
int poprawne;
int ilosc;

public:
Statystyka();
void plus(); // dodawanie jedynki do poprawnych odpowiedzi
void plusilosc(); // dodawanie jedynki do sumy pytan
void zerowanie(); //zerowanie statystyki,ale jest konstuktor
void wyswietlstatystyke(std::ostream&strm); //wyswietla statystyke testu
};


#endif