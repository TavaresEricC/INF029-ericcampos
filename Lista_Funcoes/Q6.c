/*Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário
e retornar as três letras. A função main deve imprimir essas três letras.*/

#include <stdio.h>
#include <stdlib.h>
#define tam 3

char ler3Letras(char l1){
  scanf(" %c", &l1);
  return l1;
}

int main(){
  char a, b, c;
  printf("Digite as letras a serem exibidas: \n");

  a = ler3Letras(a);
  b = ler3Letras(b);
  c = ler3Letras(c);

  printf("\nAs letras digitadas foram: \n%c\n%c\n%c\n", a, b, c);
}