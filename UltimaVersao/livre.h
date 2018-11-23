#ifndef LIVRE_H_
#define LIVRE_H_


#include "utilizacao.h"
#include <vector>



class Livre: public Utilizacao {
	static int id;
	int identificacao;
	vector<Utente*> grupo;
	int duracao; //multiplos de 30min



public:
	static int numero_maximo_utilizadores_modo_livre;

	/**
 * @brief Construtor da classe livre
 * @param data - data em que seria realizada a aula livre
 * @param horario - string que representa o horario em formato HH:MM
 * @param preco -preco da aula
 * @param duracao - duracao da aula
 */
	Livre(string data, string horario, float preco, unsigned int duracao);

	/**
 * @brief
 * @return
 */
	float getPrecoPorPessoa();

	/**
 * @brief
 * @return
 */
 void setDuracao(int duracao);

 /**
* @brief
* @return
*/
int getDuracao() const;

		/**
	 * @brief Adiciona um utente ao grupo da aula
	 * @param u1 - utente a adicionar
	 * @return Retorna true caso seja possivel adiocionar, false caso contrário.
	 */
    bool adicionar_ao_grupo(Utente * u1);

		/**
	 * @brief Remove um utente ao grupo da aula
	 * @param u1 - utente a remover
	 * @return Retorna true caso seja possivel remover, false caso contrário.
	 */
    bool remover_do_grupo(Utente * u1);

		/**
	 * @brief
	 * @return
	 */
	 vector<Utente*> getGrupo() const;

/**
* @brief
* @return
*/
string getInfo();

/**
* @brief
* @return
*/
int getIdentificacao() const;





};


class ExceptionInvalidFreeDuration{
public:
	ExceptionInvalidFreeDuration(){
		cout<<"A dura��o do modo livre deve ter x minutos"<<endl;
	}
};



#endif /* LIVRE_H_ */
