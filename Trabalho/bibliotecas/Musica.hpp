#ifndef _MUSICA_HPP
#define _MUSICA_HPP
#include "Midia.hpp"
using namespace std;

class Musica: public Midia{
    private:
        void formataDuracao();
    public:
        Musica();
        Musica(string nome, Genero gen, int duracao, int anoLancamento);
        void imprimeinfoProduto();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif