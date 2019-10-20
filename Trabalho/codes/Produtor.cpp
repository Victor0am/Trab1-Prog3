#include "../bibliotecas/Produtor.hpp"
using namespace std;
Produtor::Produtor(){

}
Produtor::Produtor(string nome, int codigo):Usuario(nome, codigo){
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