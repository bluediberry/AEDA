
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
void pause();

int main() {
	Empresa empresa;
	empresa.abrirConfig();

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
									pause();
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
								pause();
								sucess=false;
							}
							break;
						case 3: //VER DADOS UTENTE
							{
								limpa();
								header_saldo();
								empresa.verDadosUtente(id);
								pause();
							}
							break;
						case 4:
							{
								limpa();
								header_consulta_aula();
								empresa.verAula(id);
								pause();
							}
							break;
						case 5:
							flag=false;
					}

				}


			}

			pause();
		}
			break;

		case 2: //REGISTO DE NOVO UTILIZADOR
		{
			limpa();
			header_registar_utente();
			empresa.criar_Utente();
			pause();

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
						pause();
					}
						break;

					case 2: //HORARIO DAS AULAS
						header_consulta_aulas();
						empresa.listar_allAulas();
						pause();
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
							pause();
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
									pause();
								}
							}
								break;
						case 5: //LISTAR UTENTES
							{
								limpa();
								file_utentes();
								empresa.listar_Alunos();
								pause();
							}
								break;
						case 6: //ESTATISTICAS GERAIS
						{
							limpa();
							header_estatistica();
							empresa.getEstatisticas();
							pause();
							pause();
						}
							break;

						case 7: //ALTERAR O NIVEL
						{
							limpa();
							empresa.listar_Alunos();
							int identAluno;
							cout<<"Selecione a identificacao do aluno: "<<endl;
							cin>>identAluno;
							empresa.changeNivel(identAluno);
							pause();
						}
						case 8:
						{
							//BACK UP SISTEMA
							limpa();
							empresa.guardarConfig();

						}
						break;
						case 9:
						{
							//adicionar Tecnico
							limpa();
							header_tecnicos();
							empresa.criarTecnico();
							pause();
						}
						break;
						case 10:
						{
							//pedir reparacao
							limpa();
							header_reparacoes();
							empresa.listar_camposDisponiveis();
							cout<<endl<<"Campo a reparar: ";
							int idCampo;
							cin>>idCampo;
							cout<<endl<<"Dia da reparacao: DD-MM-AAAA";
							string data;
							cin>>data;

							bool atribui=empresa.atribuirReparacao(idCampo, data);
							if(atribui){
								cout<<"A reparacao foi marcada."<<endl;
							}
							else
								cout<<"Nao existem tecnicos disponiveis. Nao havera reparacao."<<endl;

							pause();

						}
						break;
						case 11:
						{
							limpa();
							header_tecnicos();
							empresa.listarTecnicos();
							pause();
						}
						break;
						case 12:
						{
							limpa();
							header_reparacoes();
							empresa.listarReparacoes();
							pause();
						}
						break;
						case 13:
						{
							limpa();
							header_tecnicos();
							empresa.listarTecnicos();
							bool atribuido=empresa.removerTecnico();
							if(atribuido)
								cout<<"Todas as reparacoes foram atribuidas a outro tecnico"<<endl;
							else
								cout<<"Nem todas as reparacoes foram atribuidas."<<endl;
							pause();

						}
						break;

						case 14:
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


void pause() {
	cout<<"Pressione para prosseguir"<<endl;
	cin.get();
	cin.get();
}
void limpa(){
	cout << string( 100, '\n' ); //ver outro clear!
}
