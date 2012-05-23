#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#include "String.h"

String::String(char *s)
{

    str=s;
}
char *String::strOku()
{
    return str;
}
void String::strAyar(char *a)
{
    str=a;
}

bool String::operator==(const String &sag)const
{

    if(strcmp(str,sag.str)==0)
    return true;
    else return false;
}
bool String::operator>(const String &sag)const
{
  if(strcmp(str,sag.str)>0)
    return true;
    else return false;
}
bool String::operator<(const String &sag)const
{
  if(strcmp(str,sag.str)<0)
    return true;
    else return false;
}bool String::operator>=(const String &sag)const
{
  if(strcmp(str,sag.str)>=0)
    return true;
    else return false;
}bool String::operator<=(const String &sag)const
{
  if(strcmp(str,sag.str)<=0)
    return true;
    else return false;
}
ostream &operator<<(ostream &cik,const String &a)
{
    if(isdigit(a.str[0])==0)
    cik<<a.str;
    else
    cik<<""<<a.str[0]<<a.str[1]<<":"<<a.str[2]<<a.str[3];
    return cik;
}

void String::harfBuyut(char *k)
{
    int length=0;if(isalpha(k[0]))
    {while(k[length]!=NULL)
    {
        length++;
    }
    for(int i=0; i<length; i++)
        k[i]=toupper(k[i]);}

}
istream &operator>>(istream &gir,String &a)
{char *b;
String *c;

b=new char[20];
c=new String(NULL);
    gir>>b;


a.harfBuyut(b);
   a.strAyar(b);

return gir;
}
