#include<stdio.h>
#include<stdlib.h>

typedef struct reg_no
{
    int dado;
    struct reg_no *proximo;
} tipo_no;

typedef struct reg_fila
{
    struct reg_no *inicio;
} tipo_fila;


tipo_fila* criar_fila()
{
    tipo_fila *fila;
    fila = (tipo_fila*) malloc(sizeof(tipo_fila));
    fila->inicio = NULL;
    return fila;
}

int fila_vazia(tipo_fila *fila)
{
    if (fila->inicio == NULL)
    {
        return 1;
    }
    return 0;
}

void listar(tipo_fila *fila)
{
    tipo_no *atual;
    atual = fila->inicio;
    printf("\n");
    while (atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
}

void incluir_no_fim(tipo_fila *fila, int numero)
{
  tipo_no *novo, *atual;
  novo = (tipo_no*) malloc(sizeof(tipo_no));
  novo->dado = numero;
  novo->proximo = NULL;
  if (fila_vazia(fila))
  {
    fila->inicio = novo;
  }
  else
  {
    atual = fila->inicio;
    while (atual->proximo != NULL)
    {
      atual = atual->proximo;
    }
    atual->proximo = novo;
  }
}

int retirar_do_inicio(tipo_fila *fila)
{
    int dado;

    tipo_no *auxiliar = NULL;
    if (fila->inicio != NULL)
    {
        auxiliar = fila->inicio;
        fila->inicio = auxiliar->proximo; // ou fila->inicio->proximo;
        dado = auxiliar->dado;
        free(auxiliar);
    }

    return dado;
}

int tamanho_fila(tipo_fila *fila){
    int contador_da_fila = 0;
    tipo_no* atual;

    atual = fila->inicio;

    while (atual != NULL){
        contador_da_fila++;
        atual = atual -> proximo;
    }
    return contador_da_fila;
}

/*157. Implemente uma função que receba três filas, f, impares e pares (todas já
inicializadas), e separe todos os valores guardados em f de tal forma que os
valores pares são colocados na fila pares e os valores ímpares na impares. Ao final
da execução desta função, f permanecerá com todos os seus elementos. O
protótipo desta função é o seguinte: void separa_filas(TFila* f, TFila* par,TFila*
impar).*/
void SeparaFilas (tipo_fila *fila, tipo_fila *par, tipo_fila *impar){
  tipo_no *atual = fila->inicio, *no_par = NULL, *no_impar = NULL, *novo = NULL;

  while (atual != NULL){
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = atual->dado;
    novo->proximo = NULL;
    //Incluindo na fila par
    if (novo->dado % 2 == 0){
      if (fila_vazia(par)){
        par->inicio = novo;
      }
      else{
        no_par = par->inicio;
        while (no_par->proximo != NULL)
        {
          no_par = no_par->proximo;
        }
        no_par->proximo = novo;
      }
    }
    //Incluindo na fila impar
    else {
      if (fila_vazia(par)){
        impar->inicio = novo;
      }
      else{
        no_impar = impar->inicio;
        while (no_impar->proximo != NULL)
        {
          no_impar = no_impar->proximo;
        }
        no_impar->proximo = novo;
      }
    }
    atual = atual->proximo;
  }
}
