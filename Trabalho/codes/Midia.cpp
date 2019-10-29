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

char Midia::gettipo(){
    return this->tipo;
}
void Midia::settipo(char tipo){
    this->tipo = tipo;
}
Midia::Midia(){
}

Midia::Midia(string nome, int codigo, Genero genero, float duracao, char tipo){
    this->genero = genero;
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->tipo = tipo;
    qtdProdutos++;
}

Genero Midia::getgenero(){
    return this->genero;
}
void Midia::setgenero(Genero genero){
    this->genero = genero;
}

string Midia::getduracao_virgula(){
    return this->duracao_virgula;
}
void Midia::setduracao_virgula(string duracao){
    this->duracao_virgula = duracao;
}
void Midia::foiFavoritado(){
    this->vezesFavoritado++;
}
int Midia::getvezesFavoritado(){
    return this->vezesFavoritado;
}
void Midia::setvezesFavoritado(){
    this->vezesFavoritado = 0;
}
string Midia::getnometipo(){
    string aux;
    if (tipo == 'P'){
        aux = "Podcast";
    }
    if(tipo  == 'M'){
        aux = "Música";
    }
    return aux;
}
string Midia::getnome_low(){
    return this->nome_low;
}
void Midia::setnome_low(){
    nome_low = nome;
    for (int i = 0; i < this->nome_low.size(); i++){
        if(nome_low[i] >= 'A' && nome_low[i]<='Z'){
            nome_low[i]+=32;
        }
    }
}
void Midia::setbackup(string backup){
    this->backup = backup;
}
string Midia::getbackup(){
    return this->backup;
}
Midia::~Midia(){
    
}
