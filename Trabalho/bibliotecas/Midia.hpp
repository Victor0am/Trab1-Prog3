#ifndef _MIDIA_HPP
#define _MIDIA_HPP
#include <iostream>
#include <string>
#include <vector>
//#include "Produtor.hpp"
#include "Genero.hpp"
//#include "Assinante.hpp"
//#include "PlataformaDigital.hpp"
using namespace std;
class Midia{
    protected:
        string nome;
        int codigo;
        int duracao;
        int anoLancamento;
        //vector<Produtor *> produtores;
        //vector<Assinante *> assinantes;
        Genero genero;
    public:
        static int qtdProdutos;
        static void imprimeQtdProdutos();
        Midia();
        Midia(string nome, int codigo, Genero genero);
        void imprimeInfoProduto();
        void imprimeNoArquivo(ofstream &outfile);
        string getnome();
        void setnome(string nome);
        int getcodigo();
        void setcodigo(int codigo);
        int getduracao();
        void setduracao(int duracao);
        int getanoLancamento();
        void setanoLancamento(int anoLancamento);
        // void formataDuracao();
};
// int Midia::qtdProdutos = 0;

#endif