/*
 * aula.h
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */

#ifndef AULA_H_
#define AULA_H_

#include "utilizacao.h"
#include "data.h"
#include "horas.h"
#include "utente.h"
#include "professor.h"
#include <vector>

class Aula: public Utilizacao{
	Horario horario;
	vector<Utente> alunos;
	Professor professor;

public:
	Aula(Data data, Horario horario, Professor prof);
	Professor getProfessor();
	Horario getHorario();
	string getInfo(); //imprime informações sobre a aula, friendly way

	void setPreco(float preco);
	void setProfessor(Professor prof);
	void setDuracao(unsigned int duracao);
	int add_aluno(const Utente &u1);
};


class ExceptionInvalidClassDuration{
public:
	ExceptionInvalidClassDuration(){
		cout<<"Uma aula nao pode exceder x min."<<endl; //ver a duracao
	}
};

class ExceptionMaxUtentes{
public:
	ExceptionMaxUtentes(){
		cout<<"Numero de alunos por aula excedido."<<endl;
	}
};
#endif /* AULA_H_ */
