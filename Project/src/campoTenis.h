/*
 * camposTenis.h
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */

#ifndef CAMPOTENIS_H_
#define CAMPOTENIS_H_

#include "utente.h"
#include "professor.h"
#include "utilizacao.h"
#include <vector>

class campoTenis{
	const unsigned int id;
	const unsigned int nMaxUtentes;
	vector<Utilizacao> utilizacoes;

public:
	campoTenis(unsigned int id, unsigned int nMaxUtentes);


};



#endif /* CAMPOTENIS_H_ */
