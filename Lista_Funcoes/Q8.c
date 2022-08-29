/*Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do
cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve
imprimir os dados do cliente.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 38
#define nas 11
#define cd 12  

typedef struct{
  char nome[tam], sexo, cpf[cd], dataNascimento[nas];
}cadastro;

cadastro p1;
cadastro cad(){
  setlocale(LC_ALL, "Portuguese");
  
  printf("\nDigite o nome do cliente: ");
  fflush(stdin);
  fgets(p1.nome, 38, stdin);
  
  printf("\nDigite o sexo do cliente (M ou F): ");
  scanf("%c", &p1.sexo);
  fflush(stdin);

  printf("\nDigite o cpf do cliente (Somente números): ");
  getchar();
  fflush(stdin);
  fgets(p1.cpf, 12, stdin);

  printf("\nDigite a data de nascimento do cliente (Formato DD/MM/AAAA): ");
  getchar();
  fflush(stdin);
  fgets(p1.dataNascimento, 11, stdin);

  return p1;
}

int main(){
  cadastro pes;
  printf("CADASTRO DE CLIENTES\n\n");
  printf("Digite dados de cadastro:\n");
  pes = cad();

  printf("\n\nDados do cliente:\n\n");
  printf("Nome: %s", pes.nome);
  printf("\nCPF: %s", pes.cpf);
  printf("\nData de Nascimento: %s", pes.dataNascimento);
  printf("\nSexo: %c\n", pes.sexo);
}