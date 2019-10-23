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
float Midia::getduracao(){
    return this->duracao;
}
void Midia::setduracao(float duracao){
    this->duracao = duracao;
}
int Midia::getanoLancamento(){
    return this->anoLancamento;
}
void Midia::setanoLancamento(int anoLancamento){
    this->anoLancamento = anoLancamento;
}
Midia::Midia(){
    cout << "Midia criada com sucesso... nem tanto né...";
}
Midia::Midia(string nome, int codigo, Genero* genero, float duracao){
    this->genero = genero;
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    qtdProdutos++;
}

Genero Midia::getgenero(){
    return (*this)->genero;
}
// void Midia::imprimeInfoMidia(){
    //prints na ordem que quiser depois...
// }
// void formataDuracao(){
//     //this->duracao= algo
// }
//void Midia::imprimeNoArquivo(ofstream &outfile);