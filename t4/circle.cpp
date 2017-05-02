#include <iostream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const double PI = 3.14159;


class Point{
private:
    double x;
    double y;

public:
    Point(){
        x = y = 0.0;
    }
    Point(double x1, double y1){
        x = x1;
        y = y1;
    }
    void move(double dx, double dy){
        x = x + dx;
        y = y + dy;
    }
    double distanceTo(Point* p){
        return sqrt(pow((p->x - x), 2) + pow((p->y - y),2));
    }
    double pega_x(){
        return x;
    }
    double pega_y(){
        return y;
    }
};

class Circle{
private:
    Point p;
    double r;
public:
    Circle(){
        p = Point(0.0, 0.0);
        r = 0.0;
    }
    Circle(double x1, double y1, double r1){
        p = Point(x1, y1);
        r = r1;
    }
    double area(){
        return PI * r * r;
    }
    void setRadius(double radius){
        r = radius;
    }
    double pega_Radius(void){
  	   return r;
   }
   Point pega_Point(void){
	   return p;
   }
    double distanceTo(Circle *c2){
        Point p2 = c2->pega_Point();
        return p.distanceTo(&p2) - (r + c2->pega_Radius());
    }
};

int main() {
     Circle c1, c2;

	c1 = Circle(50, 50, 40);
	c2 = Circle(200, 50, 40);
}
