/*
 * data.cpp
 *
 *  Created on: 18/10/2018
 *      Author: Cláudia Mamede
 */

#include "data.h"


Data::Data(string data){
	//Formato DD-MM-YYYY
	dia=stoi(data.substr(0,2));
	mes=stoi(data.substr(3,2));
	ano=stoi(data.substr(6,4));

	hora=0;
	minutos=0;

}


Data::Data(string data, string horas){
	//Formato DD-MM-YYYY e HH:MM
	dia=stoi(data.substr(0,2));
	mes=stoi(data.substr(3,2));
	ano=stoi(data.substr(6,4));

	hora=stoi(horas.substr(0,2));
	minutos=stoi(horas.substr(3,2));

}

int Data::getAno() const{
	return this->ano;
}

int Data::getMes() const{
	return this->mes;
}

int Data::getDia() const{
	return this->dia;
}

int Data::getHoras() const{
	return this->hora;
}

int Data::getMin() const{
	return this->minutos;
}

string Data::get_data() const{
	//Criar excepçoes para os limites: dia[1-31], mes[1-12]
	string day, month, year, date;

	if(dia < 10)
		day = "0" + to_string(dia);
	else
		day = to_string(dia);

	if(mes < 10)
		month = "0" + to_string(mes);
	else
		month = to_string(mes);

	year = to_string(ano);

	date = day + "-" + month + "-" + year;

	return date;
}

string Data::get_horas() const {
	//Criar excepçoes para os limites: hora[1-24] minutos[0-59]
	string hour, minutes, hours;
	if(hora < 10)
		hour = "0" + to_string(hora);
	else
		hour = to_string(hora);

	if(minutos < 10)
		minutes = "0" + to_string(minutos);
	else
		minutes = to_string(minutos);

	hours = hour + ":" + minutes;

	return hours;
}


bool operator<(const Data &outra) const {
	//TO DO
	return true;
}
