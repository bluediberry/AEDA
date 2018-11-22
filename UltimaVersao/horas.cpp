/*
 * horas.cpp
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */


#include "horas.h"
Horario::Horario(string horario){
	//formato HH:MM
	horas=stoi(horario.substr(0,2));
	minutos=stoi(horario.substr(3,2));
}

Horario::Horario(int horas, int minutos){
	this->horas=horas;
	this->minutos=minutos;
}

int Horario::getHoras() const{
	return this->horas;
}

int Horario::getMin() const{
	return this->minutos;
}

string Horario::horario_friendly_print() const {
	//Criar excepçoes para os limites: hora[1-24] minutos[0-59]
	string hour, minutes, hours;
	if(horas < 10)
		hour = "0" + to_string(horas);
	else
		hour = to_string(horas);

	if(minutos < 10)
		minutes = "0" + to_string(minutos);
	else
		minutes = to_string(minutos);

	hours = hour + "h" + minutes;

	return hours;
}


bool Horario::operator==(const Horario &outro){
	if(this->getHoras() != outro.getHoras() || this->getMin() != outro.getMin())
		return false;

	return true;
}

bool Horario::operator>(const Horario &outro){
	if(this->getHoras() > outro.getHoras()){
		return true;
	}
	else if(this->getHoras() == outro.getHoras()){
		if(this->getMin() > outro.getMin()){
			return true;
		}
	}

	return false;
}

Horario Horario::com_duracao(int duracao){
	int hora=duracao/60;
	int minutos=duracao%60;

	Horario h1(this->getHoras()+hora, this->getMin()+minutos);
	return h1;
}

