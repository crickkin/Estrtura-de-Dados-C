#include <stdio.h>
#include "lib_fila_array.h"

int main()
{
    tipo_fila *fila, *fila1, *fila2;
    int opcao, numero, fila_utilizada = 1;

    fila1 = criar_fila(10);
    fila2 = criar_fila(10);

    fila = fila1;
    do
    {
        printf("\n\n0 - Sair\n");
        printf("1 - Incluir dado\n");
        printf("2 - Exibir dados\n");
        printf("3 - retirar dado da fila\n");
        printf("4 - Trocar fila\n");
        if (fila_utilizada == 1) printf("\nVoce esta utilizando a fila 1\n\n");
        else                      printf("\nVoce esta utilizando a fila 2\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1: printf("Entre com um número:");
                    scanf("%d", &numero);
                    if (incluir_no_fim(fila, numero)){
                      printf("valor adicionado com sucesso!\n\n");
                    }
                    else{
                      printf("Fila cheia");
                    }
                    break;
            case 2: if (!fila_vazia(fila))
                    {
                      listar(fila);
                    }
                    else
                    {
                      printf("fila vazia!\n");
                    }
                    break;
            case 3: if (!fila_vazia(fila))
                    {
                      retirar_do_inicio(fila);
                    }
                    else
                    {
                      printf("fila vazia!\n");
                    }
                    break;
            case 4:  if (fila_utilizada == 1){
                        fila = fila2;
                        fila_utilizada = 2;
                      }
                      else{
                        fila = fila1;
                        fila_utilizada = 1;
                      }
                      printf("\nfila trocada com sucesso!\n");
                      break;
        }
    }
    while(opcao != 0);

    return 0;
}
