#ifndef _ARTISTA_HPP
#define _ARTISTA_HPP
#include "Produtor.hpp"
using namespace std;

class Artista:Produtor{
    Artista(string nome, int codigo);
    void imprimirNoArquivo(ofstream &outfile);
};

#endif