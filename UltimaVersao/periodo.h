/*
 * periodo.h
 *
 *  Created on: 19/11/2018
 *      Author: Cláudia Mamede
 */

#ifndef PERIODO_H_
#define PERIODO_H_

#include "aula.h"
#include "livre.h"

class Periodo{
	Horario inicio_bloco;
	int identificacao_aula;
	int identificacao_livre;


public:

	Periodo(string horario): inicio_bloco(Horario(horario)) {
		identificacao_aula=0;
		identificacao_livre=0;


	};

	void setIdentificacaoAula(int &value){ identificacao_aula=value; }
	void setIdentificacaoLivre(int &value){ identificacao_livre=value; }
	int getIdentificacaoAula() const{ return this->identificacao_aula; }
	int getIdentificacaoLivre() const{ return this->identificacao_livre;}
	Horario getInicioBloco() const {return inicio_bloco;}


};




#endif /* PERIODO_H_ */
