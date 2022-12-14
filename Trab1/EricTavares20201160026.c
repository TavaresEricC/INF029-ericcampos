// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Eric Campos Tavares 
//  email: tavaresericc@gmail.com
//  Matrícula: 20201160026
//  Semestre: 2022.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "EricTavares20201160026.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include "trab1.h"
#include <string.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */

int somar(int x, int y)
{
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int id = 1;
  //quebrar a string data em strings sDia, sMes, sAno

  DataQuebrada data1 = quebraData(data);
  
  if (data1.valido == 0){
    return 0;
  }
  id = validaData(data1.iDia, data1.iMes, data1.iAno);

  if(id == 1){
    return 1;
  }else{
    return 0;
  }
  

}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
    DataQuebrada datai = quebraData(datainicial);
    DataQuebrada dataf = quebraData(datafinal);

    if(datai.iAno > dataf.iAno){
      dma.retorno = 4;
      return dma;
    }else if(datai.iAno == dataf.iAno){
      if(datai.iMes > dataf.iMes){
        dma.retorno = 4;
        return dma;
      }else if(datai.iMes == dataf.iMes){
        if(datai.iDia > dataf.iDia){
          dma.retorno = 4;
          return dma;
        }
      }
    }
      //calcule a distancia entre as datas
    dma.qtdDias = 0;
    dma.qtdMeses = 0;
    dma.qtdAnos = 0;
    //contdia = datai.iDia, contmes = datai.iMes, contano = datai.iAno
    int virames = 0, contdia = datai.iDia, contmes = datai.iMes, contano = datai.iAno;
      
    while(datai.iDia!=dataf.iDia || datai.iMes!=dataf.iMes || datai.iAno!=dataf.iAno){
      datai.iDia++;
      dma.qtdDias++;
      if(datai.iMes == 2){
        if(datai.iAno % 4 == 0 && (datai.iAno % 100 != 0 || datai.iAno % 400 == 0)){
          if(datai.iDia > 29){
            virames = 1;
          }
        }else if(datai.iDia > 28){
          virames = 1;
        }
      }
      if(datai.iMes == 4 || datai.iMes == 6 || datai.iMes == 9 || datai.iMes == 11){
        if(datai.iDia > 30){
          virames = 1;
        }
      }else if(datai.iDia > 31){
        virames = 1;
      }
      if(virames == 1){
        datai.iDia = 1;
        dma.qtdDias = 0;
        dma.qtdMeses++;
        if(dma.qtdMeses == 12){
          dma.qtdMeses = 0;
          dma.qtdAnos++;
        }
        datai.iMes++;
        if(datai.iMes > 12){
        datai.iMes = 1;
        datai.iAno++;
        }
        virames = 0;
      }
      
    }
      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
  }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0, i;
    if(isCaseSensitive == 1){
      for(i=0; texto[i] != '\0'; i++){
        if(texto[i] == c){
          qtdOcorrencias++;
        }
      }
    }else{
      char copia[250];
      strcpy(copia, texto);
      viraminuscula(copia);
      if(c >= 65 && c <= 90){
        c = c+32;
      }

      
      for(i=0; copia[i]!='\0'; i++){
        if(copia[i] == c){
          qtdOcorrencias++;
        }
      }
    }
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int tambusca = strlen(strBusca), tamtexto = strlen(strTexto);
    int itexto, ibusca, iaux, cont;
	  int textoint[tamtexto], buscaint[tambusca]; 
	  tamtexto = viraint(strTexto, tamtexto, textoint);
	  tambusca = viraint(strBusca, tambusca, buscaint);


    for(itexto = 0, cont = 0; itexto < tamtexto; itexto++){
        if(textoint[itexto] == buscaint[0]){ 
            for(iaux = itexto, ibusca = 0; ibusca < tambusca; ibusca++, iaux++){ 
                if(textoint[iaux] != buscaint[ibusca]){
                    break;
                }
            }
            if(ibusca == tambusca){
                posicoes[cont] = itexto+1;
                posicoes[cont+1] = iaux;
                cont = cont + 2;
                itexto = iaux - 1;
                qtdOcorrencias++;
            }
        }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int inverso = 0;
  while(num>0){
    inverso = (inverso*10) + (num%10);
    num = num/10;
  }
  
  return inverso;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int i, n, aux, aux2, qtdOcorrencias = 0;

	while(numerobase>0){
		n = numerobase % 10;
		aux = numerobusca/10; 
		aux2 = numerobase/10; 
		for(i = 10; aux > 0; i *= 10, aux /= 10){ 
			n = n+(aux2 % 10)*i;
		}
		
		if(n == numerobusca){ 
			qtdOcorrencias++;
		}
		
		numerobase /= 10;
	}
    return qtdOcorrencias;
}