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
	/**
 * @brief Construtor da classe Utilizacao.
 * @param data - data em que foi realizada a utlizacao
 * @param horario -  Horario em que foi utlizado
 * @param preco -  Preco da utilizacao
 */
	Utilizacao(string data, string horario, float preco);

	/**
 * @brief
 * @return
 */
	void setPreco(float preco);

	/**
 * @brief
 * @return
 */
	float getPreco() const;

	/**
 * @brief
 * @return
 */
	void setData(Data data);

	/**
 * @brief
 * @return
 */
	Data getData() const;

	/**
 * @brief
 * @return
 */
	void setHorario(Horario horario);

	/**
 * @brief
 * @return
 */
	Horario getHorario() const;



};

class ExceptionMaxUtentes{
public:
	ExceptionMaxUtentes(){
			cout<<"Numero de utentes excedido."<<endl;
	}
};


#endif /* UTILIZACAO_H_ */
