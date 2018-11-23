#include <stdio.h>
#include "aula.h"

int Aula::id=0;
int Aula::numero_maximo_utilizadores_por_aula=10;

Aula::Aula(string data, string horario, float preco): Utilizacao(data, horario, preco){
	identificacao=id;
	id++;
}

Aula::Aula(int ident, string data, string horario, float preco): Utilizacao(data, horario, preco){
	this->identificacao=ident;
	id=ident;
	id++;
}

bool Aula::adicionar_aluno(Utente * u1){
	if(alunos.size() < numero_maximo_utilizadores_por_aula)
	{
		alunos.push_back(u1);
		return true;
	}

	return false;
}

bool Aula::remover_aluno(Utente * u1){
	for(unsigned int i=0; i<alunos.size(); i++){
		if(alunos[i] == u1){
			alunos.erase(alunos.begin()+i);
			return true;
		}
	}
	return false;
}

string Aula::getInfo(){
	string toconvert = to_string(this->getIdentificacao()) + ":" + this->getData().data_friendly_print() + ":" + this->getHorario().horario_friendly_print() + to_string(this->getPreco());
	//const char * to_print = toconvert.c_str();

	return toconvert;
}

bool Aula::operator==(const Aula &a2){
	if(this->getIdentificacao() == a2.getIdentificacao()){
		return true;
	}
	else
		return false;
}

vector<Utente*> Aula::getAlunos() const{
	return alunos;
}

int Aula::getIdentificacao() const{
	return identificacao;
}
