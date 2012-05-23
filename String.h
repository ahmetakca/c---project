#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
class String
{
    friend ostream &operator<<(ostream &,const String &);
 friend istream &operator>>(istream &,String &);
public:
    String(char *);
    void yazdir();

    char *strOku();
    void strAyar(char *);
    bool operator==(const String &)const;
    bool operator>(const String &)const;
    bool operator<(const String &)const;
    bool operator>=(const String &)const;
    bool operator<=(const String &)const;

    void harfBuyut(char *);
private:
    char *str;
};

#endif // STRING_H_INCLUDED
