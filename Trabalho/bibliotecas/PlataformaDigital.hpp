#ifndef _PLATAFORMADIGITAL_HPP
#define _PLATAFORMADIGITAL_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Artista.hpp"
#include "Assinante.hpp"
#include "Produtor.hpp"
#include "Genero.hpp"
#include "Midia.hpp"
#include "Podcaster.hpp"
#include "Usuario.hpp"
using namespace std;

class PlataformaDigital{
    private:
        string nome;
        vector<Artista*> artistasCadastrados;
        vector<Podcaster*> podcastersCadastrados;
        vector<Assinante*> assinantesCadastrados;
        vector<Midia*> midiasCadastradas;
        vector<Genero*> generosCadastrados;
        vector<Usuario*> usuariosCadastrados;
    public:
        PlataformaDigital();
        PlataformaDigital(string nome);
        void setnome(string nome);
        string getnome();
        vector<Genero*> getgenero();
        vector<Usuario*> getusuario();
        // vector<Assinante*> getassinante();
        void carregaArquivoUsuarios(ifstream &infile);
        void carregaArquivoGeneros(ifstream &infile);
        void carregaArquivoMidia(ifstream &infile);
        // void imprimeProdutos(string genero);
        void imprimeAssinantes();
        void inserirAssinante(Assinante* a);
        // void removerAssinante(Assinante* a);
        void imprimePodcasters();
        void cadastrarPodcaster(Podcaster* p);
        void imprimeArtistas();
        void cadastrarArtista(Artista* a);
        Genero sigla_genero(string sigla);
        void imprimeMidias();
        // void inserirProduto(Midia* novoProduto, vector<Produtor*> produtores);
        // void imprimeNoArquivo(ofstream &outfile);
        // void carregaArquivoFavoritos(ifstream &infile);
        // void exportarBiblioteca();
        // void gerarRelatorios();
};

#endif