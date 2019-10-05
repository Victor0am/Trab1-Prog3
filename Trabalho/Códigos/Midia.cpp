#include "../Bibliotecas/Midia.hpp"

string Midia::getnome(){
    return this->nome;
}
void Midia::setnome(string nome){
    this->nome = nome;
}
int Midia::getcodigo(){
    return this->codigo;
}
void Midia::setcodigo(int codigo){
    this->codigo = codigo;
}
int Midia::getduracao(){
    return this->duracao;
}
void Midia::setduracao(int duracao){
    this->duracao = duracao;
}
int Midia::getanoLancamento(){
    return this->anoLancamento;
}
void Midia::setanoLancameot(int anoLancamento){
    this->anoLancamento = anoLancamento;
}
Midia();
Midia(string nome, int codigo, Genero genero);
void imprimeInfoProduto();
imprimeNoArquivo(ofstream &outfile);
string getnome();