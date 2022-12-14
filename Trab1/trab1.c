6#include <stdio.h>
#include <locale.h>
#define tam 11

int validaData(int dia, int mes, int ano){
  if(ano>=0){
    if(mes==2){
      if((dia==30 || dia==31) && mes==2){
       return 0;
      }
      if(dia==29 && mes==2 && (ano%4==0 &&(ano%400==0 || ano%100!=0))){
        return 1;
      }else{
        return 0;
      }
    }else{
      if(mes==4 || mes==6 || mes==9 || mes==11){
        if(dia<=0 || dia>30 ){
          return 0;
        }else{
         return 1;
        }
      }else{
        if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
          if(dia<=0 || dia>31){
            return 0;
          }else{
            return 1;
          }
        }
      }
    }
    if(mes > 12){
      return 0;
    }
  }
  return 1;
}

void viraminuscula(char texto[]){
  int i;
  for(i=0; texto[i]!='\0'; i++){
    if(texto[i]>=65 && texto[i]<=90){
      texto[i] = texto[i] + 32;
    }
  }
}

int viraint(char texto[], int Tam, int intexto[]){
  int i, j;
  for(i = 0; i<Tam; i++){
    if(texto[i] == -61){
      for(j=i; j<Tam; j++){
        texto[j] = texto[j+1];
      }
      Tam--;
    }
    intexto[i] = texto[i];
  }
  return Tam;
}