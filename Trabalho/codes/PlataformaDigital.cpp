#include "../bibliotecas/PlataformaDigital.hpp"
using namespace std;
PlataformaDigital::~PlataformaDigital(){
    for(Midia* m : midiasCadastradas){
        delete m;
    }
    for(Produtor* p: produtoresCadastrados){
        if(p->gettipo() == 'A'){
            delete (Artista*)p;
        }else{
            delete(Podcaster*)p;
        }
    }
    for(Genero * g: generosCadastrados){
        delete g;
    }
    for(Assinante * a : assinantesCadastrados){
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
    for(Produtor*p : produtoresCadastrados){
        if(p->getcodigo() == codigo && p->gettipo() == 'A'){
            return (Artista *)p;
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
    vector<string> lista_generos;
    Genero* genero;
    getline(infile, sigla, ';');
    getline(infile, nome);
    while(infile.good()){
        getline(infile, sigla, ';');
        if(infile.eof()){
            break;
        }
        for(string s : lista_generos){
            if(s==sigla){
                cerr << "Inconsistências na entrada" << endl; 
                exit(1);
            }
        }
        getline(infile, nome);
        fix_string(&nome);
        genero = new Genero(nome, sigla);
        generosCadastrados.push_back(genero);
        lista_generos.push_back(genero->getsigla());
    }
}

void PlataformaDigital::verifica_produtor(string produtor){
    string aux;
    stringstream convert(produtor);
    while(getline(convert, aux, ',')){
        if (stoi(aux)== 0){
            cerr << "Erro de formatação" << endl;
            exit(1);
        }
    }
}

void PlataformaDigital::carregaArquivoUsuarios(ifstream &infile){
    int codigo;
    vector <int> lista_codigos;
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
        if(codigo == 0){
            cerr << "Erro de formatação" << endl;
            exit(1);
        }
        infile >> tipo;
        infile.ignore(1);
        if(infile.eof()){
            break;
        }
        for(int i: lista_codigos){
            if(i == codigo){
                cerr << "Inconsistências na entrada" << endl;
                exit(1);
            }
        }
        getline(infile, nome);
        fix_string(&nome);
        if (tipo == 'U'){
            user = new Assinante(nome, codigo, tipo);
            inserirAssinante((Assinante*)user);
        }else{
            if (tipo == 'P'){
                user = new Podcaster(nome, codigo, tipo);
                cadastrarProdutor((Produtor*)user);
            }else if(tipo == 'A'){
                user = new Artista(nome, codigo, tipo);
                cadastrarProdutor((Produtor*)user);
            } else{
                cerr << "Inconsistências na entrada" << endl;
                exit(1);
            }
        }
        lista_codigos.push_back(codigo);
    }
}

void PlataformaDigital::carregaArquivoMidia(ifstream &infile){
    int codigo, codigo_album;
    vector<int>lista_codigos;
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
        infile >> codigo;
        infile.ignore(1);
        if(!infile.good()){
            break;
        }
        for(int i : lista_codigos){
            if(i == codigo){
                cerr << "Inconsistências na entrada" << endl;
            }
        }
        if(codigo == 0){
            throw invalid_argument("codigo invalido");
        }
        getline(infile, nome, ';');
        backup.append(nome);
        backup.append(1u,';');
        infile >> tipo;
        backup.append(1u, tipo);
        backup.append(1u,';');
        infile.ignore(1);
        getline(infile, produtor, ';');
        verifica_produtor(produtor);
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
        if (duracao == 0){
            throw invalid_argument("Duração precisa ser um número");
        }
        getline(infile, genero, ';');
        backup.append(genero);
        backup.append(1u,';');
        getline(infile, ttemp, ';');
        backup.append(ttemp);
        backup.append(1u,';');
        if (!ttemp.empty()){
            temporada = atoi(ttemp.c_str());
            if(temporada == 0){
                throw invalid_argument("temporada não existente");
            }
        }
        getline(infile, nome_album, ';');
        getline(infile, codigo_albums, ';');
        backup.append(codigo_albums);
        backup.append(1u,';');
        infile >> publicacao;
        backup.append(to_string(publicacao));
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
                if(codigo_album == 0){
                    throw invalid_argument("codigo de album não existe");
                }
                Album *album = new Album(nome_album, codigo_album, publicacao);
                Artista * artista = getArtista(produtor);
                artista->lancarAlbum(album);
                album->musicaNoAlbum(musica);
            }
        }
        else if(tipo == 'P'){
            Podcast * podcast = new Podcast(codigo, nome, duracao, publicacao, temporada, tipo);
            podcast->setnome_low();
            podcast->setvezesFavoritado();
            podcast->setbackup(backup);
            podcast->setduracao_virgula(duracao_virgula);
            podcast->setgenero(sigla_genero(genero));
            midiasCadastradas.push_back(podcast);
            codigo_produtor(produtor, podcast);
        }
        else{
            throw invalid_argument("Não existe esse tipo");
        }
        }
        catch(invalid_argument & e){
            cerr << "Erro de formatação" << endl;
            exit(1);
        }
        lista_codigos.push_back(codigo);
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
        if (code == 0){
            cerr << "Erro de formatação" << endl;
            exit(1);
        }
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
                if (!check){
                    favs.push_back(stoi(aux));
                    if(stoi(aux) == 0){
                        cerr << "Erro de formatação" << endl;
                        exit(1);
                    }
                }
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
 * Métodos das Saidas
 *************************/

void PlataformaDigital::gerarRelatorios(){
    Backup();
    Estatisticas();
    lista_favoritos();
    lista_produtores();
}



void PlataformaDigital::Backup(){
    ofstream outfile("saidas/4-backup.txt");
    outfile << "Usuarios" << endl;
    for(Assinante* a : assinantesCadastrados){
        outfile << a->getcodigo() << ';';
        outfile << a->getnome() << endl;
    }
    for(Produtor* p : produtoresCadastrados){
        outfile << p->getcodigo() << ';';
        outfile << p->getnome() << endl;
    }
    outfile << endl;
    outfile << "Midias" << endl;
    for(Midia* m : midiasCadastradas){
        outfile << m->getbackup() << endl;
    }
    outfile.close();
}


void PlataformaDigital::Estatisticas(){
    ofstream outfile("saidas/1-estatisticas.txt");
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
    for(Genero* g : generosCadastrados){
        float minutos = 0;
        int total = 0;
        for (Assinante *a: assinantesCadastrados){
            for(Midia * m : a->getFavoritos2()){
                if(m->getgenero().getnome() == g->getnome()){
                    total ++;
                    minutos += m->getduracao();
                }
            }
        }
        if(total > maistocado){
            totalmin = minutos;
            maistocado = total;
            maior = g->getnome();
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
            outfile << g->getnome();
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
    ofstream outfile("saidas/2-produtores.csv");
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
    ofstream outfile("saidas/3-favoritos.csv");
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

