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

	/**
 * @brief
 * @return
 */
	vector<Utente*> getUtentes();

	/**
 * @brief
 * @return
 */
	vector<Professor*> getProfessores();

	/**
 * @brief
 * @return
 */
	vector<campoTenis*> getCampos();

	/**
 * @brief
 * @return
 */
	vector<Aula*> getAulas();

	/**
 * @brief
 * @return
 */
	vector<Livre*> getLivre();

	/**
 * @brief Recolhe informacao do teclado e cria um utente com essa informacao
 * @return Retorna true caso seja possivel criar o utente
 */
	bool criar_Utente();

	/**
 * @brief Recolhe informacao do teclado e cria um professor com essa informacao
 * @return Retorna true caso seja possivel criar o professor
 */
	bool criar_Professor();

	/**
 * @brief Recolhe informacao do teclado e cria uma aula com essa informacao
 * @return Retorna true caso seja possivel criar uma aula
 */
	bool criar_Aula();

	/**
 * @brief Recolhe informacao do teclado e cria uma aula livre com essa informacao
 * @return Retorna true caso seja possivel criar a aula
 */
	bool criar_Modo_Livre();

	/**
 * @brief Adiciona um campo ao vetor de campos
 * @param campo - Campo que vai ser adicionado
 * @return Nothing
 */
	void adicionar_campo(campoTenis * campo);

	/**
 * @brief Adiciona um utente ao vetor de utentes
 * @param utente - utente que vai ser adicionado
 * @return Nothing
 */
	void adicionar_Utente(Utente * utente);

	/**
 * @brief Adiciona um professor ao vetor de professores
 * @param professor - professor que vai ser adicionado
 * @return Nothing
 */
	void adicionar_Professor(Professor * professor);

	/**
 * @brief Adiciona uma aula com ao vetor de aulas
 * @param a1 - aula que vai ser adicionada
 * @return Nothing
 */
	void adicionar_Aula(Aula * a1);

	/**
 * @brief Adiciona um aula livre ao vetor de aulas livres
 * @param l1 - Aula livre que vai ser adicionada
 * @return Nothing
 */
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
