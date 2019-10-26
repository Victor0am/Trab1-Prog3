#ifndef _MUSICA_HPP
#define _MUSICA_HPP
#include "Midia.hpp"

using namespace std;

class Musica: public Midia{
    private:
        // Album* album;
        
    public:
        Musica();
        Musica(string nome, int codigo, float duracao, int anoLancamento, char tipo);
        void imprimeInfoMidia();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif