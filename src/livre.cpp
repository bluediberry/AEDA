#include "livre.h"

int Livre::id=0;
int Livre::numero_maximo_utilizadores_modo_livre=15;

Livre::Livre(string data, string horario, float preco, unsigned int duracao): Utilizacao(data, horario, preco){
	this->duracao=duracao;
	identificacao=id;
	id++;
}

void Livre::setDuracao(int duracao){
	int dur;
	this->duracao=duracao;

	while(duracao<0 || duracao >5){
		cout<<"O tempo m�ximo de ocupacao de um campo em tempo livre � 2h30."<<endl;
		cout<<"Escolha um numero de 1(30min)-5(2h30)."<<endl;
		cin>>dur;
		setDuracao(dur);
	}
}

int Livre::getDuracao() const{
	return this->duracao;
}

bool Livre::adicionar_ao_grupo(Utente * u1){
	if(grupo.size() < numero_maximo_utilizadores_modo_livre){
		grupo.push_back(u1);
		return true;
	}

	throw ExceptionMaxUtentes();
	return false;
}

bool Livre::remover_do_grupo(Utente * u1){
	for(unsigned int i=0; i<grupo.size(); i++){
		if(grupo[i]==u1){
			grupo.erase(grupo.begin()+i);
			return true;
		}
	}

	return false;
}

float Livre::getPrecoPorPessoa(){
	float preco_por_pessoa=this->getPreco()/(grupo.size());

	return preco_por_pessoa;
}

vector<Utente*> Livre::getGrupo() const{
	return grupo;
}

string Livre::getInfo(){
	string toconvert = to_string(this->getIdentificacao())+":"+this->getData().data_friendly_print()+":"+this->getHorario().horario_friendly_print()+":"+to_string(this->getDuracao())+":"+to_string(this->getPreco())+to_string(this->getGrupo().size());
	//const char * to_print = toconvert.c_str();
	return toconvert;
}

int Livre::getIdentificacao() const{
	return identificacao;
}
