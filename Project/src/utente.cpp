/*
 * utente.cpp
 *
 *  Created on: 19/10/2018
 *      Author: Cl�udia Mamede
 */

#include "utente.h"

Utente::Utente(string nome, string password, int nivel, bool cartao) : Pessoa(nome, password){
	this->nivel=nivel;
	this->cartao=cartao;
	this->conta=0;
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

void Utente::adiciona_ao_ficheiro(){
	ofstream ofs;
	string info_total, id, nivel, cartao, nome;

	nome=this->getNome();

	id=to_string(this->getID());
	nivel=to_string(this->getNivel());

	if(this->getCartao())
		cartao="Sim";
	else
		cartao="Nao";

	info_total = id + " | " + nome + " | " + nivel + " | " + cartao;

	ofs.open("utentes.txt", ofstream::out | ofstream::app);
	ofs << info_total;
	ofs.close();
}
