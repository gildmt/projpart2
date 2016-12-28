/*
* Excecoes.c
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#include "Excecoes.h"


FicheiroInexistente::FicheiroInexistente(string tipo_fich){
	this->tipo_fich = tipo_fich;
}


ostream& operator<< (ostream& out, const FicheiroInexistente & fich_inex){
	out << endl << TAB << "Esse ficheiro nao existe." << endl 
		<< TAB << "Sera criado um ficheiro de " 
		<< fich_inex.tipo_fich << " com esse nome.\n";
	return out;
}

FicheiroInvalido::FicheiroInvalido(string tipo_fich){
	this->tipo_fich = tipo_fich;
}


ostream& operator<< (ostream& out, const FicheiroInvalido & fich_inva){
	out << endl << TAB << "Esse ficheiro e invalido." << endl << TAB << "Introduza o nome de um ficheiro de "
		<< fich_inva.tipo_fich << " valido(ou control+z para sair): ";
	return out;
}

