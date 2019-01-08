#ifndef TECNICO_H_
#define TECNICO_H_

#include "pessoa.h"
#include "campoTenis.h"
//#include "data.h"

#define MAX_UTILIZACAO 10;

class Tecnico: public Pessoa {
	int numeroReparacoes;
	int DiasAteDisponibilidade;
	vector<campoTenis*> camposReparados;


public:
	/**
	 * @brief construtor da classe tecnico
	 * @param nome nome do tecnico
	 * @param dataAtual data de "inscricao" do tecnico para trabalhar
	 * @param dataInicioTrabalho data disponivel para o tecnico começar a trabalhar
	 */
	Tecnico(string nome, string dataAtual, string dataInicioTrabalho);

	/**
	 * @brief Altera numero de reparacoes realizadas ate ao momento
	 * @param numeroReparacoes - novo numero de reparacoes realizadas
	 */
	void setNumeroReparacoes(int numeroReparacoes);

	/**
	 * @brief Altera numero de dias ate disponibilidade
	 * @param numeroDias - novo numero de dias ate disponibilidade
	 */
	void setDiasAteDisponibilidade(int numeroDias);

	/**
	 * @brief Compara dois objetos e ordena-os, verificando qual tem menor numero de DiasAteDisponibilidade e se for igual, pelo menor numero de reparacoes realizadas.
	 * @param t1 - objeto de comparacao
	 * @return true se o objeto tem valores menores do que t1.
	 */
	bool operator<(const Tecnico &t1) const;

	/**
	 * @brief Retorna numero de dias ate disponibilidade
	 * @return numero de DiasAteDisponiblidade
	 */
	int getDiasAteDisponibilidade() const;

	/**
	 * @brief Retorna numero de repacoes realizadas.
	 * @return numeroReparacoes
	 */
	int getNumeroReparacoes() const;

	/**
	 * @brief Retorna os campos onde o tecnico trabalhou
	 * @return vetor com os campos onde foram feitas reparacoes
	 */
	vector<campoTenis*> getCamposReparados() const;

	/**
 * @brief Retorna informacao relativa ao tecnico
 * @return informacao do tecnico
 */
	const char* getInfo();

};

class NaoDA{
public:
	NaoDA(){
		cout<<"nao dava."<<endl;
	}
};


#endif /* TECNICO_H_ */
