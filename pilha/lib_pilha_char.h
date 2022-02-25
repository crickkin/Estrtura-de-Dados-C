typedef struct reg_no tipo_no;
typedef struct reg_pilha tipo_pilha;

tipo_pilha* criar_pilha();
int pilha_vazia(tipo_pilha *pilha);
void incluir_no_topo(tipo_pilha *pilha, char letra);
char retirar_do_topo(tipo_pilha *pilha);
void listar(tipo_pilha *pilha);
char ComparaPilha(tipo_pilha *pilha1, tipo_pilha *pilha2);
void InverteString(tipo_pilha *pilha, char *string);
int VerificarParenteses(tipo_pilha *pilha, char *string);
