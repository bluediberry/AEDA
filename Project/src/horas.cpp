/*
 * horas.cpp
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */


#include "horas.h"
Horario::Horario(string horario){
	//formato HHhMM
	horas=stoi(horario.substr(0,2));
	minutos=stoi(horario.substr(3,2));
	data=NULL;
}

Horario::Horario(string horario, Data data){ //formato HHhMM, Formato DD-MM-YYYY
	horas=stoi(horario.substr(0,2));
	minutos=stoi(horario.substr(3,2));
	this->data = data;
}



int Horario::getHoras() const{
	return this->horas;
}

int Horario::getMin() const{
	return this->minutos;
}

Data Horario::getData() const {
	return this->data;
}

string Horario::getHorario() const {
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

	hours = hour + ":" + minutes;

	return hours;
}


bool Horario::operator= (const Horario &outro){
	if(this->getHoras() != outro.getHoras() || this->getMin() != outro.getMin() || this->getData() != outro.getData())
		return false;

	return true;
}

