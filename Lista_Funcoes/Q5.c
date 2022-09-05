/*Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize
struct para fazer o retorno.*/

#include <stdio.h>
#include <locale.h>
#define tam 4
int i;

typedef struct{
  int a[tam];
}num;

num ler4Numeros(){
  num n;
  for(i=0; i<tam; i++){
    printf("%dº número: ", i+1);
    scanf("%d", &n.a[i]);
  }
  return n;
}

int main(){
  num n;
  printf("Digite os números a serem exibidos:\n");
  n = ler4Numeros();
  printf("\nOs números digitados foram: ");
  for(i=0; i<tam; i++){
    printf("%d\t", n.a[i]);
  }
  printf("\n");
}