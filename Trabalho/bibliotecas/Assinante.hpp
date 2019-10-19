#ifndef _ASSINANTE_HPP
#define _ASSINANTE_HPP
#include <vector>
#include <string>
#include "Usuario.hpp"
#include "Midia.hpp"
#include "PlataformaDigital.hpp"
using namespace std;

class Assinante:Usuario{
    private:
        vector<Midia*> Favoritos;
    public:
        Assinante();
        Assinante(string nome, int codigo);
        void imprimeFavoritos();
        void inserirFavorito(Midia* favorito);
        void removerFavorito();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif