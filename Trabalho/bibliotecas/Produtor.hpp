#ifndef _PRODUTOR_HPP
#define _PRODUTOR_HPP
#include <vector>
#include <algorithm>
#include "Usuario.hpp"
#include "Midia.hpp"
using namespace std;

class Produtor: public Usuario{
    private:
        vector<Midia*> produtosDesenvolvidos;
        int qtdLikes;
    public:
        Produtor();
        ~Produtor();
        Produtor(string nome,int codigo, char tipo);
        void imprimeNoArquivo(ofstream &outfile);
        void imprimeProdutosDesenvolvidos();
        vector<Midia *> getprodutosDesenvolvidos();
        void desenvolverProdutos(Midia* midia);
        void ordenaProdutos();
        void calculaLikes();
        void setqtdLikes();
        int getqtdLikes();
        char gettipo();
};


#endif