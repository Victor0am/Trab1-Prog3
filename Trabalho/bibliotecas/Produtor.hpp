#ifndef _PRODUTOR_HPP
#define _PRODUTOR_HPP
#include <vector>
#include <algorithm>
#include "Usuario.hpp"
#include "Midia.hpp"
//#include "PlataformaDigital.hpp"
using namespace std;

class Produtor: public Usuario{
    private:
        vector<Midia*> produtosDesenvolvidos;
        int qtdLikes;
        //PlataformaDigital Plat;
    public:
        Produtor();
        ~Produtor();
        Produtor(string nome,int codigo);
        void imprimeNoArquivo(ofstream &outfile);
        void imprimeProdutosDesenvolvidos();
        // virtual void produzir(Midia* m) = 0;
        vector<Midia *> getprodutosDesenvolvidos();
        void desenvolverProdutos(Midia* midia);
        void ordenaProdutos();
        void calculaLikes();
        int getqtdLikes();
};


#endif