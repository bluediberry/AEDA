#ifndef HORAS_H_
#define HORAS_H_

#include <string>
using namespace std;

class Horario{
	int horas;
	int minutos;

public:

	/**
 * @brief Construtor da classe Horario
 * @param horario - string que representa o horario em formato HH:MM
 */
	Horario(string horario);

	/**
 * @brief Construtor da classe Horario
 * @param horas - Parametro das horas relativas ao horario
 * @param horas - Parametro dos minutos relativos ao horario
 */
	Horario(int horas, int minutos);

	/**
 * @brief
 * @return
 */
	int getHoras() const;

	/**
 * @brief
 * @return
 */
	int getMin() const;

	/**
 * @brief Coloca o horario num formato user friendly
 * @param Retorna o horario no formato 10h30
 */
	string horario_friendly_print() const;

	/**
 * @brief Cria um novo horario com uma certa duracao
 * @param duracao - tempo que demora uma certa aula
 * @return Retorna o Horario em questao
 */
	Horario com_duracao(int duracao);

	/**
 * @brief Operador == para comparar horarios.
 * @param outroHorario - uma outro horario para comparar ao horario em questão.
 * @return Retorna true caso o horario em questão seja igual ao horario a comparar, false caso contrário.
 */
	bool operator==(const Horario &outroHorario);

	/**
 * @brief Operador > para comparar horarios.
 * @param outroHorario - uma outro horario para comparar ao horario em questão.
 * @return Retorna true caso o horario em questão seja maior ao horario a comparar, false caso contrário.
 */
	bool operator>(const Horario &outroHorario);
};



#endif /* HORAS_H_ */
