#include "utente.h"
#include <stdio.h>

FILE * utentes;
const char *path1="utentes_registados.txt";

Utente::Utente(int id, string nome, string password, int nivel, bool cartao, int livre, int aula) : Pessoa(id, nome){
	this->nivel=nivel;
	this->cartao=cartao;
	if(this->cartao==true){
		this->conta=5.95;
	}
	else
		this->conta=0;

	this->password=password;
	total_livre=livre;
	total_aula=aula;

}

Utente::Utente(string nome, string password, int nivel, bool cartao) : Pessoa(nome){
	this->nivel=nivel;
	this->cartao=cartao;
	if(this->cartao==true){
		this->conta=5.95;
	}
	else
		this->conta=0;
	this->password=password;
	total_livre=0;
	total_aula=0;
}

void Utente::setCartao(bool cartao){
	this->cartao=cartao;
}

int Utente::getNivel() const{
	return this->nivel;
}

void Utente::setNivel(int nivel){
	this->nivel=nivel;
}
float Utente::getConta() const{
	return this->conta;
}

bool Utente::getCartao() const{
	return this->cartao;
}

const char * Utente::getInfo(){
	string toconvert = to_string(this->getID()) + ":" + to_string(this->getCartao()) + ":" + to_string(this->getNivel()) + ":" + this->getPassword() + ":" + to_string(this->getConta()) + ":" + to_string(this->getTotalAula()) + ":" + to_string(this->getTotalLivre()) + ":" + this->getNome();
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

int Utente::getTotalAula() const{
	return total_aula;
}

int Utente::getTotalLivre() const{
	return total_livre;
}

void Utente::acrescentaAula(int numeroAcrescentar){
	total_aula+=numeroAcrescentar;
}

void Utente::acrescentaLivre(int numeroAcrescentar){
	total_livre+=numeroAcrescentar;
}

bool Utente::operator<(const Utente& u1) const{
	int total=total_aula + total_livre;
	int total1=u1.getTotalAula() + u1.getTotalLivre();

	if(total < total1){
		return true;
	}
	else if(total==total1){
		return this->getNome() < u1.getNome();
	}
	else
		return false;
}
