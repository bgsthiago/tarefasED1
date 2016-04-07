/*
 * Implementacao de lista sem n� cabe�a.
 */

#include"lista_dinamica.h"
#include<stdio.h>
#include<stdlib.h>

/* Inicializa uma lista */
void inicLista(Lista *p_l){
	*p_l = NULL;
}

/* Verifica se a lista est� vazia ou nao */
int listaVazia(Lista *p_l){
	if(*p_l == NULL)
		return 1;
	return 0;
}

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e){
	if(p_l != NULL){
		No_lista *novo = (No_lista*) malloc(sizeof(No_lista));
	  novo->info = e;
	  novo->prox = *p_l;
	  *p_l = novo;
	}
}

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
	if(p_l != NULL){
		No_lista *novo = (No_lista*) malloc(sizeof(No_lista));
		novo->info = e;
		novo->prox = NULL;
		if(*p_l == NULL)
			*p_l = novo;
		else{
			No_lista *aux = *p_l;
			while(aux->prox != NULL)
				aux = aux->prox;
			aux->prox = novo;
		}
	}
}

/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e){
	No_lista *novo;
	No_lista *aux = *p_l;
	if(ordenada(p_l)){
		novo = (No_lista*) malloc(sizeof(No_lista));
		novo->info = e;
		if(aux==NULL || (aux!=NULL && aux->info > e)){
			novo->prox = aux;
			*p_l = novo;
		}
		else{
			while(aux->prox!=NULL && aux->prox->info < e)
				aux = aux->prox;
			novo->prox = aux->prox;
			aux->prox = novo;
		}
	}
}

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l){
	int isOrder = 1;
	No_lista *atual = *p_l, *ant;
	/*is the list empty
		is the size = 1 */
	if(*p_l == NULL || (*p_l)->prox == NULL)
		return 1;
	while(atual->prox != NULL && isOrder == 1){
		ant = atual;
		atual = atual->prox;
		if(ant->info > atual->info)
			return 0;
	}
	return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l){
	printf("erro");
	No_lista *p, *q, *r;

	int size = tamanho(p_l), cont ,i;

	for(i = size - 1; i >= 1; i--){
		r = NULL;
		q = *p_l;
		p = q->prox;
		for(cont = 0; cont < i; cont++){
			if(q->info > p->info){
				if(r == NULL)
					*p_l = p;
				else
					r->prox = q->prox;

					q->prox = p->prox;
					p->prox = q;
					r = p;
					q = r->prox;
					p = q->prox;
			}
			else{
				r = q;
				q = q->prox;
				p = p->prox;
			}
		}
	}
}

int tamanho(Lista *p_l){
	int tam = 0;
	if(!listaVazia(p_l)){
		tam++;
		No_lista* aux = *p_l;
		while(aux->prox!=NULL){
			tam++;
			aux = aux->prox;
		}
	}
	return tam;
}

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l, elem_t *p_e){
	No_lista *aux;
	if(listaVazia(p_l))
		return 0;
	aux = *p_l;
	*p_l = aux->prox;
	*p_e = aux->info;
	free(aux);
	return 1;
}

/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia */
int removeFim(Lista *p_l, elem_t *p_e){
	No_lista *first, *second;
	if(listaVazia(p_l))
		return 0;
	first = *p_l;
	second = *p_l;
	if(first->prox == NULL){	//there's only one data on the list
		*p_l = NULL;
		*p_e = first->info;
		free(first);
		return 1;
	} //regular remove
	else{
		second = first->prox;
		while(second->prox != NULL){
				first = first->prox;
				second = first->prox;
		}
		first->prox = NULL;
		*p_e = second->info;
		free(second);
		return 1;
	}
}

/* Remove o numero de valor e.
   Retorna 0 caso este numero n�o tenha sido encontrado */
int removeValor(Lista *p_l, elem_t e){
	No_lista *first, *second;
	first = *p_l;
	second = first->prox;
	if(first->info == e){ //if e(value) is the first on the list
		*p_l = second;
		e = first->info;
		free(first);
		return 1;
	}
	while(first->prox != NULL){ //regular research and remove
		if(second->info == e){
			first->prox = second->prox;
			free(second);
			return 1;
		}
		first = first->prox;
		second = first->prox;
	}
	return 0;
}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l){
	No_lista *anterior, *atual, *prox;
	anterior = NULL;
	atual = *p_l;
	while(atual != NULL){
		prox = atual->prox;
		atual->prox = anterior;
		anterior = atual;
		atual = prox;
	}
	*p_l = anterior;
}

/* Remove todos os numeros da lista */
void libera(Lista *p_l){
	if(p_l != NULL){
		No_lista* no;
		while((*p_l) != NULL){
			no = *p_l;
			*p_l = (*p_l)->prox;
			free(no);
		}
		free(p_l);
	}
}

/* Exibe o conteudo da lista */
void exibe(Lista *p_l){
	Lista aux;
	aux = *p_l;
	while(aux != NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
}
