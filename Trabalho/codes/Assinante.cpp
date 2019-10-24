#include "../bibliotecas/Assinante.hpp"
using namespace std;
Assinante::Assinante(){

}
Assinante::Assinante(string nome, int codigo):Usuario(nome, codigo){
}
void Assinante::imprimeFavoritos(){
    if (Favoritos.empty()){
        return;
    }
    int i = 1;
    vector<Midia*>::iterator it = this->Favoritos.begin();
    while(it!= this->Favoritos.end()){
        cout << i << "************" << endl;
        (*it)->imprimeInfoMidia();
        it++;
        i++;
    }
}
void Assinante::inserirFavorito(Midia* favorito){
    this->Favoritos.push_back(favorito);
}
void Assinante::removerFavorito(){
    Midia* favorito;
    this->Favoritos.pop_back();
}

vector <Midia*> Assinante::getFavoritos(){
    return this->Favoritos;
}

// void Assinante::imprimeNoArquivo(ofstream &outfile);