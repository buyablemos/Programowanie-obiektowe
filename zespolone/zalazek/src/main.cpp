#include <iostream>
#include <fstream>
#include "WyrazenieZesp.hh"
#include "Statystyka.hh"



using std::cout;
using std::cerr;
using std::cin;
using std::endl;

void WykonajTest(std::istream &StrmWej,const char **argv)
{

  int lpetli=0;
  int pozwolenie=0;

  WyrazenieZesp PytanieTestowe;
  LZespolona  Odpowiedz;
  Statystyka Stat;

  //Stat.zerowanie(); bylo ale jest konstruktor

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  
  while (!(StrmWej >> PytanieTestowe).eof()){            // dziala az do napotkania eof
  
    if(StrmWej.fail()){                                  // sprawdza czy dobrze wczytujemy wyrazenia z pliku
 
    std::cerr<<"Nie można wczytać wyrażenia zespolonego z pliku"<<"\n\n";
    
    exit(2);
    }  
    else
    Stat.plusilosc();

    cout << " Prosze rozwiazac dzialanie: ";
    cout << PytanieTestowe << endl;
    
   

    while(lpetli<3){
      cin >> Odpowiedz;
      
      pozwolenie=cin.fail();
      
      if( !pozwolenie ){
      
        cout<<" Twoja odpowiedz to "<<Odpowiedz<<endl;
        if(Odpowiedz==PytanieTestowe.Oblicz()){
        
        Stat.plus();
        cout<<" Jest to poprawna odpowiedz!"<<endl<<endl;
        }
        else{
        cout<<" Bledna odpowiedz"<<endl;
        cout<<" Poprawna odpowiedz to "<<PytanieTestowe.Oblicz()<<endl<<endl;
        }
        break;
      }
      
      else{
      
      if(lpetli<2){
      cout<< " Wpisz jeszcze raz liczbe zespolona"<<endl;
      }
      cin.clear();
      cin.ignore(10000,'\n');
      lpetli++;
      }
    }
    if(lpetli==3){
    cout<<" Liczba zostala wpisana zle 3 razy. Test przechodzi dalej."<<endl<<endl;
    }
    lpetli=0;
    
  }
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  
  Stat.wyswietlstatystyke(cout);                      //wyswietla statystyke testu
  
}

 

int main(int argc,const char **argv)
{

  if (argc < 2) {
    cerr << endl;
    cerr << " Brak nazwy pliku z zawartoscia testu." << endl;   // sprawdza czy podalismy argument z nazwa pliku
    cerr << endl;
    return 1;
  }

  std::ifstream  PlikTestu(argv[1]);

  if (PlikTestu.is_open() == false) {                           // otwiera plik z wyrazeniami nad ktorymi program bedzie pracowal 
                                                                //               oraz
    cout << "Nie można otworzyć pliku:" << argv[1];             // sprawdza czy udalo sie otworzyc plik

    return 1;
  }

  WykonajTest(PlikTestu,argv);                                  // wykonuje caly modul testu
  
  PlikTestu.close();                                            // zamyka plik z danymi
  
}
