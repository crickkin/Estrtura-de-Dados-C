/*155. Se um fila representada por arranjos (vetores) não é considerada circular,
sugere-se que cada operação Desenfileira deve deslocar para “frente” todo
elemento restante de uma fila. Um método alternativo é adiar o deslocamento até

que “tras” seja igual ao último índice do vetor. Quando essa situação ocorre e faz-
se uma tentativa de inserir um elemento na fila, a fila inteira é deslocada para

“frente”, de modo que o primeiro elemento da fila fique na primeira posição do
vetor, ou posição 0, caso a implementação seja em C. Escreva as funções

Desenfileira, Enfileira e Vazia usando esse novo método.*/
#include<stdio.h>
#include<stdlib.h>

typedef struct reg_fila
{
    int *dado;
    int inicio, fim, tamanho;
} tipo_fila;


tipo_fila* criar_fila(int tamanho)
{
    tipo_fila *fila;
    fila = (tipo_fila*) malloc(sizeof(tipo_fila));
    fila->dado = (int*) malloc(tamanho * sizeof(int));
    fila->tamanho = tamanho;
    fila->inicio = 0;
    fila->fim = 0;

    return fila;
}

int fila_vazia(tipo_fila *fila)
{
    if (fila->fim == 0 || fila->inicio == fila->fim)
    {
        return 1;
    }
    return 0;
}

void listar(tipo_fila *fila)
{
    int i = fila->inicio;

    printf("\n");
    while (i < fila->fim)
    {
        printf("%d ", fila->dado[i]);
        i ++;
    }
}

int incluir_no_fim(tipo_fila *fila, int numero)
{
  int i;

  if (fila->fim < fila->tamanho){
    fila->dado[fila->fim] = numero;
    fila->fim ++;
    return 1;
  }
  if (fila->inicio != 0){
    for(i=0; fila->inicio < fila->tamanho; i++){
      fila->dado[i] = fila->dado[fila->inicio];
      fila->inicio++;
    }
    fila->inicio = 0;
    fila->fim = i;
    fila->dado[fila->fim] = numero;
    fila->fim ++;

    return 1;
  }

  return 0;
}

int retirar_do_inicio(tipo_fila *fila)
{
    int dado;

    if (fila_vazia(fila)) return 0;

    dado = fila->dado[fila->inicio];
    fila->inicio ++;

    return dado;
}
