#ifndef _GENERO_HPP
#define _GENERO_HPP
#include <string>
#include <iostream>
//using namespace std;
class Genero{
    private:
        std::string nome;
        std::string sigla;
        int contador_de_favoritos;
    public:
        Genero(std::string nome, std::string sigla);
        Genero();
        std::string getnome();
        void setnome(std::string nome);
        std::string getsigla();
        void setsigla(std::string sigla);
        void imprimeGenero();
        void contaFavoritos();
        int getcontador();
};

#endif