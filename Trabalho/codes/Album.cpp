#include "../bibliotecas/Album.hpp"
using namespace std;
string Album::getnome(){
    return this->nome;
}
void Album::setnome(string nome){
    this->nome = nome;
}
float Album::getduracao(){
    return this->duracao;
}
void Album::setDuracao(float duracao){
    this->duracao = duracao;//olhar como que faz para colocar musicas no album e entao a duracao será a soma das duracoes...
}
int Album::getqtdMusicas(){
    return this->qtdMusicas; 
}
void Album::setqtdMusicas(int qtdMusicas){
    this->qtdMusicas = qtdMusicas;
}
int Album::getanoLancamento(){
    return this->anoLancamento;
}
void Album::setanoLancamento(int anoLancamento){
    this->anoLancamento = anoLancamento;
}
Album::Album(){

}
Album::Album(string nome, float duracao, int anoLancamento, int qtdMusicas){
    this->setnome(nome);
}