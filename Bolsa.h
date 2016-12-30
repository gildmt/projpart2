/*
 * Bolsa.h
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#ifndef BOLSA_H_
#define BOLSA_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "OrdemVenda.h"
#include "Tabela.h"
#include "OrdemCompra.h"
#include "Cliente.h"
#include "Utils.h"
#include "Transacao.h"
#include "insertionSort.h"
#include "Noticias.h"


using namespace std;

/**
 * @class	Bolsa
 *
 * @brief	Classe que guarda os clientes, ordens de compra e venda, e transacoes da bolsa e as funcoes para manipulacao da mesma.
 */

class Bolsa {
private:
	/** @brief	Vector de clientes da bolsa. */
	vector<Cliente> clientes;
	/** @brief	Vector de ordens compra da bolsa. */
	vector<OrdemCompra> ordensCompra;
	/** @brief	Vector de ordens venda da bolda. */
	vector<OrdemVenda> ordensVenda;
	/** @brief	Vector de transacoes da bolsa. */
	vector<Transacao> transacoes;

	/** @brief	Tabela de Dispersão dos clientes inativos da bolsa. */
	tabHCli cliInativos;
	/** @brief	Arvore de pesquisa com noticias sobre empresas. */
	BST<Noticia> arvoreNoticias;

public:

	/**
	 * @fn	Bolsa::Bolsa()
	 *
	 * @brief	Construtor por defeito.
	 */

	Bolsa():arvoreNoticias(Noticia(0, 0, 0, " ", " ", 0)) {};

	/**
	 * @fn	void Bolsa::le_ficheiros(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra);
	 *
	 * @brief	Le os ficheiros com informacoes para preencher os vectores da bolsa.
	 *
	 * @param			fichClientes		Ficheiro com as informacoes dos clientes.
	 * @param			fichTransacoes  	Ficheiro com as informacoes das transacoes.
	 * @param			fichOrdensVenda 	Ficheiro com as informacoes das ordens venda.
	 * @param			fichOrdensCompra	Ficheiro com as informacoes das ordens compra.
	 */

	void le_ficheiros(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra);

	/**
	 * @fn	void Bolsa::le_ficheiros_cli(string & fichClientes);
	 *
	 * @brief	Le o ficheiro com as informacoes dos clientes.
	 *
	 * @param			fichClientes		Ficheiro com as informacoes dos clientes.
	 */

	void le_ficheiros_cli(string & fichClientes);

	/**
	 * @fn	void Bolsa::le_ficheiros_tran(string & fichTransacoes);
	 *
	 * @brief	Le o ficheiro com as informacoes das transacoes.
	 *
	 * @param			fichTransacoes  	Ficheiro com as informacoes das transacoes.
	 */

	void le_ficheiros_tran(string & fichTransacoes);

	/**
	 * @fn	void Bolsa::le_ficheiros_ordv(string & fichOrdensVenda);
	 *
	 * @brief	Le o ficheiro com as informacoes das ordens de venda.
	 *
	 * @param			fichOrdensVenda 	Ficheiro com as informacoes das ordens venda.
	 */

	void le_ficheiros_ordv(string & fichOrdensVenda);

	/**
	 * @fn	void Bolsa::le_ficheiros_ordc(string & fichOrdensCompra);
	 *
	 * @brief	Le o ficheiro com as informacoes das ordens de compra.
	 *
	 * @param			fichOrdensCompra 	Ficheiro com as informacoes das ordens compra.
	 */

	void le_ficheiros_ordc(string & fichOrdensCompra);

	/**
	 * @fn	void Bolsa::guarda_alteracoes(int n, string & fich);
	 *
	 * @brief	Guarda alteracoes feitas nos vectores no ficheiro fich.
	 *
	 * @param 		  	n   	Inteiro de 1 a 4 que representa os varios vectores da bolsa.
	 * @param			fich	O ficheiro onde o vector e guardado.
	 */

	void guarda_alteracoes(int n, string & fich);

	/**
	 * @fn	void Bolsa::ad_ordem_compra();
	 *
	 * @brief	Adiciona uma ordem de compra ao vector de ordens de compra, com parametros definidos pelo utilizador.
	 */

	void ad_ordem_compra();

	/**
	 * @fn	void Bolsa::ad_ordem_venda();
	 *
	 * @brief	Adiciona uma ordem de venda ao vector de ordens de venda, com parametros definidos pelo utilizador.
	 */

	void ad_ordem_venda();

	/**
	 * @fn	void Bolsa::ad_cli();
	 *
	 * @brief	Adiciona um cliente ao vector de clientes, com parametros definidos pelo utilizador.
	 */

	void ad_cli();


	/**
	* @fn	void Bolsa::rem_ordem_compra();
	*
	* @brief	Remove uma ordem de compra ao vector de ordens de compra, com parametros definidos pelo utilizador.
	*/

	void rem_ordem_compra();

	/**
	* @fn	void Bolsa::rem_ordem_venda();
	*
	* @brief	Remove uma ordem de venda do vector de ordens de venda, com parametros definidos pelo utilizador.
	*/

	void rem_ordem_venda();

	/**
	* @fn	void Bolsa::rem_cli();
	*
	* @brief	Remove um cliente do vector de clientes, com parametros definidos pelo utilizador.
	*/

	void rem_cli();
	

	/**
	* @fn	void Bolsa::listar_transacoes();
	*
	* @brief	Lista as todas as transacoes.
	*/

	void listar_transacoes();



	/**
	 * @fn	void Bolsa::listar_transacoes_cli();
	 *
	 * @brief	Lista as transacoes de um cliente.
	 */

	void listar_transacoes_cli();

	/**
	 * @fn	void Bolsa::listar_transacoes_titulo();
	 *
	 * @brief	Lista todas as transacoes com um certo titulo.
	 */

	void listar_transacoes_titulo();

	/**
	 * @fn	void Bolsa::listar_transacoes_intervalo_de_tempo();
	 *
	 * @brief	Lista transacoes por dia, mes ou ano.
	 */

	void listar_transacoes_intervalo_de_tempo();

	/**
	 * @fn	void Bolsa::listar_clientes();
	 *
	 * @brief	Lista todos os clientes.
	 */

	void listar_clientes();

	/**
	 * @fn	void Bolsa::listar_ordensVenda();
	 *
	 * @brief	Lista todas as de ordens venda.
	 */

	void listar_ordensVenda();

	/**
	 * @fn	void Bolsa::listar_ordensCompra();
	 *
	 * @brief	Lista todas as de ordens compra.
	 */

	void listar_ordensCompra();





	////////////////////////////////////////////////


	void alterar_morada();

	void alterar_tel();

	void listar_clientes_ativos();

	void listar_clientes_inativos();

	/**
	* @fn	void Bolsa::listar_noticias_titulo();
	*
	* @brief	Lista noticias por titulo da empresa que e sobre.
	*/

	void listar_noticias_titulo();

	/**
	* @fn	void Bolsa::listar_noticias_intervalo_de_tempo();
	*
	* @brief	Lista noticias por dia, mes ou ano.
	*/

	void listar_noticias_intervalo_de_tempo();

	/**
	* @fn	void Bolsa::ad_noticia();
	*
	* @brief	Adiciona noticia a arvore de noticias.
	*/

	void ad_noticia();

	/**
	* @fn	void Bolsa::rem_noticia();
	*
	* @brief	Remove noticia da arvore de noticias.
	*/

	void rem_noticia();

	/**
	* @fn	void Bolsa::actualiza_rating();
	*
	* @brief	Actualiza o rating de uma noticia da arvore de noticias.
	*/

	void actualiza_rating();
};

#endif /* BOLSA_H_ */