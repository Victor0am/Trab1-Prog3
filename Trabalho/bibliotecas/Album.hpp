#ifndef _ALBUM_HPP
#define _ALBUM_HPP
#include<iostream>
#include <string>
// #include "Artista.hpp"
#include "Musica.hpp"
#include <vector>
using namespace std;

class Album{
    private:
        string nome;
        float duracao;
        int codigo;
        int anoLancamento;
        int qtdMusicas;
        // Produtor artista;
        vector<Musica*> Musicas;
    public:
        string getnome();
        void setnome(string nome);
        int getduracao();
        void setduracao(int duracao);
        int getqtdMusicas();
        void setqtdMusicas(int qtdMusicas);
        int getanoLancamento();
        void setanoLancamento(int anoLancamento);
        Album();
        Album(string nome, int codigo, int anoLancamento);
        void imprimeNoArquivo(ofstream &outfile);
        void musicaNoAlbum(Musica * musica);
};

#endif