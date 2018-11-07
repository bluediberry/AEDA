

#ifndef UTENTE_H_
#define UTENTE_H_

#include "pessoa.h"
#include <fstream>

class Utente: public Pessoa {
	int nivel;
	float conta;
	//vector<Aula> aulas;
	//vector<Livre> livres;
	bool cartao;

public:
	Utente(string nome, string password, int nivel, bool cartao);
	void setCartao(bool cartao);
	float getConta() const;
	int getNivel() const;
	bool getCartao() const;
	void adiciona_ao_ficheiro();


};



#endif /* UTENTE_H_ */
