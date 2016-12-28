/*
 * Ordens.h
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#ifndef ORDEM_H_
#define ORDEM_H_

#include <string>
#include <iostream>
#include "Cliente.h"
#include "Data.h"


using namespace std;

/**
 * @class	Ordem
 *
 * @brief	Classe que representa uma ordem na bolsa de valores.
 */

class Ordem {
protected:
	/** @brief	Titulo da ordem. */
	string titulo;
	/** @brief	Data da ordem. */
	Data data;
	/** @brief	NIF do cliente que fez a ordem. */
	long nif_cliente;
public:

	/**
	 * @fn	Ordem::Ordem(string titulo, Data data, long nif_cliente);
	 *
	 * @brief	Constructor da classe.
	 *
	 * @param	titulo	   	Titulo da ordem.
	 * @param	data	   	Data da ordem.
	 * @param	nif_cliente	NIF do cliente.
	 */

	Ordem(string titulo, Data data, long nif_cliente);

	/**
	 * @fn	const string& Ordem::getTitulo() const
	 *
	 * @brief	Retorna o titulo da ordem.
	 *
	 * @return	O titulo da ordem.
	 */

	const string& getTitulo() const {
		return titulo;
	}

	/**
	 * @fn	void Ordem::setTitulo(const string& titulo)
	 *
	 * @brief	Define o titulo da ordem.
	 *
	 * @param	titulo Novo titulo da ordem.
	 */

	void setTitulo(const string& titulo) {
		this->titulo = titulo;
	}

	/**
	 * @fn	long Ordem::getNif();
	 *
	 * @brief	Retorna o NIF do cliente que fez a ordem.
	 *
	 * @return	NIF do cliente que fez a ordem.
	 */

	long getNif();

	/**
	 * @fn	Data Ordem::getData();
	 *
	 * @brief	Retorna a data da ordem.
	 *
	 * @return	a data da ordem.
	 */

	Data getData();

};




#endif /* ORDEM_H_ */
