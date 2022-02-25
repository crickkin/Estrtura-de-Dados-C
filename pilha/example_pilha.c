#include<stdio.h>
#include"lib_pilha.h"

int main()
{
    tipo_pilha *pilha, *pilha1, *pilha2;
    int opcao, numero, valor, utilizada = 1, i;
    char string[20];

    pilha1 = criar_pilha();
    pilha2 = criar_pilha();

    pilha = pilha1;
    do
    {
        printf("\n\n0 - Sair\n");
        printf("1 - Empilhar\n");
        printf("2 - Exibir dados\n");
        printf("3 - Desempilhar\n");
        printf("4 - Trocar Pilha\n");
        printf("151 - Compara Pilhas\n");
        if (utilizada == 1) printf("\n***Pilha 1***\n");
        else                printf("\n***Pilha 2***\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1: printf("Entre com um número:");
                    scanf("%d", &numero);
                    incluir_no_topo(pilha, numero);
                    break;
            case 2: if (pilha_vazia(pilha))
                    {
                        printf("pilha vazia!\n");
                    }
                    else
                    {
                        listar_pilha(pilha);
                    }
                    break;
            case 3: if (!pilha_vazia(pilha))
                    {
                        valor = retirar_do_topo(pilha);
                    }
                    else
                    {
                      printf("pilha vazia!\n");
                    }
                    break;
            case 4: if (utilizada == 1){
                      pilha = pilha2;
                      utilizada = 2;
                    }
                    else{
                      pilha = pilha1;
                      utilizada = 1;
                    }
            case 151: if (ComparaPilha(pilha1, pilha2)){
                        printf("\nAs pilhas sao iguais!\n");
                      }
                      else {
                        printf("\nAs pilhas sao diferentes!");
                      }
                      break;
        }
    }
    while(opcao != 0);
    return 0;
}
