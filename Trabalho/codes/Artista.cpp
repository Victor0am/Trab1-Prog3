#include "../Bibliotecas/Artista.hpp"
void Artista:Artista(string nome, int codigo){
    Artista:Produtor(nome, codigo);
}
void Artista:imprimirNoArquivo(ofstream &outfile);