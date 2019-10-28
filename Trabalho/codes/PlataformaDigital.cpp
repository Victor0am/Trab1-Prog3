#include "../bibliotecas/PlataformaDigital.hpp"
using namespace std;
PlataformaDigital::~PlataformaDigital(){
    for(Midia* m : midiasCadastradas){
        delete m;
    }
    for(Produtor* p: produtoresCadastrados){
        delete p;
    }
    for(Genero * g: generosCadastrados){
        delete g;
    }
    for(Usuario * u : usuariosCadastrados){
        delete u;
    }
    for(Assinante * a : assinantesCadastrados){
        delete a;
    }
    for(Podcaster* p : podcastersCadastrados){
        delete p;
    }
    for(Artista* a: artistasCadastrados){
        delete a;
    }
}
void PlataformaDigital::setnome(string nome){
    this->nome = nome;
}
string PlataformaDigital::getnome(){
    return this->nome;
}
Artista* PlataformaDigital::getArtista(string produtor){
    stringstream convert(produtor);
    string aux;
    getline(convert, aux, ',');
    int codigo = stoi(aux);
    for(Artista*a : artistasCadastrados){
        if(a->getcodigo() == codigo){
            return a;
        }
    }
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
    while(infile.good()){
            infile >> codigo;
            infile.ignore(1);
            infile >> tipo;
            infile.ignore(1);
            if(infile.eof()){
                break;
            }
            getline(infile, nome);
            fix_string(&nome);
            user = new Usuario(nome, codigo);
            usuariosCadastrados.push_back(user);
            if (tipo == 'U'){
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
    string backup;
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
    while(infile.good()){
        try{
            /* code */
            infile >> codigo;
            // cout << typeid(codigo).hash_code;
            infile.ignore(1);
            getline(infile, nome, ';');
            backup.append(nome);
            backup.append(1u,';');
            infile >> tipo;
            backup.append(1u, tipo);
            backup.append(1u,';');
            infile.ignore(1);
            getline(infile, produtor, ';');
            backup.append(produtor);
            backup.append(1u,';');
            getline(infile, dtemp, ';');
            duracao_virgula = dtemp;
            backup.append(duracao_virgula);
            backup.append(1u,';');
            for (int i = 0; i < dtemp.size(); i++){
                if (dtemp[i] == ',')
                    dtemp[i] = '.';
            }
            duracao = atof(dtemp.c_str());
            getline(infile, genero, ';');
            backup.append(genero);
            backup.append(1u,';');
            getline(infile, ttemp, ';');
            backup.append(ttemp);
            backup.append(1u,';');
            if (!ttemp.empty()){
                temporada = atoi(ttemp.c_str());
            }
            getline(infile, nome_album, ';');
            getline(infile, codigo_albums, ';');
            backup.append(codigo_albums);
            backup.append(1u,';');
            infile >> publicacao;
            backup.append(to_string(publicacao));
        }
        catch(invalid_argument & ti){
            // std::cerr << e.what() << '\n';
            cerr << "Erro de formatação" << endl;
        }
        if (tipo == 'M'){
            Musica * musica = new Musica(nome, codigo, duracao, publicacao, tipo);
            musica->setvezesFavoritado();
            musica->setnome_low();
            musica->setbackup(backup);
            musica->setduracao_virgula(duracao_virgula);
            musica->setgenero(sigla_genero(genero));
            midiasCadastradas.push_back(musica);
            codigo_produtor(produtor, musica);
            if (!codigo_albums.empty()){
                codigo_album = atoi(codigo_albums.c_str());
                Album *album = new Album(nome_album, codigo_album, publicacao);
                Artista * artista = getArtista(produtor);
                artista->lancarAlbum(album);
                album->musicaNoAlbum(musica);
            }
        }
        if(tipo == 'P'){
            Podcast * podcast = new Podcast(codigo, nome, duracao, publicacao, temporada, tipo);
            podcast->setnome_low();
            podcast->setvezesFavoritado();
            podcast->setbackup(backup);
            podcast->setduracao_virgula(duracao_virgula);
            podcast->setgenero(sigla_genero(genero));
            midiasCadastradas.push_back(podcast);
            codigo_produtor(produtor, podcast);
        }
        tipo = 'z';
        backup.clear();
    }
}

bool PlataformaDigital::ingenero(string genero){
    for (Genero *G : generosCadastrados){
        if (genero == G->getsigla()){
            return true;
        }
    }
    return false;
}

bool PlataformaDigital::inprodutores(int produtor){
    for (Produtor *P : produtoresCadastrados){
        if (produtor == P->getcodigo()){
            return true;
        }
    }
    return false;
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
    p->setqtdLikes();
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
    cerr << "Inconsistências na entrada" << endl;
    exit(1);
}
void PlataformaDigital::codigo_produtor(string codigos, Midia * midia){
    int codigo;
    vector <int> codigos_produtores;
    string aux;
    stringstream convert(codigos);
    while(getline(convert, aux, ',')){
        codigos_produtores.push_back(stoi(aux));
    }
    for(int codigo : codigos_produtores){
        if (inprodutores(codigo))
            for(Produtor* p : produtoresCadastrados){
                if(p->getcodigo()==codigo){
                    p->desenvolverProdutos(midia);
                }
            }
        else{
            cerr << "Inconsistências na entrada" << endl;
            exit(1);
        }
    }
}
void PlataformaDigital::carregaArquivoFavoritos(ifstream &infile){
    string codigo;
    string favoritos, aux, linha;
    getline(infile, codigo, ';');
    getline(infile, favoritos);
    int code;
    int temp = -1;
    while(infile.good()){
        bool verificacao = false;
        vector <int> favs;
        infile >> code;
        infile.ignore(1);
        getline(infile, linha);
        if (!infile.good() && temp == code)
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
        for (int i = 0; i < assinantesCadastrados.size(); i++){
            if (assinantesCadastrados[i]->getcodigo() == code && !favs.empty()){
                for (int j = 0; j < favs.size(); j++){
                    assinantesCadastrados[i]->inserirFavorito(ProcuraMidia(favs[j]));
                    ProcuraMidia(favs[j])->foiFavoritado();
                    verificacao = true;
                }
            }
            if (assinantesCadastrados[i]->getcodigo() == code && favs.empty()){
                verificacao = true;
            }
        }
        temp = code;
        if (verificacao){
            continue;
            }
        else{
            cerr << "Inconsistencias na entrada" << endl;
            exit(1);
        }
    }
    /******************************************** 
     LINHA TERMINADA COM VIRGULA, 2 VIRGULAS SEGUIDAS, ESPAÇO EM BRANCO
     ********************************************/
}

Midia* PlataformaDigital::ProcuraMidia(int codigo){
    for (Midia *m : midiasCadastradas){
        if (codigo == m->getcodigo()){
            return m;
        }
    }
    cerr << "Inconsistencias na entrada" << endl;
    exit(1);
}

PlataformaDigital::PlataformaDigital(){}
PlataformaDigital::PlataformaDigital(string nome){
    this->nome = nome;
}



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
    Backup();
    Estatisticas();
    lista_favoritos();
    lista_produtores();
}


// 
void PlataformaDigital::Backup(){
    ofstream outfile("4-backup.txt");
    outfile << "Usuarios" << endl;
    for (int i = 0; i < usuariosCadastrados.size(); i++){
        outfile << usuariosCadastrados[i]->getcodigo() << ';';
        outfile << usuariosCadastrados[i]->getnome() << endl;
    }
    outfile << endl;
    outfile << "Midias" << endl;
    for(Midia* m : midiasCadastradas){
        outfile << m->getbackup() << endl;
    }
    outfile.close();
}


void PlataformaDigital::Estatisticas(){
    ofstream outfile("1-estatisticas.txt");
    Horas_consumidas(outfile);
    G_mais_ouvido(outfile);
    midias_por_g(outfile);
    Top_midias(outfile);
    Top_produtores(outfile);
    outfile.close();
}

//
void PlataformaDigital::Horas_consumidas(ofstream &outfile){
    float total = 0;
    for(Assinante*a : assinantesCadastrados){
        for(Midia*m : a->getFavoritos2()){
            total += m->getduracao();
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

//
void PlataformaDigital::G_mais_ouvido(ofstream &outfile){
    string maior = generosCadastrados[0]->getsigla();
    int maistocado = 0;
    float totalmin = 0;
    for (int i = 0; i < generosCadastrados.size(); i++){
        float minutos = 0;
        int total = 0;
        for (int j = 0; j < assinantesCadastrados.size(); j++){
            for (int k = 0; k < assinantesCadastrados[j]->getFavoritos().size(); k++){
                if (assinantesCadastrados[j]->getFavoritos()[k]->getgenero().getnome() == generosCadastrados[i]->getnome()){
                    total++;
                    minutos += assinantesCadastrados[j]->getFavoritos()[k]->getduracao();
                }
            }
        }
        if (total > maistocado){
            totalmin = minutos;
            maistocado = total;
            maior = generosCadastrados[i]->getsigla();
        }
    }
    string s(to_string(totalmin));
    for (int i = 0; i < 4; i++){
        s.pop_back();
    }
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '.'){
            s[i] = ',';
        }
    }
    outfile << "Gênero mais ouvido: " << maior << " - " << s << " minutos\n\n";
}



//
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
    outfile << "Mídias por Gênero:\n";
    for (Genero* g : generosCadastrados){
        int aux = 0;
        if(g->getcontador() != 0){
            outfile << g->getsigla();
            outfile << ":" << g->getcontador() << endl;
        }
    }
    outfile << endl;
}

void PlataformaDigital::Top_midias(ofstream &outfile){
    int aux = 0;
    outfile << "Top 10 Mídias:" << endl;
    sort(midiasCadastradas.begin(), midiasCadastradas.end(), [](Midia * lhs, Midia * rhs) {return lhs->getvezesFavoritado() > rhs->getvezesFavoritado();});
    for(Midia* m : midiasCadastradas){
        outfile << m->getnome() << ":";
        outfile << m->getgenero().getnome() << ':';
        outfile << m->getvezesFavoritado() << endl;
        aux++;
        if(aux>= 10){
            break;
        }
    }
    outfile << endl;
}

void PlataformaDigital::Top_produtores(ofstream &outfile){
    int aux = 0;
    outfile << "Top 10 Produtores:" << endl;
    for(Produtor* p: produtoresCadastrados){
        p->calculaLikes();
    }
    sort(produtoresCadastrados.begin(), produtoresCadastrados.end(), [](Produtor * lhs, Produtor * rhs) {return lhs->getqtdLikes() > rhs->getqtdLikes();});
    for(Produtor* p: produtoresCadastrados){
        outfile << p->getnome() << ':';
        outfile << p->getqtdLikes() << endl;
        aux ++;
        if(aux >= 10){
            break;
        }
    }
    outfile << endl;
}

void PlataformaDigital::lista_produtores(){ 
    ofstream outfile("2-produtores.csv");
    int aux;
    sort(produtoresCadastrados.begin(), produtoresCadastrados.end(), [](Produtor * lhs, Produtor * rhs) {return lhs->getnomelow()<rhs->getnomelow();});
    for (Produtor* p : produtoresCadastrados){
        outfile << p->getnome() << ";";
        p->ordenaProdutos();
        vector<Midia*> midias = p->getprodutosDesenvolvidos();
        aux = 12-midias.size();
        for(Midia* m : midias){
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

//
void PlataformaDigital::lista_favoritos(){ 
    ofstream outfile("3-favoritos.csv");
    outfile << "CódigoAssinante;Tipo Mídia;Código Mídia;Gênero;Duração" << endl;
    for (Assinante* a : assinantesCadastrados){
        a->ordenaFavoritos();
        for(Midia* m : a->getFavoritos2()){
            outfile << a->getcodigo() << ';';
            outfile << m->getnometipo() << ';';
            outfile << m->getcodigo() << ';';
            outfile << m->getgenero().getnome() << ';';
            outfile << m->getduracao_virgula() << endl;
        }
    }
    outfile.close();
}

