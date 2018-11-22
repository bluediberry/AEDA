/*
 * empresa.h
 *
 *  Created on: 17/11/2018
 *      Author: Cláudia Mamede
 */

#ifndef EMPRESA_H_
#define EMPRESA_H_

#include "utente.h"
#include "professor.h"
#include "campoTenis.h"
#include <fstream>


class Empresa{
	vector<Utente*> utentes;
	vector<Professor*> professores;
	vector<campoTenis*> campos;
	vector<Aula*> aulas;
	vector<Livre*> modo_livre;

public:
	static float cartao_gold_preco;
	static float desconto_cartao_gold;
	static int numero_maximo_utentes_por_campo;
	static float preco_modo_livre;

	vector<Utente*> getUtentes();
	vector<Professor*> getProfessores();
	vector<campoTenis*> getCampos();
	vector<Aula*> getAulas();
	vector<Livre*> getLivre();

	bool criar_Utente();
	bool criar_Professor();
	bool criar_Aula();
	bool criar_Modo_Livre();

	void adicionar_campo(campoTenis * campo);
	void adicionar_Utente(Utente * utente);
	void adicionar_Professor(Professor * professor);
	void adicionar_Aula(Aula * a1);
	void adicionar_Livre(Livre * l1);

	bool registar_CampoTenis();
	bool adicionar_DiadeAtividade(int idCampo);
	void listar_DiadeAtividade(int idCampo, Data dia);
	void listar_camposDisponiveis();
	void listar_professoresDisponiveis();
	void listar_Alunos();

	void listar_allAulas();
	void listar_Aulas(string nomeProfessor);

	bool findUtente(int id);
	bool checkPassword(int id, string password);

	void getEstatisticas();

	float getSaldo();


	bool juntar_a_aula(int idAluno);
	bool juntar_a_modo_livre(int idAluno);

	int guardarConfig();

	void verAula(int idAluno);
	void verDadosUtente(int idAluno);
};




#endif /* EMPRESA_H_ */
