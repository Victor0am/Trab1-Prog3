// #define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include "bibliotecas/Genero.hpp"
using namespace std;

int main(int argc, char** argv){
    vector <string> flags;
    if (argc == 1 || argc != 9){
        cerr << "Erro de I/O" << endl;
        exit(1);
    }
    for (int i = 0; i < argc; i++){
        flags.push_back(string(argv[i]));
        cout << argv[i] << endl;
    }
    if (flags[1] == "-g"){
        cout << "Funcionou !!!" << endl;
    }
    ifstream generos;
    ofstream saida;
    saida.open("saida.txt");
    generos.open("entradas/generos.csv", ios::in);
    if(/*!generos.is_open()*/ generos.fail()){
        cerr << "Erro ao abrir arquivo, o mesmo não existe"<< endl;
        exit(1);
    }
    int i = 0;
    string nome;
    string sigla;
    Genero* genre;
    vector<Genero *> gen;
    vector<Genero*>::iterator it; 
    getline(generos, sigla, ';');
    getline(generos, nome);
    while(/*!generos.eof*/ generos.good()){
        getline(generos, sigla, ';');
        if(generos.eof()){
            break;
        }
        getline(generos, nome);
        genre = new Genero(nome, sigla);
        gen.push_back(genre);
        //it++;
        i++;
    }
    // i = 0;
    // it = gen.begin();
    // while(it!= gen.end()){
    //     //printar os negócios do jeito que ela pedir
    //     cout << gen.at(i)->getnome() <<endl;
    //     cout << gen.at(i)->getsigla() << endl;
    //     it++;
    //     i++;
    // }
    for(Genero* g : gen){
        saida << g->getsigla() << ";";
        saida << g->getnome() << endl;
    }
    //for_each(gen.begin(), gen.end(), gen->imprimirGenero());
    //cout << "it = " << i << endl;
}