#include "../Bibliotecas/Produtor.hpp"
using namespace std;
Produtor::Produtor(){

}
Produtor::Produtor(string nome, int codigo){
    Usuario::setnome(nome);
    Usuario::setcodigo(codigo);
}
void Produtor::imprimeNoArquivo(ofstream &outfile);
void Produtor::imprimeProdutosDesenvolvidos();