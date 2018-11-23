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

	/**
 * @brief
 * @return
 */
	void setIdentificacaoAula(int &value){ identificacao_aula=value; }

	/**
 * @brief
 * @return
 */
	void setIdentificacaoLivre(int &value){ identificacao_livre=value; }

	/**
 * @brief
 * @return
 */
	int getIdentificacaoAula() const{ return this->identificacao_aula; }

	/**
 * @brief
 * @return
 */
	int getIdentificacaoLivre() const{ return this->identificacao_livre;}

	/**
 * @brief
 * @return
 */
	Horario getInicioBloco() const {return inicio_bloco;}


};




#endif /* PERIODO_H_ */
