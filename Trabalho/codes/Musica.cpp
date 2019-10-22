#include "../bibliotecas/Musica.hpp"

Musica::Musica(){
    cout << "Musica Publicada"<<endl;
}
Musica::Musica(string nome, Genero gen, float duracao, int anoLancamento): Midia(nome, codigo, genero, duracao){
    this->anoLancamento = anoLancamento;
}
 void Musica::imprimeInfoMidia(){
    cout << this->codigo << ";";
    cout << this->nome << ";";
    cout << this->duracao<< endl;
 }
// void Musica::imprimeNoArquivo(ofstream &outfile);
// void Musica::formataDuracao();