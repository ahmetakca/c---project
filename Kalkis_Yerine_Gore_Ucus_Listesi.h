#ifndef KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED
#define KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED

#include "ucus.h"
class kalkisYerineGoreListe{
private:
Ucus lbas;
Ucus *lstBas;
public:

kalkisYerineGoreListe();
void ciftBagEkle(Ucus *);
Ucus *ara(int);
void ciftBagliDugumSil(Ucus *);
void ciftBagliDugumCikar(Ucus *);
void varisYerineGoreListele(String *);
void kalkisYerineGoreListele(String *);
void kalkisVeVarisYerineGoreListele(String *,String *);
void listele();
};

#endif // KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED
