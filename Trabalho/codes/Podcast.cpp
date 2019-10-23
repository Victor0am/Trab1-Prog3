#include "../bibliotecas/Podcast.hpp"

Podcast::Podcast(){}
Podcast::Podcast(int codigo, string nome, Genero* gen, float duracao, int anoLancamento, int qtdTemporadas)/*:Midia(nome, codigo, gen, duracao)*/{
    this->codigo = codigo;
    this->nome = nome;
    this->genero = gen;
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;
    this->qtdTemporadas = qtdTemporadas;
}
void Podcast::imprimeInfoMidia(){
    cout << this->codigo << ";";
    cout << this->genero->getnome() << ";";
    cout << this->nome << ";";
    cout << this->duracao<< endl;
}