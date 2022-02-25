#include <stdio.h>
#include "lib_fila.h"

int main()
{
    tipo_fila *fila, *fila1, *fila2, *fila_par, *fila_impar;
    int opcao, numero, fila_utilizada = 1;

    fila1 = criar_fila();
    fila2 = criar_fila();
    fila_par = criar_fila();
    fila_impar = criar_fila();

    fila = fila1;
    do
    {
        printf("\n\n0 - Sair\n");
        printf("1 - Incluir dado\n");
        printf("2 - Exibir dados\n");
        printf("3 - Excluir dado\n");
        printf("4 - Trocar fila\n");
        printf("157 - Dividir fila em pares e impares\n");
        printf("158 - \n");
        if (fila_utilizada == 1) printf("\nVoce esta utilizando a fila 1\n\n");
        else                      printf("\nVoce esta utilizando a fila 2\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1: printf("Entre com um número:");
                    scanf("%d", &numero);
                    incluir_no_fim(fila, numero);
                    break;
            case 2: if (fila_vazia(fila))
                    {
                        printf("fila vazia!\n");
                    }
                    else
                    {
                        listar(fila);
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
            case 157: SeparaFilas(fila, fila_par, fila_impar);
                      printf("Lista par: ");
                      listar(fila_par);
                      printf("\nLista impar: ");
                      listar(fila_impar);
                      break;
        }
    }
    while(opcao != 0);

    return 0;
}
