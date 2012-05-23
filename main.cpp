#include <iostream>
#include <conio.h>
#include <String.h>
using namespace std;

#include "ucus.h"
#include "String.h"
#include "Ucus_Numarasina_Gore_Ucus_Listesi.h"
#include "Kalkis_Yerine_Gore_Ucus_Listesi.h"
int menuSecim();

int main()
{

    numarayaGoreListe numaraListesi;
    kalkisYerineGoreListe kalkisYeriListesi;
    Ucus *birUcus1,*birUcus2,*birUcus;
    int uNo;
    String *kYeri;
    String *vYeri;
    String *kZamani;
    int nKSay;
    int lKSay;

    int secenek;

    do
    {
        secenek=menuSecim();
        switch(secenek)
        {
        case 1:

            cout<<"Ucusun numarasini giriniz:"<<endl;
            cin>>uNo;
            birUcus=kalkisYeriListesi.ara(uNo);
            if(birUcus==NULL)
            {
                kYeri=new String(NULL);
                vYeri=new String(NULL);
                kZamani=new String(NULL);
                cout<<"Ucusun kalkis yerini giriniz:"<<endl;
                cin>>*kYeri;


                cout<<"Ucusun varis yerini giriniz:"<<endl;
                cin>>*vYeri;

                cout<<"Ucusun kalkis zamanini giriniz:"<<endl;
                cin>>*kZamani;
                cout<<"Ucusun normal koltuk sayisini giriniz:"<<endl;
                cin>>nKSay;
                birUcus1=new Ucus(uNo,kYeri,vYeri,kZamani,nKSay);


                kalkisYeriListesi.ciftBagEkle(birUcus1);
                birUcus2=new Ucus(uNo,kYeri,vYeri,kZamani,nKSay);
                numaraListesi.ekle(birUcus2);

                cout<<"Ucus Eklendi"<<endl;
            }
            else cout<< uNo<<" numarali ucus var!!!"<<endl;
            break;
        case 2:
            cout<<"Ucusun numarasini giriniz:"<<endl;
            cin>>uNo;
            birUcus=numaraListesi.ucusVarMi(uNo);
            if(birUcus==NULL)
            {

                kYeri=new String(NULL);
                vYeri=new String(NULL);
                kZamani=new String(NULL);
                cout<<"Ucusun kalkis yerini giriniz:"<<endl;
                cin>>*kYeri;

                cout<<"Ucusun varis yerini giriniz:"<<endl;
                cin>>*vYeri;

                cout<<"Ucusun kalkis zamanini giriniz:"<<endl;
                cin>>*kZamani;

                cout<<"Ucusun normal koltuk sayisini giriniz:"<<endl;
                cin>>nKSay;
                cout<<"Ucusun normal koltuk sayisini giriniz:"<<endl;
                cin>>lKSay;

                birUcus1=new Ucus(uNo,kYeri,vYeri,kZamani,nKSay,lKSay);
                kalkisYeriListesi.ciftBagEkle(birUcus1);
                birUcus2=new Ucus(uNo,kYeri,vYeri,kZamani,nKSay,lKSay);
                numaraListesi.ekle(birUcus2);


                cout<<"Ucus Eklendi"<<endl;
            }
            else cout<< uNo<<" numarali ucus var!!!"<<endl;
            break;
        case 3:
            cout<<"Ucusun numarasini giriniz:"<<endl;
            cin>>uNo;
            birUcus1=kalkisYeriListesi.ara(uNo);
            if(birUcus!=NULL)
            {
                cout<<"Ucusun yeni luks koltuk sayisini giriniz:"<<endl;
                cin>>lKSay;

                birUcus1->luksKoltukAyarla(lKSay);
                birUcus2=numaraListesi.ucusVarMi(uNo);
                birUcus2->luksKoltukAyarla(lKSay);
                cout<<"Ucus guncellendi!!!"<<endl;
            }
            else cout<<"Bu numarali ucus bulunamadi!!!"<<endl;
            break;
        case 4:
            cout<<"Ucusun numarasini giriniz:"<<endl;
            cin>>uNo;
            birUcus=kalkisYeriListesi.ara(uNo);
            if(birUcus!=NULL)
            {
                kalkisYeriListesi.ciftBagliDugumSil(birUcus);
                birUcus=numaraListesi.cikar(uNo);
                cout<<*birUcus<<endl;
                delete(birUcus);
                cout<<"Ucus Silindi!!!"<<endl;
            }
            else cout<<"Bu numarali ucus bulunamadi!!!"<<endl;
            break;
        case 5:
            cout<<"Ucusun numarasini giriniz:"<<endl;
            cin>>uNo;
            birUcus=numaraListesi.ucusVarMi(uNo);
            if(birUcus!=NULL)
            {
                birUcus->ucusYaz();
                cout<<*birUcus<<endl;
            }
            else cout<<"Bu numarali ucus bulunamadi!!!"<<endl;
            break;
        case 6:
            numaraListesi.listele();
            break;
        case 7:
            vYeri=new String(NULL);
            cout<<"Ucusun kalkis yerini giriniz:"<<endl;
            cin>>*vYeri;
            kalkisYeriListesi.varisYerineGoreListele(vYeri);
            break;
        case 8:
            kYeri=new String(NULL);

            cout<<"Ucusun kalkis yerini giriniz:"<<endl;
            cin>>*kYeri;


            kalkisYeriListesi.kalkisYerineGoreListele(kYeri);
            break;
        case 9:
            kYeri=new String(NULL);
            vYeri=new String(NULL);
            cout<<"Ucusun kalkis yerini giriniz:"<<endl;
            cin>>*kYeri;

            cout<<"Ucusun kalkis yerini giriniz:"<<endl;
            cin>>*vYeri;

            kalkisYeriListesi.kalkisVeVarisYerineGoreListele(kYeri,vYeri);
            break;
        }
        getch();

    }
    while (secenek!=0);
    return 0;


    cout << "Hello world!" << endl;
    return 0;
}//
int menuSecim(void)
{
    int secim;

    cout << endl;
    cout << "\n\n\n\t\t\tHAVAYOLU BILET SATIS SISTEMI\n\n\n" << endl;
    cout << "\t 1) Luks koltuk icermeyen yeni bir ucusun eklenmesi" << endl;
    cout << "\t 2) Luks koltuk iceren yeni bir ucusun eklenmesi" << endl;
    cout << "\t 3) Bir ucusun luks koltuk sayisinin guncellenmesi" << endl;
    cout << "\t 4) Bir ucusun iptal edilmesi" << endl;
    cout << "\t 5) Bir ucusun bilgilerinin goruntulenmesi" << endl;
    cout << "\t 6) Luks koltuk iceren ucuslarin listesi" << endl;
    cout << "\t 7) Bir yere olan ucuslarin listesi" << endl;
    cout << "\t 8) Bir yerden kalkan ucuslarin listesi" << endl;
    cout << "\t 9) Bir yerden bir yere olan ucuslarin listesi" << endl;
    cout << "\t 0) Cikis\n" << endl;
    do
    {
        cout << "Seciminizi Giriniz:  "<<endl;
        cin >> secim;
    }
    while(secim<0 || secim>10);

    return secim;
}
