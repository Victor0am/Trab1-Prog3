#ifndef _ARTISTA_HPP
#define _ARTISTA_HPP
#include "Produtor.hpp"
#include "Album.hpp"
#include <vector>
using namespace std;

class Artista:Produtor{
    private:
        //vector<Album*> AlbumsLancados;
    public:
        Artista(string nome, int codigo);
        void imprimirNoArquivo(ofstream &outfile);
        //void lancarAlbum(Album* album);
};

#endif