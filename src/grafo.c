#include <stdio.h>
#include <stdlib.h>

#include <estruturas.h>
#include <grafo.h>

struct aresta {
  int peso, adjacente;
}

struct vertice {
  int cor, grau;
  Lista *Adjacencias;
};

struct grafo {
  int tamanho, tipo;
  Vertice vertices[];
};

Vertice *verticeCriar () {
  Vertice *V = malloc(sizeof(Vertice));
  
  V->Lista = listaGenericaCriar();
  V->cor = 0;
  V->grau = 0;
  
  return(V);
}

Grafo *grafoCriar (int tamanho, int tipo) {
  Grafo *G = malloc(sizeof(Grafo));

  G->tipo = tipo;
  G->vertices = malloc(sizeof(Vertice) * tamanho);
  G->tamanho = tamanho;
  for (int i = 0; i < tamanho; i++) {
    G->vertices[i] = novoVertice();
  }

  return(G);
}

Aresta *arestaCriar (int peso, int adjacente) {
  Aresta *A = malloc(sizeof(Aresta));

  A->peso = peso;
  A->adjacente = adjacente;

  return(A);
}

int arestaAdicionar (int peso, int atual, int adjacente, Grafo *G) {
