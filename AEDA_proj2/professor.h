#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include <string>
#include <iostream>
#include <fstream>
#include "pessoa.h"
#include "aula.h"
#include <vector>

class Professor : public Pessoa {
	vector<Aula*> aulas_dadas;

public:
	/**
 * @brief Construtor da classe Professor.
 * @param id - Id do professor
 * @param nome -  Nome do professor
 */
	Professor(int id, string nome);

	/**
 * @brief Construtor da classe Professor.
 * @param nome -  Nome do professor
 */
	Professor(string nome);

	/**
 * @brief Atribui uma certe aula dada a um professor
 * @param a1 - aula a atribuir
  */
	void adicionar_aula(Aula * a1);

	/**
 * @brief Remove a aula dada por um professor
 * @param a1 - aula a remover
 * @return Retorna true caso seja possivel remover, false caso contrário.
 */
	bool remover_aula(Aula * a2);

	/**
 * @brief
 * @return
 */
	vector<Aula*> getAulas() const;

	/*VIRTUAL METHODS*/
	const char* getInfo();
};

struct profPtr {
	Professor *prof;
};


#endif /* PROFESSOR_H_ */
