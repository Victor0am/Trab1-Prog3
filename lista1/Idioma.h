#ifndef _IDIOMA_H
#define _IDIOMA_H
class Idioma{
    private:
        int codigo;
        string nome;
    public:
        int getcodigo();
        void setcodigo(int codigo);
        string getnome();
        void setnome(string nome);
}

#endif