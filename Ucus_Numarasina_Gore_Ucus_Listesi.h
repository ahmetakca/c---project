#ifndef UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED
#define UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED

#include "ucus.h"
class numarayaGoreListe{
private:
Ucus *bas;
int ucusSay;
public:
numarayaGoreListe();
int ucusSayOku();
void ekle(Ucus *);
Ucus *cikar(int);
Ucus *ucusVarMi(int);

void listele();

};


#endif // UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED
