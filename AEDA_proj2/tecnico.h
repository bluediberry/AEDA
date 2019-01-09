#ifndef TECNICO_H_
#define TECNICO_H_

#include "pessoa.h"
#include "campoTenis.h"
//#include "data.h"

#define MAX_REPARACOES 10

class Tecnico: public Pessoa {
	int numeroReparacoes;
	int DiasAteDisponibilidade;
	vector<campoTenis*> camposReparados;
	vector<Data*> diasReparacao;
	float custo;
	Data dataInscricao;

public:
	/**
	 * @brief contrutor da classe tecnico
	 * @param idTec identificador do tecnico
	 * @param nome nome do tecnico
	 * @param nrRep numero de reparacoes efetuadas pelo tecnico
	 * @param diasDisp numero de dias ate o tecnico se encontrar disponivel
	 * @param data data em que o tecnico se juntou a empresa
	 */
	Tecnico(int idTec, string nome, int nrRep, int diasDisp, float custo, string data);

	/**
	 * @brief construtor da classe tecnico
	 * @param nome nome do tecnico
	 * @param diasAteDisp numero de dias ate o tecnico estar disponivel
	 */
	Tecnico(string nome, int diasAteDisp, float custo, string data);

	/**
	 * @brief retorna data em que o tecnico se juntou a empresa
	 * @return string com a data
	 */
	string getData() const;

	/**
	 * @brief Retorna o valor do custo do serviço associado à reparacao.
	 * @return float com o preço cobrado pelo tecnico
	 */
	float getCusto() const;
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
	string getInfo() const;

	/**
	 * @brief Retorna os dias em que o tecnico trabalhou a fazer reparacoes.
	 * @return vetor com as datas dos dias que o tecnico trabalhou
	 */
	vector<Data*> getDiasReparacao() const;

	/**
	 * @brief Verifica se o tecnico trabalhou no dia "dia".
	 * @param dia - string com o dia a procurar
	 * @return true se ele trabalha nesse dia, false se nao trabalha.
	 */
	bool checkDiaReparacao(string dia);

	/**
	 * @brief Adiciona um dia de reparacao ao vetor de dias.
	 */
	void adicionarDiaReparacao(string data);

	/*
	 * @brief ADiciona um campo para reparacao ao vetor de acmpos
	 */
	void adicionarCampoReparacao(campoTenis * ct1);

	/*
	 * @brief Verifica se o tecnico ja esta disponivel para trabalhar apartir do dia dia.
	 * @return true se estiver disponivel, false se nao estiver.
	 */
	bool disponivel(string dia);
};

class ExceptionNumeroDeReparacoesExcedida{
public:
	ExceptionNumeroDeReparacoesExcedida();
	string getInfo() const {
		return "O tecnico escolhido excedeu o numero de reparacoes.";
	}
};


#endif /* TECNICO_H_ */
