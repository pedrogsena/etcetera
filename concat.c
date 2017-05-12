#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  char *saida;
  int i, tam = 1, count = 0, j;
  if(argc >= 3){
    for(i = 1; i < argc; i++) tam += strlen(argv[i]);
    saida=(char*)malloc(tam * sizeof(char));
    for(i = 1; i < argc; i++){
      for(j = 0; argv[i][j] != '\0'; j++){
        saida[count] = argv[i][j];
        count++;
      }
    }
    saida[count]='\0';
    printf("%s\n",saida);
    free(saida);
  } else if(argc == 2){
    if(!strcmp(argv[1],"help")) printf("Este programa concatena duas ou\n mais strings fornecidas como argumentos.\n");
    else printf("%s\n",argv[1]);
  }
  return 0;
}
