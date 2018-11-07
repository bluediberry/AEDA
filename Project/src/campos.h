#ifndef CAMPOS_H_
#define CAMPOS_H_

#include "data.h"
#include <string>
using namespace std;

long counter=0;

class CampoTenis {
  const unsigned int id;
  const int nMaxUtentes;
  vector <Utilizacao> utilizacao;
public:
  CampoTenis(unsigned int id, const int nMaxUtentes);
  virtual ~CampoTenis();
  const unsigned int getID() const;
  unsigned int getnMaxUtentes() const;


/* teste3: a)operador de comparacao */

}

class Utilizacao {
  friend class CampoTenis;
  float preco;
  Data data;
  unsigned int duracao;
  unsigned int NumUtilizadores;
  vector <Utentes> utente;

public:
  Utilizacao(unsigned int CampoTenis::id, float preco, unsigned int duracao, unsigned int NumUtilizadores);
  ~Utilizacao();
  float getPreco();
  unsigned int getDuracao();
  unsigned int getNumUtilizadores();
  bool checkIfFull(const int nMaxUtentes);
  //void addUtentes(const int nMaxUtentes);
  virtual bool checkDuracao(unsigned int duracao);
  virtual string getTipoAula();



}

class Livre : public Utilizacao {

  public:
    void setPreco();
    bool checkDuracao(unsigned int duracao);


}

class Aula : public Utilizacao {
    Prefessor professor;
  public:
    string getProfessor();
    void setPreco();
    bool checkDuracao(unsigned int duracao);


}

class InvalidDuracaoExceptionAula {
public:
  InvalidDuracaoExceptionAula(unsigned int  duracao){
    cout << duracao << "as aulas tem de ser multiplas de 30min e ter no maximo 1h" << endl;
  }
};

class InvalidDuracaoExceptionLivre {
public:
  InvalidDuracaoExceptionLivre(unsigned int duracao){
    cout << duracao << "utilizacoes livres tem de ser multiplas de 30min e no maximo 2h" << endl;
  }

}






#endif /* CAMPOS_H_ */
