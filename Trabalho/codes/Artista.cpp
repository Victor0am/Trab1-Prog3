#include "../bibliotecas/Artista.hpp"
Artista::Artista(string nome, int codigo, char tipo): Produtor(nome, codigo, tipo){
    
}
void Artista::lancarAlbum(Album*album){
    albumsLancados.push_back(album);
}

Artista::~Artista(){
    for(Album * a: albumsLancados){
        delete a;
    }
}

void Artista::imprimirNoArquivo(ofstream &outfile){
    
}