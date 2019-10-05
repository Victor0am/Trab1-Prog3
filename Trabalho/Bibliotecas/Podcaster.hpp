#ifndef _PODCASTER_HPP
#define _PODCASTER_HPP
#include "Produtor.hpp"
using namespace std;

class Podcaster:Produtor{
    void Podcaster(string nome, int codigo);
    void imprimirNoArquivo(ofstream &outfile);
};

#endif