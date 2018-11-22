/*
 * aula.h
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */

#ifndef AULA_H_
#define AULA_H_


#include "utilizacao.h"
#include <vector>



class Aula: public Utilizacao {
	static int id;
	int identificacao;
	vector<Utente*> alunos;

public:
	static int numero_maximo_utilizadores_por_aula;
	Aula(int id, string data, string horario, float preco);
	Aula(string data, string horario, float preco);
	bool adicionar_aluno(Utente * u1);
	bool remover_aluno(Utente * u1);
	vector<Utente*> getAlunos() const;
	bool operator==(const Aula &a2);
	string getInfo();
	int getIdentificacao() const;

};



#endif /* AULA_H_ */
