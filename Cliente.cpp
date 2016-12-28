/*
 * Clientes.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */
#include "Cliente.h"

Cliente::Cliente(string nome, long nif, string morada, long tel, Data ultAtividade) {
	this->nome = nome;
	this->nif = nif;
	this->morada = morada;
	this->tel = tel;
	this->ultAtividade = ultAtividade;
}

Cliente::Cliente()
{

};

Cliente::Cliente(ifstream & in){
	string nome_aux;
	long nif_aux;
	string morada_aux;
	long tel_aux;
	string ultAtividade_aux;
	
	getline(in, nome_aux, ';'); nome_aux.erase(nome_aux.end() - 1); //apaga ultimo espaco
	
	in >> nif_aux;
	in.ignore(3); //anda 3 espaco
	
	getline(in, morada_aux, ';'); morada_aux.erase(morada_aux.end() - 1); //apaga ultimo espaco

	in >> tel_aux;
	in.ignore(3); //anda 3 espaco

	getline(in, ultAtividade_aux);
	

	nome = nome_aux;
	nif = nif_aux;
	morada = morada_aux;
	tel = tel_aux;
	ultAtividade = Data(ultAtividade_aux);


}

string Cliente::getNome(){
	return nome;

}
long Cliente::getNif() const{
	return nif;
}

string Cliente::getMorada(){
	return morada;

}
long Cliente::getTel(){
	return tel;
}
Data Cliente::getUltAtividade(){
	return ultAtividade;
}

void Cliente::setNome(string nome){
	this->nome = nome;
}

void Cliente::setNif(long nif){
	this->nif = nif;
}

void Cliente::setMorada(string morada){
	this->morada = morada;
}

void Cliente::setTel(long tel){
	this->tel = tel;
}
void Cliente::setUltAtividade(Data ultAtividade){
	this->ultAtividade = ultAtividade;
}

bool Cliente::operator<(const Cliente &cl) const {
	return nome < cl.nome;
}



void Cliente::guardar(ofstream & out) const{
	out << nome << " ; "
		<< nif << " ; "
		<< morada << " ; "
		<< tel << " ; "
		<< ultAtividade << endl;
}


ostream& operator<<(ostream& out, const Cliente &cl)
{

	out << TAB << BARRA << " " << setw(16) << cl.nome
		<< " " << BARRA << " " << right << setfill('0') << setw(9) << cl.nif << left << setfill(' ')  << " " << BARRA
		<< " " << setw(23) << cl.morada << " " << BARRA
		<< " " << right << setfill('0') << setw(9) << cl.tel << left << setfill(' ') << " " << BARRA << endl;

	return out;
}
