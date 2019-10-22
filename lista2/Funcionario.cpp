#include "Funcionario.h"
using namespace std;
string Funcionario::getcpf(){
    return this->cpf;
}
void Funcionario::setcpf(string cpf){
    this->cpf = cpf;
}
string Funcionario::getrg(){
    return this->rg;
}
void Funcionario::setrg(string rg){
    this->rg = rg;
}
string Funcionario::getendereco(){
    return this->endereco;
}
void Funcionario::setendereco(string endereco){
    this->endereco = endereco;
}
string Funcionario::gettelefone(){
    return this->telefone;
}
void Funcionario::settelefone(string telefone){
    this->telefone = telefone;
}
string Funcionario::getemail(){
    return this->email;
}
void Funcionario::setemail(string email){
    this->email = email;
}
string Funcionario::getnome(){
    return this->nome;
}
void Funcionario::setnome(string nome){
    this->nome = nome;
}
string Funcionario::getmatricula(){
    return this->matricula;
}
void Funcionario::setmatricula(string matricula){
    this->matricula = matricula;
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
