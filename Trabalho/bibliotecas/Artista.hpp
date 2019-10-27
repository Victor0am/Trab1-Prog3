#ifndef _ARTISTA_HPP
#define _ARTISTA_HPP
#include <vector>
#include "Produtor.hpp"
// #include "Musica.hpp"
using namespace std;

class Artista: public Produtor{
    private:
        // vector<Musica* > musicasLancadas;
    public:
        Artista(string nome, int codigo);
        void imprimirNoArquivo(ofstream &outfile);
        // void produzir(Midia* m);
};

#endif