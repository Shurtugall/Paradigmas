#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "window.h"
#include <FL/fl_ask.H>

using namespace std;

class Dados{
protected:
    string label;
    string id;
public:
    Dados(string label, string id){
        this->label = label;
        this->id = id;
    }
    string get_label(){
        return label;
    }
    string get_id(){
        return id;
    }

    string set_label(string label){
        this->label = label;
    }
    string set_id(string id){
        this->id = id;
    }
};

class Gerador: public UserInterface{
protected:
    vector<Dados> dados;
    string titulo;
public:
    Gerador(){
        botao_clear->callback((Fl_Callback*) func_botao_clear, (void*)(this));
        botao_update->callback((Fl_Callback*) func_botao_update, (void*)(this));
        botao_delete->callback((Fl_Callback*) func_botao_delete, (void*)(this));
        botao_insert->callback((Fl_Callback*) func_botao_insert, (void*)(this));
        botao_import->callback((Fl_Callback*) func_botao_import, (void*)(this));
        botao_export->callback((Fl_Callback*) func_botao_export, (void*)(this));
        botao_generate->callback((Fl_Callback*) func_botao_generate, (void*)(this));
        browser->callback((Fl_Callback*) func_browser, (void*)(this));
        botao_seta_titulo->callback((Fl_Callback*) func_botao_seta_titulo, (void*)(this));
    }

    static void func_browser(Fl_Widget* Btn, void* userdata){
        Gerador* prog = static_cast<Gerador*>(userdata);
        int indice = prog->browser->value();
        prog->inputLabel->value(prog->dados[indice-1].get_label().c_str());
        prog->inputId->value(prog->dados[indice-1].get_id().c_str());
    }

    static void func_botao_clear(Fl_Widget* Btn, void* userdata){
        Gerador* prog = static_cast<Gerador*>(userdata);
        prog->inputTitle->value("");
        prog->inputLabel->value("");
        prog->inputId->value("");
    }

    static void func_botao_update(Fl_Widget* Btn, void* userdata){
        Gerador* prog = static_cast<Gerador*>(userdata);
        int indice = prog->browser->value();
        cout << indice << endl;
        if(indice > 0){
            string label = string(prog->inputLabel->value());
            string id = string(prog->inputId->value());
            if(label != "" && id != ""){
                prog->dados[indice-1].set_label(label);
                prog->dados[indice-1].set_id(id);
                prog->browser->text(indice, (id, + " | " + label).c_str());
            }
        }
    }

    static void func_botao_insert(Fl_Widget* Btn, void* userdata){
        Gerador* prog = static_cast<Gerador*>(userdata);
        string label = string(prog->inputLabel->value());
        string id = string(prog->inputId->value());
        if(label == "" && id == ""){
            fl_alert("Digite algo nos campos label e string");
        }
        else if(label != "" && id != ""){
            prog->dados.push_back(Dados(label, id));
            prog->browser->add((id + " | " + label).c_str());
        }
    }

    static void func_botao_delete(Fl_Widget* Btn, void* userdata){
        Gerador* prog = static_cast<Gerador*>(userdata);
        int indice = prog->browser->value();
        if(indice > 0){
            prog->dados.erase(prog->dados.begin() + indice-1);
            prog->browser->remove(indice);
            prog->inputLabel->value("");
            prog->inputId->value("");
        }
    }

    static void func_botao_import(Fl_Widget* Btn, void* userdata){
        Gerador* prog = static_cast<Gerador*>(userdata);
        string arquivo = string(prog->inputFile->value());
        ifstream entrada(arquivo + ".csv");
        if(entrada.is_open()){
            for(auto aux = prog->dados.size() -1; aux >= 0; aux--){
                prog->dados.pop_back();
                prog->browser->remove(aux+1);
            }
            //prog->titulo = "";
            prog->caixa_titulo->label("");

            string linha;
            string aux[2];
            getline(entrada, linha);
            prog->titulo = linha;
            while(!entrada.eof()){
                getline(entrada, linha);
                if(!linha.empty()){
                    stringstream linestream(linha);
                    getline(linestream, aux[0], '|');
                    getline(linestream, aux[1], '|');
                    prog->dados.push_back(Dados(aux[1], aux[0]));
                }
            }
            //prog->caixa_titulo->label((prog->titulo).c_str());
            for(auto i = 0; i < prog->dados.size(); i++){
                prog->browser->add((prog->dados[i].get_id() + " | " + prog->dados[i].get_label()).c_str());
            }
        }
        else{
            fl_alert("Erro na leitura de arquivo");
        }
    }

    static void func_botao_export(Fl_Widget* Btn, void* userdata){
        Gerador* prog = static_cast<Gerador*>(userdata);
        string arquivo = string(prog->inputFile->value());
        if(arquivo != ""){
            if(prog->titulo == ""){
                fl_alert("Insira um titulo no campo válido e clique em set title");
            }
            else{
                ofstream saida(arquivo + ".csv");
                saida << prog->titulo << endl;
                for(auto i = 0; i < prog->dados.size(); i++){
                    saida << prog->dados[i].get_id() << "|" << prog->dados[i].get_label() << endl;
                }
            }
        }
        else{
            fl_alert("Digite o nome do arquivo no campo file name");
        }
    }

    static void func_botao_seta_titulo(Fl_Widget* Btn, void* userdata){
        Gerador* prog = static_cast<Gerador*>(userdata);
        if(prog->inputTitle->value() != ""){
            prog->caixa_titulo->label(prog->inputTitle->value());
            prog->titulo = string(prog->inputTitle->value());
        }
    }

    static void func_botao_generate(Fl_Widget* Btn, void* userdata){
        Gerador* prog = static_cast<Gerador*>(userdata);
        ofstream saida("index.html");
        ifstream entrada("template.html");
        if(entrada.is_open()){
            string linha;
            while(!entrada.eof()){
                getline(entrada, linha);
                if(linha == ">>>1<<<"){
                    //prog->modifica_1(saida);
                    saida << "<title>" << prog->titulo << "</title>" << endl;
                }
                else if(linha == ">>>2<<<"){
                    //prog->modifica_2(saida);
                    saida << "<h1>" << prog->titulo << "</h1>" << endl;
                }
                else if(linha == ">>>3<<<"){
                    prog->modifica_3(saida);
                }
                else if(linha == ">>>4<<<"){
                    prog->modifica_4(saida);
                }
                else if(linha == ">>>5<<<"){
                    prog->modifica_5(saida);
                }
                else if(linha == ">>>6<<<"){
                    prog->modifica_6(saida);
                }
                else if(linha == ">>>7<<<"){
                    prog->modifica_7(saida);
                }
                else{
                    saida << linha << endl;
                }
            }
        }
    }

    /*static void modifica_1(ofstream &saida){
        saida << "<title>" << prog->titulo << "</title>" << endl;
    }

    static void modifica_2(ofstream &saida){
        saida << "<h1>" << prog->titulo << "</h1>" << endl;
    }*/

    void modifica_3(ofstream &saida){
        for(int i = 0; i < dados.size(); i++){
            saida << "<div class=\"form-group\">\n"
            << "<label for=\"" << dados[i].get_id() << "\" class=\"col-sm-2 control-label\">" << dados[i].get_label() << "</label>\n"
            << "<div class=\"col-sm-6\">\n"
            << "<input type=\"text\" class=\"form-control validate[required]\" id=\"" << dados[i].get_id() << "\" placeholder=\"" << dados[i].get_label() << "\">\n"
            << "</div>\n"
            << "</div>\n";
        }
    }


    void modifica_4(ofstream &saida){
        saida << "dataSet[seq]=[index,icons";
        for(int i = 0; i < dados.size(); i++){
            saida << ", " << dados[i].get_id();
        }
        saida << "];\n";
    }

    void modifica_5(ofstream &saida){
        saida << "oTable=$('#table').dataTable({\n"
        <<"\"data\": dataSet,\n"
        <<"\"columns\": [\n"
        <<"{ \"title\": \"Seq\", \"class\": \"center\" },\n"
        <<"{ \"title\": \"\", \"class\": \"center\" },\n";
        for(int i = 0; i < dados.size(); i++){
            saida << "{\"title\": \"" << dados[i].get_label() << "\"},\n";
        }
        saida << "]\n" << "});\n";
    }

    void modifica_6(ofstream &saida){
        saida << "$('#table tbody').on( 'click', '.glyphicon-edit', function () {\n"
        << "$('#list').hide();\n"
        << "var rows = $(this).parents('tr').children();\n"
        << "$('#seq').text(rows[0].innerHTML);\n";
        for(int i = 0; i < dados.size(); i++){
            saida << "$('#" << dados[i].get_id() << "').val(rows[" << i+2 << "].innerHTML);\n";
        }
        saida << "$('#formID').show()\n;" << "} );";
    }

    void modifica_7(ofstream &saida){
        saida << "function save() {\n" << "var seq=$('#seq').text();\n"
        << "if ( isNaN(seq) ) { seq=0; }\n" << "var key=formId+\"_\"+seq;\n" << "var object={\n";
        for(int i = 0; i < dados.size(); i++){
            saida <<  "\"" << dados[i].get_id() << "\": $(\"#" <<dados[i].get_id() << "\").val(),\n";
        }
        saida <<"}\n"<< "localStorage.setItem(key, JSON.stringify(object));\n" << "}\n";
    }

    void show(){
        w->show();
    }
};

int main(){
    Gerador prog;
    prog.show();
    return Fl::run();
}
