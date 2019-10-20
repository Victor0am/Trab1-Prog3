#include "../bibliotecas/PlataformaDigital.hpp"
using namespace std;
void PlataformaDigital::setnome(string nome){
    this->nome = nome;
}
string PlataformaDigital::getnome(){
    return this->nome;
}

vector<Genero*> PlataformaDigital::getgenero(){
    return this->generosCadastrados;
}

vector<Usuario*> PlataformaDigital::getusuario(){
    return this->usuariosCadastrados;
}

void PlataformaDigital::carregaArquivoGeneros(ifstream &infile){
    string nome;
    string sigla;
    Genero* genre;
    getline(infile, sigla, ';');
    getline(infile, nome);
    while(infile.good()){
            getline(infile, sigla, ';');
            if(infile.eof()){
                break;
            }
            getline(infile, nome);
            genre = new Genero(nome, sigla);
            generosCadastrados.push_back(genre);
    }
}

void PlataformaDigital::carregaArquivoUsuarios(ifstream &infile){
    int codigo;
    char tipo;
    string nome;
    string code;
    Usuario* user;
    string tipo0;
    getline(infile, code, ';');
    getline(infile, tipo0, ';');
    getline(infile, nome);
    // cout << code << "," << tipo0 << "," << nome << endl;
    while(infile.good()){
            infile >> codigo;
            infile.ignore(1);
            // cout << codigo;
            infile >> tipo;
            // cout << tipo << endl;
            getline(infile, nome, ';');
            if(infile.eof()){
                break;
            }
            getline(infile, nome);
            if (tipo == 'U'){
                // cout << "Teste" << endl;
                user = new Assinante(nome, codigo);
                inserirAssinante((Assinante*)user);
            }
            if (tipo == 'P'){
                user = new Podcaster(nome, codigo);
                cadastrarPodcaster((Podcaster*)user);
            }
            if(tipo == 'A'){
                user = new Artista(nome, codigo);
                cadastrarArtista((Artista*)user);
            }
    }
}

void PlataformaDigital::imprimeAssinantes(){
    for(Assinante *a: assinantesCadastrados){
        cout << a->getcodigo() << " ";
        cout << a->getnome() << endl;
    }
}

void PlataformaDigital::inserirAssinante(Assinante* a){
    assinantesCadastrados.push_back(a);
}
void PlataformaDigital::cadastrarPodcaster(Podcaster* p){
    podcastersCadastrados.push_back(p);
}
void PlataformaDigital::cadastrarArtista(Artista* a){
    artistasCadastrados.push_back(a);
}
void PlataformaDigital::imprimePodcasters(){
    for(Podcaster *p: podcastersCadastrados){
        cout << p->getcodigo() << " ";
        cout << p->getnome() << endl;
    }
}
void PlataformaDigital::imprimeArtistas(){
    for(Artista *a: artistasCadastrados){
        cout << a->getcodigo() << " ";
        cout << a->getnome() << endl;
    }
}
PlataformaDigital::PlataformaDigital(){}
PlataformaDigital::PlataformaDigital(string nome){//lembrar que os arquivos vao estar em ordem "aleatória" nos arv lá
    this->nome = nome;
}