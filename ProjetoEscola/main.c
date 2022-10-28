/*Projeto Escola
Participantes:
Eric Campos Tavares - 20201160026
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


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

#include "funcuti.h"
#include "cadastros.h"
#include "alunos.h"
#include "listar.h"
//typedef struct{
  //char nome[str], sexo, matricula[mat], cpf[cp], nasc[dtn];
//}Professor;

int main(){
  setlocale(LC_ALL, "pt-BR");
  int qtdalu = 0, qtdprof = 0, qtddisc = 0, op = 0, j;
  char sair;
  pessoa aluno[tam];
  pessoa professor[tam];
  

  do{
    system("clear");
    printf("---------ESCOLA---------\n\n");
    printf("Digite uma das opções a seguir:\n\n");
    printf("\n1 - Alunos;");
    printf("\n2 - Professores;");
    printf("\n3 - Disciplina.\n");
    printf("\nDigite 0 pra sair");
    printf("\n\nOpção digitada: ");
    scanf("%d", &op);

    switch(op){
      case 1:
        system("clear");
        qtdalu = alunos(aluno, qtdalu);
      break;

      case 2:
        system("clear");
        printf("Cadastro de professoress:\n\n");
        qtdprof = cadastro(professor, qtdalu);
        
        /*printf("Lista de alunos:");
        
        for(j=0; j<i; j++){
          printf("\n\nAluno #%d", j+1);
          printf("\n\nNome: %s.", aluno[j].nome);
          printf("\nData de nascimento: %s.", aluno[j].nasc); 
          printf("\nCPF: %s.", aluno[j].cpf); 
          printf("\nSexo: %c", aluno[j].sexo);
          printf("\nMatrícula: %s.", aluno[j].matricula);
          printf("\nCurso: %s.", aluno[j].curso);
          printf("\nSemestre: %s.", aluno[j].semestre);
        }
        getchar();
        printf("\n\nPressione enter para sair");
        scanf("%c", &sair);
        if(sair){
          break;
        }*/
      break;
      default:if(op!=0){
        printf("Opção inválida!!");
      }
    }
  }while(op!=0);
}