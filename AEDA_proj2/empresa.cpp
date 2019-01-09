#include "empresa.h"

float Empresa::cartao_gold_preco = 5.95;
float Empresa::desconto_cartao_gold = 0.15;
int Empresa::numero_maximo_utentes_por_campo=25;
float Empresa::preco_modo_livre=7.50;

Empresa::Empresa() : utilizadores(Utente("", "",0,true)){
	gastosEmReparacoes=0;
}
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
}

void Empresa::listar_allAulas(){
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
}


void Empresa::listar_camposDisponiveis(){
	cout<<"ID\tMAX UTIL\tABERTURA\tFECHO"<<endl;
	for(unsigned int i=0; i<getCampos().size(); i++){
			cout<<getCampos().at(i)->getNumeroCampo()<<"\t";
			cout<<getCampos().at(i)->getMaxUtilizadores()<<"\t\t";
			cout<<getCampos().at(i)->getHorarioAbertura().horario_friendly_print()<< "\t\t";
			cout<<getCampos().at(i)->getHorarioFecho().horario_friendly_print()<<endl;
		}
}

void Empresa::listar_professoresDisponiveis(){
	auto it = professores.begin();
	for(it; it!=professores.end(); it++){
		cout<<(*it).prof->getID()<<"\t";
		cout<<(*it).prof->getNome()<<"\t"<<endl;
	}
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
	cout<<"Ganhos da empresa:\t\t"<<getSaldo()<<endl;
	cout<<"Gastos da empresa:\t\t"<<getGastosEmReparacoes()<<endl;
	cout<<"Numero de tecnicos associados:\t"<<getTecnicos().size()<<endl<<endl;
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
	cout<<endl<<"Duracao:   nr blocos de 30min"<<endl;
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
		cout<<"Escolha um modo livre valido. "<<endl;
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

void Empresa::guardarConfig(){
	/*GUARDAR INFO DOS CAMPOS*/
	ofstream campos;
	campos.open ("./Files/campos.txt");
	for(unsigned int i=0; i<getCampos().size(); i++){
		campos<<getCampos().at(i)->getInfo()<<endl;
	}
	campos.close();


	/*GUARDAR INFO DOS UTENTES*/
	ofstream utentes;
	BSTItrIn<Utente> it(utilizadores);
	utentes.open("./Files/utentes.txt");

	while(!it.isAtEnd()){
		Utente u1 = it.retrieve();
		string info = it.retrieve().getInfo();
		utentes<<info<<endl;
		it.advance();
	}
	utentes.close();


	/*GUARDAR INFO DOS PROFS*/
	ofstream professor;
	professor.open("./professores.txt");
	auto itprof = professores.begin();

	for(itprof; itprof!=getProfessores().end(); itprof++){
		Professor *p1 = (*itprof).prof;
		professor<<p1->getInfo()<<endl;
	}
	professor.close();


	/*GUARDAR INFO DOS TECNICOS*/
	ofstream tecs;
	tecs.open("./Files/tecnicos.txt");
	vector<Tecnico> temp1;

	while(!tecnicos.empty()){
		Tecnico t1 = tecnicos.top();
		tecs<<t1.getInfo()<<endl;
		tecnicos.pop();
		temp1.push_back(t1);
	}

	for(unsigned int i=0; i<temp1.size(); i++){
		tecnicos.push(temp1[i]);
	}


	/*GUARDAR INFO DAS AULAS*/
	ofstream aulas;
	aulas.open("./Files/aulas.txt");
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

	/**GUARDAR INFO REPARACOES*/
	ofstream reparacoes;
	reparacoes.open("./Files/reparacoes.txt");
	vector<Tecnico> temp2;

	while(!tecnicos.empty()){
		Tecnico t1 = tecnicos.top();
		for(unsigned int i=0; i<t1.getCamposReparados().size(); i++){
			reparacoes<<t1.getID()<<":"<<t1.getCamposReparados().at(i)->getNumeroCampo()<<":"<<t1.getDiasReparacao()[i]->data_friendly_print()<<endl;
		}

		tecnicos.pop();
		temp1.push_back(t1);
	}

	for(unsigned int i=0; i<temp2.size(); i++){
		tecnicos.push(temp2[i]);
	}
}

void Empresa::abrirConfig(){
	//campos
	string line, abertura, fecho;
	int idCampo, numUtilizadores;
	int pointsIndex;
	ifstream campos;
	campos.open("./Files/campos.txt");
	while(getline(campos, line)){
		pointsIndex=line.find_first_of(':');
		idCampo = atoi((line.substr(0,pointsIndex)).c_str());
		line.erase(0, pointsIndex+1);

		pointsIndex=line.find_first_of(':');
		numUtilizadores = atoi((line.substr(0,pointsIndex)).c_str());
		line.erase(0, pointsIndex+1);

		pointsIndex=line.find_first_of(':');
		abertura=line.substr(0,pointsIndex);
		line.erase(0, pointsIndex+1);

		pointsIndex=line.find_first_of(':');
		fecho=line.substr(0,pointsIndex);
		line.erase(0, pointsIndex+1);

		campoTenis *ct1 = new campoTenis(idCampo, numUtilizadores, abertura, fecho);
		adicionar_campo(ct1);
	}

	//utentes
	string line1, password, nome;
	int idUtilizador, nivel, cartao, nlivre, naulas;
	float conta;
	ifstream utentes;
	utentes.open("./Files/utentes.txt");
	while(getline(utentes, line1)){
		pointsIndex=line1.find_first_of(':');
		idUtilizador = atoi((line1.substr(0,pointsIndex)).c_str());
		line1.erase(0, pointsIndex+1);

		pointsIndex=line1.find_first_of(':');
		cartao = atoi((line1.substr(0,pointsIndex)).c_str());
		line1.erase(0, pointsIndex+1);

		pointsIndex=line1.find_first_of(':');
		nivel=atoi(line1.substr(0,pointsIndex).c_str());
		line1.erase(0, pointsIndex+1);

		pointsIndex=line1.find_first_of(':');
		password=line1.substr(0,pointsIndex);
		line1.erase(0, pointsIndex+1);

		pointsIndex=line1.find_first_of(':');
		conta=atof(line1.substr(0,pointsIndex).c_str());
		line1.erase(0, pointsIndex+1);

		pointsIndex=line1.find_first_of(':');
		naulas=atoi(line1.substr(0,pointsIndex).c_str());
		line1.erase(0, pointsIndex+1);

		pointsIndex=line1.find_first_of(':');
		nlivre=atoi(line1.substr(0,pointsIndex).c_str());
		line1.erase(0, pointsIndex+1);

		pointsIndex=line1.find_first_of(':');
		nome=line1.substr(0,pointsIndex);
		line1.erase(0, pointsIndex+1);

		Utente u1(idUtilizador, nome, password, nivel, cartao, nlivre, naulas, conta);
		adicionarUtilizador(u1);
	}

	//professores
	string line3, nomeProf;
	int idProfessor;
	ifstream professores;
	professores.open("./Files/professores.txt");
	while(getline(professores, line3)){
		pointsIndex=line3.find_first_of(':');
		idProfessor = atoi((line3.substr(0,pointsIndex)).c_str());
		line3.erase(0, pointsIndex+1);

		pointsIndex=line3.find_first_of(':');
		nomeProf=line3.substr(0,pointsIndex);
		line3.erase(0, pointsIndex+1);

		Professor *p1 = new Professor(idProfessor, nomeProf);
		adicionarProfessor(p1);
	}

	//aulas+dias
	string line4, data, horario;
	int idAula, idCampo2;
	float preco;
	ifstream aulas;
	aulas.open("./Files/aulas.txt");
	while(getline(aulas, line4)){
		pointsIndex=line4.find_first_of(':');
		idCampo2 = atoi((line4.substr(0,pointsIndex)).c_str());
		line4.erase(0, pointsIndex+1);

		pointsIndex=line4.find_first_of(':');
		idAula=atoi((line4.substr(0,pointsIndex)).c_str());
		line4.erase(0, pointsIndex+1);

		pointsIndex=line4.find_first_of(':');
		data=line4.substr(0,pointsIndex);
		line4.erase(0, pointsIndex+1);

		pointsIndex=line4.find_first_of(':');
		horario=line4.substr(0,pointsIndex);
		line4.erase(0, pointsIndex+1);

		pointsIndex=line4.find_first_of(':');
		preco=atof(line4.substr(0,pointsIndex).c_str());
		line4.erase(0, pointsIndex+1);


		atribuir_campo_prof(idCampo2, idAula, data, horario, preco);
	}


	//tecnicos
	string line6, nomeTec;
	int DiasAteDisponibilidade, nrReparacoes, idTecnico;
	float custoReparacao;
	ifstream tecnicos;
	tecnicos.open("./File/tecnicos.txt");
	while(getline(tecnicos, line6)){
		pointsIndex=line6.find_first_of(':');
		idTecnico = atoi((line6.substr(0,pointsIndex)).c_str());
		line6.erase(0, pointsIndex+1);

		pointsIndex=line6.find_first_of(':');
		nomeTec=line6.substr(0,pointsIndex);
		line6.erase(0, pointsIndex+1);

		pointsIndex=line6.find_first_of(':');
		custoReparacao=atof(line6.substr(0,pointsIndex).c_str());
		line6.erase(0, pointsIndex+1);

		pointsIndex=line6.find_first_of(':');
		nrReparacoes = atoi((line6.substr(0,pointsIndex)).c_str());
		line6.erase(0, pointsIndex+1);

		pointsIndex=line6.find_first_of(':');
		DiasAteDisponibilidade = atoi((line6.substr(0,pointsIndex)).c_str());
		line6.erase(0, pointsIndex+1);

		Tecnico t1(idTecnico, nomeTec, nrReparacoes, DiasAteDisponibilidade, custoReparacao, "01-01-1999");
		adicionarTecnico(t1);
	}

	//reparacoes
	string line5, data2;
	int idCampo3, idTecnico2;

	ifstream reparacoes;
	reparacoes.open("./Files/reparacoes.txt");
	while(getline(reparacoes, line5)){
		pointsIndex = line5.find_first_of(':');
		idTecnico2 = atoi((line5.substr(0, pointsIndex)).c_str());
		line5.erase(0, pointsIndex+1);

		pointsIndex=line5.find_first_of(':');
		idCampo3=atoi((line5.substr(0,pointsIndex)).c_str());
		line5.erase(0, pointsIndex+1);

		pointsIndex=line5.find_first_of(':');
		data2=line5.substr(0,pointsIndex);
		line5.erase(0, pointsIndex+1);

		adicionarReparacao(idTecnico2, idCampo3, data2);
	}


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
		cout<<"O nivel foi alterado para "<<newnivel<<endl;
	}
	else {
		cout<<"O utente em questao nao foi encontrado. Tente com outro ID."<<endl;
	}
}

void Empresa::adicionarTecnico(Tecnico &t1) {
	tecnicos.push(t1);
}

priority_queue<Tecnico> Empresa::getTecnicos() {
	return tecnicos;
}

bool Empresa::atribuirReparacao(int idCampo, string dataReparacao){
	vector<Tecnico> temp;

	while(!tecnicos.empty()){
		Tecnico t1 = tecnicos.top();

		if(!t1.checkDiaReparacao(dataReparacao)){
			for(unsigned int i=0; i<campos.size(); i++){
				campoTenis *ct1 = campos.at(i);
				if(ct1->getNumeroCampo() == idCampo){
					try
					{
						tecnicos.pop();
						t1.adicionarCampoReparacao(ct1);
						t1.adicionarDiaReparacao(dataReparacao);
					}
					catch(ExceptionNumeroDeReparacoesExcedida &exception){
						cerr<<exception.getInfo();
						return false;
					}

					int n = t1.getNumeroReparacoes();
					n++;
					t1.setNumeroReparacoes(n);
					gastosEmReparacoes+=t1.getCusto();
					tecnicos.push(t1);

					cout<<"O campo "<<idCampo<<" vai ser reparado pelo tecnico "<<t1.getNome()<<endl;
					return true;
				}
			}
		}

		temp.push_back(tecnicos.top());
		tecnicos.pop();
	}

	for(unsigned int i=0; i<temp.size(); i++){
		tecnicos.push(temp[i]);
	}

	return false;
}

float Empresa::getGastosEmReparacoes() const {
	return gastosEmReparacoes;
}



void Empresa::adicionarReparacao(int idTecnico, int idCampo, string data){
	vector<Tecnico> temp;

	while(!tecnicos.empty()){
		Tecnico t1 = tecnicos.top();
		if(t1.getID() == idTecnico){
			for(unsigned int i=0; i<campos.size(); i++){
				campoTenis* ct1 = campos.at(i);
				if(campos[i]->getNumeroCampo() == idCampo){
					tecnicos.pop();
					t1.adicionarCampoReparacao(ct1);
					t1.adicionarDiaReparacao(data);
					gastosEmReparacoes+=t1.getCusto();
					tecnicos.push(t1);
					return;
				}
			}
		}

		temp.push_back(t1);
		tecnicos.pop();
	}

	for(unsigned int i=0; i<temp.size(); i++){
		tecnicos.push(temp[i]);
	}

}

void Empresa::criarTecnico() {
	string nome, data;
	int diasAteDisp;
	float custo;

	cout<<"Nome do tecnico: ";
	cin>>nome;
	cout<<"Disponibilidade ao fim de: (nr de dias)";
	cin>>diasAteDisp;
	cout<<"Preco do servico:";
	cin>>custo;
	cout<<"Data de inscricao: DD-MM-AAAA";
	cin>>data;

	Tecnico t1(nome, diasAteDisp, custo, data);
	adicionarTecnico(t1);

}

void Empresa::listarTecnicos(){
	vector<Tecnico> temp;

	cout<<"ID\tNOME\tREPARACOES EFETUADAS\tDIAS ATE DISP"<<endl;
	while(!tecnicos.empty()){

		cout<<tecnicos.top().getID()<<"\t";
		cout<<tecnicos.top().getNome()<<"\t";
		cout<<tecnicos.top().getNumeroReparacoes()<<"\t\t\t\t";
		cout<<tecnicos.top().getDiasAteDisponibilidade()<<endl;

		temp.push_back(tecnicos.top());
		tecnicos.pop();
	}

	for(unsigned int i=0; i<temp.size(); i++){
		tecnicos.push(temp[i]);
	}
}

void Empresa::listarReparacoes(){
	vector<Tecnico> temp;

	cout<<"NOME\tCAMPO REPARADO\tDATA"<<endl;
	while(!tecnicos.empty()){
		Tecnico t1 = tecnicos.top();
		for(unsigned int i=0; t1.getDiasReparacao().size(); i++){
			cout<<t1.getNome()<<"\t";
			cout<<t1.getCamposReparados()[i]->getNumeroCampo()<<"\t\t\t";
			cout<<t1.getDiasReparacao()[i]->data_friendly_print()<<endl;
		}

		temp.push_back(t1);
		tecnicos.pop();
	}

	for(unsigned int i=0; i<temp.size(); i++){
		tecnicos.push(temp[i]);
	}
}


bool Empresa::removerTecnico(){
	int idTec;
	cout<<"Escolha o tecnico a remover: "<<endl;
	cin>>idTec;

	vector<Tecnico> temp;
	int contador=0;
	int numDatas=0;
	while(!tecnicos.empty()){
		if(tecnicos.top().getID() == idTec){
			Tecnico t=tecnicos.top();
			numDatas=t.getDiasReparacao().size();

			for(unsigned int i=0; i<t.getCamposReparados().size(); i++){
				campoTenis *ct1=t.getCamposReparados().at(i);
				string data = t.getDiasReparacao().at(i)->data_friendly_print();

				if(atribuirReparacao(ct1->getNumeroCampo(), data)){
					contador++;
				}

			}

			tecnicos.pop();
			break;

		}

		temp.push_back(tecnicos.top());
		tecnicos.pop();

	}

	for(unsigned int i=0; i<temp.size(); i++){
		tecnicos.push(temp[i]);
	}

	if(numDatas==contador)
		return true; //todas as reparacoes foram re-atribuidas
	else
		return false;



}
