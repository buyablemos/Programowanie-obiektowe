#include "lazik.hh"


void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}


void lazik::obroc(double kat){

U.rotacja(MacierzRotacji('z',kat));

}

void lazik::jedz(double d){

Wektor3D W1{d,0,0};


U.translacja((U.getmacierz()*W1));
}


void lazik::rysuj(API3D *gnuplot){

std::array<Wektor3D,8> wspolrzedne;
wspolrzedne=wymiary.przeliczwierzcholki();

for(int i=0;i<8;++i){

wspolrzedne[i]=this->U.przeliczdorodzica(wspolrzedne[i]);

}

int x=gnuplot->getpointer()->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(wspolrzedne[0][0],wspolrzedne[0][1],wspolrzedne[0][2]), drawNS::Point3D(wspolrzedne[1][0],wspolrzedne[1][1],wspolrzedne[1][2]), 
    drawNS::Point3D(wspolrzedne[3][0],wspolrzedne[3][1],wspolrzedne[3][2]), drawNS::Point3D(wspolrzedne[2][0],wspolrzedne[2][1],wspolrzedne[2][2])
      },{
	drawNS::Point3D(wspolrzedne[4][0],wspolrzedne[4][1],wspolrzedne[4][2]), drawNS::Point3D(wspolrzedne[5][0],wspolrzedne[5][1],wspolrzedne[5][2]), 
    drawNS::Point3D(wspolrzedne[7][0],wspolrzedne[7][1],wspolrzedne[7][2]), drawNS::Point3D(wspolrzedne[6][0],wspolrzedne[6][1],wspolrzedne[6][2])     
	  }},this->kolor);//rysuje niebieski graniastosłup*/
/*
int a=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[0][0],wspolrzedne[0][1],wspolrzedne[0][2]),drawNS::Point3D(wspolrzedne[1][0],wspolrzedne[1][1],wspolrzedne[1][2]),"blue");
int b=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[1][0],wspolrzedne[1][1],wspolrzedne[1][2]),drawNS::Point3D(wspolrzedne[3][0],wspolrzedne[3][1],wspolrzedne[3][2]),"blue");
int c=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[3][0],wspolrzedne[3][1],wspolrzedne[3][2]),drawNS::Point3D(wspolrzedne[2][0],wspolrzedne[2][1],wspolrzedne[2][2]),"blue");
int d=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[2][0],wspolrzedne[2][1],wspolrzedne[2][2]),drawNS::Point3D(wspolrzedne[0][0],wspolrzedne[0][1],wspolrzedne[0][2]),"blue");

int e=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[4][0],wspolrzedne[4][1],wspolrzedne[4][2]),drawNS::Point3D(wspolrzedne[5][0],wspolrzedne[5][1],wspolrzedne[5][2]),"red");
int f=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[5][0],wspolrzedne[5][1],wspolrzedne[5][2]),drawNS::Point3D(wspolrzedne[7][0],wspolrzedne[7][1],wspolrzedne[7][2]),"red");
int g=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[7][0],wspolrzedne[7][1],wspolrzedne[7][2]),drawNS::Point3D(wspolrzedne[6][0],wspolrzedne[6][1],wspolrzedne[6][2]),"red");
int h=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[6][0],wspolrzedne[6][1],wspolrzedne[6][2]),drawNS::Point3D(wspolrzedne[4][0],wspolrzedne[4][1],wspolrzedne[4][2]),"red");

int i=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[0][0],wspolrzedne[0][1],wspolrzedne[0][2]),drawNS::Point3D(wspolrzedne[4][0],wspolrzedne[4][1],wspolrzedne[4][2]),"red");
int j=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[1][0],wspolrzedne[1][1],wspolrzedne[1][2]),drawNS::Point3D(wspolrzedne[5][0],wspolrzedne[5][1],wspolrzedne[5][2]),"red");
int k=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[2][0],wspolrzedne[2][1],wspolrzedne[2][2]),drawNS::Point3D(wspolrzedne[6][0],wspolrzedne[6][1],wspolrzedne[6][2]),"red");
int l=gnuplot->getpointer()->draw_line(drawNS::Point3D(wspolrzedne[3][0],wspolrzedne[3][1],wspolrzedne[3][2]),drawNS::Point3D(wspolrzedne[7][0],wspolrzedne[7][1],wspolrzedne[7][2]),"red");


std::array<int,12> tablicakresektmp{a,b,c,d,e,f,g,h,i,j,k,l};
this->tablicakresek=tablicakresektmp;
*/
//gnuplot->getpointer()->erase_shape(tablicakresek[1]);
//wait4key();

this->id=x;
}


void lazik::animujobrot(double kat){
double czasruchu=abs(kat/VKATOWA);
double czasklatki=(CZESTOTLIWOSCODSWIEZANIA/(double)1000);
double iloscklatek=czasruchu/czasklatki;
double katklatki =(double)(kat/iloscklatek);
this->obrot+=kat;

for(double i=0;i<iloscklatek;++i){

 obroc(katklatki);
 /*
 gnuplotptr->getpointer()->erase_shape(tablicakresek[0]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[1]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[2]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[3]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[4]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[5]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[6]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[7]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[8]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[9]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[10]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[11]);
*/

 gnuplotptr->getpointer()->erase_shape(this->id);
 rysuj(gnuplotptr);
 std::this_thread::sleep_for(std::chrono::milliseconds(CZESTOTLIWOSCODSWIEZANIA));
}

}


void lazik::animujruch(double droga,double predkosc){

if((predkosc-0<DOKLZMIENNOPRZECINKOWA)){
std::cerr<<"Blad-predkosc nie moze byc rowna 0";
exit(1);};

double czasruchu=abs(droga/predkosc);
double czasklatki=CZESTOTLIWOSCODSWIEZANIA/(double)1000;
double iloscklatek=czasruchu/czasklatki;
double ruchklatki=droga/iloscklatek;


for(int i=0;i<iloscklatek;++i){

 jedz(ruchklatki);
 /*
 gnuplotptr->getpointer()->erase_shape(tablicakresek[0]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[1]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[2]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[3]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[4]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[5]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[6]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[7]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[8]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[9]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[10]);
 gnuplotptr->getpointer()->erase_shape(tablicakresek[11]);
 */
 gnuplotptr->getpointer()->erase_shape(this->id);
 rysuj(gnuplotptr);
 std::this_thread::sleep_for(std::chrono::milliseconds(CZESTOTLIWOSCODSWIEZANIA));
}

}

void lazik::pokazinfo(){

std::cout<<"Aktywny łazik:"<<std::endl<<std::endl;
std::cout<<"Nazwa: "<<nazwa<<std::endl;
std::cout<<"Kolor: "<<kolor<<std::endl;
std::cout<<"                    |x\t\ty\tz|"<<std::endl;
std::cout<<"Aktualne położenie: "<<std::fixed<<std::setprecision(1)<<'|'<<U.getwektor()<<'|'<<std::endl;

std::cout<<"Aktualna orientacja: "<<'|'<<std::setprecision(0)<<obrot<<'|'<<std::endl<<std::endl;
}