#ifndef _PRODUTOR_HPP
#define _PRODUTOR_HPP
#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>
#include "PlataformaDigital.hpp"
using namespace std;

class Produtor:Usuario{
    private:
        vector<Midia*> produtosDesenvolvidos;
        PlataformaDigital Plat;
    public:
        Produtor();
        Produtor(string nome,int codigo);
        void imprimeNoArquivo(ofstream &outfile);
        void imprimeProdutosDesenvolvidos();
};


#endif