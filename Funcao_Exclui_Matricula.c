/* Universidade do Estado da Bahia - UNEB
   DCET-I - Sistemas de Informação - 2017.1
   Linguagens de Programação I
   Pedro Gabriel Sena Cardoso */

/* Função de exclusão de elemento de uma lista simplesmente encadeada,
    a partir do número de matrícula fornecido.
   Nota: a função realiza apenas a exclusão lógica do elemento;
    a exclusão física (a liberação de memória alocada no heap)
    deve ser efetuada pela instância (main, ou outra função)
    que chamou esta função. */

int exclui_matric(NODO_LL **pInicio, char matric[])
{

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
