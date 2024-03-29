#include "../bibliotecas/Produtor.hpp"
using namespace std;
Produtor::Produtor(){

}
Produtor::Produtor(string nome, int codigo, char tipo):Usuario(nome, codigo, tipo){
}
void Produtor::setqtdLikes(){
    this->qtdLikes = 0;
}
void Produtor::imprimeProdutosDesenvolvidos(){
    for(Midia * m : produtosDesenvolvidos){
        m->imprimeInfoMidia();
    }
}
void Produtor::desenvolverProdutos(Midia* midia){
    this->produtosDesenvolvidos.push_back(midia);
}
vector<Midia*> Produtor::getprodutosDesenvolvidos(){
    return this->produtosDesenvolvidos;
}
void Produtor::calculaLikes(){
    for(Midia* m : produtosDesenvolvidos){
        this->qtdLikes += m->getvezesFavoritado();
    }
}
int Produtor::getqtdLikes(){
    return this->qtdLikes;
}
void Produtor::imprimeNoArquivo(ofstream &outfile){
    
}
void Produtor::ordenaProdutos(){
    sort(produtosDesenvolvidos.begin(), produtosDesenvolvidos.end(), [](Midia * lhs, Midia * rhs) {return lhs->getnome_low() < rhs->getnome_low();});
}
Produtor::~Produtor(){

}
char Produtor::gettipo(){
    return this->tipo;
}