#ifndef _ALUNO_H
#define _ALUNO_H

class Aluno{
    private:
        string matriculaInstituicao;
        int codigo;
        string cpf;
        string rg;
        string endereco;
        string telefone;
        string email;
        string nome;
    public:
        static int qtdAlunos;
        int getcodigo();
        void setcodigo(int codigo);
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
}

#endif