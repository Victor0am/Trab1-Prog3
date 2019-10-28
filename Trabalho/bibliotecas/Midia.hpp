#ifndef _MIDIA_HPP
#define _MIDIA_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Genero.hpp"
// #include "Produtor.hpp"
//#include "Assinante.hpp"
//#include "PlataformaDigital.hpp"
using namespace std;
class Midia{
    protected:
        int codigo;
        int vezesFavoritado;
        string nome;
        string nome_low;
        string backup;
        float duracao;
        int anoLancamento;
        char tipo;
        string duracao_virgula;
        // vector<Produtor*> produtores;
        //vector<Assinante *> assinantes;
        Genero genero;
    public:
        static int qtdProdutos;
        static void imprimeQtdProdutos();
        Midia();
        ~Midia();
        // Midia(string nome, int codigo, Genero genero, float duracao);
        Midia(string nome, int codigo, Genero genero, float duracao, char tipo);
        virtual void imprimeInfoMidia() = 0;
        // virtual void imprimeNoArquivo(ofstream &outfile) = 0;
        string getnome();
        void setnome(string nome);
        int getcodigo();
        void setcodigo(int codigo);
        float getduracao();
        string getnome_low();
        void setnome_low();
        void setduracao(float duracao);
        string getduracao_virgula();
        void setduracao_virgula(string duracao);
        int getanoLancamento();
        void setbackup(string backup);
        string getbackup();
        void setanoLancamento(int anoLancamento);
        Genero getgenero();
        void foiFavoritado();
        // void setprodutores(Produtor * p);
        void setgenero(Genero genero);
        char gettipo();
        void settipo(char tipo);
        string getnometipo();
        int getvezesFavoritado();
        void setvezesFavoritado();
        // string duracao_virgula();
        // void formataDuracao();
};
// int Midia::qtdProdutos = 0;

#endif