#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// kalkulator - dodawania i odejmowanie (+ wartość bezwzględna)
/*
int main() {
    int a, b, c, d, e;
    cout << "Podaj dwie liczby ktorych chcesz poznac wynik dodawania i odejmowania:" << endl;
    cin >>  a  >> b;
    c = a + b;
    if (a < b) {
        d = b - a;
    }
    else if (a > b) {
        d = a - b;
    }
    cout << "Twoj wynik dodawania to: " << c << endl << "Twoj wynik odejmowania (wartosc bezwgledna) to: " << d << endl;
    e = a - b;
    cout << "Twoj wynik odjemowania to: " << e << endl;
    return 0;
}
/**/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                                                ,---------------------------------------------------------,
                                                |Program który pokazuje ile razy została wywołana funkcja:|
                                                |          Przykład dla liczby 30:                        |
                                                |---------------Początek----------------------------------|
                                                |A's func jest wywoływana raz:                            |
                                                |val = val*2                                              |
                                                |val = 2                                                  |
                                                |----------------Potem------------------------------------|
                                                |Func firmy B jest wywoływany raz:                        |
                                                |val = val*3                                              |
                                                |val = 6                                                  |
                                                |----------------Potem------------------------------------|
                                                |Func firmy C jest wywoływany raz:                        |
                                                |val = val*5                                              |
                                                |val = 30                                                 |
                                                |----------------Wynik------------------------------------|
                                                |         aby uzyskać liczbę:                             |
                                                |           ----> 30 <----                                |
                                                |   każda funkcja została wykonana 1 razy                 |
                                                '---------------------------------------------------------'
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                
*//*
class A
{
public:
    A() {
        callA = 0;
    }
private:
    int callA;
    void inc() {
        callA++;
    }

protected:
    void func(int& a)
    {
        a = a * 2;
        inc();
    }
public:
    int getA() {
        return callA;
    }
};

class B
{
public:
    B() {
        callB = 0;
    }
private:
    int callB;
    void inc() {
        callB++;
    }
protected:
    void func(int& a)
    {
        a = a * 3;
        inc();
    }
public:
    int getB() {
        return callB;
    }
};

class C
{
public:
    C() {
        callC = 0;
    }
private:
    int callC;
    void inc() {
        callC++;
    }
protected:
    void func(int& a)
    {
        a = a * 5;
        inc();
    }
public:
    int getC() {
        return callC;
    }
};

class D : public A, public B, public C
{

    int val;
public:
    
    D()
    {
        val = 1;
    }


  
    void update_val(int new_val)
    {
        int const_new_val = new_val;
        while (val != const_new_val) {
            if (new_val % 2 == 0) {
                A::func(val);
                new_val /= 2;
            }
            else if (new_val % 3 == 0) {
                B::func(val);
                new_val /= 3;
            }
            else if (new_val % 5 == 0) {
                C::func(val);
                new_val /= 5;
            }
        }
    }

    void check(int); 
};

void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}

int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/