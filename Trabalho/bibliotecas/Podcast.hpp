#ifndef _PODCAST_HPP
#define _PODCAST_HPP
#include "Midia.hpp"
using namespace std;

class Podcast:public Midia{
    private:
        int qtdTemporadas;
    public:
        Podcast();
        Podcast(int codigo, string nome, float duracao, int anoLancamento, int qtdTemporadas);
        void imprimeInfoMidia();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif