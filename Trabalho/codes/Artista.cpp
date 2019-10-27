#include "../bibliotecas/Artista.hpp"
Artista::Artista(string nome, int codigo): Produtor(nome, codigo){
    
}
void Artista::lancarAlbum(Album*album){
    albumsLancados.push_back(album);
}

Artista::~Artista(){
    
}

void Artista::imprimirNoArquivo(ofstream &outfile){
    
}