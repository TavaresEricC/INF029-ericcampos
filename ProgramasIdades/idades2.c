/*Evoluir o programa anterior para ler também o nome das pessoas e imprimir o nome e a idade de todos que forem maior que a média.*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define TAM 5

typedef struct{
  int idade;
  char nome[31];
}pessoa;

pessoa pes[TAM];

int main(){
  setlocale(LC_ALL, "Portuguese");
  int i, soma = 0, media; 

  printf("\nDigite as idades e nomes.\n");

  for(i=0; i<TAM; i++){
    printf("\nNome: ");
    fflush(stdin);
    getchar();
    fgets(pes[i].nome, 31, stdin);
    
    printf("\nIdade %d: ", i+1);
    scanf("%d", &pes[i].idade);
    fflush(stdin);
  }
  
  printf("\n\nIdade(s) maior(es) que a média\n");
  for(i=0;i<TAM;i++){
    soma = soma + pes[i].idade;
  }
  media = soma/TAM;

  for(i=0; i<TAM; i++){
    if(pes[i].idade > media){
      printf("Idade: %d\n", pes[i].idade);
      printf("Nome: %s\n\n", pes[i].nome);
    }
  }
  printf("\n");
}