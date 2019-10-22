#ifndef _FUNCIONARIO_H
#define _FUNCIONARIO_H
#include <iostream>
#include <list>
#include <string>
#include "Pedido.h"
using namespace std;
class Funcionario{
    private:
        string nome;
        string rg;
        string cpf;
        string endereco;
        string email;
        tm dataNascimento;
        list<Pedido*> Pedidos;
    public:
        string getcpf();
        void setcpf(string cpf);
        string getcrg();
        void getrg(string rg);
        string getendereco();
        void setendereco(string endereco);
        string gettelefone();
        void settelefone(string telefone);
        string getnome();
        void setnome(string nome);
	    tm getDataNascimento();
	    void setDataNascimento();
        void Adiciona_Pedido(Pedido p);
};

#endif