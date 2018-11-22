/*
 * dia.h
 *
 *  Created on: 19/11/2018
 *      Author: Cláudia Mamede
 */

#ifndef DIA_H_
#define DIA_H_

#include "data.h"
#include "periodo.h"
class Dia {
	Data data;
	vector<Periodo*> blocos;

public:
	Dia(string data): data(Data(data)){};

	Data getData() const {return data;}
	vector<Periodo*>& getBlocos() {return blocos;}
	const vector<Periodo*>& getBlocos() const {return blocos;}
	void inicializar_horario(Horario& abertura, Horario& fecho){
		unsigned int numero_blocos = (((fecho.getHoras()*60 + fecho.getMin()) - (abertura.getHoras()*60 + abertura.getMin()))/30);
		for(unsigned int i=0; i<numero_blocos; i++){
			Periodo *p1 = new Periodo(abertura.com_duracao(30*i).horario_friendly_print());
			blocos.push_back(p1);
		}
	}


};



#endif /* DIA_H_ */
