/*
 * Ordens.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */


#include "Ordem.h"
#include "Cliente.h"


Ordem::Ordem(string titulo, Data data, long nif_cliente) {
	this->titulo = titulo;
	this->data=data;
	this->nif_cliente = nif_cliente;
}

long Ordem::getNif() {
	return nif_cliente;
}

Data Ordem::getData() {
	return data;
}