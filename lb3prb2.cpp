#include <iostream>
#include <math.h>
using namespace std;

class Polar {
    float radius, angle; 

public:
    Polar(){
        radius=0.0;
        angle=0.0;
    }
    Polar(float r, float a){
        radius=r;
        angle=a;
    }

    double getRadius() const {
        return radius;
    }

    double getAngle() const {
        return angle;
    }
    void display(){
        cout<<"(<<radius<<","<<angle<<)";
    }
};

class Cartesian {
    float xco, yco;

public:
    Cartesian() {
        xco=0.0;
        yco=0.0;
    }
    Cartesian(float x,float y) {
        xco=x;
        yco=y;
    }
      Cartesian(Polar p) {
        xco=p.getRadius()*cos(p.getAngle());
        yco=p.getRadius()*sin(p.getAngle());
       
    }

    void display() const {
        cout << "Cartesian Coordinates: (" << xco << ", " << yco << ")" << endl;
    }
};

int main() {
    float radius, angle;
    cout << "Enter the radius: ";
    cin >> radius;
    cout << "Enter the angle (in degrees): ";
    cin >> angle;
    Polar p(radius,angle);
    p.display();

    Cartesian cart(p);
    cart.display();

    return 0;
}
