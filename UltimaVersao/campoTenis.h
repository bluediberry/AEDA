/*
 * camposTenis.h
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */

#ifndef CAMPOTENIS_H_
#define CAMPOTENIS_H_


#include <vector>
#include <list>
#include "dia.h"

using namespace std;

class campoTenis{
	Horario abertura;
	Horario fecho;
	static int id;
	int MAX_UTILIZADORES;
	int numero_campo;
	vector<Dia> ocupacao_por_dia;


public:
	campoTenis(const campoTenis&) = default;
	campoTenis(int num_campo, int nMaxUtentes, string abertura, string fecho);
	campoTenis(int nMaxUtentes, string abertura, string fecho);
	int getNumeroCampo() const;
	Horario getHorarioAbertura() const;
	Horario getHorarioFecho() const;
	int getMaxUtilizadores() const;
	string getInfo();
	void adicionar_dia(const Dia & d1);
	vector<Dia> getOcupacao() {return ocupacao_por_dia;}
	const vector<Dia> getOcupacao() const {return ocupacao_por_dia;}




};



#endif /* CAMPOTENIS_H_ */
