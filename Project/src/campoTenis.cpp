/*
 * camposTenis.cpp
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */

#include "campoTenis.h"
campoTenis::campoTenis(unsigned int id, unsigned int nMaxUtentes){
	this->id=id;
	this->nMaxUtentes=nMaxUtentes;
	this->utilizacoes = NULL;
}


