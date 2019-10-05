#ifndef _MIDIA_HPP
#define _MIDIA_HPP
#include <iostream>
#include <string>

class Midia{
    protected:
        string nome;
        int codigo;
        int duracao;
        int anoLancamento;
    public:
        static int qtdProdutos;
        static void imprimeQtdProdutos();
        Midia();
        Midia(string nome, int codigo, Genero genero);
        void imprimeInfoProduto();
        imprimeNoArquivo(ofstream &outfile);
        string getnome();
        void setnome(string nome);
        int getcodigo();
        void getcodigo(int codigo);
        int getduracao();
        void setduracao(int duracao);
        int getanoLancamento();
        void setanoLancameot(int anoLancamento);
};

#endif