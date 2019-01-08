#include "data.h"


Data::Data(string data){
	//Formato DD-MM-YYYY
	string date;
	int day, month, year;
	day=stoi(data.substr(0,2));
	month=stoi(data.substr(3,2));
	year=stoi(data.substr(6,4));

	//Este throw talvez tenha de estar num while para q o programa nao va abaixo.
	while(day < 0 || day > 31 || month < 0 || month > 12 || year < 2010 ){ //a empresa so abriu um 2010
		cout<<"Introduza uma data v�lida no formato DD-MM-YYYY.  Dia[0-31] Mes[0-12] Ano[2011, ...]"<<endl;
		cin>>date;
		day=stoi(data.substr(0,2));
		month=stoi(data.substr(3,2));
		year=stoi(data.substr(6,4));
	}

	dia=day;
	mes=month;
	ano=year;

}


int Data::getAno() const{
	return this->ano;
}

int Data::getMes() const{
	return this->mes;
}

int Data::getDia() const{
	return this->dia;
}


string Data::data_friendly_print() const{
	//Criar excep�oes para os limites: dia[1-31], mes[1-12]
	string day, month, year, date;

	if(dia < 10)
		day = "0" + to_string(dia);
	else
		day = to_string(dia);

	if(mes < 10)
		month = "0" + to_string(mes);
	else
		month = to_string(mes);

	year = to_string(ano);

	date = day + "-" + month + "-" + year;

	return date;
}



bool Data::operator<(const Data &outra) {
	if(this->getAno() > outra.getAno())
		return false;
/*	else if(this.getAno() < outra.getAno())
		return true; */
	else if (this->getAno() == outra.getAno()){
		if(this->getMes() > outra.getMes()) return false;

		else if (this->getMes() == outra.getMes())
			if(this->getDia() > outra.getDia() )
				return false;


	}
	return true;
}

bool Data::operator==(const Data &outra){
	if(this->getDia() != outra.getDia() || this->getMes() != outra.getMes() || this->getAno() != outra.getAno())
		return false;
	return true;
}
