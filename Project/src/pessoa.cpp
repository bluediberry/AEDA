/*
 * pessoa.cpp
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */


#include "pessoa.h"

Pessoa::Pessoa(string nome, string password, long id){
	this->nome=nome;
	this->password=password;
	this->id=id;

	if(id < 100000000 || id > 999999999){
		throw ExceptionInvalidID();
	}

	//criar uma função que procure o id no ficheiro dos utentes e nos profs... -> se nao encontrar tudo OK, se encontrar ExceptionPessoaAlreadyRegistered
}

int Pessoa::getID() const{
	return this->id;
}

string Pessoa::getNome() const{
	return this->nome;
}

string Pessoa::getPassword() const{
	return this->password;
}

void Pessoa::setPassword(string pass){
	password = pass;
}




