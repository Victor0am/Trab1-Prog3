#ifndef _ARTISTA_HPP
#define _ARTISTA_HPP
#include <vector>
#include "Produtor.hpp"
#include "Album.hpp"
using namespace std;

class Artista: public Produtor{
    private:
        vector<Album*> albumsLancados;
    public:
        Artista(string nome, int codigo);
        ~Artista();
        void imprimirNoArquivo(ofstream &outfile);
        void lancarAlbum(Album*album);
        
};

#endif