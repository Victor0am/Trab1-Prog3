#ifndef _ALBUM_HPP
#define _ALBUM_HPP
#include<iostream>
#include <string>
#include "Artista.hpp"
#include "Musica.hpp"
#include <vector>
using namespace std;

class Album{
    private:
        string nome;
        float duracao;
        int anoLancamento;
        int qtdMusicas;
        Artista artista;
        vector<Musica*> Musicas;
    public:
        string getnome();
        void setnome(string nome);
        float setduracao();
        void setduracao(float duracao);
        int getqtdMusicas();
        void setqtdMusicas(int qtdMusicas);
        int getanoLancamento();
        void setanoLancamento(int anoLancamento);
        Album();
        Album(string nome, float duracao, int anoLancamento, int qtdMusicas);
        imprimeNoArquivo(ofstream &outfile);
};

#endif