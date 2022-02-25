#include<stdio.h>
#include"lib_pilha_char.h"

int main()
{
    tipo_pilha *pilha, *pilha1, *pilha2;
    int opcao, valor, utilizada = 1, i, numero;
    char string[20], letra;

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
        printf("152 - Inverte String\n");
        printf("153 - Confere Parenteses\n");
        if (utilizada == 1) printf("\n***Pilha 1***\n");
        else                printf("\n***Pilha 2***\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1: printf("Entre com uma letra: ");
                    fflush(stdin);
                    scanf("%c", &letra);
                    incluir_no_topo(pilha, letra);
                    break;
            case 2: if (pilha_vazia(pilha))
                    {
                        printf("pilha vazia!\n");
                    }
                    else
                    {
                        listar(pilha);
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
            case 152: printf("Insira uma string de ate 20 caracteres: ");
                      fflush(stdin);
                      scanf("%s", string);
                      InverteString(pilha, string);
                      printf("\n\t%s\n", string);
                      break;
            case 153: printf("Digite uma frase com parenteses: ");
                      scanf("%s", string);
                      if(VerificarParenteses(pilha, string)){
                        printf("\nQuantidade de abre e fecha parenteses igual\n");
                      }
                      else{
                        printf("\nO numero de abre e fecha parenteses esta errado\n");
                      }
                      break;
        }
    }
    while(opcao != 0);
    return 0;
}
