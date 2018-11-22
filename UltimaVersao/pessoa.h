/*
 * pessoa.h
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */


#ifndef PESSOA_H_
#define PESSOA_H_

#include <iostream>
#include <string>

using namespace std;


class Pessoa{
	string nome;
	int nif;
	static int number;

public:
	Pessoa(int id, string nome);
	Pessoa(string nome);
	int getID() const;
	string getNome() const;
	string getPassword() const;
	void setPassword(string password);
	virtual const char* getInfo()=0;
	bool operator==(const Pessoa &p1);
};



class ExceptionAlreadyRegistered{
public:
	ExceptionAlreadyRegistered(){
		cout<<"Ja existe alguem registado com esse id."<<endl;
	}
};
#endif /* PESSOA_H_ */
