/*
 * OrdemVenda.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */


#include "OrdemVenda.h"

OrdemVenda::OrdemVenda(string titulo, Data data, long nif_cliente, int quantidade, float precoMin) : Ordem(titulo, data, nif_cliente) {
	this->quantidade=quantidade;
	this->precoMin=precoMin;
}

void OrdemVenda::guardar(ofstream & out) const{
	out << nif_cliente << " ; "
		<< data << " ; "
		<< titulo << " ; "
		<< precoMin << " ; "
		<< quantidade << endl;

}

bool OrdemVenda::operator <(const OrdemVenda& ov){
	return data < ov.data;
}

ostream& operator<<(ostream& out, const OrdemVenda & ordem)
{
	out << TAB << BARRA << " " << right << setfill('0') << setw(9) << ordem.nif_cliente << setfill(' ') << left
		<< " " << BARRA << " " << setw(12) << ordem.data << " " << BARRA
		<< " " << setw(13) << ordem.titulo << " " << BARRA
		<< " " << right << setw(12) << ordem.precoMin << " " << BARRA
		<< " " << setw(10) << ordem.quantidade << " " << BARRA << endl;

	return out;
}
