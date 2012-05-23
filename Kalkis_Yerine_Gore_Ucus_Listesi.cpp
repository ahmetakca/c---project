#include <iostream>
#include<string.h>
using namespace std;

#include "ucus.h"
#include "Kalkis_Yerine_Gore_Ucus_Listesi.h"
kalkisYerineGoreListe::kalkisYerineGoreListe():lbas(0,NULL,NULL,NULL,0,0)
{

    lbas.sonrakiAyarla(&lbas);
    lbas.oncekiAyarla(&lbas);
    lstBas=&lbas;
//    suanki.oncekiAyarla(&suanki);
}

void kalkisYerineGoreListe::ciftBagEkle(Ucus *yeni)
{
    Ucus *gecici,*onceki;
    gecici=lstBas->sonrakiOku();

    while(gecici!=lstBas && (*yeni->kalkisYeriOku())>=(*gecici->kalkisYeriOku()))
    {
        if((*yeni->kalkisYeriOku())==(*gecici->kalkisYeriOku()))
        {
            if((*yeni->kalkisZamaniOku())>(*gecici->kalkisZamaniOku()))
            {
                gecici=gecici->sonrakiOku();
                continue;
            }
            else
            {
                break;
            }
        }
        gecici=gecici->sonrakiOku();
    }
    yeni->sonrakiAyarla(gecici);
    yeni->oncekiAyarla(gecici->oncekiOku());

    onceki=gecici->oncekiOku();
    onceki->sonrakiAyarla(yeni);
    gecici->oncekiAyarla(yeni);


}
Ucus *kalkisYerineGoreListe::ara(int uNo)
{
    Ucus *gecici;
    gecici=lstBas->sonrakiOku();
    while(gecici!=lstBas)
    {
        if(uNo==gecici->ucusNoOku())
        {
            return gecici;
        }
        gecici=gecici->sonrakiOku();
    }
    return NULL;
}
void kalkisYerineGoreListe::ciftBagliDugumSil(Ucus *silinecek)
{
    ciftBagliDugumCikar(silinecek);
    delete(silinecek);
}
void kalkisYerineGoreListe::ciftBagliDugumCikar(Ucus *cikarilacak)
{
    cikarilacak->oncekiOku()->sonrakiAyarla(cikarilacak->sonrakiOku());
    cikarilacak->sonrakiOku()->oncekiAyarla(cikarilacak->oncekiOku());
}
void kalkisYerineGoreListe::varisYerineGoreListele(String *vYer)
{
    Ucus *gecici;
    gecici=(&lbas)->sonrakiOku();
    gecici->ucusYaz();
    while(gecici!=(&lbas))
    {
        if((*vYer)==(*gecici->varisYeriOku()))
            cout<<*gecici<<endl;
        gecici=gecici->sonrakiOku();
    }
}
void kalkisYerineGoreListe::kalkisYerineGoreListele(String *kYer)
{
    Ucus *gecici;
    gecici=lstBas->sonrakiOku();
    gecici->ucusYaz();
    while(gecici!=(lstBas))
    {
        if(*kYer==(*gecici->kalkisYeriOku()))
            cout<<*gecici<<endl;
        gecici=gecici->sonrakiOku();
    }
}
void kalkisYerineGoreListe::kalkisVeVarisYerineGoreListele(String *kYer,String *vYer)
{
    Ucus *gecici;
    gecici=lstBas->oncekiOku();
    gecici->ucusYaz();
    while(gecici!=(lstBas))
    {
        if(*kYer==(*gecici->kalkisYeriOku()))
           if(*vYer==(*gecici->varisYeriOku()))
                cout<<*gecici<<endl;
        gecici=gecici->oncekiOku();
    }
}
void kalkisYerineGoreListe::listele()
{
    Ucus *gecici;
    gecici=lstBas->sonrakiOku();
    while(gecici!=lstBas)
    {

        cout<<*gecici<<endl;
        gecici=gecici->sonrakiOku();
    }
}
