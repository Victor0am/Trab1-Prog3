#include "../bibliotecas/Musica.hpp"

Musica::Musica(){
    cout << "Musica Publicada"<<endl;
}
Musica::Musica(string nome, int codigo, float duracao, int anoLancamento, char tipo)/*:Midia(nome, codigo, genero, duracao)*/{
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->tipo = tipo;
    this->anoLancamento = anoLancamento;
}

void Musica::imprimeInfoMidia(){
    cout << this->codigo << ";";
    this->genero.imprimeGenero();
    cout << this->nome << ";";
    cout << this->duracao<< endl;
}
// void Musica::imprimeNoArquivo(ofstream &outfile);
// void Musica::formataDuracao();