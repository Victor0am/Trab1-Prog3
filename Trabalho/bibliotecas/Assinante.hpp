#ifndef _ASSINANTE_HPP
#define _ASSINANTE_HPP
#include <vector>
#include <list>
#include <string>
#include "Usuario.hpp"
#include "Midia.hpp"

using namespace std;

class Assinante: public Usuario{
    private:
        list<Midia*> fav;
    public:
        Assinante();
        ~Assinante();
        Assinante(string nome, int codigo, char tipo);
        void imprimeFavoritos();
        void inserirFavorito(Midia* favorito);
        void removerFavorito();
        void imprimeNoArquivo(ofstream &outfile);
        void ordenaFavoritos();
        list <Midia*> getFavoritos2();
};

#endif