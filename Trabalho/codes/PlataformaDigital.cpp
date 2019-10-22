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

void PlataformaDigital::carregaArquivoMidia(ifstream &infile){
    int codigo;
    string nome;
    string lixo;
    char tipo;
    int produtor;
    float duracao;
    string genero;
    int temporada;
    string album;
    int publicacao;
    
    getline(infile, lixo);
    while(infile.good()){
        infile >> codigo;
        getline(infile, nome, ';');
        infile.ignore(1);
        infile >> tipo;
        infile.ignore(1);
        infile >> produtor;
        infile.ignore(1);
        infile >> duracao;
        getline(infile, genero, ';');
        infile >> temporada;
        infile.ignore(1);
        getline(infile, album, ';');
        infile >> publicacao;
        if (tipo == 'M'){
            Musica * musica = new Musica(nome, sigla_genero(genero), duracao, publicacao);
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

Genero PlataformaDigital::sigla_genero(string sigla){
    for (Genero *g: generosCadastrados){
        if (sigla == g->getsigla()){
            return g;
        }
    }
}

PlataformaDigital::PlataformaDigital(){}
PlataformaDigital::PlataformaDigital(string nome){//lembrar que os arquivos vao estar em ordem "aleatória" nos arv lá
    this->nome = nome;
}
