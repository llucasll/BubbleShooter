# Português

The english version of this file ~can be found below~ is in building.

## Sobre

Projeto desenvolvido pelos estudantes Lucas Camilo e Rafael Aguiar para a disciplina de Computação I do Bacharelado em Ciência da Computação da Universidade Federal do Rio de Janeiro, ministrada pelo professor Adriano Cruz em 2017.2.

Para desenvolvê-lo, tomamos como base o código-fonte de "06_moving_images" que pode ser encontrado em
	
	http://equipe.nce.ufrj.br/adriano/sdl/sdl.htm

Os requisitos do projeto podem ser encontrados em

	http://equipe.nce.ufrj.br/adriano/c/projetos/proj20172/projeto/projeto.pdf

O projeto deve utilizar a biblioteca SDL 2.

## Entendendo a estrutura do projeto

#### Localizar código
	
Para encontrar rapidamente por uma string, você pode usar o comando

	$ find ./ -type f -exec grep -l -i "" {} \;

#### Estrutura

A estrutura do jogo foi dividida seguindo alguns conceitos de MVC.
Os arquivos são numerados com um código, que antecede seu nome, seguindo a numenclatura:

	0. Inicializações básicas
	1. Dados
	2. Controle
	3. Visualização

Também foram usados nesse projeto conceitos sobre Programação Orientada a Eventos, Inversão de Controle, além de Threads.

Para o desenvolvimento do jogo, foi desenvolvida concomitantemente a ele uma biblioteca que chamamos simplesmente de IU (Interface do Usuário). Essa biblioteca se encontra em
	
	lib/iu/

Ela utiliza a biblioteca SDL2 e outras bibliotecas padrões do C para realizar a maioria de suas funções, intermediando e facilitando a utilização dessas bibliotecas.

Outros componentes mais gerais do jogo (que podem ser reaproveitados em outros projetos) se encontram em
	
	lib/
	
Onde alojamos nossa biblioteca personalizada.

O arquivos do jogo propriamente dito se dividem entre src/ (código-fonte) e media/ (arquivos de mídia, como imagens e sons).

As telas possuem diretórios próprios dentro da estrutura de diretórios do projeto. Elas podem ser encontradas em

	src/menu/
	src/partida/
	src/fim/

#### Convenções de nomenclatura
	
* Variável/Função - primeiroSegundo
* Tipos personalizados - PrimeiroSegundo

---

# English version

## About

Project depeloped by the students Lucas Camilo and Rafael Aguiar to the Computation I discipline of the Computational Science degree in the Federal University of Rio de Janeiro, taught by Adriano Cruz in 2017.2 semester.

#### This section is in building.
