/*
 * utente.h
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */


#ifndef UTENTE_H_
#define UTENTE_H_

#include "pessoa.h"


class Utente: public Pessoa {
	int nivel;
	float conta;
	//vector<Aula> aulas;
	//vector<Livre> livres;
	bool cartao;

public:
	Utente(string nome, string password, long id, int nivel, bool cartao);
	void setCartao(bool cartao);
	float getConta() const;
	int getNivel() const;
	bool getCartao() const;
	void adiciona_ao_ficheiro();
//	bool find_ID_file(long id); //procura no ficheiro dos utentes se existe alguem com o id=id;


};



#endif /* UTENTE_H_ */
