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
    double cpf;
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
            if(d<=0 && d>30 && a<0){
                return 0;
            }else{
                return 1;
            }
        }else{
            if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
                if(d<=0 && d>31 && a<0){
                    return 0;
                }else{
                    return 1;
                }
            }
        }
    }
}

int validarCPF(double CPF){
    if(CPF>99999999999 || CPF <0){
        return 0;
    }else{
        return 1;
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
            printf("Informe o CPF do cliente (Apenas números. Caso comece com 0, ignore-o): ");
            scanf("%lf", &cadastro.cpf);
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
        printf("\n\nNome do cliente: %s", cadastro.nome);
        printf("Data de nascimento do cliente: %d/%d/%d.\n", cadastro.dataNascimento.dia, cadastro.dataNascimento.mes, cadastro.dataNascimento.ano);
        printf("CPF do cliente: %.0lf.\n", cadastro.cpf);
        printf("Sexo do cliente: %c.\n", cadastro.sexo);
    }
    return 0;
}
