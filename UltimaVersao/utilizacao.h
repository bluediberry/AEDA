/*
 * utilizacao.h
 *
 *  Created on: 16/11/2018
 *      Author: Cláudia Mamede
 */

#ifndef UTILIZACAO_H_
#define UTILIZACAO_H_

#include "data.h"
#include "horas.h"
#include "utente.h"

class Utilizacao {
	Data data;
	Horario horario;
	float preco;


public:
	Utilizacao(string data, string horario, float preco);
	void setPreco(float preco);
	float getPreco() const;
	void setData(Data data);
	Data getData() const;
	void setHorario(Horario horario);
	Horario getHorario() const;



};

class ExceptionMaxUtentes{
public:
	ExceptionMaxUtentes(){
			cout<<"Numero de utentes excedido."<<endl;
	}
};


#endif /* UTILIZACAO_H_ */
