/*Faça um programa que imprima o seu nome, sua matrícula, e o seu semestre de ingresso no curso. Cada informação em uma linha.*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    printf("\nNome: Eric Campos Tavares");
    printf("\nMatrícula: 20201160026");
    printf("\nSemestre de ingresso no curso: 2020.1\n");
}