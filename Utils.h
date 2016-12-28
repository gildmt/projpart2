/*
* Utils.h
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include <windows.h>

/**
 * @def	ALTURA_ECRA
 *
 * @brief	Define a altura do output no ecra.
 */

#define ALTURA_ECRA 24

/**
 * @def	TAB_BIG
 *
 * @brief	Espaco usado para formatacao de elementos no ecra.
 */

#define TAB_BIG "          "

/**
 * @def	TAB
 *
 * @brief	Espaco usado para formatacao de elementos no ecra.
 */

#define TAB    "   "

/**
 * @def	BARRA
 *
 * @brief	Barra usada para formatacao de elementos no ecra.
 */

#define BARRA    "|"

#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

#include "Data.h"

#undef max

using namespace std;

/**
 * @property	extern string fichClientes, fichTransacoes, fichOrdensVenda, fichOrdensCompra
 *
 * @brief	Guarda os nomes dos ficheiros com os dados externamente para serem usados em varias funçoes.

 */

extern string fichClientes, fichTransacoes, fichOrdensVenda, fichOrdensCompra;

/**
 * @fn	void clearScreen();
 *
 * @brief	Apaga o ecra.
 */

void clearScreen();

/**
 * @fn	void linha(int n);
 *
 * @brief	Linha usada para formatacao de elementos no ecra.
 *
 * @param	n	Tamanho da linha e imprimir.
 */

void linha(int n);

/**
 * @fn	long le_num();
 *
 * @brief	Le um numero escrito pelo o utilizador.
 *
 * @return	Um long com o numero lido.
 */

long le_num();

/**
 * @fn	float le_float();
 *
 * @brief	Le um numero escrito pelo o utilizador.
 *
 * @return	Um float com o numero lido.
 */

float le_float();

/**
 * @fn	int leInteiro(int min, int max);
 *
 * @brief	Le um numero escrito pelo o utilizador.
 *
 * @param	min	O valor minimo a partir do qual aceita um inteiro para ler.
 * @param	max	O valor maximo antes do qual aceita um inteiro para ler.
 *
 * @return	Um inteiro com o numero lido.
 */

int leInteiro(int min, int max);

/**
 * @fn	long leNif();
 *
 * @brief	Le o NIF de um utilizador.
 *
 * @return	Um long com o NIF lido.
 */

long leNif();

/**
 * @fn	string leTitulo();
 *
 * @brief	Le uma string de uma palavra escrita pelo utiizador..
 *
 * @return	Uma string com o titulo lido.
 */

string leTitulo();

/**
 * @fn	void espera_input();
 *
 * @brief	Espera por imput do utilizador.
 */

void espera_input();

/**
 * @fn	Data getData();
 *
 * @brief	Retorna a data actual.
 *
 * @return	A data actual.
 */

Data getData();











void DatePlusDays(struct tm* date, int days);




void dataMaisDias(Data& data, int dias);











/**
 * @fn	bool fich_vazio(fstream& pFile);
 *
 * @brief	Testa para ver se um ficheiro esta vazio.
 *
 * @param			pFile	O ficheiro a testar.
 *
 * @return	True se o ficheiro estiver vazio, falso se nao.
 */

bool fich_vazio(fstream& pFile);

/**
 * @fn	void acabalog(string &str);
 *
 * @brief	Acrescenta o sufixo .log a uma string passada.
 *
 * @param		str	A string para acrescentar o sufixo.
 */

void acabalog(string &str);








template< typename T >
typename std::vector<T>::iterator
insert_sorted(std::vector<T> & vec, T const& item)
{
	return vec.insert
		(
		std::upper_bound(vec.begin(), vec.end(), item),
		item
		);
}






#endif /* SRC_UTILS_H_ */
