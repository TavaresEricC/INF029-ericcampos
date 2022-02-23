/*Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas. Ao final imprima tudo. Utilize vetor e struct.*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 5
typedef struct{
  int idade, cpf;
  char nome[31], sexo;
}cadastro;

cadastro cad[TAM];

int main(){
  int i;
  printf("-----------CADASTRO-----------\n\n");
  for(i=0;i<TAM;i++){
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(cad[i].nome,30, stdin);

    printf("Digite a idade: ");
    scanf(" %d", &cad[i].idade);
    fflush(stdin);

    printf("Digite o sexo (m ou f): ");
    scanf(" %c", &cad[i].sexo);
    fflush(stdin);
    
    printf("Digite o CPF(Caso primeiro digito seja 0, desconsidere): ");
    scanf("%d", &cad[i].cpf);
    fflush(stdin);
  }

  printf("\n\nOs dados cadastrados foram:\n\n");

  for(i=0;i<TAM;i++){
    printf("Pessoa %d:\n", i+1);
    printf("\nNome: %s", cad[i].nome);
    printf("\nIdade: %d", cad[i].idade);
    printf("\nSexo: %c", cad[i].sexo);
    printf("\nCPF: %d\n\n", cad[i].cpf);
  }
}