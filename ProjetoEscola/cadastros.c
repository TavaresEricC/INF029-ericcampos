#include <stdio.h>
#include "funcuti.h"
#define tam 15
#define str 31
#define dtn 11
#define mat 13
#define cp 12
#define sem 7
#define cod 9

typedef struct{
  char nome[str], curso[str], sexo, nasc[dtn], semestre[sem], matricula[mat], cpf[cp];
}pessoa;

typedef struct{
  char nome[str], codigo[cod], semestre[sem], professor[str];
}disciplina;

int cadastro(pessoa ficha[], int qtd){
  int i = 0;
  
  printf("\nDigite o nome do aluno: ");
  fflush(stdin);
  getchar();
  fgets(ficha[qtd].nome, 31, stdin);

  tiralinha(ficha[qtd].nome);
  /*while(cad[qtd].nome[i] != '\0'){
    i++;
  }
  if(cad[qtd].nome[i-1] == '\n'){
    cad[qtd].nome[i-1] = '\0';
  }*/

  printf("\nInforme a data de nascimento: ");
  fflush(stdin);
  
  fgets(ficha[qtd].nasc, dtn, stdin);
  tiralinha(ficha[qtd].nasc);
  
  printf("\nDigite o CPF do aluno(Apenas números): ");
  getchar();
  fflush(stdin);
  fgets(ficha[qtd].cpf, cp, stdin);
  tiralinha(ficha[qtd].cpf);

  
  printf("\nDigite o sexo do aluno (F:  feminino, M: masculino. O: outros): ");
  getchar();
  scanf("%c", &ficha[qtd].sexo);
  fflush(stdin);
  
  printf("\nDigite a matrícula do aluno: ");
  fflush(stdin);
  getchar();
  fgets(ficha[qtd].matricula, mat, stdin);
  tiralinha(ficha[qtd].matricula);
  
  printf("\nDigite o curso do aluno: ");
  fflush(stdin);
  
  fgets(ficha[qtd].curso, 31, stdin);

  tiralinha(ficha[qtd].curso);
  /*i=0
  
  while(cad[qtd].curso[i] != '\0'){
    i++;
  }
  if(cad[qtd].curso[i-1] == '\n'){
    cad[qtd].curso[i-1] = '\0';
  }*/
  
  printf("\nDigite o semestre atual do aluno: ");
  fflush(stdin);
  getchar();
  fgets(ficha[qtd].semestre, sem, stdin);
  tiralinha(ficha[qtd].semestre);

  qtd++;
  return qtd;
}
