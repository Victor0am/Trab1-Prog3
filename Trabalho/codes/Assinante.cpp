#include "../bibliotecas/Assinante.hpp"
using namespace std;
Assinante::Assinante(){

}
Assinante::Assinante(string nome, int codigo):Usuario(nome, codigo){
}
void Assinante::imprimeFavoritos(){
    vector<Midia*>::iterator it = this->Favoritos.begin();
    while(it!= this->Favoritos.end()){
        //printar os negócios do jeito que ela pedir
        it++;
    }
}
void Assinante::inserirFavorito(Midia* favorito){
    this->Favoritos.push_back(favorito);
}
void Assinante::removerFavorito(){
    Midia* favorito;
    this->Favoritos.pop_back();
}
// void Assinante::imprimeNoArquivo(ofstream &outfile);