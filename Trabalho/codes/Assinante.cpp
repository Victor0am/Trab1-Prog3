#include "../Bibliotecas/Assinante.hpp"
using namespace std;
Assinante::Assinante(){

}
Assinante::Assinante(string nome, int codigo){
    setnome(nome);
    setcodigo(codigo);

}
void Assinante::imprimeFavorito();
void Assinante::inserirFavorito(Midia * favorito);
void Assinante::removerFavorito();
void Assinante::imprimeNoArquivo(ofstream &outfile);