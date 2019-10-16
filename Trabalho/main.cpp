// #define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include "bibliotecas/Genero.hpp"
using namespace std;

int main(){
    ifstream generos;
    generos.open("entradas/generos.csv", ios::in);
    if(!generos.is_open()){
        cerr << "Erro ao abrir arquivo, o mesmo não existe"<< endl;
    }
    int i = 0;
    string nome;
    string sigla;
    Genero* genre;
    vector<Genero *>gen;
    vector<Genero*>::iterator it = gen.begin();
    getline(generos, sigla, ';');
    getline(generos, nome);
    while(!generos.eof()){
        getline(generos, sigla, ';');
        getline(generos, nome);
        genre = new Genero(nome, sigla);
        gen.push_back(genre);
        //it++;
        i++;
    }
    while(it!= gen.end()){
        //printar os negócios do jeito que ela pedir
        cout << "it = " << i << endl;
        it++;
    }
    cout << "it = " << i << endl;
}