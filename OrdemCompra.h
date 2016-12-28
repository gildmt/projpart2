/*
 * OrdemCompra.h
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#ifndef ORDEMCOMPRA_H_
#define ORDEMCOMPRA_H_

#include "Ordem.h"
#include "Utils.h"

#include <string>
#include <iostream>

using namespace std;

/**
 * @class	OrdemCompra
 *
 * @brief	Classe que representa uma ordem de compra na bolsa de valores.
 */

class OrdemCompra: public Ordem {
private:
	/** @brief	O preco maximo disposto a pagar por acao. */
	float precoMax;
	/** @brief	O valor maximo disposto a pagar. */
	float valorMaxGastar;
public:

	/**
	 * @fn	OrdemCompra::OrdemCompra(string titulo, Data data, long nif_cliente, float precoMax, float valorMaxGastar);
	 *
	 * @brief	Constructor.
	 *
	 * @param	titulo		  	O titulo da ordem de compra.
	 * @param	data		  	A data da ordem de compra.
	 * @param	nif_cliente   	O NIF do cliente  da ordem de compra.
	 * @param	precoMax	  	O preco maximo disposto a pagar por acao.
	 * @param	valorMaxGastar	O valor maximo disposto a pagar.
	 */

	OrdemCompra(string titulo, Data data, long nif_cliente, float precoMax, float valorMaxGastar);

	/**
	 * @fn	float OrdemCompra::getPrecoMax() const
	 *
	 * @brief	Retorna o preco maximo disposto a pagar por acao.
	 *
	 * @return	O preco maximo disposto a pagar por acao.
	 */

	float getPrecoMax() const {
		return precoMax;
	}

	/**
	 * @fn	void OrdemCompra::setPrecoMax(float precoMax)
	 *
	 * @brief	Define o preco maximo disposto a pagar por acao.
	 *
	 * @param	precoMax	O preco maximo disposto a pagar por acao.
	 */

	void setPrecoMax(float precoMax) {
		this->precoMax = precoMax;
	}

	/**
	 * @fn	float OrdemCompra::getValorMaxGastar() const
	 *
	 * @brief	Retorna o valor maximo disposto a pagar.
	 *
	 * @return	O valor maximo disposto a pagar.
	 */

	float getValorMaxGastar() const {
		return valorMaxGastar;
	}

	/**
	 * @fn	void OrdemCompra::setValorMaxGastar(float valorMaxGastar)
	 *
	 * @brief	Define o valor maximo disposto a pagar.
	 *
	 * @param	valorMaxGastar	O valor maximo disposto a pagar.
	 */

	void setValorMaxGastar(float valorMaxGastar) {
		this->valorMaxGastar = valorMaxGastar;
	}

	/**
	 * @fn	void OrdemCompra::guardar(ofstream & out) const;
	 *
	 * @brief	Escreve no ficheiro que guarda as informacoes das ordens de compra.
	 *
	 * @param			out	Ficheiro em que se escreve as informacoes.
	 */

	void guardar(ofstream & out) const;

	/**
	* @fn	bool OrdemCompra::operator <(const OrdemCompra& oc);
	*
	* @brief	Operador de comparacao "menor que".
	*
	* @param	oc	Ordem de Compra a comparar.
	*
	* @return	True se o primeiro parametro for menor que o segundo.
	*/

	bool operator <(const OrdemCompra& oc);



	/**
	 * @fn	friend ostream& OrdemCompra::operator<<(ostream& out, const OrdemCompra & ordem);
	 *
	 * @brief	Operador para imprimir ordem de compra.
	 *
	 * @param			out  	Onde imprimir a ordem de compra.
	 * @param 		  	ordem	A ordem de compra a imprimir.
	 */

	friend ostream& operator<<(ostream& out, const OrdemCompra & ordem);	
	
};



#endif /* ORDEMCOMPRA_H_ */
