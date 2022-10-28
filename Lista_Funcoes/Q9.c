/*Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada
validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente
deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado
com sucesso ou se houve erro, informando onde foi o erro:
•
 função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
•
 função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
masculino; f e F para feminino, o e O para outro).
•
 função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
•
 função validarNacimento: recebe o data digitada, e valida é uma data válida.
*/

#include <stdio.h>
#include <locale.h>

#define tam 21

typedef struct {
    int id;
    long int cpf;
    char nome[tam], sexo;
    struct{
        int dia, mes, ano;
    }dataNascimento;
}cliente;

int validarNome(char nome[tam]){
    int i=0;
    while(nome[i]!='\0'){
        i++;
    }
    if(i>20){
        return 0;
    }else{
        return 1;
    }
}

int validarNascimento(int d, int m, int a){
    setlocale(LC_ALL, "Portuguese");
    if(a>0){
      if(m==2){
      if((d==30 || d==31) && m==2){
        return 0;
      }
      if(d==29 && m==2 && (a%4==0 &&(a%400==0 || a&100!=0))){
        return 1;
      }else{
        return 0;
      }
    }else{
      if(m==4 || m==6 || m==9 || m==11){
        if(d<=0 || d>30 ){
          return 0;
        }else{
         return 1;
        }
      }else{
        if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
          if(d<=0 || d>31){
            return 0;
          }else{
            return 1;
          }
        }
      }
    }
    }
    
}

int validarCPF(long int CPF){
  int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, v1, v2, r1, r2;
  if(CPF < 10000000000){
    n1 = 0;
    n2 = CPF/1000000000;
    n3 = CPF%1000000000/100000000;
    n4 = CPF%100000000/10000000;
    n5 = CPF%10000000/1000000;
    n6 = CPF%1000000/100000;
    n7 = CPF%100000/10000;
    n8 = CPF%10000/1000;
    n9 = CPF%1000/100;
    n10 = CPF%100/10;
    n11 = CPF%10;

    v1 = (n1*10) + (n2*9) + (n3*8) + (n4*7) + (n5*6) + (n6*5) + (n7*4) + (n8*3) + (n9*2);
    
    v2 = (n1*11) + (n2*10) + (n3*9) + (n4*8) + (n5*7) + (n6*6) + (n7*5) + (n8*4) + (n9*3) + (n10*2);
    
    r1 = (v1*10)%11;
    r2 = (v2*10)%11;
    if(r1 == 10){
      r1 =0;
    }
    if(r2 == 10){
      r2 = 0;
    }

    if(r1 == n10 && r2 == n11){
      return 1;
    }else{
      return 0;
    }
  }else{
    n1 = CPF/10000000000;
    n2 = CPF%10000000000/1000000000;
    n3 = CPF%1000000000/100000000;
    n4 = CPF%100000000/10000000;
    n5 = CPF%10000000/1000000;
    n6 = CPF%1000000/100000;
    n7 = CPF%100000/10000;
    n8 = CPF%10000/1000;
    n9 = CPF%1000/100;
    n10 = CPF%100/10;
    n11 = CPF%10;

    v1 = (n1*10) + (n2*9) + (n3*8) + (n4*7) + (n5*6) + (n6*5) + (n7*4) + (n8*3) + (n9*2);
    
    v2 = (n1*11) + (n2*10) + (n3*9) + (n4*8) + (n5*7) + (n6*6) + (n7*5) + (n8*4) + (n9*3) + (n10*2);
    
    r1 = (v1*10)%11;
    r2 = (v2*10)%11;
    if(r1 == 10){
      r1 =0;
    }
    if(r2 == 10){
      r2 = 0;
    }

    if(r1 == n10 && r2 == n11){
      return 1;
    }else{
      return 0;
    }
  }
}

int validarSexo(char sex){
    char Validos[] = {'M', 'm', 'F', 'f', 'O', 'o'};
    int qtdVald = 6, i=0;

    for(i=0; i<qtdVald; i++){
        if(Validos[i] == sex){
            return 1;
        }
    }
    return 0;
}

cliente cadastrarCliente(){
    setlocale(LC_ALL, "Portuguese");
    cliente cadastro;
    cadastro.id = -1;
    printf("Informe o nome do cliente: ");
    fflush(stdin);
    fgets(cadastro.nome, 30, stdin);

    if(validarNome(cadastro.nome) == 0){
        return cadastro;
    }else{
        printf("Informe a data de nascimento:\n");
        printf("Informe o dia: ");
        scanf("%d", &cadastro.dataNascimento.dia);
        fflush(stdin);
        printf("Informe o mes: ");
        scanf("%d", &cadastro.dataNascimento.mes);
        fflush(stdin);
        printf("Informe o ano: ");
        scanf("%d", &cadastro.dataNascimento.ano);
        fflush(stdin);

        if(validarNascimento(cadastro.dataNascimento.dia, cadastro.dataNascimento.mes, cadastro.dataNascimento.ano) == 0){
            return cadastro;
        }else{
            printf("Informe o CPF do cliente (Apenas números.): ");
            scanf("%ld", &cadastro.cpf);
            fflush(stdin);

            if(validarCPF(cadastro.cpf) == 0){
                return cadastro;
            }else{
                printf("Informe o sexo do cliente (M ou m (Masculino), F ou f (Feminino), O ou o (Outro)): ");
                scanf(" %c", &cadastro.sexo);
                fflush(stdin);

                if(validarSexo(cadastro.sexo) == 0){
                    return cadastro;
                }else{
                    cadastro.id++;
                }
            }
        }
    }


    return cadastro;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    cliente cadastro;
    printf("\n\n--------------CADASTRO DE CLIENTES--------------\n\n");
    cadastro = cadastrarCliente();

    if(cadastro.id == -1){
        printf("\nErro no cadastro. Verifique os dados.\n");
    }else{
        printf("\nCliente cadastrado com sucesso!\n");
        printf("\nDados do cliente");
        printf("\n\nNome do cliente: %s.", cadastro.nome);
        printf("Data de nascimento do cliente: %d/%d/%d.\n", cadastro.dataNascimento.dia, cadastro.dataNascimento.mes, cadastro.dataNascimento.ano);
        if(cadastro.cpf < 10000000000){
        printf("CPF do cliente: %d%ld.\n", 0, cadastro.cpf);  
        }else{ 
        printf("CPF do cliente: %ld.\n", cadastro.cpf);  
        }
        printf("Sexo do cliente: %c.\n", cadastro.sexo);
    }
    return 0;
}