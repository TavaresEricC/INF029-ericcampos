#include <stdio.h>
#include <stdlib.h>
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

void listarAlunos(pessoa alunos[], int qtd){
  int j;
  char sair;
  system("clr");
  printf("Lista de alunos:");
        
        for(j=0; j<qtd; j++){
          printf("\n\nAluno #%d", j+1);
          printf("\n\nNome: %s.", alunos[j].nome);
          printf("\nData de nascimento: %s.", alunos[j].nasc); 
          printf("\nCPF: %s.", alunos[j].cpf); 
          printf("\nSexo: %c", alunos[j].sexo);
          printf("\nMatrícula: %s.", alunos[j].matricula);
          printf("\nCurso: %s.", alunos[j].curso);
          printf("\nSemestre: %s.", alunos[j].semestre);
        }
        getchar();
        printf("\n\nPressione enter para sair");
        scanf("%c", &sair);
  
}