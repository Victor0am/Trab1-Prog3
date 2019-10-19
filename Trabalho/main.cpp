// #define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "bibliotecas/PlataformaDigital.hpp"
#include "bibliotecas/Genero.hpp"
int Midia::qtdProdutos = 0;
using namespace std;

int main(int argc, char** argv){
    PlataformaDigital *spotify = new PlataformaDigital("Spotify");
    vector <string> flags;
    if (argc == 1  /*argc != 9*/){
        cerr << "Erro de I/O" << endl;
        exit(1);
    }
    for (int i = 1; i < argc; i++){
        flags.push_back(string(argv[i]));
        cout << argv[i] << endl;
    }
    ifstream generos, usuarios, favoritos, midias;
    for (int i = 0; i < flags.size() - 1; i++){
        //Genero
        if (flags[i] == "-g"){
            cout << "Genero" << endl;
            cout << flags[i+1] << endl;
            generos.open(flags[i+1]);
            if(generos.fail()){
                cerr << "Erro de I/O"<< endl;
                exit(1);
            }
            i++;
        }
        //Usuarios
        if (flags[i] == "-u"){
            cout << "Usuarios" << endl;
            cout << flags[i+1] << endl;
            usuarios.open(flags[i+1]);
            if(usuarios.fail()){
                cerr << "Erro de I/O"<< endl;
                exit(1);
            }
            i++;
        }
        //Favoritos
        if (flags[i] == "-f"){
            cout << "Favoritos" << endl;
            cout << flags[i+1] << endl;
            favoritos.open(flags[i+1]);
            if(favoritos.fail()){
                cerr << "Erro de I/O"<< endl;
                exit(1);
            }
            i++;
        }
        if (flags[i] == "-m"){
            cout << "Midias" << endl;
            cout << flags[i+1] << endl;
            midias.open(flags[i+1]);
            if(midias.fail()){
                cerr << "Erro de I/O"<< endl;
                exit(1);
            }
            i++;
        }
    }
    ofstream saida;
    saida.open("saida.txt");
    if(generos.fail()){
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
    while(generos.good()){
        getline(generos, sigla, ';');
        if(generos.eof()){
            break;
        }
        getline(generos, nome);
        genre = new Genero(nome, sigla);
        gen.push_back(genre);
        i++;
    }
    for(Genero* g : gen){
        saida << g->getsigla() << ";";
        saida << g->getnome() << endl;
    }
}