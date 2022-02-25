#include<stdio.h>
#include<stdlib.h>

typedef struct reg_no
{
    int dado;
    struct reg_no *proximo;
} tipo_no;

typedef struct reg_pilha
{
    struct reg_no *topo;
} tipo_pilha;


tipo_pilha* criar_pilha()
{
    tipo_pilha *pilha;
    pilha = (tipo_pilha*) malloc(sizeof(tipo_pilha));
    pilha->topo = NULL;
    return pilha;
}

int pilha_vazia(tipo_pilha *pilha)
{
    if (pilha->topo == NULL)
    {
        return 1;
    }
    return 0;
}

void incluir_no_topo(tipo_pilha *pilha, int numero)
{
    tipo_no *novo;
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = numero;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

void listar(tipo_pilha *pilha)
{
    tipo_no *atual;
    atual = pilha->topo;
    printf("\n");
    while (atual != NULL)
    {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }
}

int retirar_do_topo(tipo_pilha *pilha)
{
    tipo_no *auxiliar = NULL;
    int dado;
    if (pilha->topo != NULL)
    {
        auxiliar = pilha->topo;
        pilha->topo = auxiliar->proximo; // ou pilha->topo->proximo;
        dado = auxiliar->dado;
        free(auxiliar);
        return dado;
    }

    return dado;
}

/*151. Desenvolva um algoritmo para testar se duas pilhas P1 e P2 são iguais.
Duas pilhas são guais se possuem os mesmos elementos, na mesma ordem.
Sua função deverá retornar 1 para p1 == p2 e 0 para p1 != p2.*/
int ComparaPilha(tipo_pilha *pilha1, tipo_pilha *pilha2){
  int valor1, valor2;

  while (pilha1->topo != NULL && pilha2->topo != NULL){
    valor1 = retirar_do_topo(pilha1);
    valor2 = retirar_do_topo(pilha2);

    if (valor1 != valor2) return 0;
  }

  /*Caso algumas das duas não esteja vazia no final do while,
  significa que uma é maior que outra, logo, são diferentes.*/
  if (pilha1->topo != NULL || pilha2->topo != NULL) return 0;

  return 1;
}
