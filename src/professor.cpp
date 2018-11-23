#include "professor.h"


FILE *profs;
const char* path="profs_registados.txt";

Professor::Professor(int id, string nome): Pessoa(id, nome) {}

Professor::Professor(string nome) : Pessoa(nome){}

const char * Professor::getInfo(){
	string toconvert = to_string(this->getID()) + ":" + this->getNome();
	const char * to_print = toconvert.c_str();
	return to_print;
}

void Professor::adicionar_aula(Aula * a1){
	aulas_dadas.push_back(a1);
}

bool Professor::remover_aula(Aula * a2){
	for(unsigned int i=0; i<aulas_dadas.size(); i++){
		if(aulas_dadas[i]==a2){
			aulas_dadas.erase(aulas_dadas.begin()+i);
			return true;
		}
	}
	return false;
}

vector<Aula*> Professor::getAulas() const{
	return this->aulas_dadas;
}
