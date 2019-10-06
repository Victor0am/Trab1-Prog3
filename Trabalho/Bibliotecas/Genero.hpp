#ifndef _GENERO_HPP
#define _GENERO_HPP
#include <string>
#include <iostream>

class Genero{
    private:
        string nome;
        string sigla;
    public:
        Genero();
        Genero(string nome, string sigla);
        string getnome();
        void setnome(string nome);
        string getsigla();
        void setsigla(string sigla);
};

#endif