/*
 * data.h
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */

#ifndef DATA_H_
#define DATA_H_


#include <string>
#include <string.h>
#include <iostream>

using namespace std;

class Data{
	int dia;
	int mes;
	int ano;
public:
	Data(string data);
	Data(string data, string horas);
	int getAno() const;
	int getMes() const;
	int getDia() const;

	string get_data() const;
	string get_horas() const;
	bool operator<(const Data &outraData);
	bool operator=(const Data &outraData);

};

class InvalidDateException{
public:
	InvalidDateException(){
		std::cout<<"A data inserida não é válida. Insira números válidos no formato DD-MM-YYYY"<<std::endl;
	}
};




#endif /* DATA_H_ */
