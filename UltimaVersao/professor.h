/*
 * professor.h
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */


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
	Professor(int id, string nome);
	Professor(string nome);
	void adicionar_aula(Aula * a1);
	bool remover_aula(Aula * a2);
	vector<Aula*> getAulas() const;

	/*VIRTUAL METHODS*/
	const char* getInfo();
};



#endif /* PROFESSOR_H_ */
