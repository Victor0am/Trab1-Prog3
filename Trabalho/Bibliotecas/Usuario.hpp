#ifndef _USUARIO_HPP
#define _USUARIO_HPP
#include <iostream>
using namespace std;
class Usuario{
    protected:
        string nome; 
        int codigo;
    public:
        void imprimeNoArquivo(ofstream &outfile);
        void setcodigo(int codigo);
        int getcodigo();
        void setnome(string nome);
        string getnome();
};

#endif