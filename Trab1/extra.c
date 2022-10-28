/*int i=0, dia, mes, ano, j, k;
  char d[3], m[3], a[5];
  
  for(i=0; dt[i]!='/'; i++){
   d[i] = dt[i];
  }

  if(i == 1 || i == 2){
    d[i] = '\0';
  }else{
    return 0;
  }

  j = i+1;
  i=0;

  for(; dt[j]!='/'; j++){
    m[i] = dt[j];
    i++;
  }
  
  if(i == 1 || i ==2){
    m[i] = '\0';
  }else{
    return 0;
  }

  j++;
  i=0;
 
  for(; dt[j]!='\0'; j++){
    a[i] = dt[j];
    i++;
  }
  
  if(i == 2 || i == 4){
    a[i] = '\0';
  }else{
    return 0;
  }
  
  for(j=0; d[j]!='\0'; j++);

  if(j == 1){
    dia = d[0] - 48;
  }else if(j == 2){
    dia = (d[0] - 48)*10;
    dia = dia + (d[1] - 48);
  }

  for(j=0; m[j] != '\0'; j++);

  if(j==1){
    mes = m[0] - 48;
  }else if(j == 2){
    mes = (m[0] - 48)*10;
    mes = mes + (m[1] - 48);
  }

  if(i == 2){
    ano = (a[0] - 48)*10;
    ano = ano + (a[1] - 48);
  }else if(i == 4){
    ano = (a[0] - 48)*1000;
    ano = ano + (a[1] - 48)*100;
    ano = ano + (a[2] - 48)*10;
    ano = ano + (a[3] - 48);
  }*/


/*int main(){
  setlocale(LC_ALL, "pt-BR");
  char data[tam];
  int id;
  printf("Por favor, digite uma data: ");
  fgets(data, tam, stdin);
  tiralinha(data);
  
  if(validaData(data) == 0){
    printf("\nData inválida!\n");
  }else if(validaData(data) == 1){
    printf("\nA data informada é válida!\n");
  }
}*/