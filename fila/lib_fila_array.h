typedef struct reg_no tipo_no;
typedef struct reg_fila tipo_fila;

tipo_fila* criar_fila(int tamanho);
int fila_vazia(tipo_fila *fila);
void listar(tipo_fila *fila);
int incluir_no_fim(tipo_fila *fila, int numero);
void retirar_do_inicio(tipo_fila *fila);
tipo_fila* excluir_fila(tipo_fila *fila);
