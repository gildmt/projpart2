/*
 * OrdemCompra.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#include "OrdemCompra.h"

OrdemCompra::OrdemCompra(string titulo, Data data, long nif_cliente, float precoMax, float valorMaxGastar) : Ordem(titulo, data, nif_cliente) {
	this->precoMax=precoMax;
	this->valorMaxGastar=valorMaxGastar;
}


void OrdemCompra::guardar(ofstream & out) const{
	out << nif_cliente << " ; "
		<< data << " ; "
		<< titulo << " ; "
		<< precoMax << " ; "
		<< valorMaxGastar << endl;

}

bool OrdemCompra::operator <(const OrdemCompra& oc){
	return data < oc.data;
}


ostream& operator<<(ostream& out, const OrdemCompra & ordem)
{
	out << TAB << BARRA << " " << right << setfill('0') << setw(9) << ordem.nif_cliente << setfill(' ') << left
		<< " " << BARRA << " " << setw(12) << ordem.data << " " << BARRA
		<< " " << setw(13) << ordem.titulo << " " << BARRA
		<< " " << right << setw(12) << ordem.precoMax << " " << BARRA
		<< " " << setw(12) << ordem.valorMaxGastar << " " << BARRA << endl;
	
	return out;
}