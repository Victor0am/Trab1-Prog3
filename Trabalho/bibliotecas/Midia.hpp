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
        float duracao;
        int anoLancamento;
        //vector<Produtor *> produtores;
        //vector<Assinante *> assinantes;
        Genero genero;
    public:
        static int qtdProdutos;
        static void imprimeQtdProdutos();
        Midia();
        Midia(string nome, int codigo, Genero genero);
        void imprimeInfoMidia() = 0;
        void imprimeNoArquivo(ofstream &outfile) = 0;
        string getnome();
        void setnome(string nome);
        int getcodigo();
        void setcodigo(int codigo);
        float getduracao();
        void setduracao(float duracao);
        int getanoLancamento();
        void setanoLancamento(int anoLancamento);
        // void formataDuracao();
};
// int Midia::qtdProdutos = 0;

#endif