/*
 * utilizacao.h
 *
 *  Created on: 13/11/2018
 *      Author: Cláudia Mamede
 */

#ifndef UTILIZACAO_H_
#define UTILIZACAO_H_


#include "campoTenis.h"
#include "data.h"
#include "utente.h"
#include <vector>

class Utilizacao{
  friend class CampoTenis;

  float preco;
  unsigned int duracao; //em minutos
  vector <Utente> utente;

public:
  Utilizacao();
  virtual void setPreco(float preco)=0;
  virtual void setDuracao(unsigned int duracao)=0;

};





#endif /* UTILIZACAO_H_ */
