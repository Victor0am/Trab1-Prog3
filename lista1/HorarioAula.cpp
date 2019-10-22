#include "HorarioAula.h"

    string getdiaSemana(){
        return this->diaSemana;
    }
    void setdiaSemana(string diaSemana){
        this->diaSemana = diaSemana;
    }
    int getcodigo(){
        return this->codigo;
    }
    void setcodigo(int codigo){
        this->codigo = codigo;
    }
    tm getHorarioFim() {
		return this->HorarioFim;
	}
	void setHorarioFim() {
		tm tt;
        time(&tt);
        tm dataAtual = *localtime(&tt);
        this->HorarioFim = dataAtual;
	}
	tm getHorarioInicio() {
		return this->HorarioInicio;
	}
	void setHorarioInicio(tm HorarioInicio) {
		tm tt;
        time(&tt);
        tm dataAtual = *localtime(&tt);
        this->HorarioInicio = dataAtual;
	}