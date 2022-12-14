/*Crie um programa que defina variáveis do tipo int, char, string [10 posições], float, double. Deve ser definido também uma variável ponteiro para cada um dos tipos acima. Faça leituras (scanf) e escrita (printf) das variáveis primitivas e depois faça o mesmo utilizando ponteiros.*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define tam 11

int main(){
  setlocale(LC_ALL, "Portuguese");
  int num, *n = malloc(1);
  char c,str[tam], *ch = malloc(1), *strp = malloc(sizeof(tam));
  float flutua, *fpoint = malloc(1);
  double laele, *dpoint = malloc(1);

  printf("Digite um número inteiro: ");
  scanf("%d", &num);
  getchar();
  
  printf("\nDigite um caracter: ");
  scanf("%c", &c);
  getchar();
  
  printf("\nDigite uma palavra de até 10 letras: ");
  fgets(str, tam, stdin);
  
  
  printf("\nDigite um número com casas após a vírgula: ");
  scanf("%f", &flutua);
  getchar();
  
  printf("\nDigite um número com casas após a vírgula: ");
  scanf("%lf", &laele);
  getchar();
  
  printf("\nNúmero inteiro: %d.", num);
  printf("\nCaracter: %c", c);
  printf("\nPalavra: %s", str);
  printf("\nPonto flutuante: %f", flutua);
  printf("\nPonto flutuante maior: %lf", laele);

  printf("\n\nDigite um número inteiro: ");
  scanf("%d", n);
  getchar();
  
  printf("\nDigite um caractere: ");
  scanf("%c", ch);
  getchar();

  printf("\nDigite uma palavra de até 10 letras: ");
  fgets(strp, tam, stdin);

  printf("\nDigite um número com casas após a vírgula: ");
  scanf("%f", fpoint);
  getchar();

  printf("\nDigite um número com casas após a vírgula: ");
  scanf("%lf", dpoint);
  getchar();

  printf("\nNúmero inteiro: %d.", *n);
  printf("\nCaracter: %c", *ch);
  printf("\nPalavra: %s", strp);
  printf("\nPonto flutuante: %f", *fpoint);
  printf("\nPonto flutuante maior: %lf", *dpoint);
  
  return 0;
}