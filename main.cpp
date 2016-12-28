/*
 * main.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#include "Bolsa.h"
#include "Data.h"
#include "Menus.h"
#include "Utils.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>


using namespace std;

string fichClientes, fichTransacoes, fichOrdensVenda, fichOrdensCompra;


int main(){

	if (infoInicial(fichClientes, fichTransacoes, fichOrdensVenda, fichOrdensCompra))
		return 1;

	// cria bolsa
	Bolsa bolsa_de_valores;
	
	//le ficheiros
	bolsa_de_valores.le_ficheiros(fichClientes, fichTransacoes, fichOrdensVenda, fichOrdensCompra);

	opcoesIniciais(bolsa_de_valores); // menu inicial com as grandes opcoes
	// que implementam as funcionalidades
	// disponibilizadas
	
	return 0;
}