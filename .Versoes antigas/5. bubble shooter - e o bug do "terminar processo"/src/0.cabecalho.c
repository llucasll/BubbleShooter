/*
	Convenções de nomenclatura:
	
	* Variável/Função - primeiroSegundo
	* Tipos personalizados - PrimeiroSegundo
*/

#include "0.all.h"

#ifndef CABECALHO //evitar inclusões cíclicas ("guarda de cabeçalho")
	#define CABECALHO

	/* CONSTANTES */
	#define linhas 10
	#define colunas 30

	/* GLOBAIS */
	const Coordenadas campo = {colunas, linhas}, npc = {61, 61}, tela = {640, 480};//tamanhos
	Coordenadas velocidade;
	Bola *matriz[linhas][colunas];
	Tiro tiro;

#endif
