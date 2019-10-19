#include "../bibliotecas/PlataformaDigital.hpp"
using namespace std;
void PlataformaDigital::setnome(string nome){
    this->nome = nome;
}
string PlataformaDigital::getnome(){
    return this->nome;
}
// void PlataformaDigital::carregaArquivoGeneros(ifstream &infile){
//     string nome;
//     string sigla;
//     getline(infile, sigla, ';');
//     getline(infile, nome);
//     while(!infile.eof()){
//         getline(infile, sigla, ';');
//         getline(infile, nome);
//         Genero *gen =  new Genero(nome, sigla);
//     }
// }
PlataformaDigital::PlataformaDigital(){

}
PlataformaDigital::PlataformaDigital(string nome){//lembrar que os arquivos vao estar em ordem "aleatória" nos arv lá
    this->nome = nome;
}