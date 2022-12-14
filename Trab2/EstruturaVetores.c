#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

void quicksort(int number[],int first,int last){
	int i, j, pivot, temp;

	if(first<last){
		pivot=first;
		i=first;
		j=last;

		while(i<j){
			while(number[i]<=number[pivot]&&i<last){
				i++;
			}
			while(number[j]>number[pivot]){
				j--;
			}

			if(i<j){
				temp=number[i];
				number[i]=number[j];
				number[j]=temp;
			}
		}
		
		temp=number[pivot];
		number[pivot]=number[j];
		number[j]=temp;

		quicksort(number,first,j-1);
		quicksort(number,j+1,last);
	}
}


int validaposicao(int num){
  if(num<1 || num>10){
    return POSICAO_INVALIDA;
  }else{
    return SUCESSO;
  }
}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    
    if(validaposicao(posicao) == POSICAO_INVALIDA){       
      // se posição é um valor válido {entre 1 e 10}       
      return  POSICAO_INVALIDA;     
    }else if(tamanho <=0){
        // o tamanho deve ser maior ou igual a 1
        return  TAMANHO_INVALIDO;      
    }
      posicao --;
  
    if(vetorPrincipal[posicao].estrutaux){
      // a posicao pode já existir estrutura auxiliar
      return  JA_TEM_ESTRUTURA_AUXILIAR;
    }else 
      vetorPrincipal[posicao].estrutaux = calloc(tamanho, sizeof(int));
      
     if(vetorPrincipal[posicao].estrutaux == NULL){
      // o tamanho ser muito grande
      return  SEM_ESPACO_DE_MEMORIA;
    }else{
      // criar estrutura auxiliar
      vetorPrincipal[posicao].tamanho = tamanho;
      vetorPrincipal[posicao].posicoes = 0;
      return  SUCESSO;
    }

    
} 

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    int tamEstruturaAuxiliar = vetorPrincipal[posicao-1].tamanho;
    vetorPrincipal[posicao].posicoes = 0;
    //printf("\t%d\n", tamEstruturaAuxiliar);
    
    if(validaposicao(posicao) == POSICAO_INVALIDA){
      // se posição é um valor válido {entre 1 e 10}
     
      posicao_invalida = 1;
    }
    if(posicao_invalida){
      return  POSICAO_INVALIDA;
    }else 
      posicao--;
      if(vetorPrincipal[posicao].estrutaux){
      // a posicao pode já existir estrutura auxiliar
      existeEstruturaAuxiliar = 1;
    }
    
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar)
        {
          
          if(vetorPrincipal[posicao].posicoes < vetorPrincipal[posicao].tamanho){
            temEspaco = 1;
          }
            if (temEspaco)
            {
                vetorPrincipal[posicao].estrutaux[vetorPrincipal[posicao].posicoes] = valor;
                vetorPrincipal[posicao].posicoes++;
                //insere
                retorno = SUCESSO;
            }
            else
            {
                return  SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  if(validaposicao(posicao) == POSICAO_INVALIDA){       
    // se posição é um valor válido {entre 1 e 10}       
    return  POSICAO_INVALIDA;     
  }

  posicao--;
  if(!vetorPrincipal[posicao].estrutaux){
		return SEM_ESTRUTURA_AUXILIAR;
	}

  if(vetorPrincipal[posicao].posicoes == 0){
		return ESTRUTURA_AUXILIAR_VAZIA;
	}

  vetorPrincipal[posicao].posicoes--;
  
  int retorno = SUCESSO;
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  if(validaposicao(posicao) == POSICAO_INVALIDA){
    // se posição é um valor válido {entre 1 e 10}       
    return  POSICAO_INVALIDA;     
  }else{
    posicao--;
  }
  if(!vetorPrincipal[posicao].estrutaux){
		return SEM_ESTRUTURA_AUXILIAR;
	}else if(vetorPrincipal[posicao].posicoes == 0){
		return ESTRUTURA_AUXILIAR_VAZIA;
	}else

  for(int i = 0; i < vetorPrincipal[posicao].posicoes; i++){
    if(vetorPrincipal[posicao].estrutaux[i] == valor){
      for(int j = i; j < vetorPrincipal[posicao].posicoes-1; j++){
        vetorPrincipal[posicao].estrutaux[j] = vetorPrincipal[posicao].estrutaux[j+1];
      }
      vetorPrincipal[posicao].posicoes--;
      return SUCESSO;
    }
    return NUMERO_INEXISTENTE;
  }
  
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  if(validaposicao(posicao) == POSICAO_INVALIDA){
    // se posição é um valor válido {entre 1 e 10}       
    return  POSICAO_INVALIDA;     
  }else{
    posicao--;
  }
  if(!vetorPrincipal[posicao].estrutaux){
		return SEM_ESTRUTURA_AUXILIAR;
	}

  for(int i=0; i<vetorPrincipal[posicao].posicoes; i++){
    vetorAux[i] = vetorPrincipal[posicao].estrutaux[i];
  }
  int retorno = SUCESSO;
  return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  if(validaposicao(posicao) == POSICAO_INVALIDA){
    // se posição é um valor válido {entre 1 e 10}       
    return  POSICAO_INVALIDA;     
  }else{
    posicao--;
  }
  if(!vetorPrincipal[posicao].estrutaux){
		return SEM_ESTRUTURA_AUXILIAR;
	}

  for(int i=0; i<vetorPrincipal[posicao].posicoes; i++){
    vetorAux[i] = vetorPrincipal[posicao].estrutaux[i];
  }
  quicksort(vetorAux, 0, vetorPrincipal[posicao].tamanho-1);
  int retorno = SUCESSO;
  return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int cont=0, k=0;
  for(int i=0; i<TAM; i++){
    if(vetorPrincipal[i].posicoes == 0){
      cont++;
    }
  }
  if(cont == TAM){
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
    for(int i=0; i<TAM; i++){
      if(vetorPrincipal[i].posicoes != 0){
        for(int j = 0; j<vetorPrincipal[i].posicoes; j++, k++){
          vetorAux[k] = vetorPrincipal[i].estrutaux[j];
        }
      }
    }
 
  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int cont=0, k=0;
  for(int i=0; i<TAM; i++){
    if(vetorPrincipal[i].posicoes == 0){
      cont++;
    }
  }
  if(cont == TAM){
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
    for(int i=0; i<TAM; i++){
      if(vetorPrincipal[i].posicoes != 0){
        for(int j = 0; j<vetorPrincipal[i].posicoes; j++,k++){
          vetorAux[k] = vetorPrincipal[i].estrutaux[j];
        }
      }
    }
  quicksort(vetorAux, 0, k-1);
  int retorno = SUCESSO;
  return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
  if(validaposicao(posicao) == POSICAO_INVALIDA){
    // se posição é um valor válido {entre 1 e 10}       
    return  POSICAO_INVALIDA;     
  }else{
    posicao--;
  }
  if(vetorPrincipal[posicao].tamanho + novoTamanho < 1){
    return NOVO_TAMANHO_INVALIDO;
  }else if(!vetorPrincipal[posicao].estrutaux){
		return SEM_ESTRUTURA_AUXILIAR;
	}

  vetorPrincipal[posicao].estrutaux = realloc(vetorPrincipal[posicao].estrutaux, sizeof(int)*(vetorPrincipal[posicao].tamanho + novoTamanho));
  
  if(vetorPrincipal[posicao].estrutaux){
        vetorPrincipal[posicao].tamanho = vetorPrincipal[posicao].tamanho + novoTamanho;
        if(vetorPrincipal[posicao].posicoes > vetorPrincipal[posicao].tamanho){
            vetorPrincipal[posicao].posicoes = vetorPrincipal[posicao].tamanho;
        }
        return SUCESSO;
    }
    return SEM_ESPACO_DE_MEMORIA;
  
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
  int qtd;
  if(validaposicao(posicao) == POSICAO_INVALIDA){
    // se posição é um valor válido {entre 1 e 10}       
    return  POSICAO_INVALIDA;     
  }else{
    posicao--;
  }
  if(!vetorPrincipal[posicao].estrutaux){
		return SEM_ESTRUTURA_AUXILIAR;
	}else if(vetorPrincipal[posicao].posicoes == 0){
		return ESTRUTURA_AUXILIAR_VAZIA;
	}else
  qtd = vetorPrincipal[posicao].posicoes;
  return qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
  for(int i = 0; i<TAM; i++){
    vetorPrincipal[i].estrutaux = NULL;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
  for(int i =0; i<TAM; i++){
    free(vetorPrincipal[i].estrutaux);
  }
}


