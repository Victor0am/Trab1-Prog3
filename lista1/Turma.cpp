#include "Turma.h"

    int Turma::getcodigo(){
        return this->codigo;
    }
    void Turma::setcodigo(int codigo){
        this->codigo = codigo;
    }
    int Turma::getvagas(){
        return this->vagas;
    }
    void Turma::setvagas(int vagas){
        this->vagas = vagas;
    }
    int Turma::getano(){
        return this->ano;
    }
    void Turma::setano(int ano){
        this->ano = ano;
    }
    int Turma::getsemestre(){
        return this->semestre;
    }
    void Turma::setsemestre(int semestre){
        this->semestre = semestre;
    }
    tm getDtInicio() {
		return this.DtInicio;
	}
	void setDtInicio(time_t DtInicio) {
		time_t tt;
        time(&tt);
        tm dataAtual = *localtime(&tt);
        this->DtInicio = dataAtual;
	}
	tm getDtFim() {
		return this.DtFim;
	}
	void setDtFim(time_t DtFim) {
		time_t tt;
        time(&tt);
        tm dataAtual = *localtime(&tt);
        this->DtFim = dataAtual;
	}