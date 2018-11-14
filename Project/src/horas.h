/*
 * horas.h
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */

#ifndef HORAS_H_
#define HORAS_H_

#include <string>
#include "data.h"

class Horario{
	int horas;
	int minutos;
	Data data;

public:
	Horario(string horario);
	Horario(string horario, Data data);
	int getHoras() const;
	int getMin() const;
	Data getData() const;
	string getHorario() const;
	bool operator=(const Horario &outroHorario);


};



#endif /* HORAS_H_ */
