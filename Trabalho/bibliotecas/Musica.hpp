#ifndef _MUSICA_HPP
#define _MUSICA_HPP
#include "Midia.hpp"

using namespace std;

class Musica: public Midia{        
    public:
        Musica();
        ~Musica();
        Musica(string nome, int codigo, float duracao, int anoLancamento, char tipo);
        void imprimeInfoMidia();

};

#endif