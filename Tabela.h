/*
* Cliente.h
*
*  Created on: 22/12/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#ifndef TABELA_H_
#define TABELA_H_

#include <string>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Cliente.h"


using namespace std;


struct CliHash {
	int operator()(const Cliente & cl) const {
		int pos = 0;
		long nif_cli = cl.getNif();
		string nif_cli_s = to_string(nif_cli);

		for (size_t i = 0; i < nif_cli_s.size(); i++)
			pos += 37 * pos + nif_cli_s.at(i);

		return pos;

	}

	bool operator()(const Cliente & cl1, const Cliente & cl2) const {
		return cl1.getNif() == cl2.getNif();
	}
};


typedef unordered_set<Cliente, CliHash, CliHash> tabHCli;


#endif /* TABELA_H_ */
