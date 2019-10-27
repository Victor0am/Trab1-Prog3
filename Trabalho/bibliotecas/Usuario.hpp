#ifndef _USUARIO_HPP
#define _USUARIO_HPP
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//Classe usuario está "pronta" -- falta consertar o método de imprimir no arquivo
class Usuario{
    protected:
        string nome; 
        string nome_low;
        int codigo;
        char tipo;
    public:
        void imprimeNoArquivo(ofstream &outfile);
        void setcodigo(int codigo);
        int getcodigo();
        void setnome(string nome);
        string getnome();
        string getnomelow();
        void setnomelow();
        Usuario();
        Usuario(string _nome, int codigo);
};

#endif