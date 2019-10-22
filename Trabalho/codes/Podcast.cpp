#include "../bibliotecas/Podcast.hpp"

Podcast::Podcast(){}
Podcast::Podcast(int codigo, string nome, Genero gen, float duracao, int anoLancamento, int qtdTemporadas):Midia(nome, codigo, gen, duracao){
    this->qtdTemporadas = qtdTemporadas;
    this->anoLancamento = anoLancamento;
}
void Podcast::imprimeInfoMidia(){
    cout << this->codigo << ";";
    cout << this->nome << ";";
    cout << this->duracao<< endl;
}