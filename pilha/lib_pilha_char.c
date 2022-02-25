/*152. Faça um programa para inverter a ordem dos elementos existentes em uma
string de tamanho máximo 20. Utilize, obrigatoriamente, uma pilha como memória
temporária para armazenar a string. Imprima a string após a inversão.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct reg_no
{
    char dado;
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

void incluir_no_topo(tipo_pilha *pilha, char letra)
{
    tipo_no *novo;
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = letra;
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
        printf("%c\n", atual->dado);
        atual = atual->proximo;
    }
}

char retirar_do_topo(tipo_pilha *pilha)
{
    tipo_no *auxiliar = NULL;
    char dado;
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

void InverteString(tipo_pilha *pilha, char *string){
  int tamanho = strlen(string), i;
  tipo_no *novo = NULL, *atual = pilha->topo;

  while (!pilha_vazia(pilha)){
    retirar_do_topo(pilha);
  }

  for (i = 0; i < tamanho; i++){
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = string[i];
    novo->proximo = pilha->topo;
    pilha->topo = novo;
  }
  atual = pilha->topo;
  for (int i = 0; i < tamanho; i++){
    string[i] = retirar_do_topo(pilha);
  }
}

/*153. Construa um programa, que use a estrutura pilha e verifique se o número de
abre parênteses é igual ao número de fecha parênteses em uma expressão
matemática.*/
int VerificarParenteses(tipo_pilha *pilha, char *string){
  int count = 0, tamanho = strlen(string);

  while (!pilha_vazia(pilha)){
    retirar_do_topo(pilha);
  }

  for (int i=0; i < tamanho; i++){
    if (string[i] == '('){
      count ++;
    }
    else if (string[i] == ')'){
      count --;
    }
  }

  //Caso count seja 0, o numero de parenteses é igual
  if (count == 0) return 1;

  return 0;
}
