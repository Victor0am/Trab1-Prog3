#ifndef _PRODUTOR_HPP
#define _PRODUTOR_HPP
#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>
//#include "PlataformaDigital.hpp"
using namespace std;

class Produtor: public Usuario{
    private:
        vector<Midia*> produtosDesenvolvidos;
        //PlataformaDigital Plat;
    public:
        Produtor();
        Produtor(string nome,int codigo);
        void imprimeNoArquivo(ofstream &outfile);
        void imprimeProdutosDesenvolvidos();
        void desenvolverProdutos(Midia* midia);
};


#endif