#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Pontuacao{
private:
    int sword;
    int bow;
    int axe;
public:
    Pontuacao(){
        sword = 0;
        bow = 0;
        axe = 0;
    }
    Pontuacao(int s, int b, int a){
        sword = s;
        bow = b;
        axe = a;
    }
    int get_sword_func(){
        return sword;
    }
    int get_bow_func(){
        return bow;
    }
    int get_axe_func(){
        return axe;
    }
    int get_total_func(){
        return (sword+bow+axe);
    }
};

class Person{
private:
    string nome;
    Pontuacao p;
    int total;

public:
    Person(){
        nome = "";
        p = Pontuacao();
        total = 0;
    }
    Person(string n, int s, int b, int a){
        nome = n;
        p = Pontuacao(s, b, a);
        total = p.get_total_func();
    }
    string get_nome(){
        return nome;
    }
    int get_sword(){
        return p.get_sword_func();
    }
    int get_bow(){
        return p.get_bow_func();
    }
    int get_axe(){
        return p.get_axe_func();
    }
    int get_total(){
        return total;
    }
};

bool cmpPersonName(Person& p1, Person& p2) {
   return p1.get_nome() < p2.get_nome();
}

bool cmpPersonTotal(Person& p1, Person& p2) {
   return p1.get_total() < p2.get_total();
}

bool cmpPersonAtividades(Person& p){
     p1.get_sword < p2.get_total();
}

int main(){
    ifstream entrada("entrada.csv");
    if(!entrada.is_open()){
        cout << "Erro ao ler arquivo" << endl;
        return -1;
    }

    std::vector<Person> pessoa;
    while(!entrada.eof()){
        int s, b, a;
        string nome, auxiliar;
        for(auto i = 0; i < 16; i++){
            getline(entrada, auxiliar, '|');
            nome = auxiliar;

            getline(entrada, auxiliar, '|');

            getline(entrada, auxiliar, '|');
            s = atoi(auxiliar.c_str());

            getline(entrada, auxiliar, '|');

            getline(entrada, auxiliar, '|');
            b = atoi(auxiliar.c_str());

            getline(entrada, auxiliar, '|');

            getline(entrada, auxiliar);
            a = atoi(auxiliar.c_str());

            pessoa.push_back(Person(nome, s, b, a));
        }
    }

    std::vector<Person>::iterator it;
    /*
    std:cout<< "VALORES DAS NOTAS" << endl;
    for (it = pessoa.begin(); it != pessoa.end(); it++){
        std::cout<< it->get_nome() << " ";
        std::cout<< "|" << "Total de pontos:" << " ";
        std::cout<< it->get_total() << " ";
        std::cout << std::endl;
    }

    cout << endl;
    */
    cout<< "ORDENADO ALFABETICAMENTE" << endl << endl;
    std::sort(pessoa.begin(), pessoa.end(), cmpPersonName);
    for (it = pessoa.begin(); it != pessoa.end(); it++){
        std::cout<< it->get_nome() << " ";
        std::cout<< "|" << "Total de pontos:" << " ";
        std::cout<< it->get_total() << " ";
        std::cout << std::endl;
    }

    cout<< "ORDENADO POR ORDEM DE PONTUAÇÃO" << endl << endl;
    std::sort(pessoa.begin(), pessoa.end(), cmpPersonTotal);
    for (it = pessoa.begin(); it != pessoa.end(); it++){
        std::cout<< it->get_nome() << " ";
        std::cout<< "|" << "Total de pontos:" << " ";
        std::cout<< it->get_total() << " ";
        std::cout << std::endl;
    }



    return 0;




}
