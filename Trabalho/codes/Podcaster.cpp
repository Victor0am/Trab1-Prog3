#include "../Bibliotecas/Podcaster.hpp"
void Podcaster:Podcaster(string nome, int codigo){
    Podcaster:Produtor(nome, codigo);
}
void Podcaster:imprimirNoArquivo(ofstream &outfile);