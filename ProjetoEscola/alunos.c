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


int alunos(pessoa alunos[], int qtdalu){
  #include "listar.h"
  #include "cadastros.h"
  int opalu;

  do{
    printf("----------Alunos----------\n");
    printf("\nSelecione uma opção:");
    printf("\n\n1 - Inserir aluno;");
    printf("\n2 - Listar alunos;");
    printf("\n0 - Voltar ao menu anterior.");
    printf("\n\nOpção digitada: ");
    scanf("%d", &opalu);

    switch(opalu){
      case 1:
        qtdalu = cadastro(alunos, qtdalu);
      break;

      case 2:
        listarAlunos(alunos, qtdalu);
      break;

      default:
        if(opalu != 0){
          printf("Opção inválida!");
        }
      break;
    }
  }while(opalu!=0);
}