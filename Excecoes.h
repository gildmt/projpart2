/*
* Excecoes.h
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#ifndef SRC_EXCECOES_H_
#define SRC_EXCECOES_H_

#include <string>
#include "Utils.h"

using namespace std;

/**
* @class	FicheiroInexistente
*
* @brief	Excecao que e lancada quando se tenta abrir um ficheiro inexistente.
*/

class FicheiroInexistente {
public:
	/** @brief	O tipo de ficheiro. */
	string tipo_fich;

	/**
	* @fn	FicheiroInexistente::FicheiroInexistente(string tipo_fich);
	*
	* @brief	Construtor que aceita o tipo de ficheiro.
	*
	* @param	tipo_fich	O tipo de ficheiro.
	*/

	FicheiroInexistente(string tipo_fich);

	/**
	* @fn	friend ostream& FicheiroInexistente::operator<<(ostream& out, const FicheiroInexistente & fich_inex);
	*
	* @brief	Envia uma mensagem a avisar o utilizador que o ficheiro nao existe e sera criado um com esse nome.
	*
	* @param			out		 	A consola.
	* @param 		  	fich_inex	O nome do ficheiro.
	*/

	friend ostream& operator<<(ostream& out, const FicheiroInexistente & fich_inex);
};

/**
* @class	FicheiroInvalido
*
* @brief	Excecao que e lancada quando se abre um ficheiro invalido.
*/

class FicheiroInvalido {
private:
	/** @brief	O tipo de ficheiro.  */
	string tipo_fich;

public:

	/**
	* @fn	FicheiroInvalido::FicheiroInvalido(string tipo_fich);
	*
	* @brief	Constructor que aceita o tipo de ficheiro.
	*
	* @param	tipo_fich	O tipo de ficheiro.
	*/

	FicheiroInvalido(string tipo_fich);

	/**
	* @fn	friend ostream& FicheiroInvalido::operator<<(ostream& out, const FicheiroInvalido & fich_inva);
	*
	* @brief	Envia uma mensagem a avisar o utilizador que o ficheiro e invalido.
	*
	* @param			out		 	A consola.
	* @param 		  	fich_inva	O nome do ficheiro.
	*/

	friend ostream& operator<<(ostream& out, const FicheiroInvalido & fich_inva);
};







#endif /* SRC_EXCECOES_H_ */