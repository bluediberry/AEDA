//============================================================================
// Name        : AEDA_projeto.cpp
// Author      : Cláudia Mamede
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "empresa.h"
#include "headers.h"

using namespace std;

enum MENU_PRINCIPAL_OPTION {MENU1, LOGIN, REGISTER, CONSULT, EXIT, MANAGEMENT};
enum MANAGEMENT_OPTION {MENU2, PROF_REGISTER, CAMPO_REGISTER, USERS_CONSULT, PROF_CONSULT, CAMPO_CONSULT, ESTATISTICA, PROF_MENU};
enum LOGIN_OPTION {END_SESSION, MARCAR_AULA, MARCAR_LIVRE, VER_RELATORIO};

bool criar_Professor(Empresa & empresa);
bool criar_Utente(Empresa & empresa);
void limpa();
int inicializar_empresa(Empresa & empresa);

int main() {
	//vector<campoTenis*> camposTenis;

	Empresa empresa;
	inicializar_empresa(empresa);

	while(1){
		limpa(); //ver outro clear!
		int opcao=menu_principal();

		switch(opcao){
		case 1: { //LOGIN DE UTILIZADOR REGISTADO
			limpa();
			header_login();
			bool found=false;
			int id;
			string password;
			cout<<"ID: ";
			cin>>id;
			if(empresa.findUtente(id)){
				cout<<"Password: ";
				cin>>password;
				found=empresa.checkPassword(id, password);
			}

			if(found){
				bool sucess=false;
				bool flag=true;
				while(flag){
					limpa();
					int op=menu_login();
					switch(op){
						case 1: //MARCAR AULA
							{
								limpa();
								if(empresa.getAulas().size() > 0){
									header_consulta_aulas();
									empresa.listar_allAulas();
									header_marcar_aula();
									sucess=empresa.juntar_a_aula(id);
									if(sucess){
										cout<<"Juntou-se com sucesso à aula."<<endl;
									}
									else cout<<"Não foi possivel juntar-se à aula"<<endl;
									cout<<"Pressione para continuar."<<endl;
									string resp;
									cin>>resp;
									sucess=false;
								}

							}
							break;
						case 2: //MARCAR LIVRE
							{
								limpa();
								header_registar_modo_livre();
								empresa.criar_Modo_Livre();
								sucess=empresa.juntar_a_modo_livre(id);
								if(sucess){
									cout<<"Juntou-se com sucesso à aula."<<endl;
								}
								else cout<<"Não foi possivel juntar-se à aula"<<endl;
								cout<<"Pressione para continuar."<<endl;
								string resp;
								cin>>resp;
								sucess=false;
							}
							break;
						case 3: //VER DADOS UTENTE
							{
								limpa();
								header_saldo();
								empresa.verDadosUtente(id);
							}
							break;
						case 4:
							{
								limpa();
								header_consulta_aula();
								empresa.verAula(id);
							}
							break;
						case 5:
							flag=false;
					}

				}


			}

			string letra;
			cout<<"Pressionar para prosseguir"<<endl;
			cin>>letra;
		}
			break;

		case 2: //REGISTO DE NOVO UTILIZADOR
		{
			limpa();
			header_registar_utente();
			cout<<empresa.getUtentes().size()<<endl;
			empresa.criar_Utente();
		}
			break;
		case 3: //CONSULTAS
			{
				bool flag=true;
				while(flag){
					limpa();
					int op=menu_consultas();
					switch(op){
					case 1: //HORARIO DE UM CAMPO
					{
						header_consulta_campos();
						empresa.listar_camposDisponiveis();
						cout<<"Escolha o numero do campo: "<<endl;
						int numero_campo=0;
						cin>>numero_campo;
						cout<<empresa.getCampos().size();
						while(numero_campo < 0 || numero_campo > empresa.getCampos().size()){
							cout<<"Por favor selecione uma opção válida. \n"<<endl;
							cin>>numero_campo;
						}

						string data;
						cout<<"Escolha o dia a analisar: "<<endl;
						cin>>data;
						Data d1(data);
						empresa.listar_DiadeAtividade(numero_campo, data);
					}
						break;

					case 2: //HORARIO DAS AULAS
						header_consulta_aulas();
						empresa.listar_allAulas();
						break;

					case 3: //HORARIO DO PROFESSOR
						{
							limpa();
							file_professores();
							empresa.listar_professoresDisponiveis();
							horario_professor();
							cout<<"Escolha o nome do professor: "<<endl;
							string nome;
							cin>>nome;
							empresa.listar_Aulas(nome);
						}
						break;

					case 4:
						flag=false;
					}
				}
			}
			break;


		case 4: //MODO EMPRESA
			{
				bool flag=true;
				while(flag){
					limpa();
					int op2=management_menu();
						switch(op2){
						case 1: //REGISTAR UM PROFESSOR
							{
								limpa();
								header_registar_professor();
								empresa.criar_Professor();
							}
								break;

						case 2: //REGISTAR CAMPO
							{	limpa();
								header_registar_campo();
								empresa.registar_CampoTenis();
							}
								break;

						case 3: //ADICIONAR DIA
							{
								limpa();
								header_consulta_campos();
								empresa.listar_camposDisponiveis();

								header_dia_atividade();
								int id_campo;
								cout<<"Para que campo quer acrescentar dia de funcionamento?"<<endl;
								cin>>id_campo;
								while(id_campo < 0 || id_campo > empresa.getCampos().size()){
									cout<<"Por favor selecione uma opção válida. \n"<<endl;
									cin>>id_campo;
								}
								empresa.adicionar_DiadeAtividade(id_campo);
							}
								break;
						case 4: //CRIAR AULA
							{
								limpa();
								header_registar_aula();
								bool teste=empresa.criar_Aula();
								if(!teste){
									cout<<"Devera criar um dia de funcionamento coincidente com a data da aula"<<endl;
									cout<<"Prima uma tecla para prosseguir."<<endl;
									string tecla;
									cin>>tecla;
								}
							}
								break;
						case 5: //LISTAR UTENTES
							{
								limpa();
								file_utentes();
								empresa.listar_Alunos();
							}
								break;
						case 6: //ESTATISTICAS GERAIS
						{
							limpa();
							header_estatistica();
							empresa.getEstatisticas();
						}
							break;

						case 7: //ALTERAR O NIVEL
						{
							limpa();
							//alterar nivel do aluno
						}
						case 8:
						{
							//BACK UP SISTEMA
							limpa();
							//cabeçalho
							empresa.guardarConfig();

						}
						break;
						case 9:
							flag=false;
						}
					}
				}
			break;
		case 5:
			return 0;
		}
	}

	return 0;
}



void limpa(){
	cout << string( 100, '\n' ); //ver outro clear!
}


int inicializar_empresa(Empresa &empresa){
	/* CAMPOS */
	string line, abertura, fecho;
	int campo_id, num_utilizadores;
	int pointsIndex;
	ifstream file ("./Files/campos.txt", ios::in);
	if(file.is_open()){
		while(getline(file, line)){
			pointsIndex=line.find_first_of(':'); //identificacao do campo
			campo_id = atoi((line.substr(0,pointsIndex)).c_str());
			line.erase(0, pointsIndex+1); //ver pointsIndex+1 ??

			pointsIndex=line.find_first_of(':');
			num_utilizadores = atoi((line.substr(0,pointsIndex)).c_str());
			line.erase(0, pointsIndex+1);

			pointsIndex=line.find_first_of(':');
			abertura=line.substr(0,pointsIndex);
			line.erase(0, pointsIndex+1);

			pointsIndex=line.find_first_of(':');
			fecho=line.substr(0,pointsIndex);
			line.erase(0, pointsIndex+1);

			cout<<campo_id << "   "<<num_utilizadores<<"  "<<abertura<<"   "<<fecho<<endl;
			campoTenis *ct1 = new campoTenis(campo_id, num_utilizadores, abertura, fecho);
			empresa.adicionar_campo(ct1);
		}
	}
	else cout<<"NAO DEUU"<<endl;


	/* UTENTES */
	string line1, password, nome;
	int utente_id, nivel, cartao;
	float conta;
	ifstream file2 ("./Files/utentes.txt", ios::in);
	if(file2.is_open()){
			while(getline(file2, line1)){
				pointsIndex=line1.find_first_of(':'); //identificacao do campo
				utente_id = atoi((line1.substr(0,pointsIndex)).c_str());
				line1.erase(0, pointsIndex+1); //ver pointsIndex+1 ??

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
				nome=line1.substr(0,pointsIndex);
				line1.erase(0, pointsIndex+1);


				cout<<utente_id << "   "<<cartao<<"  "<<nivel<<"   "<<password<<"   "<<conta<<"  "<<nome<<endl;
				Utente *u1 = new Utente(utente_id, nome, password, nivel, cartao);
				empresa.adicionar_Utente(u1);
			}
		}
		else cout<<"NAO DEUU"<<endl;


	/*PROFESSORES*/
	string line3;
	int id_professor;
	string nome_prof;
	ifstream file3 ("./Files/professores.txt", ios::in);
	if(file2.is_open()){
			while(getline(file3, line3)){
				pointsIndex=line3.find_first_of(':'); //identificacao do campo
				id_professor = atoi((line3.substr(0,pointsIndex)).c_str());
				line3.erase(0, pointsIndex+1); //ver pointsIndex+1 ??

				pointsIndex=line3.find_first_of(':');
				nome_prof=line3.substr(0,pointsIndex);
				line3.erase(0, pointsIndex+1);

				cout<<id_professor << "   "<<nome_prof<<endl;
				Professor *p1 = new Professor(id_professor, nome_prof);
				empresa.adicionar_Professor(p1);
		}
	}

	/*AULAS + DIAS*/
	string line4;
	int id_aula, IDcampo;
	string data, horario;
	float preco;
	ifstream file4 ("./Files/aulas.txt", ios::in);
	if(file4.is_open()){
		while(getline(file4, line4)){
			pointsIndex=line4.find_first_of(':'); //identificacao do campo
			IDcampo = atoi((line4.substr(0,pointsIndex)).c_str());
			line4.erase(0, pointsIndex+1);

			pointsIndex=line4.find_first_of(':');
			id_aula=atoi((line4.substr(0,pointsIndex)).c_str());
			line4.erase(0, pointsIndex+1);

			pointsIndex=line4.find_first_of(':');
			data=line4.substr(0,pointsIndex);
			line4.erase(0, pointsIndex+1);

			pointsIndex=line4.find_first_of(':');
			preco=atof(line4.substr(0,pointsIndex).c_str());
			line4.erase(0, pointsIndex+1);

			Dia d1(data);
			empresa.getCampos().at(IDcampo)->adicionar_dia(d1);
			Aula *a1 = new Aula(id_aula, data, horario, preco);
			empresa.adicionar_Aula(a1);

		}
	}


	return 0;
}
