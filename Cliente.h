/*
* Cliente.h
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include <iostream>
#include <fstream>
#include "Utils.h"


using namespace std;

/**
* @class	Cliente
*
* @brief	Classe que guarda o nome, o NIF, a morada e o telemovel do cliente e as funcoes para manipulacao da mesma.
*/

class Cliente {
private:
	/** @brief	O nome do Cliente. */
	string nome;
	/** @brief	O NIF do Cliente. */
	long nif;
	/** @brief	A morada do Cliente. */
	string morada;
	/** @brief	O telemovel do Cliente. */
	long tel;
	/** @brief	A data da ultima atividade do Cliente(Criacao do Cliente ou insercao de Ordem). */
	Data ultAtividade;


public:

	/**
	* @fn	Cliente::Cliente(string nome, long NIF, string morada, long tel);
	*
	* @brief	Constructor do Cliente que aceita o nome, o NIF, a morada e o telemovel como parametros.
	*
	* @param	nome	O nome.
	* @param	NIF 	O nif.
	* @param	morada	A morada.
	* @param	tel 	O telemovel.
	*/

	Cliente(string nome, long NIF, string morada, long tel, Data ultAtividade);

	/**
	* @fn	Cliente::Cliente();
	*
	* @brief	Construtor por defeito.
	*/

	Cliente();

	/**
	* @fn	Cliente::Cliente(ifstream & in);
	*
	* @brief	Constructor que le uma linha de um ficheiro.
	*
	* @param   in	Ficheiro de Clientes.
	*/

	Cliente(ifstream & in); 

	/**
	* @fn	string Cliente::getNome();
	*
	* @brief	Retorna o nome do Cliente.
	*
	* @return	O Nome do Cliente.
	*/

	string getNome();

	/**
	* @fn	int Cliente::getNif();
	*
	* @brief	Retorna o NIF do Cliente.
	*
	* @return	 O NIF do Cliente.
	*/

	long getNif() const;


	/**
	* @fn	string Cliente::getMorada();
	*
	* @brief	Retorna a morada do Cliente.
	*
	* @return	A morada do Cliente.
	*/

	string getMorada();

	/**
	* @fn	int Cliente::getTel();
	*
	* @brief	Retorna o telemovel do Cliente.
	*
	* @return	 O telemovel do Cliente.
	*/

	long getTel();


	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* @fn	int Cliente::getTel();
	*
	* @brief	Retorna o telemovel do Cliente.
	*
	* @return	 O telemovel do Cliente.
	*/

	Data getUltAtividade();

	/**
	* @fn	void Cliente::setNome(string nome);
	*
	* @brief	Define o nome do Cliente.
	*
	* @param	nome	 O nome do Cliente.
	*/

	void setNome(string nome);

	/**
	* @fn	void Cliente::setNif(long NIF);
	*
	* @brief	Define o NIF do Cliente.
	*
	* @param	NIF	O NIF do Cliente.
	*/

	void setNif(long NIF);

	/**
	* @fn	void Cliente::setMorada(string morada);
	*
	* @brief	Define a morada do Cliente.
	*
	* @param	morada	 A morada do Cliente.
	*/

	void setMorada(string morada);

	/**
	* @fn	void Cliente::setTel(long tel);
	*
	* @brief	Define o telemovel do Cliente.
	*
	* @param	tel	O telemovel do Cliente.
	*/

	void setTel(long tel);


	/**
	* @fn	void Cliente::setTel(long tel);
	*
	* @brief	Define o telemovel do Cliente.
	*
	* @param	tel	O telemovel do Cliente.
	*/

	void setUltAtividade(Data ultAtividade);


	/**
	* @fn	bool Cliente::operator<(const Cliente &cl) const;
	*
	* @brief	Operador de comparacao "menor que".
	*
	* @param			cl	O Cliente com que se compara.
	*
	* @return	True se o primeiro parametro for menor que o segundo. False se maior ou igual.
	*/

	bool operator<(const Cliente &cl) const;

	/**
	* @fn	void Cliente::guardar(ofstream & out) const;
	*
	* @brief	Escreve no ficheiro de texto na forma "nome ; nif".
	*
	* @param			out	O Ficheiro de texto em que se escreve.
	*/

	void guardar(ofstream & out) const;


	/**
	* @fn	friend ostream& Cliente::ostream& operator<<(ostream& out, const Cliente &cl);
	*
	* @brief	Operador para imprimir Cliente.
	*
	* @param [in,out]	out  	Onde imprime a ordem de venda.
	* @param 		  	ordem	O cliente a imprimir.
	*/

	friend ostream& operator<<(ostream& out, const Cliente &cl);

};



#endif /* CLIENTE_H_ */
