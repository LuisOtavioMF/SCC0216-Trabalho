// Arquivo que define as funcoes de criacao e navegacao do grafo

#include <grafo.h>
#include <stdio.h>
#include <stdlib.h>

// Funcoes usadas pelo programa principal

// Funcao que gera um grafo a partir de um arquivo contendo os filmes e suas informacoes
// erro = 0 se tudo funcionar e erro = [verdadeiro] caso contrario
Grafo *grafoGerar(FILE *fptr, int *erro);

// Funcao que encontra e imprime n recomendacoes de filmes semelhantes ao indicado
void encontrarSemelhantes(Grafo *G, char filme[], int n);

// Funcao que encontra e imprime n recomendacoes de filmes diferentes do indicado
void encontrarDiferentes(Grafo *G, char filme[], int n);

// Funcao que encontra e imprime todos os filmes com a categoria indicada
void listarCategoria(Grafo *G, char categoria[]);

// Funcao que encontra e imprime todos os grupos de filmes fortemente relacionados
void encontrarFilmesRelacionados(Grafo *G);

// Funcoes usadas para operacoes dentro do grafo
