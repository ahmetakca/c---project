#include <iostream>

using namespace std;

#include "ucus.h"
#include "Ucus_Numarasina_Gore_Ucus_Listesi.h"
numarayaGoreListe::numarayaGoreListe()
{
    bas=NULL;
ucusSay=0;
}
int numarayaGoreListe::ucusSayOku()
{
    return ucusSay;
}
void numarayaGoreListe::ekle(Ucus *yeni)
{
    Ucus *gecici,*onceki=NULL;
    if(bas==NULL)
    {
        bas=yeni;
    }
    else if(yeni->ucusNoOku()<bas->ucusNoOku())
    {
        yeni->sonrakiAyarla(bas);
        bas=yeni;
    }
    else
    {
        onceki=bas;
        gecici=bas->sonrakiOku();
        while(gecici!=NULL&& yeni->ucusNoOku()>gecici->ucusNoOku() )
        {
            onceki=gecici;
            gecici=gecici->sonrakiOku();
        }
        yeni->sonrakiAyarla(gecici);
        onceki->sonrakiAyarla(yeni);
    }
ucusSay++;


}



Ucus *numarayaGoreListe::cikar(int uNo)
{
    Ucus *gecici,*onceki;
    if(bas->ucusNoOku()==uNo)
    {
        gecici=bas;
        bas=bas->sonrakiOku();
    }
    else
    {
        onceki=bas;
        gecici=bas->sonrakiOku();
        while((gecici!=NULL) && (uNo>gecici->ucusNoOku()))
        {
            if(gecici->ucusNoOku()==uNo)
            {
                break;
            }
            onceki=gecici;
            gecici=gecici->sonrakiOku();
        }
        onceki->sonrakiAyarla(gecici->sonrakiOku());
    }
    return gecici;
}
Ucus *numarayaGoreListe::ucusVarMi(int uNo)
{
    Ucus *gecici;
   int sayac=0;
   gecici=bas;
   while(gecici!=NULL)
    {
        if(gecici->ucusNoOku()==uNo)
        {
            return gecici;
        }
        gecici=gecici->sonrakiOku();
        sayac++;
    }
    return NULL;
}

void numarayaGoreListe::listele()
{
    Ucus *gecici;
    gecici=bas;
    gecici->ucusYaz();
    while(gecici!=NULL)
    {
        if(gecici->luksKoltukOku()!=0)
        cout<<*gecici<<endl;
        gecici=gecici->sonrakiOku();

    }
}
