#ifndef _FUNCIONARIO_H
#define _FUNCIONARIO_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Funcionario{
    private:
        string nome;
        string rg;
        string cpf;
        string endereco;
        string email;
        string matricula;
        tm dataNascimento;
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
	    tm getDataNascimento();
	    void setDataNascimento();
};

#endif