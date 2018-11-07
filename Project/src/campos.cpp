#include "campos.h"

CampoTenis::CampoTenis(unsigned int id, const int nMaxUtentes){
  this->nMaxUtentes=nMaxUtentes;

  counter++;
  this->id=counter;
}

CampoTenis::~CampoTenis() { //Auto generated destructor ?}

const unsigned int CampoTenis::getID() const{
  return id;
}

unsigned int CampoTenis::getnMaxUtentes() const{
  return nMaxUtentes;
}

Utilizacao::Utilizacao(/*unsigned int CampoTenis::id, */ float preco, unsigned int duracao, unsigned int NumUtilizadores){
  //this->id = CampoTenis::getID();
  this->preco = preco;
  this->duracao = duracao;
  this->NumUtilizadores = NumUtilizadores;
}

Utilizacao::~Utilizacao () {}


float Utilizacao::getPreco(){
  return preco;
}

unsigned int Utilizacao::getDuracao(){
  return duracao;
}

unsigned int Utilizacao::getNumUtilizadores() {
  return NumUtilizadores;
}

bool Utilizacao::checkIfFull(const int nMaxUtentes) {

  return false;
  }

bool Livre::checkDuracao(unsigned int duracao){
  return true;
}

bool Aula::checkDuracao(unsigned int duracao){
  return true;
}
