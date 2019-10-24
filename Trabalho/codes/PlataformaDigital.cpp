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
    string produtor;
    float duracao;
    string dtemp;
    string genero;
    int temporada;
    string ttemp;
    string album;
    int publicacao;
    string fim;
    
    getline(infile, lixo);
    // cout << lixo << endl;
    while(infile.good()){
        infile >> codigo;
        infile.ignore(1);
        // cout << codigo << endl;
        getline(infile, nome, ';');
        // cout << nome << endl;
        infile >> tipo;
        // cout << tipo << endl;
        infile.ignore(1);
        getline(infile, produtor, ';');
        // cout << produtor << endl;
        getline(infile, dtemp, ';');
        for (int i = 0; i < dtemp.size(); i++){
            if (dtemp[i] == ',')
                dtemp[i] = '.';
        }
        duracao = atof(dtemp.c_str());
        // infile >> duracao;
        // cout << duracao << endl;
        getline(infile, genero, ';');
        // cout << genero << endl;
        getline(infile, ttemp, ';');
        if (!ttemp.empty()){
            temporada = atoi(ttemp.c_str());
            // cout << temporada << endl;
        }
        getline(infile, album, ';');
        if (!album.empty())
            // cout << album << endl;
        infile >> publicacao;
        // cout << publicacao << endl;
        if (tipo == 'M'){
            Musica * musica = new Musica(nome, codigo, duracao, publicacao);
            musica->imprimeInfoMidia();
            musica->setgenero(sigla_genero(genero));
            // musica->setcodigo(codigo);
            midiasCadastradas.push_back(musica);
        }
        if(tipo == 'P'){
            Podcast * podcast = new Podcast(codigo, nome, duracao, publicacao, temporada);
            podcast->setgenero(sigla_genero(genero));
            midiasCadastradas.push_back(podcast);
        }
        getline(infile, fim);
        if (fim == ";;;")
            break;
    }
}

void PlataformaDigital::imprimeAssinantes(){
    for(Assinante *a: assinantesCadastrados){
        cout << a->getcodigo() << " ";
        cout << a->getnome() << endl;
    }
}

void PlataformaDigital::imprimeMidias(){
    for(Midia* m: midiasCadastradas){
        m->imprimeInfoMidia();
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
    string t = sigla.substr(0,2);
    cout << t << endl;
    for (Genero* g: generosCadastrados){
        if (t == g->getsigla()){
            // cout << "aaaa" << endl;
            g->imprimeGenero();
            return *g;
        }
    }
}

void PlataformaDigital::carregaArquivoFavoritos(ifstream &infile){
    string codigo;
    string favoritos, aux, linha;
    getline(infile, codigo, ';');
    getline(infile, favoritos);
    int code;
    while(infile.good()){
        vector <int> favs;
        cout << "**************" << endl;
        infile >> code;
        infile.ignore(1);
        getline(infile, linha);
        stringstream convert(linha);
        while(getline(convert, aux, ',')){
            favs.push_back(stoi(aux));
        }
        // cout << "AQUI =========== " << endl;
        // for (int i = 0; i < favs.size(); i++){
        //     cout << favs[i] << endl;
        // }
        // cout << "AQUI =========== " << endl;
        /******** importanteee *********/
        for (int i = 0; i < assinantesCadastrados.size(); i++){
            if (assinantesCadastrados[i]->getcodigo() == code){
                for (int j = 0; j < favs.size(); j++){
                    assinantesCadastrados[i]->inserirFavorito(ProcuraMidia(favs[j]));
                }
            }
            assinantesCadastrados[i]->imprimeFavoritos();
        }
    }
    /******************************************** 
     FALTA TRATAMENTO DE ERRO PARA O CASO DE NÃO TER UM USUARIO COM AQUELE CODIGO,
     LINHA TERMINADA COM VIRGULA, 2 VIRGULAS SEGUIDAS, E NÃO TER UM FAVORITO CADASTRADO,
     2 OU MAIS FAVORITOS DE MESMO CODIGO, ESPAÇO EM BRANCO
     ********************************************/
}

Midia* PlataformaDigital::ProcuraMidia(int codigo){
    for (Midia *m : midiasCadastradas){
        if (codigo == m->getcodigo()){
            return m;
        }
    }
}

PlataformaDigital::PlataformaDigital(){}
PlataformaDigital::PlataformaDigital(string nome){//lembrar que os arquivos vao estar em ordem "aleatória" nos arv lá
    this->nome = nome;
}

