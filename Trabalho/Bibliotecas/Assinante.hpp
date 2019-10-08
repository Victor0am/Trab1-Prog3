#ifndef _ASSINANTE_HPP
#define _ASSINANTE_HPP
#include "Usuario.hpp"
#include <vector>
#include "Midia.hpp"
#include "PlatagformaDigital.hpp"
using namespace std;

class Assinante:Usuario{
    private:
        vector<Midia*> Favoritos;
        PlatagformaDigital Plat;
    public:
        Assinante();
        Assinante(string nome, int codigo);
        void imprimeFavoritos();
        void inserirFavorito(Midia * favorito);
        void removorFavorito();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif