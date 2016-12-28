/*
 * OrdemVenda.h
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#ifndef ORDEMVENDA_H_
#define ORDEMVENDA_H_

#include "Ordem.h"
#include "Utils.h"

#include <string>
#include <iostream>


using namespace std;

/**
 * @class	OrdemVenda
 *
 * @brief	Classe que representa uma ordem de venda na bolsa de valores.
 */

class OrdemVenda: public Ordem {
private:
	/** @brief	A quantidade de acoes a vender. */
	int quantidade;
	/** @brief	O preco minimo de venda de cada acao. */
	float precoMin;
public:

	/**
	 *
	 * @brief	Constructor.
	 *
	 * @param	titulo	   	O titulo da ordem de venda.
	 * @param	data	   	A data da ordem de venda.
	 * @param	nif_cliente	O NIF do cliente da ordem de venda.
	 * @param	quantidade 	A quantidade de acoes a vender.
	 * @param	precoMin   	O preco minimo de venda de cada acao.
	 */

	OrdemVenda(string titulo, Data data, long nif_cliente, int quantidade, float precoMin);

	/**
	 * @fn	float OrdemVenda::getPrecoMin() const
	 *
	 * @brief	Retorna o preco minimo de venda de cada acao.
	 *
	 * @return	O preco minimo de venda de cada acao.
	 */

	float getPrecoMin() const {
		return precoMin;
	}

	/**
	 * @fn	void OrdemVenda::setPrecoMin(float precoMin)
	 *
	 * @brief	Define o preco minimo de venda de cada acao.
	 *
	 * @param	precoMin	O preco minimo de venda de cada acao.
	 */

	void setPrecoMin(float precoMin) {
		this->precoMin = precoMin;
	}

	/**
	 * @fn	int OrdemVenda::getQuantidade() const
	 *
	 * @brief	Retorna a quantidade de acoes a vender.
	 *
	 * @return	A quantidade de acoes a vender.
	 */

	int getQuantidade() const {
		return quantidade;
	}

	/**
	 * @fn	void OrdemVenda::setQuantidade(int quantidade)
	 *
	 * @brief	Define a quantidade de acoes a vender.
	 *
	 * @param	quantidade	A quantidade de acoes a vender.
	 */

	void setQuantidade(int quantidade) {
		this->quantidade = quantidade;
	}

	/**
	 * @fn	void OrdemVenda::guardar(ofstream & out) const;
	 *
	 * @brief	Escreve no ficheiro que guarda as informacoes das ordens de venda.
	 *
	 * @param			out	Ficheiro em que se escreve as informacoes.
	 */

	void guardar(ofstream & out) const;

	/**
	* @fn	bool OrdemVenda::operator <(const OrdemVenda& ov);
	*
	* @brief	Operador de comparacao "menor que".
	*
	* @param	ov	Ordem de Venda a comparar.
	*
	* @return	True se o primeiro parametro for menor que o segundo.
	*/

	bool operator <(const OrdemVenda& ov);


	/**
	 * @fn	friend ostream& OrdemVenda::operator<<(ostream& out, const OrdemVenda & ordem);
	 *
	 * @brief	Operador para imprimir ordem de venda.
	 *
	 * @param [in,out]	out  	Onde imprime a ordem de venda.
	 * @param 		  	ordem	A ordem de venda a imprimir.
	 */

	friend ostream& operator<<(ostream& out, const OrdemVenda & ordem);

};




#endif /* ORDEMVENDA_H_ */
