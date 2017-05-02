#include <iostream>
#include <cmath>

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
    distanceTo(Point* pvet){
        double dis = std::sqrt(pow((pvet->x - x),2) + pow((pvet->y - y),2));
        return dis;
    }
};

int main(){
    int i;
    //crie um ponto p alocado estaticamente, usando o construtor não-default;
    Point p1;
    p1 = Point(1, 2);

    //crie um array de 5 pontos alocados dinamicamente, com new, também usando o construtor não-default;
    Point* pvet[5];
    pvet[0] = new Point(12, 5);
    pvet[1] = new Point(7, 2);
    pvet[2] = new Point(10, 10);
    pvet[3] = new Point(5, 5);
    pvet[4] = new Point(13, 15);

    //calcule e mostre a distância entre o ponto p e cada um dos pontos do array;
    for(i = 0; i < 5; i++){
        std::cout << "Distancia entre o ponto p1 e os pontos do vetor:" << p1.distanceTo(pvet[i]) << std::endl;
    }

    //destrua os pontos criados dinamicamente;
    for(i = 0; i < 5; i++){
        delete pvet[i];
    }

    return 0;
}
