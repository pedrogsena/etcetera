#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Questão 1 - item a */

typedef struct pessoa{
    char* nome;
    int dia;
    int mes;
    int ano;
} Pessoa;

int maior_idade(Pessoa *person1,Pessoa *person2){
    /* Retorna 0 se idades iguais, 1 se person1 é mais velho, 2 se person2 é mais velho */
    int saida;
    saida=0*(person1->ano==person2->ano)+1*(person1->ano<person2->ano)+2*(person1->ano>person2->ano);
    if(saida==0){
        saida=0*(person1->mes==person2->mes)+1*(person1->mes<person2->mes)+2*(person1->mes>person2->mes);
        if(saida==0){
            saida=0*(person1->dia==person2->dia)+1*(person1->dia<person2->dia)+2*(person1->dia>person2->dia);
        }
    }
    return saida;
}

/* Assumindo que datas não se repetem */
char* mais_velho_rec(Pessoa *vetor, int num){
    char *chegada;
    char *saida;
    int indexchegada;
    int maisvelhode2;
    if(num=1) saida=vetor[0].nome; /* Base */
    else{
        chegada=mais_velho_rec(vetor,num-1);
        indexchegada=0;
        while(strcmp(vetor[indexchegada].nome,chegada)!=0) indexchegada++;
        maisvelhode2=maior_idade(&(vetor[indexchegada]),&(vetor[num-1]);
        if(maisvelhode2==1) saida=vetor[indexchegada].nome;
        else saida=vetor[num-1].nome;
    }
    return saida;
}

/* Questão 1 - item b */

char* mais_velho_it(Pessoa *vetor,int num){
    /* Iterativo; retorna ponteiro de char */
    int i,elder_index=0;
    for(i=1;i<num;i++) if(maior_idade(vetor+elder_index,vetor+i)==2) elder_index=i;
    return (vetor+elder_index)->nome;
}

/* Questão 1 - item c */

void produto(int **mat1, int **mat2, int linhas1, int colunas1, int linhas2, int colunas2, int **prod){
    int i,j,k;
    for(i=0;i<linhas1;i++)
        for(j=0;j<colunas2;j++)
            prod[i][j]=0;
    if(colunas1==linhas2)
        for(i=0;i<linhas1;i++)
            for(j=0;j<colunas2;j++)
                for(k=0;k<linhas2;k++)
                    prod[i][j]+=mat1[i][k]*mat2[k][j];
    return;
}

/* Questão 2 */

typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;

int Bissexto(Data *pdata){
    return !(pdata->ano%400)||(!(pdata->ano%4)&&(pdata->ano%100));
}

int QtosDiasMes(Data *pdata){
    int fevereiro,trinta,trinta_e_um;
    trinta=((pdata->mes==4)||(pdata->mes==6)||(pdata->mes==9)||(pdata->mes==11));
    fevereiro=(pdata->mes==2);
    trintaUm=!(trinta||fevereiro);
    return 30*trinta+31*trintaUm+(28+Bissexto(pdata))*fevereiro;
}

/*
int QtosDiasMesV2(int mes,int ano){
    int fevereiro,trinta,trinta_e_um,bissexto;
    trinta=((mes==4)||(mes==6)||(mes==9)||(mes==11));
    fevereiro=(mes==2);
    trintaUm=!(trinta||fevereiro);
    bissexto=!(ano%400)||(!(ano%4)&&(ano%100));
    return 30*trinta+31*trintaUm+(28+bissexto)*fevereiro;
}
*/

int validarData(Data *pdata){
    int saida;
    if(pdata->mes<1||pdata->mes>12) saida=0;
    else{
        if(pdata->dia<1||pdata->dia>QtosDiasMes(pdata)) saida=0;
        else saida=1;
    }
    return saida;
}

int sinal(int x){
    return 1*(x>0)-1*(x<0)+0*(x==0);
}

int auxdiff(int x, int y){
    int saida;
    saida=3-sinal(x-y);
    if(saida%2) saida=saida/2;
    else saida=0;
    return saida;
}

int DataMaisAntiga(Data *pdata1, Data *pdata2){
    /* Retorna 0 se datas iguais,
        1 se data1 é mais antiga, 2 se data2 é mais antiga */
    int saida;
    saida=auxdiff(pdata1->ano,pdata2->ano);
    if(saida==0) saida=auxdiff(pdata1->mes,pdata2->mes);
    if(saida==0) saida=auxdiff(pdata1->dia,pdata2->dia);
    return saida;
}

void avancarData(Data *pdata){
    /* Avança data informada em um dia */
    int qtedias;
    qtedias=QtosDiasMes(pdata);
    (pdata->dia)++;
    if(pdata->dia>qtedias){
        pdata->dia=1;
        (pdata->mes)++;
        if(pdata->mes>12){
            pdata->mes=1;
            (pdata->ano)++;
        }
    }
    return;
}

int dias(Data *pdata1, Data *pdata2){
    int saida;
    Data *pantiga;
    Data *precente;
    Data *aux;
    int contador;
    if(DataMaisAntiga(pdata1,pdata2)==0) saida=0;
    else{
        if(DataMaisAntiga(pdata1,pdata2)==1){
            pantiga=pdata1;
            precente=pdata2;
        }
        else{
            pantiga=pdata2;
            precente=pdata1;
        }
        /* Versão que avança data */
        aux=pantiga;
        contador=0;
        while(DataMaisAntiga(aux,precente)){
            avancarData(aux);
            contador++;
        }
        saida=contador;
    }
    return saida;
}

void auxprint(Data *pdata){
    printf("dia: ");
    scanf(" %d",&(pdata->dia));
    printf("mes: ");
    scanf(" %d",&(pdata->mes));
    printf("ano: ");
    scanf(" %d",&(pdata->ano));
    return;
}

int main(){
    Data data1,data2;
    int i,valido,qtedias;
    for(i=1;i<=2;i++){
        if(i==1){
            do{
                printf("Informe primeira data:\n");
                auxprint(&data1);
                valido=validarData(&data1);
                if(!valido) printf("Data invalida, informe outra data.\n\n");
            } while(!valido);
        }
        else{
            do{
                printf("Informe segunda data:\n");
                auxprint(&data2);
                valido=validarData(&data2);
                if(!valido) printf("Data invalida, informe outra data.\n\n");
            } while(!valido);
        }
    }
    qtedias=dias(&data1,&data2);
    printf("\n\nA diferenca entre as datas informadas e de %d dias.\n\n",qtedias);
    return 0;
}
