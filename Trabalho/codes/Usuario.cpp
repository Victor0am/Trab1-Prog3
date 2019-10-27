#include "../bibliotecas/Usuario.hpp"

using namespace std;
string Usuario::getnome(){
    return this->nome;
}

void Usuario::setnome(string nome){
    this->nome = nome;
}
int Usuario::getcodigo(){
    return this->codigo;
}

void Usuario::setcodigo(int codigo){
    this->codigo = codigo;
}
Usuario::Usuario(){
}

Usuario::Usuario(string _nome, int codigo){
    this->setnome(_nome);
    this->setcodigo(codigo);
    setnomelow();
}
void Usuario::imprimeNoArquivo(ofstream &outfile){
    outfile << this->codigo << ";";
    outfile << this->nome << endl;
}
string Usuario::getnomelow(){
    return this->nome_low;
}
void Usuario::setnomelow(){
    nome_low = nome;
    for (int i = 0; i < this->nome_low.size(); i++){
        if(nome_low[i] >= 'A' && nome_low[i]<='Z'){
            nome_low[i]+=32;
        }
    }
}