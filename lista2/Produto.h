#ifndef _PRODUTO_H
#define _PRODUTO_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Produto{
    private:
        string nome;
        string descricao;
        int codigo;
        int quantidadeEstoque;
        float precoBase;

    public:
        static int qtdProdutos;
        string getnome();
        void setnome(string nome);
        int getcodigo();
        void setcodigo(int codigo);
        string getcdescricao();
        void getdescricao(string descricao);
        int getquantidadeEstoque();
        void setquantidadeEstoque(int quantidadeEstoque);
        float getprecoBase();
        void setprecoBase(float precoBase);
};

#endif