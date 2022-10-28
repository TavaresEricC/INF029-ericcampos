#include <stdio.h>
#include "funcuti.h"
#define tam 15
#define str 31
#define dtn 11
#define mat 13
#define cp 12
#define sem 7
#define cod 9

typedef struct{
  char nome[str], curso[str], sexo, nasc[dtn], semestre[sem], matricula[mat], cpf[cp];
}pessoa;

typedef struct{
  char nome[str], codigo[cod], semestre[sem], professor[str];
}disciplina;

