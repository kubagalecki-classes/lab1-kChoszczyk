#include <cmath>
#include <iostream>

using namespace std;

struct Wektor2D
{
    double x;
    double y;
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
};

int main()
{
    Wektor2D vect;
    vect.x = 10.783;
    vect.y = 4.652;
    vect.norm();
    vect.print();
}
