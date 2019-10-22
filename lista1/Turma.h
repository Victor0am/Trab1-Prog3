#ifndef _TURMA_H
#define _TURMA_H

class Turma{
    private:
        int codigo;
        int vagas;
        int ano;
        int semestre;
        tm DtInicio;
        tm DtFim;
    public:
        static int qtdTurmas;
        int getcodigo();
        void setcodigo(int codigo);
        int getvagas();
        void setvagas(int vagas);
        int getano();
        void setano(int ano);
        int getsemestre();
        void setsemestre(int semestre);
        tm getDtInicio();
        tm getDtInicio();
        tm getDtFim();
        void setDtFim(time_t DtFim);
}



#endif