/*
* Data.c
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#include "Data.h"


Data::Data(int d, int m, int a) {
	dia = d;
	mes = m;
	ano = a;
}


Data::Data() {}

Data::Data(string data_str){
	istringstream line(data_str);
	line >> dia; line.ignore();
	line >> mes; line.ignore();
	line >> ano;
}

int Data::getDia() const {
	return dia;
}

int Data::getMes() const {
	return mes;
}

int Data::getAno() const {
	return ano;
}


void Data::setDia(const int& d) {
	dia = d;
}

void Data::setMes(const int& m) {
	mes = m;
}


void Data::setAno(const int& a) {
	ano = a;
}

bool Data::valida() const {

	if (ano < 0)								//ano nao pode ser negativo
		return false;

	if (mes >12 || mes <1)
		return false;

	if (dia >31 || dia < 1)
		return false;

	if ((dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)))
		return false;

	if (dia == 30 && mes == 2)
		return false;

	if ((dia == 29 && mes == 2) && !((ano - 2000) % 4 == 0))
		return false;


	return true;
}



bool Data::operator ==(const Data& d) {

	if ((dia == d.dia) && (mes == d.mes) && (ano == d.ano))
		return true;

	return false;
}

bool Data::operator <(const Data& d) {

	if (ano < d.ano)
		return true;

	if (ano > d.ano)
		return false;

	// mesmo ano
	if (mes < d.mes)
		return true;

	if (mes > d.mes)
		return false;

	// mesmo mes
	if (dia < d.dia)
		return true;

	return false;
}

ostream & operator <<(ostream& os, const Data& d) {
	os << setfill('0') << setw(2) << right << d.dia << "/"
		<< setw(2) << d.mes << "/"
		<< setw(4) << d.ano;
	os << setfill(' ') << left;
	return os;
}


