#ifndef HORAS_H_
#define HORAS_H_

#include <string>
using namespace std;

class Horario{
	int horas;
	int minutos;

public:
	Horario(string horario);
	Horario(int horas, int minutos);
	int getHoras() const;
	int getMin() const;
	string horario_friendly_print() const;
	Horario com_duracao(int duracao);
	bool operator==(const Horario &outroHorario);
	bool operator>(const Horario &outroHorario);
};



#endif /* HORAS_H_ */
