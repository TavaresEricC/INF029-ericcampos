/*Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou de menor. O programa deve repetir essa ação até que uma idade negativa seja informada*/

#include <stdio.h>

int main(){
  int idade;

  while(idade>=0){
    printf("\nDigite a sua idade: ");
    scanf("%d", &idade);
    if(idade >=18){
      printf("\nVocê é maior de idade.\n");
    }else{
      if(idade>=0 && idade<18){
        printf("\nVocê é menor de idade.\n");
      }
    }if(idade<0){
      printf("\nIdade inválida!!\n");
    }
  }
}