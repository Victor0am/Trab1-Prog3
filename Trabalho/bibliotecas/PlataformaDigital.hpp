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
#include "Usuario.hpp"
using namespace std;

class PlataformaDigital{
    private:
        string nome;
        // vector<Produtor*> produtoresCadastrados;
        // vector<Assinante*> assinantesCadastrados;
        // vector<Midia*> midiasCadastradas;
        vector<Genero*> generosCadastrados;
        vector<Usuario*> usuariosCadastrados;
    public:
        PlataformaDigital();
        PlataformaDigital(string nome);
        void setnome(string nome);
        string getnome();
        vector<Genero*> getgenero();
        vector<Usuario*> getusuario();
        void carregaArquivoUsuarios(ifstream &infile);
        void carregaArquivoGeneros(ifstream &infile);
        // void imprimeProdutos(string genero);
        // void imprimeAssinantes();
        // void inserirAssinante(Assinante* a);
        // void removerAssinante(Assinante* a);
        // void inserirProduto(Midia* novoProduto, vector<Produtor*> produtores);
        // void imprimeNoArquivo(ofstream &outfile);
        // void carregaArquivoMidia(ifstream &infile);
        // void carregaArquivoFavoritos(ifstream &infile);
        // void exportarBiblioteca();
        // void gerarRelatorios();
};

#endif