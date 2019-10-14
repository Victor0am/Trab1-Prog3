#ifndef _ASSINANTE_HPP
#define _ASSINANTE_HPP
#include "Usuario.hpp"
#include <vector>
#include "Midia.hpp"
#include "PlataformaDigital.hpp"
using namespace std;

class Assinante:Usuario{
    private:
        vector<Midia*> Favoritos;
        PlataformaDigital Plat;//pode ser retirado(?)
    public:
        Assinante();
        Assinante(string nome, int codigo);
        void imprimeFavoritos();
        void inserirFavorito(Midia * favorito);
        void removerFavorito();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif