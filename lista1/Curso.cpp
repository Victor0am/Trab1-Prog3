#include "Curso.h"

    int Curso::getcodigo(){
        return this->codigo;
    }
    void Curso::setcodigo(int codigo){
        this->codigo = codigo;
    }
    string Curso::getnome(){
        return this->nome;
    }
    void Curso::setnome(string nome){
        this->nome = nome;
    }