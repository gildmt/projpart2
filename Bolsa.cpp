/*
* Bolsa.cpp
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#include "Bolsa.h"

using namespace std;


void Bolsa::le_ficheiros_cli(string & fichClientes){
	string aux;
	int num_cli;
	ifstream f_clientes;

	f_clientes.open(fichClientes);
	getline(f_clientes, aux, ':');  //retira "Clientes:", nao interesasa
	f_clientes >> num_cli; f_clientes.ignore(); //retira num de iteracoes
	
	
	for (int i = 0; i < num_cli; i++)
	{
		Cliente cliente_lido(f_clientes);
		Data data_atual = getData();
		dataMaisDias(data_atual, -15);

		if (cliente_lido.getUltAtividade() < data_atual)
			cliInativos.insert(cliente_lido);
		else clientes.push_back(cliente_lido);
	}

	f_clientes.close();
}
void Bolsa::le_ficheiros_tran(string & fichTransacoes){
	string aux;
	int num_tran;
	ifstream f_transacoes;

	f_transacoes.open(fichTransacoes);
	getline(f_transacoes, aux, ':');  //retira "Transacoes", nao interesasa
	f_transacoes >> num_tran; f_transacoes.ignore(); //retira num de iteracoes


	for (int i = 0; i < num_tran; i++)
	{
		Transacao transacao_lida(f_transacoes);
		transacoes.push_back(transacao_lida);
	}

	f_transacoes.close();

}
void Bolsa::le_ficheiros_ordv(string & fichOrdensVenda){
	string aux;
	int num_ov;
	ifstream f_OrdensVenda;

	f_OrdensVenda.open(fichOrdensVenda);
	getline(f_OrdensVenda, aux, ':');  //retira "Ordens de Venda", nao interesasa
	f_OrdensVenda >> num_ov; f_OrdensVenda.ignore(); //retira num de iteracoes


	for (int i = 0; i < num_ov; i++)
	{
		string titulo_aux, data_str;
		float preco_acao_aux;
		int num_acoes_aux;
		long nif_aux;


		//le ficheiro
		f_OrdensVenda >> nif_aux;
		f_OrdensVenda.ignore(3); //anda 3 espaco
		getline(f_OrdensVenda, data_str, ';'); data_str.erase(data_str.end() - 1); //apaga ultimo espaco
		f_OrdensVenda.ignore(); //anda 1 espaco
		getline(f_OrdensVenda, titulo_aux, ';'); titulo_aux.erase(titulo_aux.end() - 1); //apaga ultimo espaco
		f_OrdensVenda >> preco_acao_aux;
		f_OrdensVenda.ignore(3); //anda 3 espaco
		f_OrdensVenda >> num_acoes_aux;

		
	
		OrdemVenda ordemVenda_lida(titulo_aux, Data(data_str), nif_aux, num_acoes_aux, preco_acao_aux);
		ordensVenda.push_back(ordemVenda_lida);
	}

	f_OrdensVenda.close();
}
void Bolsa::le_ficheiros_ordc(string & fichOrdensCompra){
	string aux;
	int num_oc;
	ifstream f_OrdensCompra;

	f_OrdensCompra.open(fichOrdensCompra);
	getline(f_OrdensCompra, aux, ':');  //retira "Ordens de Compra", nao interesasa
	f_OrdensCompra >> num_oc; f_OrdensCompra.ignore(); //retira num de iteracoes


	for (int i = 0; i < num_oc; i++)
	{
		string titulo_aux, data_str;
		float preco_acao_aux;
		float valorMaxGastar_aux;
		long nif_aux;


		//le ficheiro
		f_OrdensCompra >> nif_aux;
		f_OrdensCompra.ignore(3); //anda 3 espaco
		getline(f_OrdensCompra, data_str, ';'); data_str.erase(data_str.end() - 1); //apaga ultimo espaco
		f_OrdensCompra.ignore(); //anda 1 espaco
		getline(f_OrdensCompra, titulo_aux, ';'); titulo_aux.erase(titulo_aux.end() - 1); //apaga ultimo espaco
		f_OrdensCompra >> preco_acao_aux;
		f_OrdensCompra.ignore(3); //anda 3 espaco
		f_OrdensCompra >> valorMaxGastar_aux;


	OrdemCompra ordemCompra_lida(titulo_aux, Data(data_str), nif_aux, preco_acao_aux, valorMaxGastar_aux);
		ordensCompra.push_back(ordemCompra_lida);
	}
	f_OrdensCompra.close();
}


void Bolsa::le_ficheiros(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra){
	le_ficheiros_cli(fichClientes);
	le_ficheiros_tran(fichTransacoes);
	le_ficheiros_ordv(fichOrdensVenda);
	le_ficheiros_ordc(fichOrdensCompra);
}

void Bolsa::guarda_alteracoes(int n, string & fileToChange){
	ofstream fich;

	if (n < 1 || n > 4)
		return;

	switch (n) {
	case 1:
		//guarda clientes
		fich.open(fileToChange);

		fich << "Clientes: " << clientes.size() + cliInativos.size() << endl;

		for (size_t i = 0; i < clientes.size(); i++)
		{
			clientes.at(i).guardar(fich);
		}
	

		for (auto j = cliInativos.begin(); j != cliInativos.end(); j++)
		{
			j->guardar(fich);
		}

		fich.close();
		break;
	case 2:
		//guarda transacoes
		fich.open(fileToChange);

		fich << "Transacoes: " << transacoes.size() << endl;

		for (size_t i = 0; i < transacoes.size(); i++)
		{
			transacoes.at(i).guardar(fich);
		}
		fich.close();
		break;
	case 3:
		//guarda ordens de venda	
		fich.open(fileToChange);

		fich << "Ordens de Venda: " << ordensVenda.size() << endl;

		for (size_t i = 0; i < ordensVenda.size(); i++)
		{
			ordensVenda.at(i).guardar(fich);
		}
		fich.close();
		break;
	case 4:
		//guarda ordens de compra	
		fich.open(fileToChange);

		fich << "Ordens de Compra: " << ordensCompra.size() << endl;

		for (size_t i = 0; i < ordensCompra.size(); i++)
		{
			ordensCompra.at(i).guardar(fich);
		}
		fich.close();
		break;
	}
}


void Bolsa::ad_ordem_compra(){
	sort(ordensVenda.begin(), ordensVenda.end()); //o vetor de Vendas tem de estar por ordem de entrada no mercado
	string titulo;
	long nif;
	int trans = 0;
	bool cli_enc = false;
	int pos_cli;
	Data data = getData();

	cout << endl << endl;
	cout << TAB << "NIF do cliente: ";
	nif = leNif();
	
	if (nif == -1) {
		espera_input();
		return;
	}

	for (auto h = cliInativos.begin(); h != cliInativos.end(); h++)
	if (nif == h->getNif()){
		insert_sorted(clientes, *h);
		cliInativos.erase(h);
		break;
	}

	for (size_t g = 0; g < clientes.size(); g++)
	if (nif == clientes.at(g).getNif()){
		clientes.at(g).setUltAtividade(data);
		cli_enc = true;
		pos_cli = g;
		guarda_alteracoes(1, fichClientes);
		break;
	}





	if (cli_enc){
		cout << TAB << "Titulo da acao: ";
		getline(cin, titulo);

		if (titulo.empty()) {
			cout << TAB << "Input invalido.";
			espera_input();
			return;
		}

		float pMax, vMaxGastar;
		cout << TAB << "Preco maximo por acao: ";
		pMax = le_float();


		if (pMax <= 0){
			cout << endl << TAB << "Preco maximo por acao nao pode ser 0.";
			espera_input();
			return;
		}

		cout << TAB << "Valor Maximo a Gastar: ";
		vMaxGastar = le_float();

		if (vMaxGastar <= 0){
			cout << endl << TAB << "Valor Maximo a Gastar nao pode ser 0.";
			espera_input();
			return;
		}

		if (pMax > vMaxGastar){
			cout << endl << TAB << "Preco maximo por acao nao pode ser maior que o Valor Maximo a Gastar." << endl;
			espera_input();
			return;
		}

		for (size_t j = 0; j < ordensVenda.size(); j++) {
			if (ordensVenda.at(j).getTitulo() == titulo && ordensVenda.at(j).getNif() != nif) {
				float precoTransacao = (ordensVenda.at(j).getPrecoMin() + pMax) / 2;
				if (ordensVenda.at(j).getPrecoMin() <= pMax) {
					if (precoTransacao * ordensVenda.at(j).getQuantidade() <= vMaxGastar) {
						Transacao t(titulo, precoTransacao, ordensVenda.at(j).getQuantidade(), data, ordensVenda.at(j).getNif(), clientes.at(pos_cli).getNif());
						transacoes.push_back(t);
						vMaxGastar = vMaxGastar - precoTransacao * ordensVenda.at(j).getQuantidade();
						cout << TAB << "Comprou " << ordensVenda.at(j).getQuantidade() << " acoes a " << precoTransacao << " euros cada uma." << endl;
						ordensVenda.erase(ordensVenda.begin() + j);
						j--;
						trans = 1;
					}
					else if (precoTransacao * ordensVenda.at(j).getQuantidade() > vMaxGastar) {
						float nQuantidade = vMaxGastar / precoTransacao;
						int n = (int)nQuantidade;
						Transacao t(titulo, precoTransacao, n, data, ordensVenda.at(j).getNif(), clientes.at(pos_cli).getNif());
						transacoes.push_back(t);
						OrdemVenda actualizada(titulo, ordensVenda.at(j).getData(), ordensVenda.at(j).getNif(), ordensVenda.at(j).getQuantidade() - nQuantidade, ordensVenda.at(j).getPrecoMin());
						ordensVenda.erase(ordensVenda.begin() + j);
						ordensVenda.push_back(actualizada);
						cout << TAB << "Comprou " << nQuantidade << " acoes a " << precoTransacao << " euros cada uma." << endl;
						espera_input();
						guarda_alteracoes(2, fichTransacoes);
						guarda_alteracoes(3, fichOrdensVenda);
						return;
					}
				}
			}
		}

		if (vMaxGastar == 0)
		{
			espera_input();
			guarda_alteracoes(2, fichTransacoes);
			guarda_alteracoes(3, fichOrdensVenda);
			return;
		}

		OrdemCompra oc(titulo, data, nif, pMax, vMaxGastar);
		ordensCompra.push_back(oc);
		if (trans)
			cout << TAB << "Ordem de compra nao satisfeita totalmente, ordem de compra listada." << endl;
		else
			cout << TAB << "Nenhuma ordem de venda compativel encontrada, ordem de compra listada." << endl;
		espera_input();
		guarda_alteracoes(2, fichTransacoes);
		guarda_alteracoes(3, fichOrdensVenda);
		guarda_alteracoes(4, fichOrdensCompra);
		return;
	}

	cout << TAB << "Nao existe um cliente com esse NIF (adicione cliente)\n";
	espera_input();
	return;
}

void Bolsa::ad_ordem_venda(){
	sort(ordensCompra.begin(), ordensCompra.end()); //o vetor de Compras tem de estar por ordem de entrada no mercado
	string titulo;
	long nif;
	bool cli_enc = false;
	int trans = 0;
	int pos_cli;
	Data data = getData();

	cout << endl << endl;
	cout << TAB << "NIF do cliente: ";
	nif = leNif();

	if (nif == -1) {
		espera_input();
		return;
	}




	for (auto h = cliInativos.begin(); h != cliInativos.end(); h++)
	if (nif == h->getNif()){
		insert_sorted(clientes, *h);
		cliInativos.erase(h);
		break;
	}

	for (size_t g = 0; g < clientes.size(); g++)
	if (nif == clientes.at(g).getNif()){
		clientes.at(g).setUltAtividade(data);
		cli_enc = true;
		pos_cli = g;
		guarda_alteracoes(1, fichClientes);
		break;
	}





	if (cli_enc) {
		cout << TAB << "Titulo da acao: ";
		titulo = leTitulo();

		if (titulo.empty()) {
			espera_input();
			return;
		}

		float pMin;
		int qtd;
		cout << TAB << "Preco minimo por acao: ";
		pMin = le_float();

		if (pMin <= 0){
			cout << endl << TAB << "O Preco minimo por acao nao pode ser 0.";
			espera_input();
			return;
		}

		cout << TAB << "Quantidade de acoes: ";
		qtd = leInteiro(0, 999999);

		if (qtd <= 0){
			cout << endl << TAB << "A Quantidade de acoes nao pode ser 0.";
			espera_input();
			return;
		}


		for (size_t j = 0; j < ordensCompra.size(); j++) {
			if (ordensCompra.at(j).getTitulo() == titulo && ordensCompra.at(j).getNif() != nif) {
				float precoTransacao = (ordensCompra.at(j).getPrecoMax() + pMin) / 2;
				if (ordensCompra.at(j).getPrecoMax() >= pMin) {
					if (precoTransacao * qtd <= ordensCompra.at(j).getValorMaxGastar()) {
						Transacao t(titulo, precoTransacao, qtd, data, clientes.at(pos_cli).getNif(), ordensCompra.at(j).getNif());
						transacoes.push_back(t);
						float novo_valor_gastar = ordensCompra.at(j).getValorMaxGastar() - qtd * precoTransacao;
						if (novo_valor_gastar != 0){
							OrdemCompra actualizada(titulo, ordensCompra.at(j).getData(), ordensCompra.at(j).getNif(), ordensCompra.at(j).getPrecoMax(), ordensCompra.at(j).getValorMaxGastar() - qtd * precoTransacao);
							ordensCompra.push_back(actualizada);
						}
						ordensCompra.erase(ordensCompra.begin() + j);
						cout << TAB << "Vendeu " << qtd << " acoes a " << precoTransacao << " euros cada uma." << endl;
						espera_input();
						guarda_alteracoes(4, fichOrdensCompra);
						guarda_alteracoes(2, fichTransacoes);
						return;
					}
					else if (precoTransacao * qtd > ordensCompra.at(j).getValorMaxGastar()) {
						int nQuantidade = floor(ordensCompra.at(j).getValorMaxGastar() / precoTransacao + 0.5);
						Transacao t(titulo, precoTransacao, nQuantidade, data, clientes.at(pos_cli).getNif(), ordensCompra.at(j).getNif());
						transacoes.push_back(t);
						cout << TAB << "Vendeu " << nQuantidade << " acoes a " << precoTransacao << " euros cada uma." << endl;
						ordensCompra.erase(ordensCompra.begin() + j);
						j--;
						qtd = qtd - nQuantidade;
						trans = 1;
					}
				}
			}
		}

		if (qtd == 0)
		{
			espera_input();
			guarda_alteracoes(2, fichTransacoes);
			guarda_alteracoes(4, fichOrdensCompra);
			return;
		}

		OrdemVenda ov(titulo, data, nif, qtd, pMin);
		ordensVenda.push_back(ov);
		if (trans)
			cout << TAB << "Ordem de venda nao satisfeita totalmente, ordem de venda listada." << endl;
		else
			cout << TAB << "Nenhuma ordem de compra compativel encontrada, ordem de venda listada." << endl;
		espera_input();
		guarda_alteracoes(2, fichTransacoes);
		guarda_alteracoes(3, fichOrdensVenda);
		guarda_alteracoes(4, fichOrdensCompra);
		return;

	}
	cout << TAB << "Nao existe um cliente com esse NIF (adicione cliente)\n";
	espera_input();
	return;
}

void Bolsa::ad_cli(){
	string nome;
	long nif;
	string morada;
	long tel;
	Data ultAtividade;

	cout << endl << endl;
	cout << TAB << "Nome do cliente: ";
	getline(cin, nome);

	if (nome.empty()) {
		cout << TAB << "Input invalido.";
		espera_input();
		return;
	}

	cout << TAB << "NIF do cliente: ";
	nif = leNif();

	if (nif == -1) {
		espera_input();
		return;
	}

	cout << TAB << "Morada do cliente: ";
	getline(cin, morada);

	if (morada.empty()) {
		cout << TAB << "Input invalido.";
		espera_input();
		return;
	}

	cout << TAB << "Telemovel do cliente: ";
	tel = leNif();

	if (tel == -1) {
		espera_input();
		return;
	}


	for (size_t i = 0; i < clientes.size(); i++)
	if (nif == clientes.at(i).getNif())
	{
		cout << TAB << "Ja existe um cliente com esse NIF\n";
		espera_input();
		return;
	}

	ultAtividade = getData();
	insert_sorted(clientes, Cliente(nome, nif, morada, tel, ultAtividade));
	guarda_alteracoes(1, fichClientes);
}

void Bolsa::rem_ordem_compra(){
	string titulo;
	long nif;
	bool cli_encontrado = false;
	bool alteracao = false;

	cout << endl << endl;
	cout << TAB << "NIF do cliente: ";
	nif = leNif();

	if (nif == -1) {
		espera_input();
		return;
	}

	for (size_t i = 0; i < clientes.size(); i++) {
		if (nif == clientes.at(i).getNif())
			cli_encontrado = true;
	}
	if (!cli_encontrado){
		cout << TAB << "Nao existe um cliente com esse NIF\n";
		espera_input();
		return;
	}


	cout << TAB << "Titulo da acao: ";
	titulo = leTitulo();

	if (titulo.empty()) {
		espera_input();
		return;
	}

	for (size_t j = 0; j < ordensCompra.size(); j++) {
		if (ordensCompra.at(j).getTitulo() == titulo){
			alteracao = true;
			ordensCompra.erase(ordensCompra.begin() + j);
		}
	}
	if (alteracao){
		cout << TAB << "Ordem de Compra removida" << endl;
		guarda_alteracoes(4, fichOrdensCompra);
	}
	else cout << TAB << "Esse cliente nao tem Ordens de Compra desse titulo" << endl;

	espera_input();
}

void Bolsa::rem_ordem_venda(){
	string titulo;
	long nif;
	bool cli_encontrado = false;
	bool alteracao = false;

	cout << endl << endl;
	cout << TAB << "NIF do cliente: ";
	nif = leNif();

	if (nif == -1) {
		espera_input();
		return;
	}

	for (size_t i = 0; i < clientes.size(); i++) {
		if (nif == clientes.at(i).getNif())
			cli_encontrado = true;
	}
	if (!cli_encontrado){
		cout << TAB << "Nao existe um cliente com esse NIF\n";
		espera_input();
		return;
	}


	cout << TAB << "Titulo da acao: ";
	titulo = leTitulo();

	if (titulo.empty()) {
		espera_input();
		return;
	}

	for (size_t j = 0; j < ordensVenda.size(); j++) {
		if (ordensVenda.at(j).getTitulo() == titulo){
			alteracao = true;
			ordensVenda.erase(ordensVenda.begin() + j);
		}
	}
	if (alteracao){
		cout << TAB << "Ordem de Venda removida" << endl;
		guarda_alteracoes(3, fichOrdensVenda);
	}
	else cout << TAB << "Esse cliente nao tem Ordens de Venda desse titulo" << endl;

	espera_input();

}

void Bolsa::rem_cli(){
	long nif;
	bool cli_encontrado = false;
	

	cout << endl << endl;
	cout << TAB << "NIF do cliente: ";
	nif = leNif();

	if (nif == -1) {
		espera_input();
		return;
	}

	for (size_t i = 0; i < clientes.size(); i++) {
		if (nif == clientes.at(i).getNif()){
			cli_encontrado = true;
			clientes.erase(clientes.begin() + i);
		}
	}

	for (auto j = cliInativos.begin(); j != cliInativos.end(); j++)
	{
		if (nif == j->getNif()){
			cli_encontrado = true;
			cliInativos.erase(j);
			break;
		}
		
	}
	
	for (size_t j = 0; j < ordensCompra.size(); j++){
		if (ordensCompra.at(j).getNif() == nif)
			ordensCompra.erase(ordensCompra.begin() + j);
	}


	for (size_t k = 0; k < ordensVenda.size(); k++){
		if (ordensVenda.at(k).getNif() == nif)
			ordensVenda.erase(ordensVenda.begin() + k);
	}


	if (cli_encontrado){
		cout << TAB << "Cliente Removido \n";
		guarda_alteracoes(3, fichOrdensVenda);
		guarda_alteracoes(4, fichOrdensCompra);
		guarda_alteracoes(1, fichClientes);
	}
	else cout << TAB << "Nao existe um cliente com esse NIF\n";

	espera_input();

}

void Bolsa::listar_transacoes_cli(){
	long nif;

	cout << endl << endl;
	cout << TAB << "NIF do cliente: ";
	nif = leNif();

	if (nif == -1) {
		espera_input();
		return;
	}

	int primeiro_cli = -1;
	for (size_t i = 0; i < transacoes.size(); i++)
		if (nif == transacoes.at(i).getCliente_v() || nif == transacoes.at(i).getCliente_c()) {
			primeiro_cli = i;
			break;
		}

	if (primeiro_cli == -1){
		cout << endl << TAB << "Nenhum cliente com esse NIF fez transacoes.\n\n";
		espera_input();
		return;
	}

	clearScreen();
	cout << endl;
	linha(43);
	cout << TAB << left << BARRA
		<< setw(11) << " Comprador " << BARRA
		<< setw(11) << " Vendedor " << BARRA
		<< setw(12) << " Data" << BARRA
		<< setw(15) << " Titulo" << BARRA
		<< setw(14) << " Preco medio " << BARRA
		<< setw(14) << " Numero acoes" << BARRA
		<< endl;
	linha(43);

	for (size_t i = primeiro_cli; i < transacoes.size(); i++)
		if (nif == transacoes.at(i).getCliente_v() || nif == transacoes.at(i).getCliente_c())
			cout << transacoes.at(i);

	linha(43);
	cout << endl << endl;

	espera_input();
}

void Bolsa::listar_transacoes_titulo(){
	string titulo;

	cout << endl << endl;
	cout << TAB << "Titulo da transacao: ";
	titulo = leTitulo();
	
	if (titulo.empty()) {
		espera_input();
		return;
	}
	
	int primeiro_cli = -1;
	for (size_t i = 0; i < transacoes.size(); i++)
		if (titulo == transacoes.at(i).getTitulo()) {
			primeiro_cli = i;
			break;
		}

	if (primeiro_cli == -1) {
		cout << endl << TAB << "Nenhuma transacao com esse titulo.\n\n";
		espera_input();
		return;
	}

	clearScreen();
	cout << endl;
	linha(43);
	cout << TAB << left << BARRA
		<< setw(11) << " Comprador " << BARRA
		<< setw(11) << " Vendedor " << BARRA
		<< setw(12) << " Data" << BARRA
		<< setw(15) << " Titulo" << BARRA
		<< setw(14) << " Preco medio " << BARRA
		<< setw(14) << " Numero acoes" << BARRA
		<< endl;
	linha(43);

	for (size_t i = primeiro_cli; i < transacoes.size(); i++)
		if (titulo == transacoes.at(i).getTitulo())
			cout << transacoes.at(i);

	linha(43);
	cout << endl << endl;

	espera_input();
}


void Bolsa::listar_transacoes(){
	clearScreen();
	if (transacoes.size() == 0) {
		cout << endl << TAB << "Nenhuma transacao realizada.\n\n";
		espera_input();
		return;
	}

	clearScreen();
	cout << endl;
	linha(43);
	cout << TAB << left << BARRA
		<< setw(11) << " Comprador " << BARRA
		<< setw(11) << " Vendedor " << BARRA
		<< setw(12) << " Data" << BARRA
		<< setw(15) << " Titulo" << BARRA
		<< setw(14) << " Preco medio " << BARRA
		<< setw(14) << " Numero acoes" << BARRA
		<< endl;
	linha(43);

	for (size_t i = 0; i < transacoes.size(); i++)
		cout << transacoes.at(i);

	linha(43);
	cout << endl << endl;

	espera_input();
}





void Bolsa::listar_transacoes_intervalo_de_tempo() {
	int opcao, dia, mes, ano;
	int primeiro_cli = -1;


	cout << endl;
	cout << TAB << "1 - Transacoes efectuadas num dia." << endl;
	cout << TAB << "2 - Transacoes efectuadas num mes." << endl;
	cout << TAB << "3 - Transacoes efectuadas num ano." << endl;
	cout << TAB << "4 - Voltar ao menu inicial." << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leInteiro(1, 4);

	switch (opcao) {
	case 1:
		cout << endl << endl;
		cout << TAB << "Dia da transacao: ";
		dia = leInteiro(0, 31);
		cout << TAB << "Mes da transacao: ";
		mes = leInteiro(0, 12);
		cout << TAB << "Ano da transacao: ";
		ano = leInteiro(1990, 2100);

		for (size_t i = 0; i < transacoes.size(); i++)
			if (dia == transacoes.at(i).getData().getDia()
				&& mes == transacoes.at(i).getData().getMes()
				&& ano == transacoes.at(i).getData().getAno()) {
				primeiro_cli = i;
				break;
			}

		if (primeiro_cli == -1) {
			cout << endl << TAB << "Nenhuma transacao nesse dia.\n\n";
			espera_input();
			return;
		}

		clearScreen();
		cout << endl;
		linha(43);
		cout << TAB << left << BARRA
			<< setw(11) << " Comprador " << BARRA
			<< setw(11) << " Vendedor " << BARRA
			<< setw(12) << " Data" << BARRA
			<< setw(15) << " Titulo" << BARRA
			<< setw(14) << " Preco medio " << BARRA
			<< setw(14) << " Numero acoes" << BARRA
			<< endl;
		linha(43);

		for (size_t i = primeiro_cli; i < transacoes.size(); i++)
			if (dia == transacoes.at(i).getData().getDia()
				&& mes == transacoes.at(i).getData().getMes()
				&& ano == transacoes.at(i).getData().getAno())
				cout << transacoes.at(i);

		linha(43);
		cout << endl << endl;

		espera_input();
		break;
	case 2:
		cout << endl << endl;
		cout << TAB << "Mes da transacao: ";
		mes = leInteiro(0, 12);
		cout << TAB << "Ano da transacao: ";
		ano = leInteiro(1990, 2100);

		for (size_t i = 0; i < transacoes.size(); i++)
			if (mes == transacoes.at(i).getData().getMes()
				&& ano == transacoes.at(i).getData().getAno()) {
				primeiro_cli = i;
				break;
			}

		if (primeiro_cli == -1) {
			cout << endl << TAB << "Nenhuma transacao nesse mes.\n\n";
			espera_input();
			return;
		}

		clearScreen();
		cout << endl;
		linha(43);
		cout << TAB << left << BARRA
			<< setw(11) << " Comprador " << BARRA
			<< setw(11) << " Vendedor " << BARRA
			<< setw(12) << " Data" << BARRA
			<< setw(15) << " Titulo" << BARRA
			<< setw(14) << " Preco medio " << BARRA
			<< setw(14) << " Numero acoes" << BARRA
			<< endl;
		linha(43);

		for (size_t i = primeiro_cli; i < transacoes.size(); i++)
			if (mes == transacoes.at(i).getData().getMes()
				&& ano == transacoes.at(i).getData().getAno())
				cout << transacoes.at(i);

		linha(43);
		cout << endl << endl;

		espera_input();
		break;
	case 3:
		cout << endl << endl;
		cout << TAB << "Ano da transacao: ";
		ano = leInteiro(1990, 2100);

		for (size_t i = 0; i < transacoes.size(); i++)
			if (ano == transacoes.at(i).getData().getAno()) {
				primeiro_cli = i;
				break;
			}

		if (primeiro_cli == -1) {
			cout << endl << TAB << "Nenhuma transacao nesse ano.\n\n";
			espera_input();
			return;
		}

		clearScreen();
		cout << endl;
		linha(43);
		cout << TAB << left << BARRA
			<< setw(11) << " Comprador " << BARRA
			<< setw(11) << " Vendedor " << BARRA
			<< setw(12) << " Data" << BARRA
			<< setw(15) << " Titulo" << BARRA
			<< setw(14) << " Preco medio " << BARRA
			<< setw(14) << " Numero acoes" << BARRA
			<< endl;
		linha(43);

		for (size_t i = primeiro_cli; i < transacoes.size(); i++)
			if (ano == transacoes.at(i).getData().getAno())
				cout << transacoes.at(i);

		linha(43);
		cout << endl << endl;

		espera_input();
		break;
	case 4:
		return;
		break;
	}
}



//listar cliente
void Bolsa::listar_clientes() {

	clearScreen();
	if (clientes.size() == 0){
		cout << endl << TAB << "Nenhum Cliente registado no mercado." << endl << endl;
		espera_input();
		return;
	}


	cout << endl;
	linha(36);
	cout << TAB << left << BARRA
		<< setw(18) << " Nome " << BARRA
		<< setw(11) << " NIF" << BARRA
		<< setw(25) << " Morada" << BARRA
		<< setw(11) << " Telemovel " << BARRA
		<< endl;
	linha(36);


	for (size_t i = 0; i < clientes.size(); i++)
		cout << clientes.at(i);

	for (auto j = cliInativos.begin(); j != cliInativos.end(); j++)
		cout << *j;

	linha(36);
	cout << endl;
	espera_input();
}

void Bolsa::listar_ordensVenda()
{
	clearScreen();
	if (ordensVenda.size() == 0){
		cout << endl << TAB << "Nenhuma Ordem de Venda listada no mercado." << endl << endl;
		espera_input();
		return;
	}

	cout << endl;
	linha(36);
	cout << TAB << left << BARRA
		<< setw(11) << " Vendedor " << BARRA
		<< setw(12) << " Data" << BARRA
		<< setw(15) << " Titulo" << BARRA
		<< setw(14) << " Preco minimo " << BARRA
		<< setw(12) << " Quantidade " << BARRA
		<< endl;
	linha(36);

	for (size_t i = 0; i < ordensVenda.size(); i++)
		cout << ordensVenda.at(i);
	
	linha(36);
	cout << endl << endl;

	espera_input();
}

void Bolsa::listar_ordensCompra()
{
	clearScreen();
	if (ordensCompra.size() == 0){
		cout << endl << TAB << "Nenhuma Ordem de Compra listada no mercado." << endl << endl;
		espera_input();
		return;
	}

	cout << endl;
	linha(37);
	cout << TAB << left << BARRA
		<< setw(11) << " Vendedor " << BARRA
		<< setw(12) << " Data" << BARRA
		<< setw(15) << " Titulo" << BARRA
		<< setw(14) << " Preco maximo " << BARRA
		<< setw(14) << " Valor Maximo " << BARRA
		<< endl;
	linha(37);

	for (size_t i = 0; i < ordensCompra.size(); i++)
		cout << ordensCompra.at(i);

	linha(37);
	cout << endl << endl;

	espera_input();
}



void Bolsa::alterar_morada(){
	long nif;
	string nova_morada;


	cout << endl << endl;
	cout << TAB << "NIF do cliente: ";
	nif = leNif();

	if (nif == -1) {
		espera_input();
		return;
	}

	for (size_t i = 0; i < clientes.size(); i++) {
		if (nif == clientes.at(i).getNif()){
			
			cout << endl << endl;
			cout << TAB << "Nova morada do Cliente: ";
			getline(cin, nova_morada);
			if (nova_morada.empty()) {
				cout << TAB << "Input invalido.";
				espera_input();
				return;
			}
			clientes.at(i).setMorada(nova_morada);
			guarda_alteracoes(1, fichClientes);
			cout << TAB << "Morada alterada com sucesso\n";
			espera_input();
			return;			
		}
	}

	for (auto j = cliInativos.begin(); j != cliInativos.end(); j++)
	{
		if (nif == j->getNif()){

			cout << endl << endl;
			cout << TAB << "Nova morada do Cliente: ";
			getline(cin, nova_morada);
			if (nova_morada.empty()) {
				cout << TAB << "Input invalido.";
				espera_input();
				return;
			}
			Cliente temp = *j;
			temp.setMorada(nova_morada);
			cliInativos.erase(j);
			cliInativos.insert(temp);
			guarda_alteracoes(1, fichClientes);
			cout << TAB << "Morada alterada com sucesso\n";
			espera_input();
			return;
		
		}

	}

	cout << TAB << "Nao existe um cliente com esse NIF\n";

	espera_input();

}

void Bolsa::alterar_tel(){
	long nif;
	long novo_tel;


	cout << endl << endl;
	cout << TAB << "NIF do cliente: ";
	nif = leNif();

	if (nif == -1) {
		espera_input();
		return;
	}

	for (size_t i = 0; i < clientes.size(); i++) {
		if (nif == clientes.at(i).getNif()){

			cout << endl << endl;
			cout << TAB << "Novo telemovel do Cliente: ";
			novo_tel = leNif();

			if (novo_tel == -1) {
				espera_input();
				return;
			}
			clientes.at(i).setTel(novo_tel);
			guarda_alteracoes(1, fichClientes);
			cout << TAB << "Telemovel alterado com sucesso\n";
			espera_input();
			return;
		}
	}

	for (auto j = cliInativos.begin(); j != cliInativos.end(); j++)
	{
		if (nif == j->getNif()){

			cout << endl << endl;
			cout << TAB << "Novo telemovel do Cliente: ";
			novo_tel = leNif();

			if (novo_tel == -1) {
				espera_input();
				return;
			}
			Cliente temp = *j;
			temp.setTel(novo_tel);
			cliInativos.erase(j);
			cliInativos.insert(temp);
			guarda_alteracoes(1, fichClientes);
			cout << TAB << "Telemovel alterado com sucesso\n";
			espera_input();
			return;

		}

	}

	cout << TAB << "Nao existe um cliente com esse NIF\n";

	espera_input();

}

void Bolsa::listar_clientes_ativos(){
	clearScreen();
	if (clientes.size() == 0){
		cout << endl << TAB << "Nenhum Cliente ativo registado no mercado." << endl << endl;
		espera_input();
		return;
	}


	cout << endl;
	linha(36);
	cout << TAB << left << BARRA
		<< setw(18) << " Nome " << BARRA
		<< setw(11) << " NIF" << BARRA
		<< setw(25) << " Morada" << BARRA
		<< setw(11) << " Telemovel " << BARRA
		<< endl;
	linha(36);


	for (size_t i = 0; i < clientes.size(); i++)
		cout << clientes.at(i);

	linha(36);
	cout << endl;
	espera_input();
}

void Bolsa::listar_clientes_inativos(){
	
	clearScreen();
	if (clientes.size() == 0){
		cout << endl << TAB << "Nenhum Cliente ativo registado no mercado." << endl << endl;
		espera_input();
		return;
	}


	cout << endl;
	linha(36);
	cout << TAB << left << BARRA
		<< setw(18) << " Nome " << BARRA
		<< setw(11) << " NIF" << BARRA
		<< setw(25) << " Morada" << BARRA
		<< setw(11) << " Telemovel " << BARRA
		<< endl;
	linha(36);


	for (auto j = cliInativos.begin(); j != cliInativos.end(); j++)
		cout << *j;

	linha(36);
	cout << endl;
	espera_input();
}

void Bolsa::listar_noticias_titulo() {
	string titulo;

	cout << endl << endl;
	cout << TAB << "Titulo da empresa: ";
	titulo = leTitulo();

	if (titulo.empty()) {
		espera_input();
		return;
	}

	BSTItrIn<Noticia> it(arvoreNoticias);
	vector<Noticia> aux;

	while (!it.isAtEnd())
	{
		if (it.retrieve().getTitle() == titulo)
			aux.push_back(it.retrieve());
		it.advance();
	}
	if (aux.empty()) {
		cout << endl << TAB << "Nenhuma noticia sobre essa empresa.\n\n";
		espera_input();
		return;
	}

	clearScreen();
	cout << endl;
	linha(34);
	cout << TAB << left << BARRA
		<< setw(16) << " Nome do Jornal " << BARRA
		<< setw(17) << " Nome da Empresa " << BARRA
		<< setw(12) << " Data" << BARRA
		<< setw(16) << " Classificacao " << BARRA
		<< endl;
	linha(34);

	for (size_t i = 0; i < aux.size(); i++)
		cout << aux.at(i);

	linha(34);
	cout << endl << endl;

	espera_input();
}

void Bolsa::listar_noticias_intervalo_de_tempo() {
	int opcao, dia, mes, ano;
	BSTItrIn<Noticia> it(arvoreNoticias);
	vector<Noticia> aux;

	cout << endl;
	cout << TAB << "1 - Transacoes efectuadas num dia." << endl;
	cout << TAB << "2 - Transacoes efectuadas num mes." << endl;
	cout << TAB << "3 - Transacoes efectuadas num ano." << endl;
	cout << TAB << "4 - Voltar ao menu inicial." << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leInteiro(1, 4);

	switch (opcao) {
	case 1:
		cout << endl << endl;
		cout << TAB << "Dia da transacao: ";
		dia = leInteiro(0, 31);
		cout << TAB << "Mes da transacao: ";
		mes = leInteiro(0, 12);
		cout << TAB << "Ano da transacao: ";
		ano = leInteiro(1990, 2100);

		while (!it.isAtEnd())
		{
			if (it.retrieve().getDate().getAno() == ano && it.retrieve().getDate().getMes() == mes &&
				it.retrieve().getDate().getDia() == dia)
				aux.push_back(it.retrieve());
			it.advance();
		}
		if (aux.empty()) {
			cout << endl << TAB << "Nenhuma noticia nesse periodo de tempo.\n\n";
			espera_input();
			return;
		}

		clearScreen();
		cout << endl;
		linha(34);
		cout << TAB << left << BARRA
			<< setw(16) << " Nome do Jornal " << BARRA
			<< setw(17) << " Nome da Empresa " << BARRA
			<< setw(12) << " Data" << BARRA
			<< setw(16) << " Classificacao " << BARRA
			<< endl;
		linha(34);

		for (size_t i = 0; i < aux.size(); i++)
			cout << aux.at(i);

		linha(34);
		cout << endl << endl;

		espera_input();
		break;

	case 2:
		cout << endl << endl;
		cout << TAB << "Mes da transacao: ";
		mes = leInteiro(0, 12);
		cout << TAB << "Ano da transacao: ";
		ano = leInteiro(1990, 2100);

		while (!it.isAtEnd())
		{
			if (it.retrieve().getDate().getAno() == ano && it.retrieve().getDate().getMes() == mes)
				aux.push_back(it.retrieve());
			it.advance();
		}
		if (aux.empty()) {
			cout << endl << TAB << "Nenhuma noticia nesse periodo de tempo.\n\n";
			espera_input();
			return;
		}

		clearScreen();
		cout << endl;
		linha(34);
		cout << TAB << left << BARRA
			<< setw(16) << " Nome do Jornal " << BARRA
			<< setw(17) << " Nome da Empresa " << BARRA
			<< setw(12) << " Data" << BARRA
			<< setw(16) << " Classificacao " << BARRA
			<< endl;
		linha(34);

		for (size_t i = 0; i < aux.size(); i++)
			cout << aux.at(i);

		linha(34);
		cout << endl << endl;

		espera_input();
		break;
	case 3:
		cout << endl << endl;
		cout << TAB << "Ano da transacao: ";
		ano = leInteiro(1990, 2100);

		while (!it.isAtEnd())
		{
			if (it.retrieve().getDate().getAno() == ano)
				aux.push_back(it.retrieve());
			it.advance();
		}
		if (aux.empty()) {
			cout << endl << TAB << "Nenhuma noticia nesse periodo de tempo.\n\n";
			espera_input();
			return;
		}

		clearScreen();
		cout << endl;
		linha(34);
		cout << TAB << left << BARRA
			<< setw(16) << " Nome do Jornal " << BARRA
			<< setw(17) << " Nome da Empresa " << BARRA
			<< setw(12) << " Data" << BARRA
			<< setw(16) << " Classificacao " << BARRA
			<< endl;
		linha(34);

		for (size_t i = 0; i < aux.size(); i++)
			cout << aux.at(i);

		linha(34);
		cout << endl << endl;

		espera_input();
		break;
	case 4:
		return;
		break;
	}
}

void Bolsa::ad_noticia() {
	string nomeJornal;
	string titulo;
	Data ultAtividade;
	int rating;

	cout << endl << endl;
	cout << TAB << "Nome do Jornal: ";
	getline(cin, nomeJornal);

	if (nomeJornal.empty()) {
		cout << TAB << "Input invalido.";
		espera_input();
		return;
	}

	cout << TAB << "Titulo da empresa: ";
	getline(cin, titulo);

	if (titulo.empty()) {
		cout << TAB << "Input invalido.";
		espera_input();
		return;
	}

	cout << TAB << "Rating da noticia: ";
	rating = leInteiro(0, 10);
	
	ultAtividade = getData();
	Noticia nt1(ultAtividade.getDia(), ultAtividade.getMes(), ultAtividade.getAno(), nomeJornal, titulo, rating);
	arvoreNoticias.insert(nt1);
}

void Bolsa::rem_noticia()
{
	string nomeJornal;
	string titulo;
	int dia, mes, ano;

	cout << endl << endl;
	cout << TAB << "Nome do Jornal: ";
	getline(cin, nomeJornal);

	if (nomeJornal.empty()) {
		cout << TAB << "Input invalido.";
		espera_input();
		return;
	}

	cout << TAB << "Titulo da empresa: ";
	getline(cin, titulo);

	if (titulo.empty()) {
		cout << TAB << "Input invalido.";
		espera_input();
		return;
	}

	cout << TAB << "Dia da noticia: ";
	dia = leInteiro(1, 31);

	cout << TAB << "Mes da noticia: ";
	mes = leInteiro(1, 12);

	cout << TAB << "Ano da noticia: ";
	ano = leInteiro(1900, 2016);

	Noticia nt1(dia, mes, ano, nomeJornal, titulo, 0);
	
	BSTItrIn<Noticia> it(arvoreNoticias);
	bool exists = false;

	while (!it.isAtEnd())
	{
		if (it.retrieve() == nt1)
			exists = true;
		it.advance();
	}

	if(exists)
		arvoreNoticias.remove(nt1);
	else
	{
		cout << endl << TAB << "Nenhuma noticia com esses dados.\n\n";
		espera_input();
		return;
	}
}

void Bolsa::actualiza_rating()
{
	string nomeJornal;
	string titulo;
	int rating, dia, mes, ano;

	cout << endl << endl;
	cout << TAB << "Nome do Jornal: ";
	getline(cin, nomeJornal);

	if (nomeJornal.empty()) {
		cout << TAB << "Input invalido.";
		espera_input();
		return;
	}

	cout << TAB << "Titulo da empresa: ";
	getline(cin, titulo);

	if (titulo.empty()) {
		cout << TAB << "Input invalido.";
		espera_input();
		return;
	}

	cout << TAB << "Dia da noticia: ";
	dia = leInteiro(1, 31);

	cout << TAB << "Mes da noticia: ";
	mes = leInteiro(1, 12);

	cout << TAB << "Ano da noticia: ";
	ano = leInteiro(1900, 2016);

	cout << TAB << "Novo rating da noticia: ";
	rating = leInteiro(0, 10);

	Noticia nt1(dia, mes, ano, nomeJornal, titulo, 0);

	BSTItrIn<Noticia> it(arvoreNoticias);
	bool exists = false;

	while (!it.isAtEnd())
	{
		if (it.retrieve() == nt1)
		{
			it.retrieve().setRating(rating);
			exists = true;
		}
		it.advance();
	}

	if (!exists)
	{
		cout << endl << TAB << "Nenhuma noticia com esses dados.\n\n";
		espera_input();
		return;
	}
}