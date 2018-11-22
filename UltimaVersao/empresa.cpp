/*
 * empresa.cpp
 *
 *  Created on: 17/11/2018
 *      Author: Cláudia Mamede
 */

#include "empresa.h"

float Empresa::cartao_gold_preco = 5.95;
float Empresa::desconto_cartao_gold = 0.15;
int Empresa::numero_maximo_utentes_por_campo=25;
float Empresa::preco_modo_livre=7.50;


void Empresa::adicionar_campo(campoTenis * c){
	campos.push_back(c);
}

void Empresa::adicionar_Utente(Utente * u){
	utentes.push_back(u);
}

void Empresa::adicionar_Professor(Professor * p){
	professores.push_back(p);
}

void Empresa::adicionar_Livre(Livre * l){
	modo_livre.push_back(l);
}

void Empresa::adicionar_Aula(Aula * a1){
	aulas.push_back(a1);
}
vector<Utente*> Empresa::getUtentes(){
	return utentes;
}
vector<Professor*> Empresa::getProfessores(){
	return professores;
}
vector<campoTenis*> Empresa::getCampos(){
	return campos;
}
vector<Aula*> Empresa::getAulas(){
	return aulas;
}

vector<Livre*> Empresa::getLivre(){
	return modo_livre;
}

bool Empresa::registar_CampoTenis(){
	string abertura, fecho;
	cout<<"Horario de abertura:  HHhMM"<<endl;
	cin>>abertura;
	cout<<"Horario de fecho:  HHhMM"<<endl;
	cin>>fecho;

	campoTenis* ct1=new campoTenis(numero_maximo_utentes_por_campo, abertura, fecho);
	this->adicionar_campo(ct1);
	cout<<"Esta açao por si só nao faz nada. Deverá acrescentar um dia de funcionamento."<<endl;
	return true;
}

bool Empresa::adicionar_DiadeAtividade(int idCampo){
	string dia;
	cout<<"Novo dia de atividade:"<<endl;
	cin>>dia;
	Dia d(dia);

	this->getCampos().at(idCampo)->adicionar_dia(dia);
	return true;
}

bool Empresa::criar_Utente(){
	string nome, password;
	int nivel, cartao;
	cout<<"Nome: ";
	cin>>nome;
	cout<<endl<<"Password: ";
	cin>>password;
	cout<<endl<<"Nivel: ";
	cin>>nivel;
	cout<<endl<<"Pretende aderir ao cartão gold com um custo fixo mensal de "<< cartao_gold_preco << "€ que permite o acesso a aulas com 15% desconto?"<<endl;
	cout<<"0. Não, obrigada!		1. Sim, quero!"<<endl;
	cin>>cartao;

	Utente* u1 = new Utente(nome, password, nivel, cartao);
	adicionar_Utente(u1);
	cout<<"Devera fazer login com o ID: "<<u1->getID()<<endl;
	return true;
}

bool Empresa::criar_Professor(){
	string nome;
	cout<<"Nome do professor: "<<endl;
	cin>>nome;

	Professor* p1 = new Professor(nome);
	adicionar_Professor(p1);
	cout<<"Devera fazer login com o ID: "<<p1->getID()<<endl;
	return true;
}


void Empresa::listar_DiadeAtividade(int idCampo, Data data){
	for(unsigned int i=0; i<getCampos().at(idCampo)->getOcupacao().size(); i++){
		cout<<"*****"<<getCampos().at(idCampo)->getOcupacao().size()<<endl;
		if(getCampos().at(idCampo)->getOcupacao().at(i).getData() == data){
			cout<<"Data:"<<data.data_friendly_print()<<endl;
			for(unsigned int j=0; j<getCampos().at(idCampo)->getOcupacao().at(i).getBlocos().size(); j++){
				cout<<"Horario: "<<getCampos().at(idCampo)->getOcupacao().at(i).getBlocos().at(j)->getInicioBloco().horario_friendly_print();
				cout<<"   Aula:"<<getCampos().at(idCampo)->getOcupacao().at(i).getBlocos().at(j)->getIdentificacaoAula();
				cout<<"   Livre:"<<getCampos().at(idCampo)->getOcupacao().at(i).getBlocos().at(j)->getIdentificacaoLivre()<<endl;
			}
		}
	}

	cout<<"Listagem completa. Prima uma tecla."<<endl;
	string tecla;
	cin>>tecla;


}

void Empresa::listar_allAulas(){
	string tecla;
	for(unsigned int i=0; i<getAulas().size(); i++){
		for(unsigned int j=0; j<getCampos().size(); j++){
			for(unsigned int k=0; k<getCampos().at(j)->getOcupacao().size(); k++){
				for(unsigned int l=0; l<getCampos().at(j)->getOcupacao().at(k).getBlocos().size(); l++){
					if(getAulas().at(i)->getIdentificacao() == getCampos().at(j)->getOcupacao().at(k).getBlocos().at(l)->getIdentificacaoAula()){
						cout<<getAulas().at(i)->getData().data_friendly_print()<<" \t ";
						cout<<getAulas().at(i)->getHorario().horario_friendly_print()<<" \t\t ";
						cout<<getCampos().at(j)->getNumeroCampo()<<" \t ";
						cout<<getCampos().at(j)->getOcupacao().at(k).getBlocos().at(l)->getIdentificacaoAula()<<endl;
						break;

					}
				}
			}

		}
	}


	cout<<"Listagem completa. Prima uma tecla."<<endl;
	cin>>tecla;

}

void Empresa::listar_Aulas(string nomeProfessor){
	for(unsigned int i=0; i<getProfessores().size(); i++){
		if(getProfessores().at(i)->getNome()==nomeProfessor){
			cout<<"    DIA        HORARIO        IDENTIFICACAO AULA"<<endl;
			for(unsigned int j=0; j<getProfessores().at(i)->getAulas().size(); j++){
				cout<<getProfessores().at(i)->getAulas().at(j)->getData().data_friendly_print()<<"        ";
				cout<<getProfessores().at(i)->getAulas().at(j)->getHorario().horario_friendly_print()<<"                ";
				cout<<getProfessores().at(i)->getAulas().at(j)->getIdentificacao();
			}
		}
	}

	cout<<"Listagem completa. Prima uma tecla."<<endl;
	string tecla;
	cin>>tecla;
}


void Empresa::listar_camposDisponiveis(){
	for(unsigned int i=0; i<getCampos().size(); i++){
		cout<<i<<":  "<<getCampos().at(i)->getNumeroCampo()<<"   ";
		cout<<getCampos().at(i)->getMaxUtilizadores()<<"    ";
		cout<<getCampos().at(i)->getHorarioAbertura().horario_friendly_print()<< "     ";
		cout<<getCampos().at(i)->getHorarioFecho().horario_friendly_print()<<endl;
	}
	cout<<endl<<endl;
}

void Empresa::listar_professoresDisponiveis(){
	for(unsigned int i=0; i<getProfessores().size(); i++){
		cout<<getProfessores().at(i)->getID()<<"     ";
		cout<<getProfessores().at(i)->getNome()<<endl;
	}
	cout<<endl<<endl;
}

void Empresa::listar_Alunos(){
	cout<<"ID\tNOME\t\tCARTAO\tNIVEL\tCONTA"<<endl;
	for(unsigned int i=0; i<getUtentes().size(); i++){
		cout<<getUtentes().at(i)->getID()<<"\t";
		cout<<getUtentes().at(i)->getNome()<<"\t";
		cout<<getUtentes().at(i)->getCartao()<<"\t";
		cout<<getUtentes().at(i)->getNivel()<<"\t";
		cout<<getUtentes().at(i)->getConta()<<endl;
	}

	cout<<endl<<"*NOTA: 0 para nao tem cartao; 1 para tem cartao"<<endl;
	cout<<"Listagem completa. Prima uma tecla."<<endl;
		string tecla;
		cin>>tecla;
}

float Empresa::getSaldo(){
	float saldo=0.0;

	for(unsigned int i=0; i<getUtentes().size(); i++){
		saldo+=getUtentes().at(i)->getConta();
	}

	return saldo;
}
void Empresa::getEstatisticas(){
	cout<<"Numero de campos:\t\t"<<getCampos().size()<<endl;
	cout<<"Numero de professores:\t\t"<<getProfessores().size()<<endl;
	cout<<"Numero de utentes:\t\t"<<getUtentes().size()<<endl;
	cout<<"Numero de aulas:\t\t"<<getAulas().size()<<endl;
	cout<<"Numero de utilizacoes em modo livre: "<<getLivre().size()<<endl;
	cout<<"Ganhos da empresa:\t\t"<<getSaldo()<<"€"<<endl<<endl;

	cout<<"Listagem completa. Prima uma tecla."<<endl;
			string tecla;
			cin>>tecla;

}
bool Empresa::criar_Aula(){
	string hora_inicio, data;
	float preco;
	cout<<"Data da aula (DD-MM-YYYY): ";
	cin>>data;
	cout<<endl<<"Hora de inicio (HHhMM): ";
	cin>>hora_inicio;
	cout<<endl<<"Preco por pessoa: (float)";
	cin>>preco;

	Aula *a1 = new Aula(data, hora_inicio, preco);
	int id= a1->getIdentificacao();

	/* ESCOLHER PROFESSOR */
	Professor *menosOcupado=getProfessores().at(0);

	for(unsigned int i=1; i<getProfessores().size(); i++){
		if(menosOcupado->getAulas().size() > getProfessores().at(i)->getAulas().size()){
			menosOcupado=getProfessores().at(i);
		}
	}

	/* ATRIBUIR CAMPO */
	for(unsigned int i=0; i<getCampos().size(); i++){
		for(unsigned int j=0; j<getCampos().at(i)->getOcupacao().size(); j++){
			if(getCampos().at(i)->getOcupacao().at(j).getData() == data){
				for(unsigned int k=0; k<getCampos().at(i)->getOcupacao().at(j).getBlocos().size()-1; k++){
					if(getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k)->getInicioBloco() == hora_inicio){
						if(getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k)->getIdentificacaoAula() == 0){
							if(getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k+1)->getIdentificacaoAula() == 0){
								getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k)->setIdentificacaoAula(id);
								getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k+1)->setIdentificacaoAula(id);

								adicionar_Aula(a1); //adiciona aula ao vetor "aulas"
								menosOcupado->adicionar_aula(a1); //adiciona a aula ao professor menos ocupado
								return true;
							}
						}
					}
				}
			}
		}
	}

	return false;
}

bool Empresa::criar_Modo_Livre(){
	string hora_inicio, data;
	int duracao;
	cout<<"Data do aluguer (DD-MM-YYYY): ";
	cin>>data;
	cout<<endl<<"Hora de inicio (HHhMM): ";
	cin>>hora_inicio;
	cout<<endl<<"Duracao:   nº blocos de 30min"<<endl;
	cin>>duracao;


	Livre *l1 = new Livre(data, hora_inicio, duracao, preco_modo_livre);
	int id= l1->getIdentificacao();


	/* ATRIBUIR CAMPO */
	for(unsigned int i=0; i<getCampos().size(); i++){
		for(unsigned int j=0; j<getCampos().at(i)->getOcupacao().size(); j++){
			if(getCampos().at(i)->getOcupacao().at(j).getData() == data){
				for(unsigned int k=0; k<getCampos().at(i)->getOcupacao().at(j).getBlocos().size()-1; k++){
					if(getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k)->getInicioBloco() == hora_inicio){
						//ESTOU NO BLOCO INICIAL ->verificar para duracao blocos
						for(int x=0; x<duracao; x++){
							if(getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k+x)->getIdentificacaoLivre() == 0){
								getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k+x)->setIdentificacaoLivre(id);
							}


						}
						adicionar_Livre(l1); //adiciona aula ao vetor "livre"
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool Empresa::findUtente(int id){
	for(unsigned int i=0; i<getUtentes().size(); i++){
		if(getUtentes().at(i)->getID() == id){
			return true;
		}
	}
	return false;
}

bool Empresa::checkPassword(int id, string password){
	for(unsigned int i=0; i<getUtentes().size(); i++){
		if(getUtentes().at(i)->getID() == id && getUtentes().at(i)->getPassword() == password){
			return true;
		}
	}

	return false;
}

bool Empresa::juntar_a_aula(int idAluno){
	bool sucesso=false;
	int id_aula;
	cout<<"Escolha a aula: ";
	cin>>id_aula;

	while(id_aula < 0 || id_aula >= getAulas().size()){
		cout<<"Escolha uma aula valida aula: ";
		cin>>id_aula;
	}

	for(unsigned int i=0; i<getUtentes().size(); i++){
		if(getUtentes().at(i)->getID() == idAluno){
			sucesso=getAulas().at(id_aula)->adicionar_aluno(getUtentes().at(i));
			if(sucesso){
				if(getUtentes().at(i)->getCartao()){
					getUtentes().at(i)->somar_aula( getAulas().at(id_aula)->getPreco() - (desconto_cartao_gold * getAulas().at(id_aula)->getPreco() ));
				}
				else{
					getUtentes().at(i)->somar_aula( getAulas().at(id_aula)->getPreco());
				}

			}
			return sucesso;
		}
	}

	return false;

}

bool Empresa::juntar_a_modo_livre(int idAluno){
	bool sucesso=false;
	int id_modo_livre;
	cout<<"Escolha o modo livre: ";
	cin>>id_modo_livre;

	while(id_modo_livre < 0 || id_modo_livre >= getLivre().size() ){
		cout<<"Escolha um modo livre válido. "<<endl;
		cout<<"Relembramos que deve fazer reserva do campo antes de se juntar."<<endl;
		cin>>id_modo_livre;
	}

	for(unsigned int i=0; i<getUtentes().size(); i++){
		if(getUtentes().at(i)->getID() == idAluno){
			sucesso=getLivre().at(id_modo_livre)->adicionar_ao_grupo(getUtentes().at(i));
			if(sucesso){
				getUtentes().at(i)->somar_aula(getLivre().at(id_modo_livre)->getPreco());
			}
			return sucesso;
		}
	}

	return false;
}

int Empresa::guardarConfig(){
	/*GUARDAR INFO DOS CAMPOS*/
	ofstream campos;
	campos.open ("./Files/campos_temp.txt", ofstream::out);
	for(unsigned int i=0; i<getCampos().size(); i++){
		campos<<getCampos().at(i)->getInfo();
	}
	campos.close();


	/*GUARDAR INFO DOS ALUNOS*/
	ofstream alunos;
	alunos.open("./Files/alunos_temp.txt", ofstream::out);
	for(unsigned int j=0; j<getUtentes().size(); j++)
		alunos<<getUtentes().at(j)->getInfo();
	alunos.close();


	/*GUARDAR INFO DOS PROFS*/
	ofstream professor;
	professor.open("./Files/professores_temp.txt", ofstream::out);
	for(unsigned int k=0; k<getProfessores().size(); k++){
		professor<<getProfessores().at(k)->getInfo();
	}
	professor.close();


	/*GUARDAR INFO DAS AULAS*/
	ofstream aulas;
	aulas.open("./Files/aulas_temp.txt", ofstream::out);
	for(unsigned int l=0; l<getCampos().size(); l++){
		for(unsigned int n=0; n<getCampos().at(l)->getOcupacao().size(); n++){
			for(unsigned int m=0; m<getCampos().at(l)->getOcupacao().at(n).getBlocos().size(); m++){
				for(unsigned int x=0; x<getAulas().size(); x++){
					if(getAulas().at(x)->getIdentificacao() == getCampos().at(l)->getOcupacao().at(n).getBlocos().at(m)->getIdentificacaoAula()){
						aulas<<getCampos().at(l)->getNumeroCampo()<<":"<<getAulas().at(x)->getInfo()<<endl;
					}
				}
			}
		}
	}



	ifstream  src1("./Files/campos_temp.txt",ios::binary);
	ofstream  dst1("./Files/campos.txt",ios::binary);
	ifstream  src2("./Files/alunos_temp.txt", ios::binary);
	ofstream  dst2("./Files/alunos.txt",ios::binary);
	ifstream  src3("./Files/aulas_temp.txt",ios::binary);
	ofstream  dst3("./Files/aulas.txt",ios::binary);
	ifstream  src4("./Files/professores_temp.txt",ios::binary);
	ofstream  dst4("./Files/professores.txt",ios::binary);

}

void Empresa::verDadosUtente(int idAluno){
	for(unsigned int i=0; i<getUtentes().size(); i++){
		if(getUtentes().at(i)->getID()==idAluno){
			cout<<"Conta: "<<getUtentes().at(i)->getConta()<<endl;
			cout<<"Nivel: "<<getUtentes().at(i)->getNivel()<<endl;
		}
	}
	cout<<"Listagem completa. Prima uma tecla."<<endl;
	string tecla;
	cin>>tecla;

}

void Empresa::verAula(int idAluno){

	cout<<"IDENTIFICACAO\tDATA \tHORARIO"<<endl;
	for(unsigned int i=0; i<getAulas().size(); i++){
		for(unsigned int j=0; j<getAulas().at(i)->getAlunos().size(); j++){
			if(getAulas().at(i)->getAlunos().at(j)->getID() == idAluno){
				cout<<getAulas().at(i)->getIdentificacao()<<"\t\t";
				cout<<getAulas().at(i)->getData().data_friendly_print()<<"\t";
				cout<<getAulas().at(i)->getHorario().horario_friendly_print()<<"\t"<<endl;

			}
		}
	}

	cout<<"Listagem completa. Prima uma tecla."<<endl;
	string tecla;
	cin>>tecla;
}
