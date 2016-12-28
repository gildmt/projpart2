/*
* Data.h
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#ifndef SRC_DATA_H_
#define SRC_DATA_H_

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>



using namespace std;

/**
* @class	Data
*
* @brief	Classe que guarda o dia, mes e ano e as funcoes para manipulacao da mesma.
*/

class Data {
private:
	/** @brief	O ano. */
	int ano;
	/** @brief	O mes. */
	int mes;
	/** @brief	O dia. */
	int dia;
public:

	/**
	* @fn	Data::Data(int d, int m, int a);
	*
	* @brief	Construtor que aceita o dia, mes e ano.
	*
	* @param	d	O dia.
	* @param	m	O mes.
	* @param	a	O ano.
	*/

	Data(int d, int m, int a);

	/**
	* @fn	Data::Data();
	*
	* @brief	Construtor por defeito.
	*/

	Data();

	/**
	* @fn	Data::Data(string data_str);
	*
	* @brief	Constructor que converte string na forma "dd/mm/ano" para Data.
	*
	* @param	data_str	data na forma "dd/mm/ano".
	*/

	Data(string data_str);

	/**
	* @fn	bool Data::valida(void) const;
	*
	* @brief	Verifica se a data e valida.
	*
	* @return	True se valida, false se invalida.
	*/

	bool valida(void) const;

	/**
	* @fn	int Data::getDia() const;
	*
	* @brief	Retorna o dia.
	*
	* @return	O dia.
	*/

	int getDia() const;

	/**
	* @fn	int Data::getMes() const;
	*
	* @brief	Retorna o mes.
	*
	* @return	O mes.
	*/

	int getMes() const;

	/**
	* @fn	int Data::getAno() const;
	*
	* @brief	Retorna o ano.
	*
	* @return	O ano.
	*/

	int getAno() const;

	/**
	* @fn	void Data::setDia(const int& d);
	*
	* @brief	Define o dia.
	*
	* @param	d	O dia.
	*/

	void setDia(const int& d);

	/**
	* @fn	void Data::setMes(const int& m);
	*
	* @brief	Define o mes.
	*
	* @param	m	O mes.
	*/

	void setMes(const int& m);

	/**
	* @fn	void Data::setAno(const int& a);
	*
	* @brief	Define o ano.
	*
	* @param	a	O ano
	*/

	void setAno(const int& a);

	/**
	* @fn	bool Data::operator==(const Data& d);
	*
	* @brief	Operador de igualdade.
	*
	* @param	d	A data a comparar.
	*
	* @return	True se o dia, o mes e ano forem iguais. False se diferentes.
	*/

	bool operator ==(const Data& d);

	/**
	* @fn	bool Data::operator<(const Data& d);
	*
	* @brief	Operador de comparacao "menor que".
	*
	* @param	d	A data a comparar.
	*
	* @return	True se o primeiro parametro for menor que o segundo.
	*/

	bool operator <(const Data& d);

	/**
	* @fn	friend ostream& Data::operator<<(ostream& os, const Data& d);
	*
	* @brief	Escreve a data na forma dd/mm/aaaa
	*
	* @param			os	Output.
	* @param 		  	d 	A data a mostrar.
	*/

	friend ostream& operator <<(ostream& os, const Data& d);












};


#endif /* SRC_DATA_H_ */