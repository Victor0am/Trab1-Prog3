#ifndef _PRODUTOR_HPP
#define _PRODUTOR_HPP
#include "Usuario.hpp"
using namespace std;

class Produtor:Usuario{
    public:
        Produtor();
        Produtor(string nome,int codigo);
        void imprimeNoArquivo(ofstream &outfile);
        void imprimeProdutosDesenvolvidos();
};


#endif