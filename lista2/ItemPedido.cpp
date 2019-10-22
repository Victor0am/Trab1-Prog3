#include "ItemPedido.h"
using namespace std;
int ItemPedido::getquantidade(){
    return this->quantidade;
}
void ItemPedido::setquantidade(int quantidade){
    this->quantidade = quantidade;
}
float ItemPedido::getpreco(){
    return this->preco;
}
void ItemPedido::setpreco(float preco){
    this->preco = preco;
}
