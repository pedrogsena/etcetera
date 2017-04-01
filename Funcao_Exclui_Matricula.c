/* Universidade do Estado da Bahia - UNEB
   DCET-I - Sistemas de Informa��o - 2017.1
   Linguagens de Programa��o I
   Pedro Gabriel Sena Cardoso */

/* Fun��o de exclus�o de elemento de uma lista simplesmente encadeada,
    a partir do n�mero de matr�cula fornecido.
   Nota: a fun��o realiza apenas a exclus�o l�gica do elemento;
    a exclus�o f�sica (a libera��o de mem�ria alocada no heap)
    deve ser efetuada pela inst�ncia (main, ou outra fun��o)
    que chamou esta fun��o. */

int exclui_matric(NODO_LL **pInicio, char matric[])
{

    /* Declara��o e inicializa��o de ponteiros de apoio */
    NODO_LL *pAux,*pAnt;
    pAux=*pInicio;
    pAnt=NULL;

    /* Procurando elemento a ser removido */
    while(pAux!=NULL){

        /* Se encontrou, saia do la�o */
        if(strcmp(pAux->matric,matric)==0) break;

        /* Se n�o, passe ao pr�ximo elemento */
        pAnt=pAux;
        pAux=pAux->prox;

    }

    /* Se n�o encontrou, retorne 0 */
    if(pAux==NULL) return 0;

    /* Se o elemento a ser removido foi encontrado no meio ou no final da lista */
    if(pAnt!=NULL) pAnt->prox=pAux->prox;

    /* Se o elemento a ser removido foi encontrado no in�cio da lista */
    else *pInicio=(*pInicio)->prox;

    /* Por fim, retorna 1 */
    return 1;

}
