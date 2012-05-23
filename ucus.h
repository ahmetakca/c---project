#ifndef UCUS_H_INCLUDED
#define UCUS_H_INCLUDED
#include "String.h"
class Ucus
{
      friend ostream &operator<<(ostream &,const Ucus &);
private:
    const int ucusNo;
    String *kalkisYeri;
    String *varisYeri;
    String *kalkisZamani;
    const int normalKoltukSay;
    int luksKoltukSay;

    Ucus *sonraki;
    Ucus *onceki;


public:
    Ucus(int,String *,String*,String*,int,int=0);

    int ucusNoOku();
    String *kalkisYeriOku()const;
    String *varisYeriOku()const;
    String *kalkisZamaniOku();
    int luksKoltukOku();
    Ucus *sonrakiOku();
    Ucus *oncekiOku();

    void luksKoltukAyarla(int);
    void sonrakiAyarla(Ucus *);
    void oncekiAyarla(Ucus *);


    void ucusYaz();

};

#endif // UCUS_H_INCLUDED
