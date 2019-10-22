#include "Cliente.h"
using namespace std;
string Cliente::getcpf(){
    return this->cpf;
}
void Cliente::setcpf(string cpf){
    this->cpf = cpf;
}
string Cliente::getrg(){
    return this->rg;
}
void Cliente::setrg(string rg){
    this->rg = rg;
}
string Cliente::getendereco(){
    return this->endereco;
}
void Cliente::setendereco(string endereco){
    this->endereco = endereco;
}
string Cliente::gettelefone(){
    return this->telefone;
}
void Cliente::settelefone(string telefone){
    this->telefone = telefone;
}
string Cliente::getemail(){
    return this->email;
}
void Cliente::setemail(string email){
    this->email = email;
}
string Cliente::getnome(){
    return this->nome;
}
void Cliente::setnome(string nome){
    this->nome = nome;
}
tm getDataNascimento(){
    return this->dataNascimento;
}
void setDataNascimento(){
    time_t tt;
    time(&tt);
    tm dataAtual = *localtime(&tt);
    this->dataNascimento = dataAtual;
}

void Adiciona_Pedido(Pedido p){
    this->Pedidos.push_back(p);
}