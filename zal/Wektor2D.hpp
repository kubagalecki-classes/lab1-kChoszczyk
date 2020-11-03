class Wektor2D
{
public:
    Wektor2D()
    {
        x = 0;
        y = 0;
    }
    Wektor2D(double xx, double yy)
    {
        x = xx;
        y = yy;
    }
    void   setX(double xx) { x = xx; }
    void   setY(double xx) { y = xx; }
    double getX() { return x; }
    double getY() { return y; }

    // friend Wektor2D operator+(const Wektor2D& lewy, const Wektor2D& prawy);
    // friend double   operator*(const Wektor2D& lewy, const Wektor2D& prawy);

    Wektor2D operator+(const Wektor2D& prawy) const
    {
        Wektor2D tmp;
        tmp = *this;
        tmp.x += prawy.x;
        tmp.y += prawy.y;
        return tmp;
    }

    double operator*(const Wektor2D& prawy)
    {
        Wektor2D tmp;
        tmp = *this;
        tmp.x *= prawy.x;
        tmp.y *= prawy.y;
        return tmp.x + tmp.y;
    }

private:
    double x;
    double y;
};
