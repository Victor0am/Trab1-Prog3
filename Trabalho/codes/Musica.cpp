#include "../bibliotecas/Musica.hpp"

Musica::Musica(){
    cout << "Musica Publicada"<<endl;
}
Musica::Musica(string nome, Genero gen, float duracao, int anoLancamento): Midia(nome, duracao, genero){
    this->nome = nome;
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;
    this->genero = gen;
}
// void Musica::imprimeinfoMidia();
// void Musica::imprimeNoArquivo(ofstream &outfile);
// void Musica::formataDuracao();