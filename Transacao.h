/*
 * Transacao.h
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#ifndef SRC_TRANSACAO_H_
#define SRC_TRANSACAO_H_

#include "Cliente.h"
#include "Data.h"
#include "Utils.h"
#include <string>
#include <iomanip>

/**
 * @class	Transacao
 *
 * @brief	Classe que representa uma transacao na bolsa de valores.
 */

class Transacao {
private:
	/** @brief	O titulo da acao da transacao. */
	string titulo;
	/** @brief	O preco da acao. */
	float preco_acao;
	/** @brief	Numero de acoes da transacao. */
	int num_acoes;
	/** @brief	A data da transacao. */
	Data data;
	/** @brief	O NIF do cliente que vende as acoes. */
	long nif_cliente_v;
	/** @brief	O NIF do cliente que compra as acoes. */
	long nif_cliente_c;
	
public:

	/**
	 * @fn	Transacao::Transacao(string titulo, float preco_acao, int num_acoes, Data data, long cliente_v, long cliente_c);
	 *
	 * @brief	Constructor.
	 *
	 * @param	titulo	  	O titulo da acao da transacao.
	 * @param	preco_acao	O preso da acao.
	 * @param	num_acoes 	Numero de acoes da transacao.
	 * @param	data	  	A data da transacao.
	 * @param	cliente_v 	O NIF do cliente que vende as acoes.
	 * @param	cliente_c 	O NIF do cliente que compra as acoes.
	 */

	Transacao(string titulo, float preco_acao, int num_acoes, Data data, long cliente_v, long cliente_c);

	/**
	 * @fn	Transacao::Transacao(ifstream & in);
	 *
	 * @brief	Constructor que le uma linha de um ficheiro de texto.
	 *
	 * @param			in	Ficheiro de texto.
	 */

	Transacao(ifstream & in); //le linha de ficheiro

	/**
	 * @fn	bool Transacao::operator<(const Transacao &tr) const;
	 *
	 * @brief	Compara as transacoes por data.
	 *
	 * @param	tr	Segunda transacao a comparar.
	 *
	 * @return	Verdade se a data da primeira transacao for menor que da segunda.
	 */

	bool operator<(const Transacao &tr) const; // compara 2 transacoes (1 transacao e menor que outra se estiver há mais tempo no mercado)

	/**
	 * @fn	friend ostream& Transacao::operator<<(ostream& out, const Transacao & transacao);
	 *
	 * @brief	Operador para imprimir uma transacao.
	 *
	 * @param			out		 	Onde imprime a transacao.
	 * @param 		  	transacao	A transacao a imprimir.
	 */

	friend ostream& operator<<(ostream& out, const Transacao & transacao);  // mostra informacao da transacao no ecra

	/**
	 * @fn	string Transacao::getTitulo();
	 *
	 * @brief	Retorna o titulo da acao da transacao.
	 *
	 * @return	O titulo da acao da transacao.
	 */

	string getTitulo();

	/**
	 * @fn	float Transacao::getPreco_acao();
	 *
	 * @brief	Retorna o preco por acao da transacao.
	 *
	 * @return	O preco por acao da transacao.
	 */

	float getPreco_acao();

	/**
	 * @fn	int Transacao::getNum_acoes();
	 *
	 * @brief	Retorna o numero de acoes.
	 *
	 * @return	O numero de acoes.
	 */

	int getNum_acoes();

	/**
	 * @fn	Data Transacao::getData();
	 *
	 * @brief	Retorna a data da transacao.
	 *
	 * @return	The data.
	 */

	Data getData();

	/**
	 * @fn	long Transacao::getCliente_v();
	 *
	 * @brief	Retorna o NIF do cliente que vende as acoes.
	 *
	 * @return	O NIF do cliente que vende as acoes.
	 */

	long getCliente_v();

	/**
	 * @fn	long Transacao::getCliente_c();
	 *
	 * @brief	Retorna o NIF do cliente que compra as acoes.
	 *
	 * @return O NIF do cliente que vende as acoes.
	 */

	long getCliente_c();

	/**
	 * @fn	void Transacao::guardar(ofstream & out) const;
	 *
	 * @brief	Escreve num ficheiro que guarda as informacoes das transacoes.
	 *
	 * @param			out	Ficheiro em que se escreve as informacoes.
	 */

	void guardar(ofstream & out) const;
};



#endif /* SRC_TRANSACAO_H_ */