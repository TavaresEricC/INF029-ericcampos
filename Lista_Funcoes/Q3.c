/*Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial
deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve
de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do
usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fatorial(int n){
  int fat;
  if(n<0){
    return -1; 
  }else{
    for(fat=1; n>1; n--){
      fat = fat*n;
    }
    return fat;
  }
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  int a;
  printf("CALCULO DE FATORIAL\n\n");
  printf("Digite o número que deseja calcular o fatorial: ");
  scanf("%d", &a);

  if(fatorial(a) == -1){
    printf("\nErro! Fatorial não pode ser calculado\n\tFim do programa!\n");
  }else{
    printf("\nO valor do fatorial é: %d.\n", fatorial(a));
  }
}