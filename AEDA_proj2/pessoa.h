#ifndef PESSOA_H_
#define PESSOA_H_

#include <iostream>
#include <string>

using namespace std;


class Pessoa{
	string nome;
	int nif;
	static int number;

public:
	/**
 * @brief Construtor da classe Pessoa.
 * @param id - Id da pessoa
 * @param nome -  Nome da pessoa
 */
	Pessoa(int id, string nome);

	/**
 * @brief Construtor da classe Pessoa.
 * @param nome -  Nome da pessoa
 */
	Pessoa(string nome);

	/**
 * @brief
 * @return
 */
	int getID() const;

	/**
 * @brief
 * @return
 */
	string getNome() const;

	/**
 * @brief
 * @return
 */
	string getPassword() const;

	/**
 * @brief
 * @return
 */
	void setPassword(string password);

	/**
 * @brief
 * @return
 */
	virtual const char* getInfo()=0;

	/**
 * @brief Operador == para comparar pessoas.
 * @param p1 - uma outra pessoa para comparar à pessoa em questão.
 * @return Retorna true caso a pessoa em questão seja igual à pessoa a comparar, false caso contrário.
 */
	bool operator==(const Pessoa &p1);
};



class ExceptionAlreadyRegistered{
public:
	ExceptionAlreadyRegistered(){
		cout<<"Ja existe alguem registado com esse id."<<endl;
	}
};
#endif /* PESSOA_H_ */
