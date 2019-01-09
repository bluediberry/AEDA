#ifndef DATA_H_
#define DATA_H_
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

/**
 * Classe Data utilizada para comparar datas de ocorrencias.
 */
class Data{
	int dia;
	int mes;
	int ano;
public:
	/**
 * @brief Construtor da classe Date.
 * @param data - string que representa a data no formato DD-MM-AAAA.
 */
	Data(string data);

	/**
 * @brief Permite obter o dia da data.
 * @return Retorna o ano da data.
 */
	int getAno() const;

/**
 * @brief Permite obter o mês data.
 * @return Retorna o mês da data.
 */
	int getMes() const;

	/**
 * @brief Permite obter o dia da data.
 * @return Retorna o dia da data.
 */
	int getDia() const;

	/**
	 * @brief Permite obter a data num formato agradável para o utilizador.
	 * @return Retorna a data no formato DD-MM-AAAA.
	 */
	string data_friendly_print() const;

	/**
 * @brief Operador < para comparar datas.
 * @param outra - uma outra data para comparar à data em questão.
 * @return Retorna true caso a data em questão seja anterior à data a comparar, false caso contrário.
 */
	bool operator<(const Data &outraData);

	/**
 * @brief Operador == para comparar datas.
 * @param outra - uma outra data para comparar à data em questão.
 * @return Retorna true caso a data em questão seja igual à data a comparar, false caso contrário.
 */
	bool operator==(const Data &outraData);
};

class InvalidDateException{
public:
	InvalidDateException(){
		std::cout<<"A data inserida n�o � v�lida. Insira n�meros v�lidos no formato DD-MM-YYYY"<<std::endl;
	}
};




#endif /* DATA_H_ */
