#include "utente.h"
#include <stdio.h>

FILE * utentes;
const char *path1="utentes_registados.txt";

Utente::Utente(int id, string nome, string password, int nivel, bool cartao) : Pessoa(id, nome){
	this->nivel=nivel;
	this->cartao=cartao;
	this->conta=0;
	if(cartao){
		this->conta=5.95;
	}
	this->password=password;
}

Utente::Utente(string nome, string password, int nivel, bool cartao) : Pessoa(nome){
	this->nivel=nivel;
	this->cartao=cartao;
	this->conta=0;
	this->password=password;
}

void Utente::setCartao(bool cartao){
	this->cartao=cartao;
}

int Utente::getNivel() const{
	return this->nivel;
}

float Utente::getConta() const{
	return this->conta;
}

bool Utente::getCartao() const{
	return this->cartao;
}

const char * Utente::getInfo(){
	string toconvert = to_string(this->getID()) + ":" + to_string(this->getCartao()) + ":" + to_string(this->getNivel()) + ":" + this->getPassword() + ":" + to_string(this->getConta()) + ":" + this->getNome();
	const char * to_print = toconvert.c_str();

	return to_print;
}

void Utente::somar_aula(float preco){
	conta= conta+preco;
}

string Utente::getPassword() const{
	return this->password;
}

void Utente::setPassword(string pass){
	password = pass;
}
