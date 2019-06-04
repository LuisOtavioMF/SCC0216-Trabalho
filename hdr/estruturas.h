#define INICIO 1
#define FIM 2
#define ANTES 0
#define DEPOIS 1

typedef struct no No;
typedef struct lista Lista;

// Cria um novo no
No *noGenericoCriar (void *info);

// Cria uma nova lista
Lista *listaGenericaCriar ();

// Retorna o tamanho de uma lista
int listaTamanho (Lista *L);

// Retorna o no inicial de uma lista
No *listaInicial (Lista *L);

// Retorna o no final de uma lista
No *listaFinal (Lista *L);

// Insere um novo no em uma lista e retorna o tamanho dela apos a insercao
// A variavel modo (INICIO ou FIM) indica aonde o no sera inserido, se o valor dela nao for valido a funcao retorna 0
int listaGenericaInserir (Lista *L, int modo, void *info);

// Remove um no da lista e retorna a informacao contida nele
// A variavel modo (INICIO ou FIM) indica daonde o no devera ser removido, se o valor dela nao for valido a funcao retorna NULL
void *listaGenericaRemover (Lista *L, int modo);

// Finaliza a lista
// A variavel imprimir (INICIO ou FIM) indica se a lista deve ser imprimida ou nao, e se sim se deve ser imprimida de tras pra frente ou de frente pra tras
// Se ela for ser imprimida e necessario passar uma funcao (*print) que indica como a informacao da de um dado no (que tem tipo void*) deve ser imprimida, caso nao seja necessario imprimir (*print) pode ser igual a NULL
void listaFinalizar (Lista *L, int imprimir, void (*print)(void*));

void listaImprimir(Lista *L);

// Transforma a lista em um vetor de inteiros
// (*func) e uma funcao que indica como transformar a informacao dentro de um no (que tem tipo void*) em um inteiro.
// O tamanho da lista, e consequentemente do vetor, e colocado em *tamanho
int *listaParaVetorDeInteiros (Lista *L, int *tamanho, int (*func)(void*));

// Funcao que insere um no na lista de forma que ela permaneca ordenada (desde que todos os outros nos tenham sido inseridos dessa forma)
// (*menorQue) deve ser uma funcao que indica como as informacoes de cada no devem ser comparadas e deve retornar 1 (ou verdadeiro) quando o primeiro parametro for menor que o segundo, ou 0 (ou falso) caso contrario
void listaGenericaInserirOrdenado (Lista *L, void *info, int (*menorQue)(void*, void*));

// Cria um novo no e insere ele antes ou depois do no N. A variavel modo (ANTES ou DEPOIS) indica se ele deve ser inserido antes ou depois. Retorna o tamanho da lista ou 0, caso o modo seja invalido
int noGenericoInserir (Lista *L, No *N, int modo, void *info);

// Remove um no da lista e retorna a informacao contida nele
void *noGenericoRemover (Lista *L, No *N);

/*
typedef Lista Pilha;
// Cria uma nova Pilha
Pilha *pilhaCriar ();

typedef Lista Fila;
// Cria uma nova Fila
Fila *filaCriar ();
*/
