class LZespolona{
private:
double re;
double im;
public:
LZespolona  operator + (const LZespolona & NR2) const; //L1+L2
LZespolona sprzezenie() const;  //L1.Sprzezenie()
LZespolona tworz (double RZ,double IMA) : re(Re), im(Im) {}  // LZespolona L1(2,3);
explicit (zabrania niejawnego rzutowania) LZespolona LZesp(double Re) : re(Re), im(0){}

LZespolona(LZesp &L1)= default; // zeby usunac 
}


LZespolona L3 = LZespolona(2,3)+2.0;

//domyslne konstruktory

LZespolona();
LZespolona(LZesp &L); 


//w pliku cpp

LZesp LZesp::Sprzezenie(){


};