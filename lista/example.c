/*138. Escreva uma função que verifique se uma lista encadeada que contém
números inteiros está em ordem crescente.*/
#include <stdio.h>
#include "lib_lista.h"

int main()
{
    tipo_lista *lista, *lista1, *lista2, *clone, *uniao;
    tipo_no *procurado;
    int opcao, numero, *vetor, tamanho, lista_utilizada = 1;

    lista1 = criar_lista();
    lista2 = criar_lista();

    lista = lista1;
    do
    {
        printf("\n\n0 - Sair\n");
        printf("1 - Incluir dado no início\n");
        printf("2 - Exibir dados\n");
        printf("3 - Excluir dado\n");
        printf("4 - Incluir dado no fim\n");
        printf("5 - Excluir do fim\n");
        printf("6 - Incluir ordenado\n");
        printf("7 - Excluir dado específico\n");
        printf("8 - Tamanho da lista\n");
        printf("9 - Média aritmética dos elementos da lista\n");
        printf("10 - Desalocar todos os nós da lista encadeada\n");
        printf("11 - Trocar Lista\n");
        printf("12 - Listar Clone\n");
        printf("137 - Verificar Profundidade\n");
        printf("138 - Verificar se a lista está em ordem crescente\n");
        printf("139 - Clonar lista para vetor\n");
        printf("140 - Procurar Estrutura\n");
        printf("141 - Procura Celula Minima\n");
        printf("142 - Compara Listas\n");
        printf("143 - Clona lista\n");
        printf("144 - Concatena Listas\n");
        printf("145 - Inverte Lista\n");
        printf("146 - Deletar Todos Especifico\n");
        printf("147 - Deletar por Posicao\n");
        printf("148 - Uniao das Listas\n");
        if (lista_utilizada == 1) printf("\nVoce esta utilizando a lista 1\n\n");
        else                      printf("\nVoce esta utilizando a lista 2\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1: printf("Entre com um número:");
                    scanf("%d", &numero);
                    incluir_no_inicio(lista, numero);
                    break;
            case 2: if (lista_vazia(lista))
                    {
                        printf("Lista vazia!\n");
                    }
                    else
                    {
                        listar(lista);
                    }
                    break;
            case 3: if (lista_vazia(lista))
                    {
                        printf("Lista vazia!\n");
                    }
                    else
                    {
                        excluir_do_inicio(lista);
                    }
                    break;
            case 4: printf("Entre com um número:");
                    scanf("%d", &numero);
                    incluir_no_fim(lista, numero);
                    break;
            case 5: excluir_do_fim(lista);
                    break;
            case 6: printf("Entre com um número:");
                    scanf("%d", &numero);
                    incluir_ordenado(lista, numero);
                    break;
            case 7: printf("Entre com um número:");
                    scanf("%d", &numero);
                    excluir_especifico(lista, numero);
                    break;
            case 8: printf("\nA lista tem %d elementos.\n", tamanho_lista(lista));
                    break;
            case 9: printf("\nA media aritmetica e: %.2f",media_aritmetica(lista));
                    break;
            case 10:desalocar_nos(lista);
                    break;
            case 11:  if (lista_utilizada == 1){
                        lista = lista2;
                        lista_utilizada = 2;
                      }
                      else{
                        lista = lista1;
                        lista_utilizada = 1;
                      }
                      printf("\nLista trocada com sucesso!\n");
                      break;
            case 137: printf("\nInforme a posicao que deseja verificar: ");
                      scanf("%d", &numero);
                      printf("\n\nA profundidade e %d", Profundidade(lista, numero));
                      break;
            case 138: if (VerificarOrdemCrescente(lista)){
                        printf("A lista esta em ordem crescente.");
                      }
                      else{
                        printf("A lista nao esta em ordem crescente.");
                      }
                      break;
            case 139: vetor = Copia_Lista(lista, &tamanho);
                      printf("Tamanho da lista = %d\nVetor:\t", tamanho);
                      for (int i=0; i < tamanho; i++){
                        printf("[%d] ", *(vetor + i));
                      }
                      break;
            case 140: printf("Informe a posicao desejada: ");
                      scanf("%d", &numero);
                      procurado = ProcuraEstrutura(lista, numero);
                      if (procurado != NULL) printf("endereco : %p", procurado);
                      break;
            case 141: procurado = ProcuraMinimo(lista);
                      if (procurado != NULL) printf("menor valor na posicao: %p", procurado);
                      break;
            case 142: if (CompararListas(lista1, lista2)){
                        printf("As listas sao iguais");
                      }
                      else{
                        printf("As listas sao diferentes");
                      }
                      break;
            case 143: do {
                        printf("Escolha a lista que sera clonada\n");
                        scanf("%d", &numero);
                        if (numero != 1 && numero != 2){
                          printf("\n---ERRO---\nInsira um numero valido\n\n");
                        }
                      }while (numero != 1 && numero != 2);
                      clone = excluir_lista(clone);
                      if (numero == 1){
                        clone = ClonaLista(lista1);
                      }
                      else{
                        clone = ClonaLista(lista2);
                      }
                      break;
            case 12:  if(!lista_vazia(clone)){
                        listar(clone);
                      }
                      else{
                        printf("Nao existe clone");
                      }
                      break;
            case 144: if(!lista_vazia(lista1) && !lista_vazia(lista2)){
                        ConcatenaListas(lista1, lista2);
                      }
                      break;
            case 145: InverteLista(lista);
                      break;
            case 146: printf("Insira o valor que deseja eliminar da lista:\n");
                      scanf("%d", &numero);
                      if (RemoverTodosEspecifico(lista, numero)){
                        printf("Valor inserido com sucesso!\n\n");
                      }
                      break;
            case 147: printf("Insira a posicao da celula:\n");
                      scanf("%d", &numero);
                      if (RemoverPorPosicao(lista, numero)){
                        printf("Celula removida com sucesso!\n\n");
                      }
                      else{
                        printf("Celula nao encontrada");
                      }
                      break;
            case 148: uniao = UnirListas(lista1, lista2);
                      printf("\nUniao das Listas:\n");
                      listar(uniao);
                      break;
        }
    }
    while(opcao != 0);

    return 0;
}
