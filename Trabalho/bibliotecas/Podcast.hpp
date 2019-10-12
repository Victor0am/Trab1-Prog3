#ifndef _PODCAST_HPP
#define _PODCAST_HPP
#include "Midia.hpp"
using namespace std;

class Podcast:Midia{
    private:
        int qtdTemporadas;
    public:
        Podcast();
        Podcast(string nome, Genero gen, int duracao, int anoLancamento);
        void imprimeinfoProduto();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif