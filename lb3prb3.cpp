#include <iostream>
#include <math.h>
using namespace std;
class Cartesian;
class Polar {
    float radius,angle; 

public:
    Polar() {
        radius=0.0;
        angle=0.0;
    }
    Polar (float r,float a){
        radius=r;
        angle=a;
    }
    operator Cartesian();

    void display()  {
        cout << "Polar Coordinates: (" << radius << ", " << angle << " degrees)" << endl;
    }


   
};

class Cartesian {
    float xco, yco;

public:
    Cartesian() {
        xco=0.0;
        yco=0.0;

    }
    Cartesian(float x,float y){
        xco=x;
        yco=y;
    }
    void display(){
        cout<<"The x coordinate is "<<xco <<"  and y coordinate is :"<<yco<<endl;
    }
};
Polar::operator Cartesian(){
    float x=radius*cos(angle);
    float y=radius*sin(angle);
    return Cartesian(x,y);
}
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
