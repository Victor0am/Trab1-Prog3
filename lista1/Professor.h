#ifndef _PROFESSOR_H
#define _PROFESSOR_H

class Professor {
    private:
        tm DataAdmissao;
        tm DataDemissao;
        string cpf;
        string rg;
        string endereco;
        string telefone;
        string email;
        string nome;
    public:
        static int qtdProfessores;
        string getcpf();
        void setcpf(string cpf);
        string getcrg();
        void getrg(string rg);
        string getendereco();
        void setendereco(string endereco);
        string gettelefone();
        void settelefone(string telefone);
        string getemail();
        void setemail(string email);
        string getnome();
        void setnome(string nome);
	    tm getDataAdmissao();
	    void setDataAdmissao();
	    tm getDataDemissao();
	    void setDataDemissao();
        Professor(string cpf, string rg, string endereco, string email, string nome){
            qtdProfessores++;
            void setcpf(cpf);
            void getrg(rg);
            void setendereco(endereco);
            void settelefone(telefone);
            void setemail(email);
            void setnome(nome);
            void setDataAdmissao();
            void setDataDemissao();
        }
        ~Professor(){
            qtdProfessores--;
        }
}

#endif