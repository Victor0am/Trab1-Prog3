#include "../bibliotecas/PlataformaDigital.hpp"
using namespace std;

void PlataformaDigital::carregaArquivoGeneros(ifstream &infile){
    string nome;
    string sigla;
    getline(infile, sigla, ';');
    getline(infile, nome);
    while(!infile.eof()){
        getline(infile, sigla, ';');
        getline(infile, nome);
        Genero *gen =  new Genero(nome, sigla);
    }
}

PlataformaDigital::PlataformaDigital(string nome){//lembrar que os arquivos vao estar em ordem "aleatória" nos arv lá
    this->setnome(nome);
    ifstream generos;
    generos.open("../entradas/generos.csv", ios::in);
    if(!generos.is_open()){
        cerr << "Erro ao abrir arquivo, o mesmo não existe"<< endl;
    }
    ifstream favoritos;
    favoritos.open("../entradas/favoritos.csv", ios::in);
    if(!favoritos.is_open()){
        cerr << "Erro ao abrir arquivo, o mesmo não existe"<< endl;
    }
    ifstream midias;
    midias.open("../entradas/midias_corrigidas.csv", ios::in);
    if(!midias.is_open()){
        cerr << "Erro ao abrir arquivo, o mesmo não existe"<< endl;
    }
    ifstream usuarios;
    usuarios.open("../entradas/usuarios.csv", ios::in);
    if(!usuarios.is_open()){
        cerr << "Erro ao abrir arquivo, o mesmo não existe"<< endl;
    }
    this->carregaArquivoGeneros(generos);//fazer o resto
}