#include "Idioma.h"

    int Idioma::getcodigo(){
        return this->codigo;
    }
    void Idioma::setcodigo(int codigo){
        this->codigo = codigo;
    }
    string Idioma::getnome(){
        return this->nome;
    }
    void Idioma::setnome(string nome){
        this->nome = nome;
    }