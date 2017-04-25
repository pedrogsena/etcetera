/* Exercício: 
   ler cadeias de caracteres correspondendo a nomes de pessoas (terminadas com "fim");
   nomes podem estar precedidos de um tratamento (pronome);
   o programa deve contrair os tratamentos (ver lista abaixo);
   imprimir nomes processados.
   
   Contração dos pronomes de tratamento:
   Senhor -> Sr.
   Senhora -> Sra.
   Doutor -> Dr.
   Ilustríssimo -> Ilmo.
   Excelentíssimo -> Exmo.
   Dona -> D.
   Vossa Senhoria -> V.Sa. */
   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Tam_Max_Str 100
#define Qte_Max_Nomes 100

int main(){

  char nomes[Qte_Max_Nomes][Tam_Max_Str];
  char fim[]="fim";
  char *pedaco;
  char outro_pedaco[Tam_Max_Str];
  char *novo_nome;
  char tratamento[7][Tam_Max_Str]={"Vossa Senhoria","Senhora","Senhor","Doutor","Ilustrissimo","Excelentissimo","Dona"};
  char compacto[7][Tam_Max_Str]={"V.Sa.","Sra.","Sr.","Dr.","Ilmo.","Exmo.","D."};
  int i,j,k;
  int continua,tam_trat,existe;

  /* entrada: simples usando scanf */
  continua=1;
  for(i=0; i<Qte_Max_Nomes && continua; i++){
    scanf(" %[^\n]s",nomes[i]);
    fflush(stdin);
    if(strcmp(nomes[i],fim)==0) continua=0;
  }

  /* processamento */
  continua=1;
  for(i=0; i<Qte_Max_Nomes && continua; i++){
    if(strcmp(nomes[i],fim)==0) continua=0;
    if(continua){

      /* etapa 1: procurar o pronome de tratamento */
      existe=0;
      for(j=0; j<7 && !existe; j++){
        pedaco=strstr(nomes[i],tratamento[j]);
        if(pedaco!=NULL) existe=1; /* saindo com j+1 */
      }
      j--;
      if(existe){

        /* etapa 2: se existe pronome de tratamento, obter o resto da string */
        tam_trat=strlen(tratamento[j]);
        for(k=tam_trat;k<=strlen(nomes[i]);k++){
          outro_pedaco[k-tam_trat]=nomes[i][k];
        }

        /* etapa 3: concatenar tudo e copiar */
        novo_nome=strcat(compacto[j],outro_pedaco);
        strcpy(nomes[i],novo_nome);
      }
    }
  }

  /* saída */
  continua=1;
  for(i=0; i<Qte_Max_Nomes && continua; i++){
    if(strcmp(nomes[i],fim)==0) continua=0;
    if(continua){
      printf("%s\n",nomes[i]);
    }
  }

  return 0;  
}
