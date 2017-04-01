/* ================================= header ================================= */

#define TAM_MATRIC 11
#define TAM_NOME 30
#define TAM_STATUS 3


/* Estrutura de um nodo da Lista Ligada  */
typedef
struct noh {
    char matric[TAM_MATRIC];
    char nome[TAM_NOME];
    float media;
    char status[TAM_STATUS];
    struct noh *prox;
} NODO_LL;

/* Protótipo da função de exclusão da Lista Ligada */
int exclui_matric(NODO_LL **, char []);

/* ================================= source ================================= */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista-ligada.h"

int exclui_matric(NODO_LL **pInicio, char matric[]){

  /* Declaração e inicialização de ponteiros de apoio */
  NODO_LL *pAux,*pAnt;
  pAux=*pInicio;
  pAnt=NULL;

  /* Procurando elemento a ser removido */
  while(pAux!=NULL){

    /* Se encontrou, saia do laço */
    if(strcmp(pAux->matric,matric)==0) break;

    /* Se não, passe ao próximo elemento */
    pAnt=pAux;
    pAux=pAux->prox;

  }

  /* Se não encontrou, retorne 0 */
  if(pAux==NULL) return 0;

  /* Se o elemento a ser removido foi encontrado no meio ou no final da lista */
  if(pAnt!=NULL) pAnt->prox=pAux->prox;

  /* Se o elemento a ser removido foi encontrado no início da lista */
  else *pInicio=(*pInicio)->prox;

  /* Por fim, retorna 1 */
  return 1;

}
