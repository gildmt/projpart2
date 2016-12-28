/*
 * Transacao.c
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#include "Transacao.h"

Transacao::Transacao(string titulo, float preco_acao, int num_acoes, Data data, long cliente_v, long cliente_c){
	this->titulo = titulo;
	this->preco_acao = preco_acao;
	this->num_acoes = num_acoes;
	this->data = data;
	this->nif_cliente_c = cliente_c;
	this->nif_cliente_v = cliente_v;
}

Transacao::Transacao(ifstream & in){
	string titulo_aux, data_str;
	float preco_acao_aux;
	int num_acoes_aux;
	long nif1_aux, nif_aux2;

	//le ficheiro
	in >> nif1_aux;
	in.ignore(3); //anda 3 espaco
	in >> nif_aux2;
	in.ignore(3); //anda 3 espaco
	getline(in, data_str, ';'); data_str.erase(data_str.end() - 1); //apaga ultimo espaco
	in.ignore(); //anda 1 espaco
	getline(in, titulo_aux, ';'); titulo_aux.erase(titulo_aux.end() - 1); //apaga ultimo espaco
	in >> preco_acao_aux;
	in.ignore(3); //anda 3 espaco
	in >> num_acoes_aux;

	titulo = titulo_aux;
	preco_acao = preco_acao_aux;
	num_acoes = num_acoes_aux;
	data = Data(data_str);
	nif_cliente_v = nif1_aux;
	nif_cliente_c = nif_aux2;
}


bool Transacao::operator<(const Transacao &tr) const {
	if (data.getAno() < tr.data.getAno())
		return true;
	else if (data.getAno() == tr.data.getAno()) {
		if (data.getMes() < tr.data.getMes())
			return true;
		else if (data.getMes() == tr.data.getMes()) {
			if (data.getDia() < tr.data.getDia())
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}


ostream& operator<< (ostream& out, const Transacao & transacao){
	out << TAB << BARRA << " " << right << setfill('0') << setw(9) << transacao.nif_cliente_c << " " << BARRA
		<< " " << right << setw(9) << transacao.nif_cliente_v << " " << BARRA << setfill(' ') << left
		<< " " << setw(12) << transacao.data << " "<< BARRA
		<< " " << setw(13) << transacao.titulo << " " << BARRA
		<< " " << right << setprecision(2) << fixed << setw(12) << transacao.preco_acao << " " << BARRA
		<< " " << setw(12) << transacao.num_acoes << " " << BARRA << endl;
	
	return out;
}


long Transacao::getCliente_v(){
	return nif_cliente_v;
}
long Transacao::getCliente_c(){
	return nif_cliente_c;
}
string Transacao::getTitulo(){
	return titulo;
}
float Transacao::getPreco_acao() {
	return preco_acao;
}
int Transacao::getNum_acoes() {
	return num_acoes;
}
Data Transacao::getData() {
	return data;
}

void Transacao::guardar(ofstream & out) const{
	out << nif_cliente_v << " ; "
		<< nif_cliente_c << " ; "
		<< data << " ; "
		<< titulo << " ; "
		<< preco_acao << " ; "
		<< num_acoes << endl;

}