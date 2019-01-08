#include "empresa.h"

float Empresa::cartao_gold_preco = 5.95;
float Empresa::desconto_cartao_gold = 0.15;
int Empresa::numero_maximo_utentes_por_campo=25;
float Empresa::preco_modo_livre=7.50;


void Empresa::adicionar_campo(campoTenis * c){
	campos.push_back(c);
}

void Empresa::adicionarUtilizador(Utente &u1){
	utilizadores.insert(u1);
}

void Empresa::adicionarProfessor(Professor *p1){
	profPtr ptr;
	ptr.prof = p1;
	professores.insert(ptr);
}

void Empresa::adicionar_Livre(Livre * l){
	modo_livre.push_back(l);
}

void Empresa::adicionar_Aula(Aula * a1){
	aulas.push_back(a1);
}
BST<Utente> Empresa::getUtentes(){
	return utilizadores;
}
tabHProfessores Empresa::getProfessores(){
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
	cout<<"Esta acao por si so nao faz nada. Devera acrescentar um dia de funcionamento."<<endl;
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
	cout<<endl<<"Pretende aderir ao cartao gold com um custo fixo mensal de "<< cartao_gold_preco << "� que permite o acesso a aulas com 15% desconto?"<<endl;
	cout<<"0. Nao, obrigada!		1. Sim, quero!"<<endl;
	cin>>cartao;


	Utente u1(nome, password, nivel, (bool)cartao);

	adicionarUtilizador(u1);
	cout<<"Devera fazer login com o ID: "<<u1.getID()<<endl;
	return true;
}

bool Empresa::criar_Professor(){
	string nome;
	cout<<"Nome do professor: "<<endl;
	cin>>nome;

	Professor* p1 = new Professor(nome);
	adicionarProfessor(p1);
	cout<<"Devera fazer login com o ID: "<<p1->getID()<<endl;
	return true;
}


void Empresa::listar_DiadeAtividade(int idCampo, Data data){
	for(unsigned int i=0; i<getCampos().at(idCampo)->getOcupacao().size(); i++){
		if(getCampos().at(idCampo)->getOcupacao().at(i).getData() == data){
			cout<<"Data:"<<data.data_friendly_print()<<endl;
			for(unsigned int j=0; j<getCampos().at(idCampo)->getOcupacao().at(i).getBlocos().size(); j++){
				cout<<"Horario: "<<getCampos().at(idCampo)->getOcupacao().at(i).getBlocos().at(j)->getInicioBloco().horario_friendly_print();
				cout<<"\tAula:"<<getCampos().at(idCampo)->getOcupacao().at(i).getBlocos().at(j)->getIdentificacaoAula();
				cout<<"\tLivre:"<<getCampos().at(idCampo)->getOcupacao().at(i).getBlocos().at(j)->getIdentificacaoLivre()<<endl;
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
	auto it = professores.begin();

	for(it; it!=professores.end(); it++){
		string name = (*it).prof->getNome();
		if (name == nomeProfessor){
			for(unsigned int j=0; j<(*it).prof->getAulas().size(); j++){
				cout<<(*it).prof->getAulas().at(j)->getData().data_friendly_print()<<"\t\t";
				cout<<(*it).prof->getAulas().at(j)->getHorario().horario_friendly_print()<<"\t\t\t\t";
				cout<<(*it).prof->getAulas().at(j)->getIdentificacao();

			}
		}
	}

	cout<<"Listagem completa. Prima uma tecla."<<endl;
	string tecla;
	cin>>tecla;
}


void Empresa::listar_camposDisponiveis(){
	for(unsigned int i=0; i<getCampos().size(); i++){
			cout<<getCampos().at(i)->getNumeroCampo()<<"\t";
			cout<<getCampos().at(i)->getMaxUtilizadores()<<"\t\t";
			cout<<getCampos().at(i)->getHorarioAbertura().horario_friendly_print()<< "\t\t";
			cout<<getCampos().at(i)->getHorarioFecho().horario_friendly_print()<<endl;
		}
		cout<<endl<<endl;
}

void Empresa::listar_professoresDisponiveis(){
	auto it = professores.begin();

	for(it; it!=professores.end(); it++){
		cout<<(*it).prof->getID()<<"\t";
		cout<<(*it).prof->getNome()<<"\t"<<endl;
	}

	cout<<endl<<endl;
}

void Empresa::listar_Alunos(){
	cout<<"ID\tNOME\tCARTAO\tNIVEL\tCONTA"<<endl;
	BSTItrIn<Utente> it(utilizadores);


	while(!it.isAtEnd()){
		cout<<it.retrieve().getID()<<"\t";
		cout<<it.retrieve().getNome()<<"\t";
		cout<<it.retrieve().getCartao()<<"\t";
		cout<<it.retrieve().getNivel()<<"\t";
		cout<<it.retrieve().getConta()<<endl;

		it.advance();
	}


	cout<<endl<<"*NOTA: 0 para nao tem cartao; 1 para tem cartao"<<endl;
	cout<<"Listagem completa. Prima uma tecla."<<endl;
		string tecla;
		cin>>tecla;
}

float Empresa::getSaldo(){
	float saldo=0.0;

	BSTItrIn<Utente> it(utilizadores);
	while(!it.isAtEnd()){
		saldo+=it.retrieve().getConta();
		it.advance();
	}

	return saldo;
}

void Empresa::getEstatisticas(){
	BSTItrIn<Utente> it(utilizadores);
	int contador=0;
	while(!it.isAtEnd()){
		contador++;
		it.advance();
	}

	cout<<"Numero de campos:\t\t"<<getCampos().size()<<endl;
	cout<<"Numero de professores:\t\t"<<getProfessores().size()<<endl;
	cout<<"Numero de utentes:\t\t"<<contador<<endl;
	cout<<"Numero de aulas:\t\t"<<getAulas().size()<<endl;
	cout<<"Numero de utilizacoes em modo livre: "<<getLivre().size()<<endl;
	cout<<"Ganhos da empresa:\t\t"<<getSaldo()<<endl<<endl;

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
	Professor *menosOcupado = (*professores.begin()).prof;

	auto it=professores.begin();
	for(it; it!=professores.end(); it++){
		Professor *p1 = (*it).prof;
		if(menosOcupado->getAulas().size() > p1->getAulas().size()){
			menosOcupado = p1;
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
	cout<<endl<<"Duracao:   n� blocos de 30min"<<endl;
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
	BSTItrIn<Utente> it(utilizadores);
	while(!it.isAtEnd()){
		if(it.retrieve().getID() == id)
			return true;

		it.advance();
	}
	return false;
}

bool Empresa::checkPassword(int id, string password){

	BSTItrIn<Utente> it(utilizadores);
		while(!it.isAtEnd()){
			if(it.retrieve().getID() == id && it.retrieve().getPassword()==password)
				return true;

			it.advance();
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

	BSTItrIn<Utente> it(utilizadores);
	while(!it.isAtEnd()){
		if(it.retrieve().getID() == idAluno){
			Utente u1 = it.retrieve();
			sucesso=getAulas().at(id_aula)->adicionar_aluno(&u1);
			if(sucesso){
				utilizadores.remove(u1);
				u1.acrescentaAula(1);
				if(it.retrieve().getCartao()){
					u1.somar_aula(getAulas().at(id_aula)->getPreco() - (desconto_cartao_gold * getAulas().at(id_aula)->getPreco() ));
				}
				else{
					u1.somar_aula(getAulas().at(id_aula)->getPreco());
				}
				utilizadores.insert(u1);
			}
			return sucesso;
		}
		it.advance();
	}
	return false;

}

bool Empresa::juntar_a_modo_livre(int idAluno){
	bool sucesso=false;
	int id_modo_livre;
	cout<<"Escolha o modo livre: ";
	cin>>id_modo_livre;

	while(id_modo_livre < 0 || id_modo_livre >= getLivre().size() ){
		cout<<"Escolha um modo livre v�lido. "<<endl;
		cout<<"Relembramos que deve fazer reserva do campo antes de se juntar."<<endl;
		cin>>id_modo_livre;
	}

	BSTItrIn<Utente> it(utilizadores);
	while(!it.isAtEnd()){
		if(it.retrieve().getID() == idAluno){
			Utente u1 = it.retrieve();
			sucesso=getLivre().at(id_modo_livre)->adicionar_ao_grupo(&u1);
			if(sucesso){
				utilizadores.remove(u1);
				u1.acrescentaLivre(1);
				u1.somar_aula(getLivre().at(id_modo_livre)->getPreco());
				utilizadores.insert(u1);
			}
			return sucesso;
		}
		it.advance();
	}

	return false;
}

int Empresa::guardarConfig(){
	/*GUARDAR INFO DOS CAMPOS*/
	ofstream campos;
	campos.open ("./Files/campos_temp.txt", ofstream::out);
	for(unsigned int i=0; i<getCampos().size(); i++){
		campos<<getCampos().at(i)->getInfo()<<endl;
	}
	campos.close();


	/*GUARDAR INFO DOS ALUNOS*/
	ofstream utentes;
	BSTItrIn<Utente> it(utilizadores);
	utentes.open("./Files/alunos_temp.txt", ofstream::out);

	while(!it.isAtEnd()){
		Utente u1 = it.retrieve();
		utentes<<u1.getInfo()<<endl;

		it.advance();
	}
	utentes.close();


	/*GUARDAR INFO DOS PROFS*/
	ofstream professor;
	professor.open("./Files/professores_temp.txt", ofstream::out);
	auto itprof = professores.begin();

	for(itprof; itprof!=getProfessores().end(); itprof++){
		Professor *p1 = (*itprof).prof;
		professor<<p1->getInfo()<<endl;
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



	ifstream  src1("./Files/campos_temp.txt");
	ofstream  dst1("./Files/campos.txt");
	ifstream  src2("./Files/alunos_temp.txt");
	ofstream  dst2("./Files/alunos.txt");
	ifstream  src3("./Files/aulas_temp.txt");
	ofstream  dst3("./Files/aulas.txt");
	ifstream  src4("./Files/professores_temp.txt");
	ofstream  dst4("./Files/professores.txt");


}

void Empresa::verDadosUtente(int idAluno){
	BSTItrIn<Utente> it(utilizadores);
	while(!it.isAtEnd()){
		if(it.retrieve().getID() == idAluno){
			cout<<"Conta: "<<it.retrieve().getConta()<<endl;
			cout<<"Nivel: "<<it.retrieve().getNivel()<<endl;
		}
		it.advance();
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

bool Empresa::atribuir_campo_prof(int idCampo, int idAula, string data, string horario, float preco){
	Aula *a1 = new Aula(idAula, data, horario, preco);

	Professor *menosOcupado = (*professores.begin()).prof;
	auto it=professores.begin();

	for(it; it!=professores.end(); it++){
		Professor *p1 = (*it).prof;
		if(menosOcupado->getAulas().size() > p1->getAulas().size()){
			menosOcupado = p1;
		}
	}



	/* ATRIBUIR CAMPO */
		for(unsigned int i=0; i<getCampos().size(); i++){
			for(unsigned int j=0; j<getCampos().at(i)->getOcupacao().size(); j++){
				if(getCampos().at(i)->getOcupacao().at(j).getData() == data){
					for(unsigned int k=0; k<getCampos().at(i)->getOcupacao().at(j).getBlocos().size()-1; k++){
						if(getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k)->getInicioBloco().horario_friendly_print() == horario){
							if(getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k)->getIdentificacaoAula() == 0){
								if(getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k+1)->getIdentificacaoAula() == 0){
									getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k)->setIdentificacaoAula(idAula);
									getCampos().at(i)->getOcupacao().at(j).getBlocos().at(k+1)->setIdentificacaoAula(idAula);

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



void Empresa::changeNivel(int idAluno){
	int newnivel;
	bool sucesso=false;

	BSTItrIn<Utente> it(utilizadores);
	while(!it.isAtEnd()){
		Utente u1 = it.retrieve();
		if(u1.getID() == idAluno){
			cout<<"Escolha o novo nivel: ";
			cin>>newnivel;

			while(newnivel<0 || newnivel>5){
				cout<<"Escolha um nivel valido [1-5]."<<endl;
				cin>>newnivel;
			}

			utilizadores.remove(u1);
			u1.setNivel(newnivel);
			utilizadores.insert(u1);
			sucesso=true;
			break;
		}
		it.advance();
	}

	if(sucesso){
		cout<<"O nivel foi alterado para "<<newnivel<<". Prima uma tecla."<<endl;
		string tecla;
		cin>>tecla;
	}
	else {
		cout<<"O utente em questao nao foi encontrado. Tente com outro ID."<<endl;
		string tecla;
		cin>>tecla;
	}
}
