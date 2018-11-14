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
	string password;
	long id; //nif

public:
	Pessoa(string nome, string password, long id);
	int getID() const;
	string getNome() const;
	string getPassword() const;
	void setPassword(string password);
	virtual void adiciona_ao_ficheiro()=0; //É preciso criar fich.txt
//	virtual bool find_ID_file(long id)=0; //implementar tanto no prof como no utente
};

class ExceptionInvalidID{
public:
	ExceptionInvalidID(){
		cout<<"O numero ID deverá ter 9 digitos."<<endl;
	}
};

class ExceptionAlreadyRegistered{
public:
	ExceptionAlreadyRegistered(){
		cout<<"Ja existe alguem registado com esse id."<<endl;
	}
};
#endif /* PESSOA_H_ */
