#ifndef AULA_H_
#define AULA_H_
#include "utilizacao.h"
#include <vector>



class Aula: public Utilizacao {
	static int id;
	int identificacao;
	vector<Utente*> alunos;

public:
	static int numero_maximo_utilizadores_por_aula;

	/**
 * @brief Construtor da classe Aula.
 * @param id - Numero de identificação da Aula.
 * @param data - String que contem da data da aula
 * @param horario - Horario em que começa a aula
 * @param preco - Preco da aula.
 */
	Aula(int id, string data, string horario, float preco);

	/**
 * @brief Construtor da classe Aula.
 * @param data - String que contem da data da aula
 * @param horario - Horario em que começa a aula
 * @param preco - Preco da aula.
 */
	Aula(string data, string horario, float preco);

	/**
 * @brief Adiciona, se for possivel, um aluno a uma aula
 * @param u1 - Aluno a adicionar
 * @return Retorna true caso seja possível adicionar o aluno e retorna false caso contrário
 */
	bool adicionar_aluno(Utente * u1);

	/**
 * @brief Remove, se for possivel, um aluno a uma aula
 * @param u1 - Aluno a remover
 * @return Retorna true caso seja possível remover o aluno e retorna false caso contrário
 */
	bool remover_aluno(Utente * u1);

	/**
 * @brief
 * @return Vetor de alunos
 */
	vector<Utente*> getAlunos() const;

	/**
 * @brief Operador == para comparar datas.
 * @param a2 - uma outra aula para comparar à aula em questão.
 * @return Retorna true caso a aula em questão seja igual à aula a comparar, false caso contrário.
 */
	bool operator==(const Aula &a2);

	/**
 * @brief Retorna a informacao relativa a uma aula
 * @return String com a informação
 */
	string getInfo();

	/**
 * @brief
 * @return Identificacao da aula
 */
	int getIdentificacao() const;

};



#endif /* AULA_H_ */
