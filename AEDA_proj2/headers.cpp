#include "headers.h"

int menu_principal(){
	int opcao=0;
	cout<<"------------------------------------"<<endl;
	cout<<"  EMPRESA DE GESTAO DE CAMPOS TENIS "<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"Por favor, selecione uma opcao."<<endl;
	cout<<"1. Login"<<endl;
	cout<<"2. Registar"<<endl;
	cout<<"3. Consultar horarios"<<endl;
	cout<<"4. MODO EMPRESA"<<endl;
	cout<<"5. Sair"<<endl;
	cin>>opcao;
	while(opcao < 1 || opcao > 5){
		cout<<"Por favor selecione uma op��o v�lida [1-5]\n"<<endl;
		cin>>opcao;
	}
	return opcao;
}

int menu_consultas(){
	int opcao=0;
	cout<<"------------------------------------"<<endl;
	cout<<"          C O N S U L T A S         "<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"Por favor, selecione uma opcao."<<endl;
	cout<<"1. Horario de campo"<<endl;
	cout<<"2. Horario das aulas "<<endl;
	cout<<"3. Horario de professor"<<endl;
	cout<<"4. Menu anterior"<<endl;
	cin>>opcao;
	while(opcao < 1 || opcao > 4){
		cout<<"Por favor selecione uma opcao valida [1-4]\n"<<endl;
		cin>>opcao;
	}
	return opcao;
}

int management_menu(){
	int opcao=0;
	cout<<"------------------------------------"<<endl;
	cout<<"    M O D O   M A N A G E M E N T   "<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"Por favor, selecione uma op��o."<<endl;
	cout<<"1. Registar professor"<<endl;
	cout<<"2. Registar campo"<<endl;
	cout<<"3. Criar dia de funcionamento"<<endl;
	cout<<"4. Criar aula"<<endl;
	cout<<"5. Consultar utentes"<<endl;
	cout<<"6. Verificar estatisticas"<<endl;
	cout<<"7. Alterar nivel de aluno"<<endl;
	cout<<"8. Guardar configura�oes"<<endl;
	cout<<"9. Novo Tecnico"<<endl;
	cout<<"10. Pedir reparacao"<<endl;
	cout<<"11. Listar Tecnicos"<<endl;
	cout<<"12. Listar Reparacoes"<<endl;
	cout<<"13. Remover Tecnico"<<endl;
	cout<<"14. Sair"<<endl;
	cin>>opcao;
	while(opcao < 1 || opcao > 14){
		cout<<"Por favor selecione uma opcao valida [1-14]\n"<<endl;
		cin>>opcao;
	}
	return opcao;
}

int menu_login(){
	int opcao=0;
	cout<<"------------------------------------"<<endl;
	cout<<"         B E M   V I N D O !        "<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"Por favor, selecione uma op��o."<<endl;
	cout<<"1. Marcar aula"<<endl;
	cout<<"2. Marcar livre"<<endl;
	cout<<"3. Ver dados"<<endl;
	cout<<"4. Ver marcacoes"<<endl;
	cout<<"5. Sair"<<endl;
	cin>>opcao;
	while(opcao < 1 || opcao > 6){
		cout<<"Por favor selecione uma op��o v�lida [1-5]\n"<<endl;
		cin>>opcao;
	}
	return opcao;
}

void header_login(){
	cout<<"-------------------------------------"<<endl;
	cout<<"          B E M   V I N D O  !       "<<endl;
	cout<<"-------------------------------------"<<endl;
}
void header_saldo(){
	cout<<"-------------------------------------"<<endl;
	cout<<"      S A L D O   E   O U T R O S    "<<endl;
	cout<<"-------------------------------------"<<endl;
}
void header_registar_utente(){
	cout<<"-------------------------------------"<<endl;
	cout<<"   R E G I S T A R     U T E N T E   "<<endl;
	cout<<"-------------------------------------"<<endl;
}

void header_consulta_aula(){
	cout<<"-------------------------------------"<<endl;
	cout<<"     C O N S U L T A   A U L A       "<<endl;
	cout<<"-------------------------------------"<<endl;
}

void header_registar_professor(){
	cout<<"-------------------------------------"<<endl;
	cout<<" R E G I S T A R   P R O F E S S O R "<<endl;
	cout<<"-------------------------------------"<<endl;
}

void header_registar_campo(){
	cout<<"-------------------------------------"<<endl;
	cout<<"		R E G I S T A R   C A M P O     "<<endl;
	cout<<"-------------------------------------"<<endl;
}


void header_registar_aula(){
	cout<<"-------------------------------------"<<endl;
	cout<<"		R E G I S T A R   A U L A       "<<endl;
	cout<<"-------------------------------------"<<endl;
}

void header_registar_modo_livre(){
	cout<<"-------------------------------------"<<endl;
	cout<<" R E G I S T A R  M O D O  L I V R E "<<endl;
	cout<<"-------------------------------------"<<endl;
}

void header_consulta_aulas(){
	cout<<"-------------------------------------"<<endl;
	cout<<"	 A U L A S   D I S P O N I V E I S  "<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"DATA \t\t HORARIO\tCAMPO\tID AULA "<<endl;
}

void header_consulta_campos(){
	cout<<"-------------------------------------"<<endl;
	cout<<"	C A M P O S   D I S P O N I V E I S "<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<" ID : CAPACIDADE : ABERTURA : FECHO"<<endl;
}

void header_estatistica(){
	cout<<"-------------------------------------"<<endl;
	cout<<"	      E S T A T I S T I C A S       "<<endl;
	cout<<"-------------------------------------"<<endl;
}

void file_utentes(){
	cout<<"-------------------------------------"<<endl;
	cout<<"   C O N S U L T A  U T E N T E S    "<<endl;
	cout<<"-------------------------------------"<<endl;
}
void file_professores(){
	cout<<"--------------------------------------"<<endl;
	cout<<"C O N S U L T A  P R O F E S S O R E S"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"IDENTIFICACAO    NOME"<<endl;
}

void horario_professor(){
	cout<<"--------------------------------------"<<endl;
	cout<<"   H O R � R I O   P R O F E S S O R  "<<endl;
	cout<<"--------------------------------------"<<endl;
}

void header_dia_atividade(){
	cout<<"--------------------------------------"<<endl;
	cout<<"   D I A   D E   A T I V I D A D E S  "<<endl;
	cout<<"--------------------------------------"<<endl;
}


void header_marcar_aula(){
	cout<<"--------------------------------------"<<endl;
	cout<<"          M A R C A R  A U L A        "<<endl;
	cout<<"--------------------------------------"<<endl;
}

void header_tecnicos(){
	cout<<"--------------------------------------"<<endl;
	cout<<"            T E C N I C O S           "<<endl;
	cout<<"--------------------------------------"<<endl;
}

void header_reparacoes(){
	cout<<"--------------------------------------"<<endl;
	cout<<"          R E P A R A C O E S         "<<endl;
	cout<<"--------------------------------------"<<endl;
}
