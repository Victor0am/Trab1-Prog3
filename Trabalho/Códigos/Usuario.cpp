#include <../Bibliotecas/Usuario.hpp>
using namespace std;
string Usuario::getnome(){
    return this->nome;
}

void Usuario::setnome(string nome){
    this->nome = nome;
}
string Usuario::getcodigo(){
    return this->codigo;
}

void Usuario::setcodigo(string codigo){
    this->codigo = codigo;
}