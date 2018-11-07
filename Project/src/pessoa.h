
#ifndef PESSOA_H_
#define PESSOA_H_

#include <string>
using namespace std;

long counter=0;

class Pessoa{
	string nome;
	string password;
	long id;

public:
	Pessoa(string nome, string password);
	int getID() const;
	string getNome() const;
	string getPassword() const;
	void setPassword(string password);
	virtual void adiciona_ao_ficheiro(); //� preciso criar fich.txt
};



#endif /* PESSOA_H_ */
