#include "../bibliotecas/Podcast.hpp"

Podcast::Podcast(){}
Podcast::Podcast(int codigo, string nome, float duracao, int anoLancamento, int qtdTemporadas, char tipo)/*:Midia(nome, codigo, gen, duracao)*/{
    this->codigo = codigo;
    this->nome = nome;
    this->duracao = duracao;
    this->tipo = tipo;
    this->anoLancamento = anoLancamento;
    this->qtdTemporadas = qtdTemporadas;
}
void Podcast::imprimeInfoMidia(){
    cout << this->codigo << ";";
    this->genero.imprimeGenero();
    cout << this->nome << ";";
    cout << this->duracao<< endl;
}
Podcast::~Podcast(){
    
}