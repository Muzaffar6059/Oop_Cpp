#include <iostream>
#include<cmath>
using namespace std;

class Circle
{
public:
    void setRaduis(double);
    double calArea();
private:
    double radius;
};

void Circle::setRaduis(double r) {
    radius = r;
}
double Circle::calArea() {
    return 3.14 * pow(radius, 2);
}

int main()
{
    Circle c1, c2;

    c1.setRaduis(2);
    c2.setRaduis(5.3);

    cout << "The area of first circle is " << c1.calArea() << endl;
    cout << "The area of second circle is " << c2.calArea() << endl;

    
    return 0;
}