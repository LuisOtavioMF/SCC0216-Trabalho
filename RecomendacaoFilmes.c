#include <stdio.h>
#include <stdlib.h> // Talvez nao seja necessario

// Inclusao das bibliotecas especificas do projeto
#include <recomendacao.h>

#define SAIR 0
#define INDICARPARECIDOS 1
#define INDICARDIFERENTES 2
#define LISTARCATEGORIA 3
#define FILMESFORTEMENTERELACIONADOS 4
#define MAXSTRLEN 100

int main (int argc, char **argv) {
  FILE *arquivo;
  int erro;

  // Inicializacao e tratamento de erros
  if (argc == 0) {
    printf("Erro: Nao foi indicado um arquivo com os filmes e suas informacoes\n");
    return(1);
  } else if (argc > 1) {
    printf("Erro: Indique apenas um arquivo com os filmes e suas informacoes\n");
    return(2);
  }

  arquivo = fopen(argv[0], "r");
  if (arquivo == NULL) {
    printf("Erro: Arquivo invalido\n");
    return(3);
  }
  
  // Criacao do grafo a partir do arquivo
  Grafo *G = grafoGerar(arquivo, &erro);

  switch (erro) {
  case 1:
    printf("Erro: 1");
    break;
  }

  // Tomada de entradas e execucao das operacoes no grafo
  int modo;
  do {
    
    printf("Escolha uma operacao:\n");
    printf("1 - Encontrar filmes semelhantes;\n");
    printf("2 - Encontrar filmes diferentes;\n");
    printf("3 - Listar filmes em uma categoria;\n");
    printf("4 - Achar grupos de filmes fortemente relacionados;\n");
    printf("0 - Sair.\n");
    printf("Digite o numero referente a operacao: ");
    scanf("%d", &modo);

    char input[MAXSTRLEN];
    int n;
    switch (modo) {
    case INDICARPARECIDOS:
      printf("Digite o nome de um filme: ");
      scanf("%s", input);
      printf("Escolha o numero de recomendacoes: ");
      scanf("%d", &n);
      encontrarSemelhantes(G, input, n);
      break;
    case INDICARDIFERENTES:
      printf("Digite o nome de um filme: ");
      scanf("%s", input);
      printf("Escolha o numero de recomendacoes: ");
      scanf("%d", &n);
      encontrarDiferentes(G, input, n);
      break;
    case LISTARCATEGORIA:
      printf("Digite o nome de uma categoria: ");
      scanf("%s", input);
      listarCategoria(G, input);
      break;
    case FILMESFORTEMENTERELACIONADOS:
      printf("Achando filmes fortemente relacionados\n");
      encontrarFilmesRelacionados(G);
      break;
    case SAIR:
      printf("Vlw flw\n");
      break;
    default:
      printf("Erro: Operacao invalida");
      break;
    }
  } while (modo);

  return(0);
}
