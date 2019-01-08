#include "utilizacao.h"


Utilizacao::Utilizacao(string data, string horario, float preco): data(Data(data)), horario(Horario(horario)){
	this->preco=preco;

}


void Utilizacao::setPreco(float preco){
	this->preco=preco;
}

float Utilizacao::getPreco() const{
	return this->preco;
}

void Utilizacao::setData(Data data){
	this->data=data;
}

Data Utilizacao::getData() const{
	return this->data;
}

void Utilizacao::setHorario(Horario horario){
	this->horario=horario;
}

Horario Utilizacao::getHorario() const{
	return this->horario;
}
