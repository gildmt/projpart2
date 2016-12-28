/*
* Excecoes.h
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#ifndef SRC_MENUS_H_
#define SRC_MENUS_H_

#include <iostream>
#include <fstream>
#include <string>



#include "utils.h"
#include "Bolsa.h"
#include "Excecoes.h"

using namespace std;

/**
 * @fn	int verfica_fich(string & fich_veri, string tipo_fich);
 *
 * @brief	Verfica se fich_veri existe e se e valido.
 *
 * @param			fich_veri	Ficheiro a verificar.
 * @param 		  	tipo_fich	Cabecalho valido do ficheiro.
 *
 * @return	1 se nao for valido ou der erro e 0 se o ficheiro for valido.
 */

int verfica_fich(string & fich_veri, string tipo_fich);

/**
 * @fn	int infoInicial(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra);
 *
 * @brief	Verifica os 4 ficheiros de dados com a funcao verifica_fich.
 *
 * @param			fichClientes		O ficheiro com as informacoes dos clientes.
 * @param			fichTransacoes  	O ficheiro com as informacoes das transacoes.
 * @param			fichOrdensVenda 	O ficheiro com as informacoes das ordens venda.
 * @param			fichOrdensCompra	O ficheiro com as informacoes das ordens compra.
 *
 * @return	1 se um dos 4 ficheiros nao for valido e 0 se todos forem validos.
 */

int infoInicial(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra);

/**
 * @fn	void opcoesIniciais(Bolsa & bolsa_de_valores);
 *
 * @brief	Le a opcao do utilizadoe do menu inicial.
 *
 * @param			bolsa_de_valores	A classe que contem a bolsa de valores.
 */

void opcoesIniciais(Bolsa & bolsa_de_valores);

/**
 * @fn	void menuTransacoes(Bolsa & bolsa_de_valores);
 *
 * @brief	Apresenta o menu com as varias opcoes para listar as transacoes.
 *
 * @param			bolsa_de_valores	A classe que contem a bolsa de valores.
 */

void menuTransacoes(Bolsa & bolsa_de_valores);


#endif /* SRC_MENUS_H_ */