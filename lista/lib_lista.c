#include<stdio.h>
#include<stdlib.h>

typedef struct reg_no
{
    int dado;
    struct reg_no *proximo;
} tipo_no;

typedef struct reg_lista
{
    struct reg_no *inicio;
} tipo_lista;


tipo_lista* criar_lista()
{
    tipo_lista *lista;
    lista = (tipo_lista*) malloc(sizeof(tipo_lista));
    lista->inicio = NULL;
    return lista;
}

int lista_vazia(tipo_lista *lista)
{
    if (lista->inicio == NULL)
    {
        return 1;
    }
    return 0;
}

void incluir_no_inicio(tipo_lista *lista, int numero)
{
    tipo_no *novo;
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = numero;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

void incluir_no_fim(tipo_lista *lista, int numero)
{
    tipo_no *novo, *atual;
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = numero;
    novo->proximo = NULL;
    if (lista_vazia(lista))
    {
        lista->inicio = novo;
    }
    else
    {
        atual = lista->inicio;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void listar(tipo_lista *lista)
{
    tipo_no *atual;
    atual = lista->inicio;
    printf("\n");
    while (atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
}

void excluir_do_inicio(tipo_lista *lista)
{
    tipo_no *auxiliar = NULL;
    if (lista->inicio != NULL)
    {
        auxiliar = lista->inicio;
        lista->inicio = auxiliar->proximo; // ou lista->inicio->proximo;
        free(auxiliar);
    }
}

tipo_lista* excluir_lista(tipo_lista *lista)
{
    while (!lista_vazia(lista))
    {
        excluir_do_inicio(lista);
        listar(lista);
        printf("\n\n");
    }
    free(lista);
    return NULL;
}

int excluir_do_fim(tipo_lista *lista){
    tipo_no *atual = lista->inicio, *anterior = NULL;
    if(lista_vazia(lista)) return 1;
    if(atual->proximo==NULL){
        free(atual);
        lista->inicio = NULL;
        return 0;
    }
    while(atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }
    free(atual);
    anterior->proximo = NULL;
    return 0;
}

int incluir_ordenado(tipo_lista *lista, int numero)
{
    tipo_no *atual = lista->inicio, *novo = NULL,*anterior=NULL;
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = numero;
    if(lista_vazia(lista))
    {
        novo->proximo = NULL;
        lista->inicio = novo;
        return 0;
    }
    while((atual!=NULL)  &&  (novo->dado > atual->dado)){
        anterior = atual;
        atual = atual-> proximo;
    }
    if(anterior != NULL){
        anterior-> proximo = novo;
    }
    else{
        lista->inicio = novo;
    }
    novo-> proximo = atual;
    return 0;
}

int excluir_especifico(tipo_lista *lista, int numero)
{
    tipo_no *atual = lista->inicio, *anterior = NULL;

    if(lista_vazia(lista)) return 1;

    while((atual!=NULL) && (numero!=atual->dado))
    {
        anterior = atual;
        atual = atual-> proximo;
    }
    if (anterior==NULL)
    {
        lista->inicio = atual->proximo;
        free(atual);
        return  0;
    }
    if(atual != NULL)
    {
        anterior->proximo = atual->proximo;
        free(atual);
        return 0;
    }
    return 1;
}

int tamanho_lista(tipo_lista *lista){
    int contador_da_lista = 0;
    tipo_no* atual;

    atual = lista -> inicio;

    while (atual != NULL){
        contador_da_lista++;
        atual = atual -> proximo;
    }
    return contador_da_lista;

}

float media_aritmetica(tipo_lista *lista){
    int contador_da_lista = 0;
    float resultado = 0;
    tipo_no* atual;

    atual = lista -> inicio;

    while (atual != NULL){
        contador_da_lista++;
        resultado += atual -> dado;
        atual = atual -> proximo;
    }
    resultado = resultado/contador_da_lista;
    return resultado;
}

int desalocar_nos(tipo_lista *lista){
    tipo_no *auxiliar = NULL;
    while(!lista_vazia(lista)){
        auxiliar = lista->inicio;
        lista->inicio = auxiliar->proximo; // ou lista->inicio->proximo;
        free(auxiliar);
    }
    return 0;
}

/*137. A profundidade de uma c??lula c em uma lista encadeada ?? o n??mero de
passos do ??nico caminho que vai da primeira c??lula da lista at?? c. Escreva uma
fun????o que calcule a profundidade de uma dada c??lula.*/
int Profundidade(tipo_lista *lista, int posicao){
  tipo_no *atual = lista->inicio;
  int profundidade = 0;

  if (lista_vazia(lista)) return 0;

  while (atual != NULL){
    if (posicao == profundidade){
      return profundidade;
    }
    profundidade++;
    atual = atual->proximo;
  }

  return 0;
}

/*138. Escreva uma fun????o que verifique se uma lista encadeada que cont??m
n??meros inteiros est?? em ordem crescente.*/
int VerificarOrdemCrescente (tipo_lista *lista){
  tipo_no *atual = NULL, *anterior = NULL;
  int aux;

  if (lista_vazia(lista))  return 0;

  atual = lista->inicio;

  while (atual->proximo != NULL){
    anterior = atual;
    atual = atual->proximo;

    /*caso o valor atual seja menor que o anterior,
      a lista n??o est?? em ordem crescente*/
    if (atual->dado < anterior->dado){
      return 0;
    }
  }

  return 1;
}

/*139. Dada uma lista encadeada de n??meros inteiros cujo tipo que representa um
n?? da lista ?? dado por:
struct lista
{
int info;
struct lista *prox;
};
typedef struct lista Lista;
Implemente uma fun????o que receba uma lista encadeada do tipo Lista e retorne um
vetor de n??meros inteiros, alocado dinamicamente, contendo as informa????es
presentes na
mesma ordem que na lista, e o n??mero de elementos neste vetor.
Se a lista for vazia, o vetor retornado dever?? ser NULO ( NULL ) e o n??mero de
elementos igual a 0.
O prot??tipo da fun????o ?? dado por: int* Copia_Lista(Lista* L, int* n);*/
int* Copia_Lista(tipo_lista* lista, int *numero){
  tipo_no *atual = NULL;
  int *vetor;

  *numero = 0;

  if (lista_vazia(lista)) return NULL;

  atual = lista->inicio;

  while (atual != NULL){
    atual = atual->proximo;
    *numero += 1;
  }
  vetor = (int*) malloc(*numero * (sizeof(int)));
  atual = lista->inicio;
  for (int i = 0; i < *numero; i++){
    vetor[i] = atual->dado;
    atual = atual->proximo;
  }

  return vetor;
}

/*140. Escreva uma fun????o que fa??a uma busca em uma lista encadeada
crescente e retorne o endere??o da estrutura encontrada.*/
tipo_no* ProcuraEstrutura(tipo_lista *lista, int posicao){
  tipo_no *atual = lista->inicio;
  int count = 0;

  if (lista_vazia(lista)) return NULL;

  while (atual != NULL){
    if (count == posicao){
      return atual;
    }
    count++;
    atual = atual->proximo;
  }

  return NULL;
}

/*141. Escreva uma fun????o que encontre uma c??lula com conte??do m??nimo em
uma lista encadeada.*/
tipo_no* ProcuraMinimo(tipo_lista *lista){
  tipo_no *atual = lista->inicio, *menor = NULL;

  if (lista_vazia(lista)) return NULL;

  menor = atual;
  while (atual != NULL){
    if (menor->dado > atual->dado){
      menor = atual;
    }
    atual = atual->proximo;
  }

  return menor;
}

/*142. Escreva uma fun????o que verifique se duas listas encadeadas s??o iguais, ou
melhor, se t??m o mesmo conte??do.*/
int CompararListas(tipo_lista *lista1, tipo_lista *lista2){
  tipo_no *atual1 = lista1->inicio, *atual2 = lista2->inicio;

  //Se as duas listas forem vazias, s??o iguais, caso apenas uma seja, s??o diferentes.
  if (lista_vazia(lista1) && lista_vazia(lista2)) return 1;
  if (lista_vazia(lista1) && !lista_vazia(lista2)) return 0;
  if (!lista_vazia(lista1) && lista_vazia(lista2)) return 0;

  while (atual1 != NULL && atual2 != NULL){
    if (atual1->dado != atual2->dado){
      return 0;
    }
    if (atual1 == NULL) return 0;
    if (atual2 == NULL) return 0;

    atual1 = atual1->proximo;
    atual2 = atual2->proximo;
  }

  return 1;
}

/*143. Escreva uma fun????o que fa??a uma c??pia de uma lista encadeada.*/
tipo_lista* ClonaLista(tipo_lista *lista){
  tipo_no *atual = lista->inicio, *novo = NULL, *anterior = NULL;
  tipo_lista *clone;

  clone = (tipo_lista*) malloc(sizeof(tipo_lista));

  if (lista_vazia(lista)){
    clone->inicio = NULL;
  }
  else{
    while (atual != NULL){
      novo = (tipo_no*) malloc(sizeof(tipo_no));
      novo->dado = atual->dado;
      //Se atual for inicio da lista, ent??o o novo n?? ?? o inicio do clone
      if (lista->inicio == atual){
        clone->inicio = novo;
      }
      else{
        anterior->proximo = novo;
      }
      if (atual->proximo == NULL){
        novo->proximo = NULL;
      }
      anterior = novo;
      atual = atual->proximo;
    }
  }

  return clone;
}

/*144. Escreva uma fun????o que concatene duas listas encadeadas (isto ??, "engate"
a segunda no fim da primeira).*/
int ConcatenaListas(tipo_lista *lista1, tipo_lista *lista2){
  tipo_no *atual = lista1->inicio;

  if (lista_vazia(lista1)) return 0;

  while (atual->proximo != NULL) {
    atual = atual->proximo;
  }

  atual->proximo = lista2->inicio;

  return 1;
}

/*145. Escreva uma fun????o que inverta a ordem das c??lulas de uma lista
encadeada (a primeira passa a ser a ??ltima, a segunda passa a ser a pen??ltima
etc.). Fa??a isso sem usar espa??o auxiliar, apenas alterando ponteiros.*/
int InverteLista(tipo_lista *lista){
  tipo_no *atual = lista->inicio, *anterior = NULL, *temporario = NULL;

  if (lista_vazia(lista)) return 0;

  temporario = atual->proximo;

  while (temporario != NULL){
    atual->proximo = anterior;
    anterior = atual;
    atual = temporario;
    temporario = temporario->proximo;
  }

  atual->proximo = anterior;
  lista->inicio = atual;

  return 1;
}

/*146. Escreva uma fun????o para remover de uma lista encadeada todas as c??lulas
que cont??m o valor x.*/
int RemoverTodosEspecifico(tipo_lista *lista, int x){
  tipo_no *atual = lista->inicio, *anterior = NULL, *aux = NULL;

  if (lista_vazia(lista)) return 0;

  while (atual != NULL){
    if (atual->dado == x){
      if (atual == lista->inicio){
        lista->inicio = atual->proximo;
      }
      else{
        anterior->proximo = atual->proximo;
      }
      aux = atual;
      atual = atual->proximo;
      free(aux);
    }
    else{
      anterior = atual;
      atual = atual->proximo;
    }
  }

  return 1;
}

/*147. Escreva uma fun????o que remova a k-??sima c??lula de uma lista encadeada.*/
int RemoverPorPosicao(tipo_lista *lista, int posicao){
  int count = 1;
  tipo_no *atual = lista->inicio, *anterior = NULL;

  if (lista_vazia(lista)) return 0;

  while (atual != NULL){
    if (count == posicao){
      if (atual == lista->inicio){
        lista->inicio = atual->proximo;
        free(atual);
        return 1;
      }
      anterior->proximo = atual->proximo;
      free(atual);
      return 1;
    }
    count++;
    anterior = atual;
    atual = atual->proximo;
  }

  return 0;
}

/*148. Escreva uma fun????o que tenha como par??metros ponteiros para duas listas.
A fun????o deve retornar um ponteiro para uma terceira lista, que ?? o resultado da
uni??o das duas (isto ??, os elementos repetidos devem ser considerados apenas
uma vez).*/
tipo_lista *UnirListas(tipo_lista *lista1, tipo_lista *lista2){
  tipo_lista *lista3, *lista_aux;
  tipo_no *atual1 = NULL, *atual2 = NULL, *aux = NULL, *anterior = NULL;
  int dado, esta_na_lista;

  lista3 = (tipo_lista*) malloc(sizeof(tipo_lista));
  lista_aux = (tipo_lista*) malloc(sizeof(tipo_lista));

  lista3 = ClonaLista(lista1);
  lista_aux = ClonaLista(lista2);

  //Caso os dois clones de lista estejam vazios sera retornado uma lista vazia.
  if (lista_vazia(lista3))  return lista_aux;
  if (lista_vazia(lista_aux))  return lista3;

  atual2 = lista_aux->inicio;

  while (atual2 != NULL){
    dado = atual2->dado;
    esta_na_lista = 0;

    atual1 = lista3->inicio;
    while (atual1 != NULL){
      anterior = atual1;
      if (atual1->dado == atual2->dado){
        //Destruir valores que j?? est??o na lista
        esta_na_lista = 1;
        break;
      }
      atual1 = atual1->proximo;
    }

    if (!esta_na_lista){
      anterior->proximo = atual2;
      atual2->proximo = NULL;
    }
    atual2 = atual2->proximo;
  }
  free(lista_aux);
  return lista3;
}
