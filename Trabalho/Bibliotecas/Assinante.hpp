#ifndef _ASSINANTE_HPP
#define _ASSINANTE_HPP
#include "Usuario.hpp"
using namespace std;

class Assinante:Usuario{
    public:
        Assinante();
        Assinante(string nome, int codigo);
        void imprimeFavoritos();
        void inserirFavorito(Midia * favorito);
        void removorFavorito();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif