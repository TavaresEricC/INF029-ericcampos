/*#### Versão v01 ####
- Estrutura básica para representar aluno
- Estrutura inicial de menu e switch
- Lista de alunos
- Inserir aluno
- Listar alunos*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 15
#define str 31

typedef struct{
  long int matricula;
  char nome[str], curso[str];
  int semestre;
}Aluno;

void cadastro(Aluno cad[], int qtd){
  int i = 0;
  printf("\nDigite o nome do aluno: ");
  fflush(stdin);
  getchar();
  fgets(cad[qtd].nome, 31, stdin);
  
  while(cad[qtd].nome[i] != '\0'){
    i++;
  }
  if(cad[qtd].nome[i-1] == '\n'){
    cad[qtd].nome[i-1] = '\0';
  }
  
  printf("\nDigite a matrícula do aluno: ");
  scanf("%ld", &cad[qtd].matricula);
  fflush(stdin);

  printf("\nDigite o curso do aluno: ");
  fflush(stdin);
  getchar();
  fgets(cad[qtd].curso, 31, stdin);
  i=0;
  
  while(cad[qtd].curso[i] != '\0'){
    i++;
  }
  if(cad[qtd].curso[i-1] == '\n'){
    cad[qtd].curso[i-1] = '\0';
  }
  
  printf("\nDigite o semestre atual do aluno: ");
  scanf("%d", &cad[qtd].semestre);
  fflush(stdin);
}

int main(){
  setlocale(LC_ALL, "pt-BR");
  int i = 0, op = 0, j, sair;
  Aluno aluno[tam];

  do{
    system("clear");
    printf("---------ESCOLA---------\n\n");
    printf("Digite uma das opções a seguir:\n\n");
    printf("\n1 - Inserir aluno;");
    printf("\n2 - Listar alunos;");
    printf("\n3 - Sair do programa.\n");
    printf("\n\nOpção digitada: ");
    scanf("%d", &op);

    switch(op){
      case 1:
        system("clear");
        printf("Cadastro de alunos:\n\n");
        cadastro(aluno, i);
        if(i<tam){
          i++;
        }
      break;

      case 2:
        system("clear");
        printf("Lista de alunos:");
        
        for(j=0; j<i; j++){
          printf("\n\nAluno #%d", j+1);
          printf("\n\nNome: %s.", aluno[j].nome);
          printf("\nMatrícula: %ld.", aluno[j].matricula);
          printf("\nCurso: %s.", aluno[j].curso);
          printf("\nSemestre: %dº.", aluno[j].semestre);
        }
        printf("\n\nDigite qualquer número pra sair: ");
        scanf("%d", &sair);
        if(sair >= 0 && sair <=9){
          break;
        }
      break;
    }
  }while(op>0 && op<3);
}