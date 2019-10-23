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
            generos.open(flags[i+1]);
            cout << flags[i+1] << endl;
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
        //Midias
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
    ofstream saida, saida2;
    spotify->carregaArquivoGeneros(generos);
    spotify->carregaArquivoUsuarios(usuarios);
    spotify->carregaArquivoMidia(midias);
    spotify->carregaArquivoFavoritos(favoritos);
    // spotify->imprimeAssinantes();
    // cout << "====================Artistas" << endl;
    // spotify->imprimeArtistas();
    // cout << "====================Podcasters" << endl;
    // spotify->imprimePodcasters();
    // saida.open("saida.txt");
    // saida2.open("saida2.txt");
    // for(Genero* g : spotify->getgenero()){
    //     saida << g->getsigla() << ";";
    //     saida << g->getnome() << endl;
    // }
    // cout << "===========---------------Midias" << endl;
    // spotify->imprimeMidias();

    // for(Usuario* u : spotify->getusuario()){
    //     u->imprimeNoArquivo(saida2);
    //     // saida2 << u->getcodigo() << ";";
    //     // saida2 << u->getnome() << endl;
    // }
}