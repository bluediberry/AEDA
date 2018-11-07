
#include "pessoa.h"

Pessoa::Pessoa(string nome, string password){
	this->nome=nome;
	this->password=password;

	counter++;
	this->id=counter;

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
