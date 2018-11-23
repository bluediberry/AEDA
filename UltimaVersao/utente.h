#ifndef UTENTE_H_
#define UTENTE_H_

#include "pessoa.h"
#include <string>


class Utente: public Pessoa {
	int nivel;
	float conta;
	bool cartao;
	string password;


public:
	Utente(int id, string nome, string password, int nivel, bool cartao);
	Utente(string nome, string password, int nivel, bool cartao);
	string getPassword() const;
	void setPassword(string pass);
	void setCartao(bool cartao);
	void somar_aula(float preco);
	float getConta() const;
	int getNivel() const;
	bool getCartao() const;
//	string ver_report();

	/*VIRTUAL METHODS*/
	const char * getInfo();
};



#endif /* UTENTE_H_ */
