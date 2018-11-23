#include "campoTenis.h"
#include <stdio.h>

int campoTenis::id=0;

//criar construtor com id
campoTenis::campoTenis(int num_campo, int nMaxUtentes, string abertura, string fecho): abertura(Horario(abertura)), fecho(Horario(fecho)), numero_campo(num_campo),
		MAX_UTILIZADORES(nMaxUtentes){
	id=num_campo;
	id++;
}
campoTenis::campoTenis(int nMaxUtentes, string abertura, string fecho): abertura(Horario(abertura)), fecho(Horario(fecho)),MAX_UTILIZADORES(nMaxUtentes){
	this->numero_campo=id;
	id++;
}

int campoTenis::getNumeroCampo() const{
	return this->numero_campo;
}

Horario campoTenis::getHorarioAbertura() const{
	return this->abertura;
}

Horario campoTenis::getHorarioFecho() const{
	return this->fecho;
}

int campoTenis::getMaxUtilizadores() const{
	return this->MAX_UTILIZADORES;
}

string campoTenis::getInfo() {
	string toconvert = to_string(this->getNumeroCampo()) + ":" + to_string(this->getMaxUtilizadores()) + ":" + this->getHorarioAbertura().horario_friendly_print() + ":" + this->getHorarioFecho().horario_friendly_print();
	//const char* to_print = toconvert.c_str();
	return toconvert;
}

void campoTenis::adicionar_dia(const Dia & d1){
	ocupacao_por_dia.push_back(d1);
	ocupacao_por_dia.back().inicializar_horario(abertura, fecho);
}
