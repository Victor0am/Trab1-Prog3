#ifndef _HORARIOAULA_H
#define _HORARIOAULA_H

class HorarioAula{
    private:
        string diaSemana;
        tm HorarioFim;
        tm HorarioInicio;
        int codigo;
    public:
        string getdiaSemana();
        void setdiaSemana(string diaSemana);
        int getcodigo();
        void setcodigo(int codigo);
        tm getHorarioFim();
	    void setHorarioFim();
	    tm getHorarioInicio();
	    void setHorarioInicio();
}

#endif