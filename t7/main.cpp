#include <string>
#include <FL/fl_ask.H>
#include "window.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Sorteio: public UserInterface{
protected:
    std::vector<int> vet_ganhador;
    int final = -2;
public:
    Sorteio(){
        reset->callback((Fl_Callback*) botao_reset, (void*)(this));
        button_sort->callback((Fl_Callback*) botao_sorteia, (void*)(this));
    }

    void show(){
        tela->show();
    }

    void set_valores_vetor(){
        int tam = std::stoi(participantes->value());
        for(int i = 0; i < tam; i++){
            vet_ganhador.push_back(i);
        }
        std::random_shuffle(vet_ganhador.begin(), vet_ganhador.end());
        final++;
    }
    void atualiza_valores(){
        numero_sorteado->copy_label(std::to_string(vet_ganhador[final]).c_str());
        std::string numero_ganhador;
        numero_ganhador = std::to_string(final + 1) + "º Ganhador";
        saida_ganhador->copy_label(numero_ganhador.c_str());
    }

    static void botao_sorteia(Fl_Widget* btn, void* userdata){
        Sorteio* prog = static_cast<Sorteio*>(userdata);
        if(strcmp(prog->participantes->value(), "") == 0){
            fl_alert("Não posso sortear :(\nDigite o numero de particpantes!");
        }
        else{
            if(prog->vet_ganhador.empty()){
                prog->set_valores_vetor();
            }
            if(prog->final + 1 >= prog->vet_ganhador.size()){
                fl_alert("Não existem mais números para serem sorteados");
            }
            else{
                prog->final++;
                prog->atualiza_valores();
            }
        }
    }

    static void botao_reset(Fl_Widget* btn, void* userdata) {
        Sorteio* prog = static_cast<Sorteio*>(userdata);
        prog->participantes->value("");
        prog->saida_ganhador->label("");
        prog->numero_sorteado->label("");
        prog->vet_ganhador.clear();
        prog->final = -2;
    }
};

int main(){
    Sorteio prog;
    prog.show();
    return Fl::run();
}

