#include "../bibliotecas/Artista.hpp"
Artista::Artista(string nome, int codigo): Produtor(nome, codigo){
}
void Artista::lancarAlbum(Album*album){
    albumsLancados.push_back(album);
}


void Artista::imprimirNoArquivo(ofstream &outfile){
    
}