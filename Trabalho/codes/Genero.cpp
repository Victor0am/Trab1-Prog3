#include "../bibliotecas/Genero.hpp"
using namespace std;

string Genero::getnome(){
    return this->nome;
}
void Genero::setnome(string nome){
    this->nome = nome;
}
string Genero::getsigla(){
    return this->sigla;
}
void Genero::setsigla(string sigla){
    this->sigla = sigla;
}
Genero::Genero(){}
Genero::Genero(string nome, string sigla){
    this->nome = nome;
    this->sigla = sigla;
    this->contador_de_favoritos = 0;
}
void Genero::imprimeGenero(){
    cout << this->sigla << endl;
    cout << this->nome << endl;
}
void Genero::contaFavoritos(){
    this->contador_de_favoritos ++;
}
int Genero::getcontador(){
    return this->contador_de_favoritos;
}
Genero::~Genero(){
    
}