#ifndef _MUSICA_HPP
#define _MUSICA_HPP
#include "Midia.hpp"

using namespace std;

class Musica: public Midia{
    private:
        // Album* album;
        
    public:
        Musica();
        Musica(string nome, Genero gen, float duracao, int anoLancamento);
        void imprimeInfoMidia();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif