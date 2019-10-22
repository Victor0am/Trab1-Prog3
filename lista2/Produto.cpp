#include <Produto.h>
using namespace std;
string getnome(){
    return this->nome;
}
void setnome(string nome){
    this->nome = nome;
}
int getcodigo(){
    return this->codigo;
}
void setcodigo(int codigo){
    this->codigo = codigo;
}
string getcdescricao(){
    return this->descricao;
}
void getdescricao(string descricao){
    this->descricao = descricao;
}
int getquantidadeEstoque(){
    return this->quantidadeEstoque;
}
void setquantidadeEstoque(int quantidadeEstoque){
    this->quantidadeEstoque = quantidadeEstoque;
}
float getprecoBase(){
    return this->precoBase;
}
void setprecoBase(float precoBase){
    this->precoBase = precoBase;
}