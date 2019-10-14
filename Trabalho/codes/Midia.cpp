#include "../bibliotecas/Midia.hpp"
using namespace std;
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
void Midia::setanoLancamento(int anoLancamento){
    this->anoLancamento = anoLancamento;
}
Midia::Midia(){
    cout << "Midia criada com sucesso... nem tanto né..."
}
Midia::Midia(string nome, int codigo, Genero genero){

}
void Midia::imprimeInfoProduto();
void Midia::imprimeNoArquivo(ofstream &outfile);