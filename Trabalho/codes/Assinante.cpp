#include "../bibliotecas/Assinante.hpp"
using namespace std;
Assinante::Assinante(){

}
Assinante::Assinante(string nome, int codigo, char tipo):Usuario(nome, codigo, tipo){
}
void Assinante::imprimeFavoritos(){
    for(Midia* m : fav){
        m->imprimeInfoMidia();
    }
}
void Assinante::inserirFavorito(Midia* favorito){
    this->fav.push_back(favorito);
}
void Assinante::removerFavorito(){
    Midia* favorito;
    this->fav.pop_back();
}


list <Midia*> Assinante::getFavoritos2(){
    return this->fav;
}

void Assinante::ordenaFavoritos(){
    fav.sort([](Midia * lhs, Midia * rhs) {return lhs->getcodigo() > rhs->getcodigo();});
    fav.sort([](Midia * lhs, Midia * rhs) {return lhs->gettipo() < rhs->gettipo();});
    fav.reverse();
}
Assinante::~Assinante(){
    
}
