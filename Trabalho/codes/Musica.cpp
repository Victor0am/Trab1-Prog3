#include "../bibliotecas/Musica.hpp"

Musica::Musica(){
    cout << "Musica Publicada"<<endl;
}
Musica::Musica(string nome, Genero gen, int duracao, int anoLancamento){
    this->nome = nome;
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;
    this->genero = gen;
}
// void Musica::imprimeinfoProduto();
// void Musica::imprimeNoArquivo(ofstream &outfile);
// void Musica::formataDuracao();