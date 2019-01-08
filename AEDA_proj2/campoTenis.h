#ifndef CAMPOTENIS_H_
#define CAMPOTENIS_H_
#include <vector>
#include <list>
#include "dia.h"

using namespace std;

class campoTenis{
	Horario abertura;
	Horario fecho;
	static int id;
	int MAX_UTILIZADORES;
	int numero_campo;
	vector<Dia> ocupacao_por_dia;


public:
	campoTenis(const campoTenis&) = default;

	/**
 * @brief Construtor da classe campoTenis.
 * @param num_campo - Numero de identificação do campo.
 * @param nMaxUtentes - Numero maximo de utentes que e permitido no campo
 * @param abertura - Horario em que abre o campo
 * @param fecho - Horario em que fecha o campo
 */
	campoTenis(int num_campo, int nMaxUtentes, string abertura, string fecho);

	/**
 * @brief Construtor da classe campoTenis.
 * @param nMaxUtentes - Numero maximo de utentes que e permitido no campo
 * @param abertura - Horario em que abre o campo
 * @param fecho - Horario em que fecha o campo
 */
	campoTenis(int nMaxUtentes, string abertura, string fecho);

	/**
 * @brief
 * @return Numero do campo
 */
	int getNumeroCampo() const;

	/**
 * @brief
 * @return Horario de Abertura
 */
	Horario getHorarioAbertura() const;
	/**
 * @brief
 * @return Horario de fecho
 */
	Horario getHorarioFecho() const;

	/**
 * @brief
 * @return Numero maximo de utilidores
 */
	int getMaxUtilizadores() const;

	/**
 * @brief Retorna a informacao relativa a um campo de tenis
 * @return String com a informação
 */
	string getInfo();

	/**
 * @brief Inicializa mais um dia no campo de tenis
 * @param d1 - Dia a adicionar
 * @return Nothing
 */
	void adicionar_dia(const Dia & d1);

	/**
 * @brief
 * @return
 */
	vector<Dia> getOcupacao() {return ocupacao_por_dia;}

	/**
 * @brief
 * @return 
 */
	const vector<Dia> getOcupacao() const {return ocupacao_por_dia;}




};



#endif /* CAMPOTENIS_H_ */
