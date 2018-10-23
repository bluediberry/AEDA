#ifndef SRC_DATA_H_
#define SRC_DATA_H_

#include <string>
#include <string.h>

using namespace std;

class Data{
	int dia;
	int mes;
	int ano;
	int hora;
	int minutos;

public:
	Data(string data);
	Data(string data, string horas);
	int getAno() const;
	int getMes() const;
	int getDia() const;
	int getHoras() const;
	int getMin() const;
	string get_data() const;
	string get_horas() const;
	bool operator<(const Data &outraData) const;

};

