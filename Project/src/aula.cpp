/*
 * aula.cpp
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */

#include "aula.h"

Aula::Aula(Horario horario, Professor prof){
	this->horario=horario;
	this->professor=prof;
	this->alunos=NULL;

	this->preco=0;
	this->duracao=0;
}

void Aula::setPreco(float preco){
	this->preco=preco;
}

void Aula::setProfessor(Professor prof){
	this->professor=prof;
}

void Aula::setDuracao(unsigned int duracao){
	this->duracao=duracao;

	//if(duracao > ){
	throw ExceptionInvalidClassDuration();
}

int Aula::add_aluno(const Utente &u1){
	//if(alunos.size() <=  )
	{
		alunos.push_back(u1);
		return alunos.size();
	}

	throw ExceptionMaxUtentes();
	return -1;
}

string Aula::getInfo(){
	int dia, mes, ano;
	dia=this->horario.getData().getDia();
	mes=this->horario.getData().getMes();
	ano=this->horario.getData().getAno();

	int horas, minutos;
	horas=this->horario.getHoras();
	minutos=this->horario.getMin();





}
