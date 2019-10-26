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
            fix_string(&nome);
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
            user = new Usuario(nome, codigo);
            usuariosCadastrados.push_back(user);
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
    int codigo, codigo_album;
    string nome;
    string lixo;
    string codigo_albums;
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
        getline(infile, codigo_albums, ';');
        // cout << album << endl;
        if (!codigo_albums.empty()){
            codigo_album = atoi(codigo_albums.c_str());
        }
        // cout << codigo_album << endl;
        infile >> publicacao;
        // cout << publicacao << endl;
        if (tipo == 'M'){
            Musica * musica = new Musica(nome, codigo, duracao, publicacao, tipo);
            // musica->imprimeInfoMidia();
            musica->setgenero(sigla_genero(genero));
            // musica->setcodigo(codigo);
            midiasCadastradas.push_back(musica);
        }
        if(tipo == 'P'){
            Podcast * podcast = new Podcast(codigo, nome, duracao, publicacao, temporada, tipo);
            podcast->setgenero(sigla_genero(genero));
            midiasCadastradas.push_back(podcast);
        }
        tipo = 'z';
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
    for (Genero* g: generosCadastrados){
        if (t == g->getsigla()){
            // cout << "aaaa" << endl;
            // g->imprimeGenero();
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
        infile >> code;
        // cout << code << endl;
        infile.ignore(1);
        getline(infile, linha);
        if (!infile.good())
            break;
        if (linha.size()!= 1){
            stringstream convert(linha);
            while(getline(convert, aux, ',')){
                favs.push_back(stoi(aux));
            }
        }
        else
            continue;

        /******** importanteee *********/
        for (int i = 0; i < assinantesCadastrados.size(); i++){
            if (assinantesCadastrados[i]->getcodigo() == code && !favs.empty()){
                for (int j = 0; j < favs.size(); j++){
                    assinantesCadastrados[i]->inserirFavorito(ProcuraMidia(favs[j]));
                }
            }
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

/***********************
 * Saidas
 *************************/

float PlataformaDigital::Horas_consumidas(){
    float total = 0;
    for (int i = 0; i < assinantesCadastrados.size(); i++){
        for (int j = 0; j < assinantesCadastrados[i]->getFavoritos().size(); j++){
            total = assinantesCadastrados[i]->getFavoritos()[j]->getduracao() + total;
        }
    }
    return total;
}

string PlataformaDigital::G_mais_ouvido(){
    
}

int PlataformaDigital::midias_por_g(){
    for (int i = 0; i < generosCadastrados.size(); i++){
        cout << generosCadastrados[i]->getnome();
        int total = 0;
        for (int j = 0; j < midiasCadastradas.size(); j++){
            if (midiasCadastradas[j]->getgenero().getnome() == generosCadastrados[i]->getnome()){
                total++;
            }
        }
        cout << ":" << total << endl;
    }
}


void PlataformaDigital::Backup(){
    ofstream outfile("4-backup.txt");
    outfile << "Usuarios" << endl;
    for (int i = 0; i < usuariosCadastrados.size(); i++){
        outfile << usuariosCadastrados[i]->getnome() << endl;
    }

    outfile << "Midias" << endl;
    for (int i = 0; i < midiasCadastradas.size(); i++){
        outfile << midiasCadastradas[i]->getnome() << ';';
        outfile << midiasCadastradas[i]->gettipo() << ';';
        //falta produtores
        outfile << midiasCadastradas[i]->getduracao() << ';';
        outfile << midiasCadastradas[i]->getgenero().getsigla() << ';';
        //temporada
        //nome do album
        //codigo album
        outfile << midiasCadastradas[i]->getanoLancamento() << ';';
        outfile << endl;
    }
    outfile.close();
}

void PlataformaDigital::lista_favoritos(){
    ofstream outfile("3-favoritos.csv");
    for (int i = 0; i < assinantesCadastrados.size(); i++){
        for (int j = 0; j < assinantesCadastrados[i]->getFavoritos().size(); j++){
            outfile << assinantesCadastrados[i]->getcodigo() << ';';
            outfile << assinantesCadastrados[i]->getFavoritos()[j]->gettipo() << ';';
            outfile << assinantesCadastrados[i]->getFavoritos()[j]->getcodigo() << ';';
            outfile << assinantesCadastrados[i]->getFavoritos()[j]->getgenero().getnome() << ';';
            outfile << assinantesCadastrados[i]->getFavoritos()[j]->getduracao() << endl;
        }
    }
    outfile.close();
}

void PlataformaDigital::fix_string(string *s){
    for (int i = 0; i < (*s).size(); i++){
        if ((*s)[i] == '\r'){
            (*s).erase(i, 1);
            break;
        }
    }
}



