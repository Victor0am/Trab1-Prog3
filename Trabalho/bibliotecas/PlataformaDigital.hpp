#ifndef _PLATAFORMADIGITAL_HPP
#define _PLATAFORMADIGITAL_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Assinante.hpp"
#include "Produtor.hpp"
#include "Genero.hpp"
#include "Midia.hpp"
using namespace std;

class PlataformaDigital{
    private:
        string nome;
    public:
        PlataformaDigital();
        PlataformaDigital(string nome);
        void imprimeProdutos(string genero);
        void imprimeAssinantes();
        void inserirAssinante(Assinante* a);
        void removerAssinante(Assinante* a);
        void inserirProduto(Midia* novoProduto, vector<Produtor*>produtores);
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivoUsuarios(ifstream &infile);
        void carregaArquivoGeneros(ifstream &infile);
        void carregaArquivoMidia(ifstream &infile);
        void carregaArquivoFavoritos(ifstream &infile);
        void exportarBiblioteca();
        void gerarRelatorios();
        string getnome();
        void setnome(string nome);
};

#endif