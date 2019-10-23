#include "../bibliotecas/Musica.hpp"

Musica::Musica(){
    cout << "Musica Publicada"<<endl;
}
Musica::Musica(string nome, int codigo, Genero* gen, float duracao, int anoLancamento)/*:Midia(nome, codigo, genero, duracao)*/{
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;
    // this->genero= gen;
    // this->genero.imprimeGenero();
}
 void Musica::imprimeInfoMidia(){
    cout << this->codigo << ";";
    // cout << this->genero.getnome() << ";";
    cout << this->nome << ";";
    cout << this->duracao<< endl;
 }
// void Musica::imprimeNoArquivo(ofstream &outfile);
// void Musica::formataDuracao();