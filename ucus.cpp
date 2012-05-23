#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

#include "ucus.h"
#include "String.h"
ostream &operator<<(ostream &o,const Ucus &u)
{
    o<<left<<setw(8)<<u.ucusNo<<setw(12)<<(*u.kalkisYeri)<<setw(11)<<(*u.varisYeri)<<(*u.kalkisZamani)<<"  "<<setw(21)<<u.normalKoltukSay<<u.luksKoltukSay;

    return o;
}
Ucus::Ucus(int uNo,String *kYer,String *vYer,String *zmn,int nSay,int lSay):ucusNo(uNo),normalKoltukSay(nSay)
{

    kalkisYeri=kYer;
    varisYeri=vYer;
    kalkisZamani=zmn;
    luksKoltukSay=lSay;
    sonraki=NULL;
    onceki=NULL;
}
int Ucus::ucusNoOku()
{
    return ucusNo;
}
String *Ucus::kalkisYeriOku() const
{
    return kalkisYeri;
}
String *Ucus::varisYeriOku()const
{
    return varisYeri;
}
String* Ucus::kalkisZamaniOku()
{
    return kalkisZamani;
}
int Ucus::luksKoltukOku()
{
    return luksKoltukSay;
}
Ucus *Ucus::sonrakiOku()
{
    return sonraki;
}
Ucus *Ucus::oncekiOku()
{
    return onceki;

}
void Ucus::luksKoltukAyarla(int kSay)
{
    luksKoltukSay=kSay;
}
void Ucus::sonrakiAyarla(Ucus *sonrakiUcus)
{
    sonraki=sonrakiUcus;
}
void Ucus::oncekiAyarla(Ucus *oncekiUcus)
{
    onceki=oncekiUcus;
}

void Ucus::ucusYaz()
{
    cout<<"Ucus No Kalkis Yeri Varis Yeri Zamani Normal Koltuk Sayisi Luks Koltuk Sayisi"<<endl
        <<"------- ----------- ---------- ------ -------------------- ------------------\n";
}
