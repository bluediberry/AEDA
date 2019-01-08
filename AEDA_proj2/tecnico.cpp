#include "tecnico.h"

Tecnico::Tecnico(string nome, string dataAtual, string dataInicioTrabalho) : Pessoa(nome){
	Data d1(dataAtual);
	Data d2(dataInicioTrabalho);


	this->numeroReparacoes=0;

	bool disponivel=false;
	//Calcular numero de dias ateDisponibilidade
	if (d1.getAno() == d2.getAno()){
		if(d1.getMes() == d2.getMes()){
			if(d1.getDia() < d2.getDia())
				this->DiasAteDisponibilidade = d2.getDia() - d1.getDia();
			else
				this->DiasAteDisponibilidade = 0;

			disponivel=true;
		}
	}

	//if(!disponivel)
	//	throw NaoDA();

}

void Tecnico::setDiasAteDisponibilidade(int dias){
	this->DiasAteDisponibilidade=dias;
}

void Tecnico::setNumeroReparacoes(int nrep) {
	this->numeroReparacoes=nrep;
}

int Tecnico::getNumeroReparacoes() const {
	return numeroReparacoes;
}

int Tecnico::getDiasAteDisponibilidade() const{
	return DiasAteDisponibilidade;
}

bool Tecnico::operator<(const Tecnico &t1) const {

	if(this->DiasAteDisponibilidade > t1.getDiasAteDisponibilidade()){
		return true;
	}
	else if(this->DiasAteDisponibilidade == t1.getDiasAteDisponibilidade()){
		return this->numeroReparacoes > t1.getNumeroReparacoes();
	}

	return false;
}

vector<campoTenis*> Tecnico::getCamposReparados() const {
	return camposReparados;
}

const char* Tecnico::getInfo() {
	const char *ola;
	return ola;

}
