#include "../bibliotecas/Produtor.hpp"
using namespace std;
Produtor::Produtor(){

}
Produtor::Produtor(string nome, int codigo):Usuario(nome, codigo){
    this->qtdLikes = 0;
}

//void Produtor::imprimeNoArquivo(ofstream &outfile);
void Produtor::imprimeProdutosDesenvolvidos(){
    vector<Midia*>::iterator it = this->produtosDesenvolvidos.begin();
    while(this->produtosDesenvolvidos.end() != it){
        //colocar a formatação que a jordana pedir aqui...
        it++;
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
    // for(Midia*m: produtosDesenvolvidos){
    //     delete m;
    // }
}