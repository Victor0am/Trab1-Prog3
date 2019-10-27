#include "../bibliotecas/Album.hpp"
using namespace std;
string Album::getnome(){
    return this->nome;
}
void Album::setnome(string nome){
    this->nome = nome;
}
int Album::getduracao(){
    return this->duracao;
}
void Album::setduracao(int duracao){
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
Album::Album(string nome, int codigo, int anoLancamento){
    this->nome = nome;
    this->codigo = codigo;
    this->anoLancamento = anoLancamento;
    this->qtdMusicas = 0;
    this->duracao = 0;
}
void Album::musicaNoAlbum(Musica* musica){
    this->duracao += musica->getduracao();
    this->qtdMusicas++;
    Musicas.push_back(musica);
}
Album::~Album(){
    
}