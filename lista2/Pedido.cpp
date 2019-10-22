#include "Pedido.h"
using namespace std;
string Pedido::getstatus(){
    return this->status;
}
void Pedido::setstatus(string status){
    this->status = status;
}
string Pedido::getformaPgto(){
    return this->formaPgto;
}
void Pedido::setformaPgto(string formaPgto){
    this->formaPgto = formaPgto;
}
float Pedido::getvalorTotal(){
    return this->valorTotal;
}
void Pedido::setvalorTotal(float valorTotal){
    this->valorTotal = valorTotal;
}
tm getdata(){
    return this->data;
}
void setdata(){
    time_t tt;
    time(&tt);
    tm dataAtual = *localtime(&tt);
    this->data = dataAtual;
}
