#include <iostream>
#include <math.h>
using namespace std;

class Polar
{
    float radius, angle;

public:
polar(){
    radius = 0.0;
     angle = 0.0;
}
    Polar(float r,float a)
    {
        radius = r;
        angle = a;
    }

    void display()
    {
        cout << "Polar Coordinates: (" << radius << ", " << angle << ")" << endl;
    }
};

class Cartesian
{
    float xco, yco;

public:
Cartesian(){
    xco=0.0;
    yco=0.0;
}
    Cartesian(float x, float y)
    {
        xco = x;
        yco = y;
    }

    void input()
    {
        cout << "Enter xco: ";
        cin >> xco;
        cout << "Enter yco: ";
        cin >> yco;
    }

    operator Polar()
    {
        float radius = sqrt(xco * xco + yco * yco);
        float angleRad = atan2(yco, xco);
        float angle = angleRad * 180 / 3.14159;
        return Polar(radius, angle);
    }

    void display()
    {
        cout << "Cartesian Coordinates: (" << xco << ", " << yco << ")" << endl;
    }
};

int main()
{
    Cartesian cart;
    cart.input();
    Polar pol = cart;
    cart.display();
    pol.display();
    return 0;
}
