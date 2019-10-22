#include "Matricula.h"
    int Matricula::getcodigo(){
        return this->codigo;
    }
    void Matricula::setcodigo(int codigo){
        this->codigo = codigo;
    }
    int Matricula::getnota(){
        return this->codigo;
    }
    void Matricula::setnota(int nota){
        this->nota = nota;
    }
    string Matricula::getsituacao(){
        return this->situacao;
    }
    void Matricula::setsituacao(string situacao){
        this->situacao = situacao;
    }
    tm getDiaMatricula(){
        return this->DiaMatricula;
    }
    void setDiaMatricula(){
        time_t tt;
        time(&tt);
        tm dataAtual = *localtime(&tt);
        this->DiaMatricula = dataAtual;
    }