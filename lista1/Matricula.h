#ifndef _MATRICULA_H
#define _MATRICULA_H

class Matricula{
    private:
        time_t diaMatricula;
        int codigo;
        int nota;
        string situacao;
    public:
        int getcodigo();
        void setcodigo(int codigo);
        int getnota();
        void setnota(int nota);
        string getsituacao();
        void setsituacao(string situacao);
        tm getDiaMatricula();
        void setDiaMatricula();
}

#endif