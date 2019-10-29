#ifndef _PLATAFORMADIGITAL_HPP
#define _PLATAFORMADIGITAL_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <list>
#include <sstream>
#include <algorithm>
#include "Artista.hpp"
#include "Assinante.hpp"
#include "Produtor.hpp"
#include "Genero.hpp"
#include "Midia.hpp"
#include "Podcaster.hpp"
#include "Usuario.hpp"
#include "Album.hpp"
using namespace std;

class PlataformaDigital{
    private:
        string nome;
        vector<Artista*> artistasCadastrados;
        vector<Produtor*> produtoresCadastrados;
        vector<Podcaster*> podcastersCadastrados;
        vector<Assinante*> assinantesCadastrados;
        vector<Midia*> midiasCadastradas;
        vector<Genero*> generosCadastrados;
        vector<Usuario*> usuariosCadastrados;
    public:
        PlataformaDigital();
        ~PlataformaDigital();
        PlataformaDigital(string nome);
        void setnome(string nome);
        string getnome();
        vector<Genero*> getgenero();
        vector<Usuario*> getusuario();
        Artista * getArtista(string produtor);
        // vector<Assinante*> getassinante();
        void carregaArquivoUsuarios(ifstream &infile);
        void carregaArquivoGeneros(ifstream &infile);
        void carregaArquivoMidia(ifstream &infile);
        void carregaArquivoFavoritos(ifstream &infile);
        // void imprimeProdutos(string genero);
        void imprimeAssinantes();
        void inserirAssinante(Assinante* a);
        // void removerAssinante(Assinante* a);
        void imprimePodcasters();
        void cadastrarPodcaster(Podcaster* p);
        void imprimeArtistas();
        void cadastrarArtista(Artista* a);
        void cadastrarProdutor(Produtor* p);
        void lista_produtores();
        Genero sigla_genero(string sigla);
        void codigo_produtor(string codigos, Midia * midia);
        void imprimeMidias();
        Midia* ProcuraMidia(int codigo);
        bool ingenero(string genero);
        bool inprodutores(int produtor);
        void verifica_produtor(string produtor);
        // void inserirProduto(Midia* novoProduto, vector<Produtor*> produtores);
        // void imprimeNoArquivo(ofstream &outfile);
        // void exportarBiblioteca();
        // void gerarRelatorios();

        //string
        void fix_string(string *s);
        //

        // Calculos
        void Horas_consumidas(ofstream &outfile);
        void G_mais_ouvido(ofstream &outfile);
        void midias_por_g(ofstream &outfile);
        void Top_midias(ofstream &outfile);
        void Top_produtores(ofstream &outfile);
        //arquivos
        void gerarRelatorios();
        void Estatisticas();
        void Backup();
        void lista_favoritos();
};

#endif