#ifndef UTENTE_H_
#define UTENTE_H_

#include "pessoa.h"
#include <string>


class Utente: public Pessoa {
	int nivel;
	float conta;
	bool cartao;
	string password;
	int total_livre;
	int total_aula;
	//Falta acrescentar morada

public:
	/**
 * @brief Construtor da classe Utente.
 * @param id - Id do utente
 * @param nome -  Nome do Utente
 * @param password -  password do Utente
 * @param nivel -  nivel do utente
 * @param cartao -  cartao do utente
 * @param nr_livre - numero de utilizacoes em modo livre
 * @param nr_aula - numero de utilizacos em modo de aula
 */
	Utente(int id, string nome, string password, int nivel, bool cartao, int nr_livre, int nr_aula, float conta);

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

	/**
	 * @brief retorna o numero de utilizacoes em modo livre
	 * @return int
	 */
	int getTotalLivre() const;

	/**
	 * @brief retorna o numero de utilizacoes em modo aula
	 * @return int
	 */
	int getTotalAula() const;

	/**
		 * @brief acrescenta x numero de aulas
		 * @param int - numero de aulas a acrescentar
		 * @return void
		 */
	void acrescentaAula(int numeroAcrescentar);

	/**
	 * @brief acrescenta x numero de utilziacoes livres
	 * @param int - numero de livres a acrescentar
	 * @return void
	*/
	void acrescentaLivre(int numeroAcrescentar);

	/**
		* @brief operador para BST
		* @param u1 objecto do tipo utente
		*/
		bool operator<(const Utente& u1) const;




	/*VIRTUAL METHODS*/
	string getInfo() const;
	void setNivel(int nivel);
};



#endif /* UTENTE_H_ */
