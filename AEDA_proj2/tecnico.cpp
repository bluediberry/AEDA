#include "tecnico.h"

Tecnico::Tecnico(int id, string nome, int nrReparacoes, int diasAteDisp, float preco, string data) : Pessoa(id, nome), dataInscricao(Data(data)){
	this->DiasAteDisponibilidade = diasAteDisp;
	this->numeroReparacoes = nrReparacoes;
	this->custo = preco;
}

Tecnico::Tecnico(string nome, int diasAteDisp, float custo, string data) : Pessoa(nome), dataInscricao(Data(data)){
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
string Tecnico::getInfo() const {
	string toconvert = to_string(this->getID()) + ":" + this->getNome() + ":" + to_string(this->getCusto()) + ":" + to_string(this->getNumeroReparacoes()) + ":" + to_string(this->getDiasAteDisponibilidade());
	//const char * to_print = toconvert.c_str();
	return toconvert;

}

vector<Data*> Tecnico::getDiasReparacao() const {
	return diasReparacao;
}

bool Tecnico::checkDiaReparacao(string dia){
	Data data(dia);

	if(disponivel(dia)){
		for(unsigned int i=0; i<getDiasReparacao().size(); i++){
			Data *d1 = getDiasReparacao().at(i);
			if((*d1) == data){
				return true;
			}
		}
	}
	return false;
}

void Tecnico::adicionarDiaReparacao(string data){
	if(this->numeroReparacoes < MAX_REPARACOES){
	Data *d1 = new Data(data);
	this->diasReparacao.push_back(d1);
	return;
	}
	else
		throw ExceptionNumeroDeReparacoesExcedida();

}

void Tecnico::adicionarCampoReparacao(campoTenis * ct1){
	if(this->numeroReparacoes < MAX_REPARACOES){
		camposReparados.push_back(ct1);
		return;
	}
	else
		throw ExceptionNumeroDeReparacoesExcedida();

}
ExceptionNumeroDeReparacoesExcedida::ExceptionNumeroDeReparacoesExcedida(){}
float Tecnico::getCusto() const{
	return custo;
}

string Tecnico::getData() const {
	return dataInscricao.data_friendly_print();
}

bool Tecnico::disponivel(string d1) {
	Data data(d1);
	if(data < dataInscricao)
			return false;


	int ano1=dataInscricao.getAno();
	int ano2=data.getAno();
	int mes1=dataInscricao.getMes();
	int mes2=data.getMes();
	int dia1=dataInscricao.getDia();
	int dia2=data.getDia();

	if(ano1==ano2){
		if(mes1 == mes2){
			if(dia1+DiasAteDisponibilidade > dia2)
				return false;
			else
				return true;
		}
		else
			return mes1<mes2;
	}
	else
		return false;
}

