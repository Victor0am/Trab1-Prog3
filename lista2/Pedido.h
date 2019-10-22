#ifndef _PEDIDO_H
#define _PEDIDO_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Pedido{
    private:
        string status;
        string formaPgto;
        float valorTotal;
        tm data;
    public:
        static int qtdPedidos;
        string getstatus();
        void setstatus(string status);
        string getcformaPgto();
        void getformaPgto(string formaPgto);
        float getvalorTotal();
        void setvalorTotal(float valorTotal);
	    tm getdata();
	    void setdata();
};

#endif