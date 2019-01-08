#include "tecnico.h"

Tecnico::Tecnico(int id, string nome, int nrReparacoes, int diasAteDisp, float preco) : Pessoa(id, nome){
	this->DiasAteDisponibilidade = diasAteDisp;
	this->numeroReparacoes = nrReparacoes;
	this->custo = preco;
}

Tecnico::Tecnico(string nome, int diasAteDisp, float custo) : Pessoa(nome){
	this->custo=custo;
	this->numeroReparacoes=0;
	this->DiasAteDisponibilidade = diasAteDisp;
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
		if (this->numeroReparacoes > t1.getNumeroReparacoes())
			return true;
		else
			return this->custo > t1.getCusto();
	}

	return false;
}

vector<campoTenis*> Tecnico::getCamposReparados() const {
	return camposReparados;
}

const char* Tecnico::getInfo() {
	string toconvert = to_string(this->getID()) + ":" + this->getNome() + ":" + to_string(this->getCusto()) + ":" + to_string(this->getNumeroReparacoes()) + ":" + to_string(this->getDiasAteDisponibilidade());
	const char * to_print = toconvert.c_str();
	return to_print;

}

vector<Data*> Tecnico::getDiasReparacao() const {
	return diasReparacao;
}

bool Tecnico::checkDiaReparacao(string dia){
	Data data(dia);

	for(unsigned int i=0; i<getDiasReparacao().size(); i++){
		Data *d1 = getDiasReparacao().at(i);
		if((*d1) == data){
			return true;
		}
	}
	return false;
}

void Tecnico::adicionarDiaReparacao(string data){
	Data *d1 = new Data(data);
	this->diasReparacao.push_back(d1);
}

void Tecnico::adicionarCampoReparacao(campoTenis * ct1){
	camposReparados.push_back(ct1);
}


float Tecnico::getCusto() const{
	return custo;
}


