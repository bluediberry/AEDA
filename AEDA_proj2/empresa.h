#ifndef EMPRESA_H_
#define EMPRESA_H_
#include "utente.h"
#include "professor.h"
#include "campoTenis.h"

#include <fstream>

/** 2a parte do projeto **/
#include "BST.h"
#include <unordered_set>
#include "tecnico.h"
#include <queue>

struct professorPtr {
	int operator()(const profPtr &p1) const {
		return (int)p1.prof->getID(); //id � unico, diminuindo colisoes
	}
	bool operator()(const profPtr &p1, const profPtr &p2) const{
		return p1.prof->getID() == p1.prof->getID();
	}
};

typedef unordered_set<profPtr, professorPtr, professorPtr> tabHProfessores;

class Empresa{
	BST<Utente> utilizadores;
	tabHProfessores professores;
	priority_queue<Tecnico> tecnicos;
	vector<campoTenis*> campos;
	vector<Aula*> aulas;
	vector<Livre*> modo_livre;

	float gastosEmReparacoes;

public:
	static float cartao_gold_preco;
	static float desconto_cartao_gold;
	static int numero_maximo_utentes_por_campo;
	static float preco_modo_livre;

	/**
	 * @brief Construtor da classe empresa.
	 */
	Empresa();


/**
 * @brief Adiciona um utente a arvore utilizadores
 * @param utente - utente que vai ser adicionado
 */
	void adicionarUtilizador(Utente &u1);

	/**
	 * @brief Retorna o dinheiro gasto pela empresa em reparacoes
	 * @return o valor gasto em reparacoes at� ao momento.s
	 */
	float getGastosEmReparacoes() const;

/**
* @brief
*
* @return
*/
	BST<Utente> getUtentes();

	/**
 * @brief
 * @return
 */
	tabHProfessores getProfessores();

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
 */
	void adicionar_campo(campoTenis * campo);

	/**
 * @brief Adiciona um professor ao vetor de professores
 * @param professor - professor que vai ser adicionado
 */
	void adicionarProfessor(Professor * professor);

	/**
 * @brief Adiciona uma aula com ao vetor de aulas
 * @param a1 - aula que vai ser adicionada
 */
	void adicionar_Aula(Aula * a1);

	/**
 * @brief Adiciona um aula livre ao vetor de aulas livres
 * @param l1 - Aula livre que vai ser adicionada
 */
	void adicionar_Livre(Livre * l1);

	/**
 * @brief Cria um novo campo de tenis
 * @return True se for criado o campo de tenis
 */
	bool registar_CampoTenis();

	/**
 * @brief Adiciona um novo dia de atividade
 * @param idCampo - id do campo ao qual vais ser adicionado o dia
 * @return True se o dia for corretamente atribuido ao campo
 */
	bool adicionar_DiadeAtividade(int idCampo);

	/**
 * @brief mostra a informacao de um dia de atividade num campo
 * @param idCampo - id do campo que vai ser consultado
 * @param dia - dia que vai ser consultado
 */
	void listar_DiadeAtividade(int idCampo, Data dia);

	/**
 * @brief mostra a informacao sobre os campos que estao disponiveis
 */
	void listar_camposDisponiveis();

	/**
 * @brief mostra a informacao sobre os professores que estao disponiveis
 */
	void listar_professoresDisponiveis();

	/**
 * @brief mostra a informacao sobre os alunos
 */
	void listar_Alunos();

	/**
 * @brief mostra a informacao de todas as aulas
 */
	void listar_allAulas();

	/**
 * @brief mostra as aulas de um determinado professores
 * @param nomeProfessor - nome do professor que da aula
 */
	void listar_Aulas(string nomeProfessor);


	/**
 * @brief efetua a procura de um certo utente
 * @param id - id do utente que esta a ser procurado
 * @return True se for encontrado e false caso contrario
 */
	bool findUtente(int id);

	/**
 * @brief verifica se a password intruduzida é igual a gravada no sistema
 * @param id - id do utente que esta a escrever a Password
 * @param password - password que foi intruduzida
 * @return True se for encontrado e false caso contrario
 */
	bool checkPassword(int id, string password);

	/**
 * @brief Lista de estatisticas relativas a campos, professores e alunos
 */
	void getEstatisticas();

	/**
 * @brief Efetua a soma do saldo que todos os utentes tem na sua conta
 * @return Retorna o saldo total
 */
	float getSaldo();

	/**
 * @brief Junta, se for possivel, um aluno a uma certa aula
 * @param idAluno - id do utente que pretende juntar-se a aula
 * @return True se for possivel juntar o aluno e false caso contrario
 */
	bool juntar_a_aula(int idAluno);

	/**
 * @brief Junta, se for possivel, um aluno a uma certa aula de modo livre
 * @param idAluno - id do utente que pretende juntar-se a aula
 * @return True se for possivel juntar o aluno e false caso contrario
 */
	bool juntar_a_modo_livre(int idAluno);

	/**
 * @brief Guarda informacao sobre campos, professores, alunos e aulas
 * @return
 */
	void guardarConfig();

	/**
	 * @brief Abre as configuracoes guardadas nos ficheiros e preenche a empresa.
	 * @return
	 */
	void abrirConfig();

	/**
 * @brief Permite ver o dados de um utente
 * @param idAluno - id do utente
 */
	void verAula(int idAluno);

	/**
 * @brief Permite ver os dados das aulas em o aluno participou
 * @param idAluno - id do utente
 */
	void verDadosUtente(int idAluno);

	/**
	 * @brief Altera o nivel do aluno
	 * @param idAluno - id do utente
	 */
	void changeNivel(int idAluno);

	/**
	 * @brief Cria e atribui uma aula a um campo
	 * @param idCampo - identificacao do campo
	 * @param idAula - identificacao da aula
	 * @param data - dia da realizacao da aula
	 * @param horario - horario de inicio da aula
	 * @param preco - preco da aula
	 * @return true se o campo foi atribuido com sucesso
	 */
	bool atribuir_campo_prof(int idCampo, int idAula, string data, string horario, float preco);

	// 2a parte do projeto

	/**
	 * @brief Formulario para criar um tecnico
	 */
	void criarTecnico();

	/**
	 * @brief Adiciona um tecnico � priority_queue de tecnicos da empresa.
	 * @param t1 - tecnico a ser adicionado � fila
	 */
	void adicionarTecnico(Tecnico &t1);

	/**
	 * @brief Retorna a fila de tecnicos
	 * @return priority_queue com os tecnicos
	 */
	priority_queue<Tecnico> getTecnicos();

	/**
	 * @brief Adicionar tecnico � reparacao de um campo de identificacao id
	 * @param id - identificacao do campo
	 * @return true se um tecnico foi atribuido, falso se nao foi atribuido ninguem.
	 */
	bool atribuirReparacao(int id, string data);

	/**
	 * @brief Adiciona ao vetor de campos reparados do tecnico idTecnico, uma reparacao no dia data
	 * @param idTecnico identificacao do tecnico
	 * @param idCampo identificacao do campo
	 * @param data dia da reparacao
	 * @return
	 */
	void adicionarReparacao(int idTecnico, int idCampo, string data);

	/**
	 * @brief Listar todos os tecnicos disponiveis
	 * @return
	 */
	void listarTecnicos();

	/**
	 * @brief Listar reparacoes efetuadas
	 * @return
	 */
	void listarReparacoes();

	/**
	 * @brief Remove tecnico da priority queue e atribui as reparacoes a outro tecnico
	 * @return true se as novas atribuicoes foram bem sucedidas, false se nao foram
	 */
	bool removerTecnico();
};




#endif /* EMPRESA_H_ */
