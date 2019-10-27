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
    if (argc == 1 ){
        cerr << "Erro de I/O" << endl;
        exit(1);
    }
    for (int i = 1; i < argc; i++){
        flags.push_back(string(argv[i]));
    }
    ifstream generos, usuarios, favoritos, midias;
    for (int i = 0; i < flags.size() - 1; i++){
        //Genero
        if (flags[i] == "-g"){
            generos.open(flags[i+1]);
            if(generos.fail()){
                cerr << "Erro de I/O"<< endl;
                exit(1);
            }
            i++;
        }
        //Usuarios
        if (flags[i] == "-u"){
            usuarios.open(flags[i+1]);
            if(usuarios.fail()){
                cerr << "Erro de I/O"<< endl;
                exit(1);
            }
            i++;
        }
        //Favoritos
        if (flags[i] == "-f"){
            favoritos.open(flags[i+1]);
            if(favoritos.fail()){
                cerr << "Erro de I/O"<< endl;
                exit(1);
            }
            i++;
        }
        //Midias
        if (flags[i] == "-m"){
            midias.open(flags[i+1]);
            if(midias.fail()){
                cerr << "Erro de I/O"<< endl;
                exit(1);
            }
            i++;
        }
    }
    ofstream saida, saida2;
    spotify->carregaArquivoGeneros(generos);
    generos.close();
    spotify->carregaArquivoUsuarios(usuarios);
    usuarios.close();
    spotify->carregaArquivoMidia(midias);
    midias.close();
    spotify->carregaArquivoFavoritos(favoritos);
    favoritos.close();
    spotify->gerarRelatorios();
}