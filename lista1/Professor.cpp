#include "Professor.h"

string Professor::getcpf(){
    return this->cpf;
}
void Professor::setcpf(string cpf){
    this->cpf = cpf;
}
string Professor::getrg(){
    return this->rg;
}
void Professor::setrg(string rg){
    this->rg = rg;
}
string Professor::getendereco(){
    return this->endereco;
}
void Professor::setendereco(string endereco){
    this->endereco = endereco;
}
string Professor::gettelefone(){
    return this->telefone;
}
void Professor::settelefone(string telefone){
    this->telefone = telefone;
}
string Professor::getemail(){
    return this->email;
}
void Professor::setemail(string email){
    this->email = email;
}
string Professor::getnome(){
    return this->nome;
}
void Professor::setnome(string nome){
    this->nome = nome;
}
tm getDataAdmissao(){
    return this->DataAdmissao;
}
void setDataAdmissao(){
    time_t tt;
    time(&tt);
    tm dataAtual = *localtime(&tt);
    this->DataAdmissao = dataAtual;
}
tm getDataDemissao(){
    return this->DataDemissao;
}
void setDataDemissao(){
    time_t tt;
    time(&tt);
    tm dataAtual = *localtime(&tt);
    this->DataDemissao = dataAtual;
}
