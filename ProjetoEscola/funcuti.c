#include <stdio.h>

void tiralinha(char palavra[]){
  int i=0;
  while(palavra[i] != '\0'){
    i++;
  }
  if(palavra[i-1] == '\n'){
    palavra[i-1] = '\0';
  }
}