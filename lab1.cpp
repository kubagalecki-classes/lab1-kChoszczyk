#include <cmath>
#include <iostream>

using namespace std;

struct Informer
{
    Informer() { cout << "Konstrukcja" << endl; }
    ~Informer() { cout << "Destrukcja" << endl; }
};

class Wektor2D
{
public:
    Wektor2D()
    {
        x = 0;
        y = 0;
        ++num_wek;
        cout << "num_wek " << num_wek << endl;
    };

    Wektor2D(double xx, double yy)
    {
        ++num_wek;
        x = xx;
        y = yy;
        cout << "Konstruktor. Wartosci wspolrzednych:" << endl;
        cout << "x = " << x << " y = " << y << " num_wek " << num_wek << endl;
    }

public:
    ~Wektor2D()
    {
        --num_wek;
        cout << "Destruktor. Wartosci wspolrzednych:" << endl;
        cout << "x = " << x << " y = " << y << " num_wek " << num_wek << endl;
    }
    void   setX(double xx) { x = xx; }
    double getX()
    { // cout << "Wartosc x wynosi " << x << endl;
        return x;
    }
    void   setY(double xx) { y = xx; }
    double getY()
    { // cout << "Wartosc y wynosi " << y << endl;
        return y;
    }

private:
    Informer   inform;
    double     x;
    double     y;
    static int num_wek;

public:
    int populacja()
    {
        cout << "Liczba wektorow " << num_wek << endl;
        return num_wek;
    }
    double norm()
    {
        double sum, len;
        sum = x * x + y * y;
        len = sqrt(sum);
        cout << "Norma wynosi " << len << "." << endl;
        return len;
    }
    void print()
    {
        cout << "Wspolrzedna x wektora " << x << endl;
        cout << "Wspolrzedna y wektora " << y << endl;
    }

    friend ostream& operator<<(ostream& wyjscie, const Wektor2D& a);
    friend Wektor2D operator+(const Wektor2D& a, const Wektor2D& b);
    friend double   operator*(const Wektor2D& a, const Wektor2D& b);
};

int Wektor2D::num_wek = 0;

Wektor2D operator+(const Wektor2D& a, const Wektor2D& b)
{
    Wektor2D tmp;
    tmp = a;
    tmp.x += b.x;
    tmp.y += b.y;
    return tmp;
}

double operator*(const Wektor2D& a, const Wektor2D& b)
{
    Wektor2D tmp;
    tmp = a;
    tmp.x *= b.x;
    tmp.y *= b.y;
    tmp.x += tmp.y;
    return tmp.x;
}

ostream& operator<<(ostream& wyjscie, const Wektor2D& a)
{
    wyjscie << "Wlasnie drukujesz wspolrzedna x " << a.x << ", a teraz y " << a.y << endl;
    return wyjscie;
}

int main()
{
    Wektor2D vect1(2, 12);
    Wektor2D vect2;

    vect2.setX(1);
    vect2.setY(3);

    Wektor2D c;
    c = vect1 + vect2;
    double d;
    d = vect1 * vect2;
    cout << "Wartosc d " << d << endl;
    cout << c << vect1 << vect2;
}