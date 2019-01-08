#include "pessoa.h"
int Pessoa::number=0;

Pessoa::Pessoa(int id, string nome){
	this->nome=nome;
	this->nif=id;
	number=id;
	number++;
}
Pessoa::Pessoa(string nome){
	this->nome=nome;
	this->nif=number;
	number++;

}

int Pessoa::getID() const{
	return this->nif;
}

string Pessoa::getNome() const{
	return this->nome;
}

bool Pessoa::operator==(const Pessoa &outroUtente){
	if(this->getID() == outroUtente.getID() && this->getNome() == outroUtente.getNome() ){
		return true;
	}

	return false;
}
