#ifndef _ITEMPEDIDO_H
#define _ITEMPEDIDO_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class ItemPedido{
    private:
        int quantidade;
        float preco;
    public:
        int getcquantidade();
        void getquantidade(string quantidade);
        float getpreco();
        void setpreco(float preco);
};

#endif