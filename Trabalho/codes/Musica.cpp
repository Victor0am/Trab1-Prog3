#include "../bibliotecas/Musica.hpp"

Musica::Musica(){
    cout << "Musica Publicada"<<endl;
}
Musica::Musica(string nome, Genero gen, int duracao, int anoLancamento){
    Midia::setnome(nome);
    Midia::setduracao(duracao);
    Midia::setanoLancamento(anoLancamento);
    Midia
}
void Musica::imprimeinfoProduto();
void Musica::imprimeNoArquivo(ofstream &outfile);
void Musica::formataDuracao();