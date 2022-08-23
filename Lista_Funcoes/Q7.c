/*Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do
usuário e retornar as três palavras. A função main deve imprimir essas três palavras.*/

#include <stdio.h>
#include <locale.h>
#define tam 30

void ler3Palavras(char a[tam]){
  scanf(" %s", a);
}

int main(){
  char p1[tam], p2[tam], p3[tam];
  printf("Digite as três palavras a serem exibidas:\n");

  ler3Palavras(p1);
  ler3Palavras(p2);
  ler3Palavras(p3);

  printf("As palavras digitadas foram: \n%s\n%s\n%s\n", p1, p2, p3);
}