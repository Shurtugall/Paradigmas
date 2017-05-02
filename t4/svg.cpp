#include <iostream>
#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;
const double PI = 3.14159;
std::ofstream arquivo;

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

class Line{
private:
    Point p1;
    Point p2;

public:
    Line(){
        p1 = Point(0.0, 0.0);
        p2 = Point(0.0, 0.0);

    }
    Line(Point novo_p1, Point novo_p2){
        p1 = novo_p1;
        p2 = novo_p2;
    }
    Point pega_p1(){
        return p1;
    }
    Point pega_p2(){
        return p2;
    }

};

void arquivo_open(int altura, int largura){

	arquivo.open("circulos.svg");
	arquivo << "<!DOCTYPE html>\n" << "<html>\n" << "<body>\n";

	arquivo << "<svg height=\"" << altura << "\" width=\"" << largura << "\">\n";
	arquivo << "  <rect width=\"" << altura << "\" height=\"" << largura << "\" style=\"fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)\" />\n";

}

void arquivo_close(void){

	arquivo << "</svg>\n</body>\n</html>\n";
	arquivo.close();
}

void arquivo_desenha_circle(Circle *circ){

	Point p = circ->pega_Point();
	arquivo << "  <circle cx=\"" << p.pega_x() << "\" cy=\"" << p.pega_y()
			<< "\" r=\"" << circ->pega_Radius()
			<<"\" stroke=\"" << "black" << "\" stroke-width=\"3\" fill=\""
			<< "red" << "\" />\n";

}

void arquivo_desenha_linha(Line* linha){
    Point p1 = linha->pega_p1();
    Point p2 = linha->pega_p2();
    arquivo << "  <line x1=\"" << p1.pega_x() << "\" y1=\"" << p1.pega_y()<< "\" x2=\""
            << p2.pega_x() << "\" y2=\"" << p2.pega_y()
            << "\" style =\" stroke:rgb(0,0,0);stroke-width:2\" />\n";

}


int main(){
    arquivo_open(800,600);
    Circle c1, c2;

	c1 = Circle(50, 50, 40);
	c2 = Circle(200, 50, 40);

	arquivo_desenha_circle(&c1);
	arquivo_desenha_circle(&c2);

	Point p1, p2;
	p1 = Point(50, 50);
	p2 = Point(200, 50);

	Line* linha;
	linha = new Line(p1, p2);
	arquivo_desenha_linha(linha);

	arquivo_close();
}

