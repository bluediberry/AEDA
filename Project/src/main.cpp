//============================================================================
// Name        : AEDA_projeto.cpp
// Author      : Cláudia Mamede
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
#include "data.h"
#include "horas.h"
#include "pessoa.h"
#include "professor.h"
#include "utente.h"
#include "professor.h"
#include "utente.h"
//#include "empresa.h" ----> adicionar uma variavel com o preço do cartao gold!
//extern float cartao_gold_preco
static float cartao_gold_preco=5.95;

using namespace std;

int menu_principal();
int menu_login();
bool menu_registar_utentes();
bool menu_registar_professores(); //só vai estar disponivel na opcao da empresa

typedef enum MENU_OPTION {LOGIN, REGISTER, CONSULT, EXIT, MANAGEMENT};

int main() {
	int opcao=0;


	opcao = menu_principal();
	switch(opcao){
	case LOGIN:
		//menu_login();
		cout<<"entrava no login"<<endl;
		break;

	case REGISTER:
		if(!menu_registar_utentes()) //se nao registar o aluno
			menu_principal();

		break;
	case CONSULT:
		cout<<"entra no consult"<<endl;
		break;

	case MANAGEMENT:
		cout<<"entrava no management"<<endl;


	case EXIT:
		return 0;
		break;

	}

}



int menu_principal(){
	int opcao=0;

	cout<<"------------------------------------"<<endl;
	cout<<"          B E M  V I N D O !        "<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"Por favor, selecione uma opção."<<endl;
	cout<<"1. Login"<<endl;
	cout<<"2. Registar"<<endl;
	cout<<"3. Consultar horarios"<<endl;
	cout<<"4. MODO EMPRESA"<<endl;
	cout<<"4. Sair"<<endl;

	cin>>opcao;

	while(opcao < 1 || opcao > 5){
		cout<<"Por favor selecione uma opção válida [1-5]\n"<<endl;
		cin>>opcao;
	}

	return opcao;
}


bool menu_registar_utentes(){
	string nome, password, tentativa1, tentativa2;
	char letra='a'; //só para entrar no while
	long id;
	bool check=false, cartao=false;
	int nivel=0, opcao;

	cout<<"------------------------------------"<<endl;
	cout<<"      M E N U   R E G I S T A R     "<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"Por favor, preencha os seguintes campos."<<endl;

	//-----------------Preencher o ID ---------------------
	cout<<"Insira o seu NIF (funcionará como ID no sistema): ";
	cin>>id;
	cout<<endl;

	//-----------------Preencher o nome--------------------
	cout<<"Nome: ";
	cin>>nome;
	cout<<endl;

	//-----------------Definir password valida--------------

	/*
	while(check == false){
		cout<<"Password [10 carateres]: ";
		while(letra != '\0'){
			letra = getchar();
			tentativa1.push_back(letra);
			cout << '*';
		   }
		letra='a'; //reset à letra para entrar no while
		cout<<endl;
		cout<<"Repita a password: ";
		while(letra != '\0'){
			letra = getchar();
			tentativa2.push_back(letra);
			cout << '*';
		}
		cout<<endl;
		if(tentativa1.compare(tentativa2)) //são diferentes
			check=false;
		else{
			password=tentativa1;
			check=true;
		}
	}*/

	cout<<"Password: ";
	cin>>password;
	cout<<endl;

	//---------------Escolher nivel ------------------
	cout<<"1. Iniciado"<<endl;
	cout<<"2. Intermedio"<<endl;
	cout<<"3. Avancado"<<endl;
	cout<<"Nivel: "<<endl;
	cin>>nivel;

	while(nivel < 1 || nivel >3){
		cout<<"Por favor selecione uma opção válida [1-3]"<<endl;
		cin>>nivel;
	}

	//---------------Adquirir cartao --------------------
	cout<<"Pretende aderir ao cartão gold com um custo fixo mensal de "<< cartao_gold_preco << " que permite o acesso a aulas com 15% desconto?"<<endl;
	cout<<"1. Sim, quero!     2 Não, obrigada!"<<endl;
	cout<<"cheguei\n"<<endl;
	cin>>opcao;

	while(opcao < 1 || nivel >2){
		cout<<"Por favor selecione uma opção válida [1-2]"<<endl;
		cin>>opcao;
	}

	if (opcao) cartao=true; //senao esta falso por default


	Utente newUser = Utente(nome, password, id, nivel, cartao);
	//deve adicionar a um ficheiro para depois se fazer os logins
	return true;
}
