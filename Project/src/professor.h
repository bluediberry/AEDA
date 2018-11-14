/*
 * professor.h
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */


#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include <string>
#include "pessoa.h"

class Professor : public Pessoa {
	//vector<Aulas> aulas_dadas;

public:
	Professor(string nome, string password, long id);
	void adiciona_ao_ficheiro();

};



#endif /* PROFESSOR_H_ */
