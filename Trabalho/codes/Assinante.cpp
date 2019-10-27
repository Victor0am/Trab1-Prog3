#include "../bibliotecas/Assinante.hpp"
using namespace std;
Assinante::Assinante(){

}
Assinante::Assinante(string nome, int codigo):Usuario(nome, codigo){
}
void Assinante::imprimeFavoritos(){
    // if (Favoritos.empty()){
    //     return;
    // }
    int i = 1;
    vector<Midia*>::iterator it = this->Favoritos.begin();
    while(it!= this->Favoritos.end()){
        cout << i << "************" << endl;
        (*it)->imprimeInfoMidia();
        it++;
        i++;
    }
    // for(Midia* m : Favoritos){
    //     m->imprimeInfoMidia();
    // }
}
void Assinante::inserirFavorito(Midia* favorito){
    this->Favoritos.push_back(favorito);
    this->fav.push_back(favorito);
}
void Assinante::removerFavorito(){
    Midia* favorito;
    this->Favoritos.pop_back();
    // this->fav.pop_back();
}

vector <Midia*> Assinante::getFavoritos(){
    return this->Favoritos;
}
list <Midia*> Assinante::getFavoritos2(){
    return this->fav;
}

void Assinante::ordenaFavoritos(){
    // list<Midia*>::iterator it = this->fav.begin();
    // sort(Favoritos.begin(), Favoritos.end(), [](Midia * lhs, Midia * rhs) {return lhs->getcodigo() < rhs->getcodigo();});
    fav.sort([](Midia * lhs, Midia * rhs) {return lhs->getcodigo() > rhs->getcodigo();});
    fav.sort([](Midia * lhs, Midia * rhs) {return lhs->gettipo() < rhs->gettipo();});
    fav.reverse();
}
// void Assinante::imprimeNoArquivo(ofstream &outfile);