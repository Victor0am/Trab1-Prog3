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
            // getline(infile, nome, ';');
            infile.ignore(1);
            if(infile.eof()){
                break;
            }
            getline(infile, nome);
            fix_string(&nome);
            user = new Usuario(nome, codigo);
            usuariosCadastrados.push_back(user);
            if (tipo == 'U'){
                // cout << "Teste" << endl;
                user = new Assinante(nome, codigo);
                inserirAssinante((Assinante*)user);
            }else{
                user = new Produtor(nome, codigo);
                cadastrarProdutor((Produtor*)user);
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
    string duracao_virgula;
    string dtemp;
    string genero;
    int temporada;
    string ttemp;
    string nome_album;
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
        duracao_virgula = dtemp;
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
        getline(infile, nome_album, ';');
        getline(infile, codigo_albums, ';');
        // cout << album << endl;
        infile >> publicacao;
        // if (!codigo_albums.empty()){
        //     codigo_album = atoi(codigo_albums.c_str());
        //     Album *album = new Album(nome_album, codigo_album, publicacao);
        // }
        // cout << codigo_album << endl;
        // cout << publicacao << endl;
        if (tipo == 'M'){
            Musica * musica = new Musica(nome, codigo, duracao, publicacao, tipo);
            // musica->imprimeInfoMidia();
            musica->setduracao_virgula(duracao_virgula);
            musica->setgenero(sigla_genero(genero));
            // musica->setcodigo(codigo);
            midiasCadastradas.push_back(musica);
            codigo_produtor(produtor, musica);
            if (!codigo_albums.empty()){
                codigo_album = atoi(codigo_albums.c_str());
                Album *album = new Album(nome_album, codigo_album, publicacao);
                album->musicaNoAlbum(musica);
            }
        }
        if(tipo == 'P'){
            Podcast * podcast = new Podcast(codigo, nome, duracao, publicacao, temporada, tipo);
            podcast->setduracao_virgula(duracao_virgula);
            podcast->setgenero(sigla_genero(genero));
            midiasCadastradas.push_back(podcast);
            codigo_produtor(produtor, podcast);
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
void PlataformaDigital::cadastrarProdutor(Produtor*p){
    produtoresCadastrados.push_back(p);
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
            return *g;
        }
    }
}
void PlataformaDigital::codigo_produtor(string codigos, Midia * midia){
    int codigo;
    vector <int> codigos_produtores;
    string aux;
    stringstream convert(codigos);
    while(getline(convert, aux, ',')){
        // bool check = false;
        // for (int i = 0 ; i < codigos_produtores.size(); i++){
        //     if (stoi(aux) == codigos_produtores[i]){
        //         check = true;
        //         break;   
        //     }
        // }
        // if (!check)
        // codigos_produtores.push_back(stoi(aux));
        codigo = stoi(aux);
        break;
    }
    // for(int codigo : codigos_produtores){
    for(Produtor* p : produtoresCadastrados){
        if(p->getcodigo()==codigo){
            // midia->setprodutores(p);
            p->desenvolverProdutos(midia);
        }
    }
    // }
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
                bool check = false;
                for (int i = 0 ; i < favs.size(); i++){
                    if (stoi(aux) == favs[i]){
                        check = true;
                        break;   
                    }
                }
                if (!check)
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

// int PlataformaDigital::Fav_in(vector <Midia*> favoritos, Midia* favorito){
//     for (int i = 0; i < favoritos.size(); i++){
//         if (favoritos[i]->getcodigo == favorito->getcodigo()){
//             return 1;
//         }
//     }
//     return 0;
// }

void PlataformaDigital::fix_string(string *s){
    for (int i = 0; i < (*s).size(); i++){
        if ((*s)[i] == '\r'){
            (*s).erase(i, 1);
            break;
        }
    }
}

/***********************
 * Saidas
 *************************/

void PlataformaDigital::gerarRelatorios(){
    Estatisticas();
    lista_favoritos();
    lista_produtores();
    Backup();
}


void PlataformaDigital::Estatisticas(){
    ofstream outfile("1-estatisticas.txt");
    Horas_consumidas(outfile);
    G_mais_ouvido(outfile);
    midias_por_g(outfile);
}



void PlataformaDigital::Horas_consumidas(ofstream &outfile){
    float total = 0;
    for (int i = 0; i < assinantesCadastrados.size(); i++){
        for (int j = 0; j < assinantesCadastrados[i]->getFavoritos().size(); j++){
            total = assinantesCadastrados[i]->getFavoritos()[j]->getduracao() + total;
        }
    }
    string s(to_string(total));
    for (int i = 0; i < 4; i++){
        s.pop_back();
    }
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '.'){
            s[i] = ',';
        }
    }
    outfile << "Horas Consumidas: " << s << " minutos\n" << endl;
}

void PlataformaDigital::G_mais_ouvido(ofstream &outfile){
    string maior = generosCadastrados[0]->getsigla();
    int maistocado = 0;
    for (int i = 0; i < generosCadastrados.size(); i++){
        int total = 0;
        for (int j = 0; j < assinantesCadastrados.size(); j++){
            for (int k = 0; k < assinantesCadastrados[j]->getFavoritos().size(); k++){
                if (assinantesCadastrados[j]->getFavoritos()[k]->getgenero().getnome() == generosCadastrados[i]->getnome()){
                    total++;
                }
            }
        }
       if (total > maistocado){
            maistocado = total;
            maior = generosCadastrados[i]->getsigla();
        }
    }
    outfile << "Gênero mais ouvido: " << maior << " - " << maistocado << endl << endl;
}


void PlataformaDigital::Top_midias(ofstream &outfile){

}


/* ********************
 * NÃO APAGAR

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

********************* */


// void PlataformaDigital::midias_por_g(ofstream &outfile){
//     for (int i = 0; i < generosCadastrados.size(); i++){
//         int total = 0;
//         for (int j = 0; j < assinantesCadastrados.size(); j++){
//             for (int k = 0; k < assinantesCadastrados[j]->getFavoritos().size(); k++){
//                 if (assinantesCadastrados[j]->getFavoritos()[k]->getgenero().getnome() == generosCadastrados[i]->getnome()){
//                     total++;
//                 }
//             }
//         }
//         if (total != 0){
//             outfile << generosCadastrados[i]->getsigla();
//             outfile << ":" << total << endl;
//         }
//     }
// }

void PlataformaDigital::midias_por_g(ofstream &outfile){
    for(Genero *g : generosCadastrados){
        for(Assinante* a : assinantesCadastrados){
            for(Midia*m : a->getFavoritos2()){
                if(g->getsigla() == m->getgenero().getsigla()){
                    g->contaFavoritos();
                }
            }
        }
    }
    sort(generosCadastrados.begin(), generosCadastrados.end(), [](Genero * lhs, Genero * rhs) {return lhs->getcontador() > rhs->getcontador();});
    for (Genero* g : generosCadastrados){
        int aux = 0;
        if(g->getcontador() != 0){
            outfile << g->getsigla();
            outfile << ":" << g->getcontador() << endl;
        }
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

// void PlataformaDigital::lista_favoritos(){
//     ofstream outfile("3-favoritos.csv");
//     for (int i = 0; i < assinantesCadastrados.size(); i++){
//         for (int j = 0; j < assinantesCadastrados[i]->getFavoritos().size(); j++){
//             outfile << assinantesCadastrados[i]->getcodigo() << ';';
//             outfile << assinantesCadastrados[i]->getFavoritos()[j]->gettipo() << ';';
//             outfile << assinantesCadastrados[i]->getFavoritos()[j]->getcodigo() << ';';
//             outfile << assinantesCadastrados[i]->getFavoritos()[j]->getgenero().getnome() << ';';
//             outfile << assinantesCadastrados[i]->getFavoritos()[j]->getduracao() << endl;
//         }
//     }
//     outfile.close();
// }
void PlataformaDigital::lista_favoritos(){ // V.Victor
    ofstream outfile("3-favoritos.csv");
    outfile << "CódigoAssinante;Tipo Mídia;Código Mídia;Gênero;Duração" << endl;
    for (Assinante* a : assinantesCadastrados){
        a->ordenaFavoritos();
        for(Midia* m : a->getFavoritos2()){
            outfile << a->getcodigo() << ';';
            outfile << m->gettipo() << ';';
            outfile << m->getcodigo() << ';';
            outfile << m->getgenero().getnome() << ';';
            outfile << m->getduracao_virgula() << endl;
        }
    }
    outfile.close();
}


void PlataformaDigital::lista_produtores(){ // V.Victor
    ofstream outfile("2-produtores.csv");
    int aux;
    sort(produtoresCadastrados.begin(), produtoresCadastrados.end(), [](Produtor * lhs, Produtor * rhs) {return lhs->getnome() < rhs->getnome();});
    for (Produtor* p : produtoresCadastrados){
        outfile << p->getnome() << ";";
        aux = 12-p->getprodutosDesenvolvidos().size();
        for(Midia* m : p->getprodutosDesenvolvidos()){
            outfile << m->getnome() << ';';
        }
        while(aux>0){
            outfile << ';';
            aux--;
        }
        outfile << endl;
    }
    outfile.close();
}

