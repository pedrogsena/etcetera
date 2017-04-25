#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Tam_Bloco 30
#define Tam_Max_Legenda 13

typedef struct partido {
  char *legenda;
  int totaldeps;
  int votos_sim;
  int votos_nao;
  int abstencoes;
} partido;

int main() {
  partido *Tabela;
  char legenda[Tam_Max_Legenda];
  int i = 0, tamstr, totaldeps, numpartidos = Tam_Bloco, j;
  int totalsim = 0, totalnao = 0, totalabst = 0, totalgeral, totalvotosporpartido, faltosos;
  float para_impressao;
  char voto;
  
  Tabela = (partido*)malloc(numpartidos * sizeof(partido));
  
  do {
    scanf(" %s", legenda);
    if(!strcmp(legenda, "FIM")) break;
    else {
      scanf(" %d", &totaldeps);
      tamstr = strlen(legenda);
      Tabela[i].legenda = (char*)malloc(tamstr * sizeof(char));
      strcpy(Tabela[i].legenda, legenda);
      Tabela[i].totaldeps = totaldeps;
      Tabela[i].votos_sim = 0;
      Tabela[i].votos_nao = 0;
      Tabela[i].abstencoes = 0;
      i++;
      if(i % Tam_Bloco == 0) {
        numpartidos += Tam_Bloco;
        Tabela = (partido*)realloc(Tabela, numpartidos * sizeof(partido));
      }
    }
  } while(1);
  numpartidos = i;
  Tabela = (partido*)realloc(Tabela, numpartidos * sizeof(partido));
  
  do {
    scanf(" %s", legenda);
    if(!strcmp(legenda, "FIM")) break;
    else {
      scanf(" %c", &voto);
      for(j = 0; j < numpartidos; j++) {
        if(strcmp(Tabela[j].legenda, legenda) == 0) {
          i = j;
          break;
        }
      }
      switch (voto) { /* Assuma que voto sempre será S, N ou A, e nada mais. */
        case 'S':
          (Tabela[i].votos_sim)++;
          break;
        case 'N':
          (Tabela[i].votos_nao)++;
          break;
        default: /* Abstenções */
          (Tabela[i].abstencoes)++;
      }
    }
  } while(1);
  
  printf("\n");
  for(i = 0; i < numpartidos; i++) {
    totalvotosporpartido = 0;
    printf("%s: ", Tabela[i].legenda);
    
    printf("%d (Sim) ", Tabela[i].votos_sim);
    totalvotosporpartido += Tabela[i].votos_sim;
    para_impressao = (float) 100 * Tabela[i].votos_sim / Tabela[i].totaldeps;
    printf("%2.0f%%, ", para_impressao);
    
    printf("%d (Nao) ", Tabela[i].votos_nao);
    totalvotosporpartido += Tabela[i].votos_nao;
    para_impressao = (float) 100 * Tabela[i].votos_nao / Tabela[i].totaldeps;
    printf("%2.0f%%, ", para_impressao);
    
    printf("%d (Abst) ", Tabela[i].abstencoes);
    totalvotosporpartido += Tabela[i].abstencoes;
    para_impressao = (float) 100 * Tabela[i].abstencoes / Tabela[i].totaldeps;
    printf("%2.0f%%, ", para_impressao);

    faltosos = Tabela[i].totaldeps - totalvotosporpartido;
    printf("%d (Faltas) ", faltosos);
    para_impressao = (float) 100 * faltosos / Tabela[i].totaldeps;
    printf("%2.0f%%\n", para_impressao);

    totalsim += Tabela[i].votos_sim;
    totalnao += Tabela[i].votos_nao;
    totalabst += Tabela[i].abstencoes;
  }

  totalgeral = totalsim + totalnao + totalabst;
  printf("\nTOTAL: ");

  printf("%d (Sim) ", totalsim);
  para_impressao = (float) 100 * totalsim / totalgeral;
  printf("%2.0f%%, ", para_impressao);
  
  printf("%d (Nao) ", totalnao);
  para_impressao = (float) 100 * totalnao / totalgeral;
  printf("%2.0f%%, ", para_impressao);
  
  printf("%d (Abst) ", totalabst);
  para_impressao = (float) 100 * totalabst / totalgeral;
  printf("%2.0f%%\n", para_impressao);

  return 0;
}
