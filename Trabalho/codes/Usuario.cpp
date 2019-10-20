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
    //colocar algo que não sabemos ainda se precisa.
}
Usuario::Usuario(string _nome, int codigo){
    this->setnome(_nome);
    this->setcodigo(codigo);
}
void Usuario::imprimeNoArquivo(ofstream &outfile){
    outfile << this->codigo << ";";
    outfile << this->nome << endl;
}