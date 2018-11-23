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
	/**
 * @brief Construtor da classe Utente.
 * @param id - Id do utente
 * @param nome -  Nome do Utente
 * @param password -  password do Utente
 * @param nivel -  nivel do utente
 * @param cartao -  cartao do utente
 */
	Utente(int id, string nome, string password, int nivel, bool cartao);

	/**
 * @brief Construtor da classe Utente.
 * @param nome -  Nome do Utente
 * @param password -  password do Utente
 * @param nivel -  nivel do utente
 * @param cartao -  cartao do utente
 */
	Utente(string nome, string password, int nivel, bool cartao);

	/**
 * @brief
 * @return
 */
	string getPassword() const;

	/**
 * @brief
 * @return
 */
	void setPassword(string pass);

	/**
 * @brief
 * @return
 */
	void setCartao(bool cartao);

	/**
 * @brief Soma o preco de uma aula a conta do utente
 * @param preco -  preco da aula a somar
 */
	void somar_aula(float preco);

	/**
 * @brief
 * @return
 */
	float getConta() const;

	/**
 * @brief
 * @return
 */
	int getNivel() const;

	/**
 * @brief
 * @return
 */
	bool getCartao() const;
//	string ver_report();

	/*VIRTUAL METHODS*/
	const char * getInfo();
};



#endif /* UTENTE_H_ */
