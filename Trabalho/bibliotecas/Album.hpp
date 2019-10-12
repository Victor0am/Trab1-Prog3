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
        int duracao;
        int anoLancamento;
        int qtdMusicas;
        Artista artista;
        vector<Musica*> Musicas;
    public:
        Album();
        Album(string nome, int duracao, int anoLancamento, int qtdMusicas);
        imprimeNoArquivo(ofstream &outfile);
};

#endif