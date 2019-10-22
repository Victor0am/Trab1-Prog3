#include<iostream>
#include <ctime>
#include<string>

class Professor {
    static int qtdProfessores;
    private:
        time_t DataAdmissao;
        time_t DataDemissao;
        string cpf;
        string rg;
        string endereco;
        string telefone;
        string email;
        string nome;
    public:
        string getcpf();
        void setcpf(string cpf);
        string getcrg();
        void getrg(string rg);
        string getendereco();
        void setendereco(string endereco);
        string gettelefone();
        void settelefone(string telefone);
        string getemail();
        void setemail(string email);
        string getnome();
        void setnome(string nome);


}


string Professor::getcpf(){
    return this->cpf;
}
string Professor::setcpf(string cpf){
    return this->cpf = cpf;
}
string Professor::getrg(){
    return this->rg;
}
string Professor::setrg(string rg){
    return this->rg = rg;
}
string Professor::getendereco(){
    return this->endereco;
}
string Professor::setendereco(string endereco){
    return this->endereco = endereco;
}
string Professor::gettelefone(){
    return this->telefone;
}
string Professor::settelefone(string telefone){
    return this->telefone = telefone;
}
string Professor::getemail(){
    return this->email;
}
string Professor::setemail(string email){
    return this->email = email;
}
string Professor::getnome(){
    return this->nome;
}
string Professor::setnome(string nome){
    return this->nome = nome;
}