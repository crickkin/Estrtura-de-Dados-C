typedef struct reg_no tipo_no;
typedef struct reg_lista tipo_lista;

tipo_lista* criar_lista();
int lista_vazia(tipo_lista *lista);
void incluir_no_inicio(tipo_lista *lista, int numero);
void incluir_no_fim(tipo_lista *lista, int numero);
void listar(tipo_lista *lista);
void excluir_do_inicio(tipo_lista *lista);
tipo_lista* excluir_lista(tipo_lista *lista);
int excluir_do_fim(tipo_lista *lista);
int incluir_ordenado(tipo_lista *lista, int numero);
int excluir_especifico(tipo_lista *lista, int numero);
int tamanho_lista(tipo_lista *lista);
float media_aritmetica(tipo_lista *lista);
int desalocar_nos(tipo_lista *lista);
//Exercícios da Lista
/*137*/int Profundidade(tipo_lista *lista, int posicao);
/*138*/int VerificarOrdemCrescente (tipo_lista *lista);
/*139*/int* Copia_Lista(tipo_lista* lista, int *numero);
/*140*/tipo_no* ProcuraEstrutura(tipo_lista * lista, int posicao);
/*141*/tipo_no* ProcuraMinimo(tipo_lista *lista);
/*142*/int CompararListas(tipo_lista *lista1, tipo_lista *lista2);
/*143*/tipo_lista* ClonaLista(tipo_lista *lista);
/*144*/int ConcatenaListas(tipo_lista *lista1, tipo_lista *lista2);
/*145*/int InverteLista(tipo_lista *lista);
/*146*/int RemoverTodosEspecifico(tipo_lista *lista, int x);
/*147*/int RemoverPorPosicao(tipo_lista *lista, int posicao);
/*148*/tipo_lista *UnirListas(tipo_lista *lista1, tipo_lista *lista2);
