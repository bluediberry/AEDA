#ifndef LIVRE_H_
#define LIVRE_H_


#include "utilizacao.h"
#include <vector>



class Livre: public Utilizacao {
	static int id;
	int identificacao;
	vector<Utente*> grupo;
	int duracao; //multiplos de 30min



public:
	static int numero_maximo_utilizadores_modo_livre;
	Livre(string data, string horario, float preco, unsigned int duracao);
	float getPrecoPorPessoa();
    void setDuracao(int duracao);
    int getDuracao() const;
    bool adicionar_ao_grupo(Utente * u1);
    bool remover_do_grupo(Utente * u1);
    vector<Utente*> getGrupo() const;
    string getInfo();
	int getIdentificacao() const;





};


class ExceptionInvalidFreeDuration{
public:
	ExceptionInvalidFreeDuration(){
		cout<<"A dura��o do modo livre deve ter x minutos"<<endl;
	}
};



#endif /* LIVRE_H_ */
