#include <stdio.h>
#include <stdlib.h>

#include <estruturas.h>

struct no {
  void *info;
  No *proximo, *anterior;
};

struct lista {
  No *inicial, *final;
  int tamanho;
};

No *noGenericoCriar(void *info) {
  No *N = malloc(sizeof(No));

  N->info = info;

  return(N);
}

Lista *listaGenericaCriar () {
  Lista *L = malloc(sizeof(Lista));

  L->inicial = NULL;
  L->final = NULL;
  L->tamanho = 0;

  return(L);
}

int listaTamanho (Lista *L) {
  return(L->tamanho);
}

No *listaInicial (Lista *L) {
  return(L->inicial);
}

No *listaFinal (Lista *L) {
  return(L->final);
}

int listaGenericaInserir (Lista *L, int modo, void *info) {
  No *N = noGenericoCriar(info);
  N->info = info;
  if (L->tamanho == 0) {
    modo = 3;
  }
  L->tamanho += 1;
  switch (modo) {
  case 3:
    L->inicial = N;
    L->final = N;
    N->anterior = NULL;
    N->proximo = NULL;
    break;
  case INICIO:
    N->proximo = L->inicial;
    N->anterior = NULL;
    L->inicial->anterior = N;
    L->inicial = N;
    break;
  case FIM:
    N->proximo = NULL;
    N->anterior = L->final;
    L->final->proximo = N;
    L->final = N;
    break;
  default:
    return(0);
    break;
  }
  return(L->tamanho);
}

void *listaGenericaRemover (Lista *L, int modo) {
  No *N;

  switch (modo) {
  case INICIO:
    N = L->inicial;
    L->inicial = N->proximo;
    if (L->inicial) {
      L->inicial->anterior = NULL;
    }
    break;
  case FIM:
    N = L->final;
    L->final = N->anterior;
    N->anterior->proximo = NULL;
    break;
  default:
    return(NULL);
  }

  void *info = N->info;
  free(N);

  return(info);
}

void listaFinalizar (Lista *L, int imprimir, void (*print)(void*)) {
  void *info;
  for (No *N = L->inicial; N; N = N->proximo) {
    if (((imprimir == INICIO) || (imprimir == FIM)) && ((*print) != NULL)) {
      info = listaGenericaRemover(L, imprimir);
      (*print)(info);
      free(info);
    } else {
      info = listaGenericaRemover(L, INICIO);
      free(info);
    }
  }
  free(L);
}

void listaImprimir (Lista *L) {
  for (No *N = L->inicial; N; N = N->proximo) {
    printf("%d ", *(int *)N->info);
  }
  printf("\n");
}

int *listaParaVetorDeInteiros (Lista *L, int *tamanho, int (*func)(void*)) {
  *tamanho = L->tamanho;
  int *vetor = malloc((*tamanho) * sizeof(int));
  if ((*func) == NULL) {
    return(NULL);
  }
  
  int i = 0;
  for (No *N = L->inicial; N; N = N->proximo) {
    vetor[i] = (*func)(N->info);
    i++;
  }

  return(vetor);
}

void listaGenericaInserirOrdenado (Lista *L, void *info, int (*menorQue)(void*, void*)) {
  int flag = 1;
  
  for (No *N = L->inicial; N && flag; N = N->proximo) {
    if ((*menorQue)(info, N->info)) {
      printf("(%d; %d)\n", *(int*)info, *(int*)N->info);
      noGenericoInserir(L, N, ANTES, info);
      flag = 0;
    }
  }
  if (flag) {
    listaGenericaInserir(L, FIM, info);
  }
}

int noGenericoInserir (Lista *L, No *N, int modo, void *info) {

  switch (modo) {
  case ANTES:
    if (L->inicial == N) {
      listaGenericaInserir (L, INICIO, info);
    } else {
      L->tamanho += 1;
      No *novoNo = noGenericoCriar(info);
      
      novoNo->proximo = N;
      novoNo->anterior = N->anterior;
      N->anterior->proximo = novoNo;
      N->anterior = novoNo;
    }
    break;
  case DEPOIS:
    if (L->final == N) {
      listaGenericaInserir (L, FIM, info);
    } else {
      L->tamanho += 1;
      No *novoNo = noGenericoCriar(info);

      novoNo->proximo = N->proximo;
      novoNo->anterior = N;
      N->proximo->anterior = novoNo;
      N->proximo = novoNo;
    }
    break;
  default:
    return(0);
  }

  return(L->tamanho);
}

void *noGenericoRemover (Lista *L, No *N) {
  void *info;
  
  if (L->final == N) {
    info = listaGenericaRemover(L, FIM);
  } else if (L->inicial == N) {
    info = listaGenericaRemover(L, INICIO);
  } else {
    info = N->info;
    N->anterior->proximo = N->proximo;
    N->proximo->anterior = N->anterior;
    free(N);
  }

  return(info);
}
/*		 
Pilha *pilhaCriar () {
  Pilha *P = listaCriar();

  return(P);
}

Fila *filaCriar () {
  Fila *F = listaCriar();

  return(F);
}
*/
