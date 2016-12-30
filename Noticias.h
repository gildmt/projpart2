/*
 * Noticias.h
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#ifndef NOTICIAS_H_
#define NOTICIAS_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "BST.h"
#include "Data.h"
#include "Utils.h"


using namespace std;

/**
 * @class	Noticia
 *
 * @brief	Classe que representa uma noticia na bolsa de valores.
 */

class Noticia {
	/** @brief	Data da noticia. */
	Data date;
	/** @brief	Nome do jornal que publica a noticia. */
	string paperName;
	/** @brief	Titulo da empresa que a noticia e sobre */
	string title;
	/** @brief	Rating da noticia de 0 a 10 */
	int rating;
public:
	/**
	* @fn	Noticia::Noticia(int d, int m, int a, string pN, string ttl, int r);
	*
	* @brief	Construtor da classe noticia.
	*
	* @param			d		Dia de publicacao da noticia.
	* @param			m  		Mes da publicacao da noticia.
	* @param			a  		Ano da publicacao da noticia.
	* @param			pN  	Nome do jornal que publica a noticia.
	* @param			ttl  	Titulo da empresa que a noticia e sobre
	* @param			r  		Rating da noticia de 0 a 10.
	*/

	Noticia(int d, int m, int a, string pN, string ttl, int r);

	/**
	* @fn	string Noticia::getTitle();
	*
	* @brief	Retorna o titulo da noticia.
	*/

	string getTitle();

	/**
	* @fn	Data Noticia::getDate();
	*
	* @brief	Retorna a data da noticia.
	*/

	Data getDate();

	/**
	* @fn	void Noticia::setRating(int r);
	*
	* @brief	Define o rating da noticia.
	*/

	void setRating(int r);

	/**
	* @fn	bool Noticia::operator==(const Noticia & nt1) const;
	*
	* @brief	Operador de comparacao entre noticias.
	*
	* @param	oc	Noticia a comparar.
	*
	* @return	True se ambos parametros forem iguais.
	*/

	bool operator==(const Noticia & nt1) const;

	/**
	* @fn	bool Noticia::operator<(const Noticia & nt1) const;
	*
	* @brief	Operador de comparacao "menor que".
	*
	* @param	oc	Noticia a comparar.
	*
	* @return	True se o primeiro parametro for menor que o segundo.
	*/

	bool operator<(const Noticia & nt1) const;

	/**
	* @fn	friend ostream& operator<<(ostream& out, const Noticia & noticia);
	*
	* @brief	Operador para imprimir noticia.
	*
	* @param [in,out]	out  	Onde imprime a noticia.
	* @param 		  	noticia A noticia a imprimir.
	*/

	friend ostream& operator<<(ostream& out, const Noticia & noticia);
};
#endif /* NOTICIA_H_ */