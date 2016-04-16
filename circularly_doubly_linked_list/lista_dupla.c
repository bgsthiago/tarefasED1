/*
 * Implementacao de lista dupla.
 */

#include"lista_dupla.h"
#include<stdio.h>
#include<stdlib.h>

/* Inicializa uma lista */
void inicLista(Lista *p_l){
	*p_l = NULL;
}

/* Verifica se a lista est� vazia ou nao */
int listaVazia(Lista *p_l){
	if (*p_l == NULL)
		return 1;
	return 0;
}

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e){
	No_lista *novo;
	novo = malloc (sizeof(No_lista));
	novo->info = e;
	if (listaVazia(p_l)) {
		novo->prox = novo;
		novo->ant = novo;
	}
	else {
		novo->prox = *p_l;
		novo->ant = (*p_l)->ant;
		(*p_l)->ant->prox = novo;
		(*p_l)->ant = novo;
	}
	*p_l = novo;
}

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
	No_lista *novo = (No_lista*) malloc (sizeof(No_lista));
	novo->info = e;
	if(listaVazia(p_l)){
		novo->prox = novo;
		novo->ant = novo;
	}
	else{
		novo->prox = *p_l;
		novo->ant = (*p_l)->ant;
		(*p_l)->ant = novo;
		novo->ant->prox = novo;
	}

}

/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e){
	if(listaVazia(p_l)) insereInicio(p_l, e);
	if(!ordenada(p_l))
		ordena(p_l);

	if((*p_l)->info >= e)
		insereInicio(p_l, e);
	else if((*p_l)->ant->info <= e)
		insereFim(p_l, e);
	else{
		Lista aux = (*p_l)->prox;
		int flag = 1;
		No_lista *novo = (No_lista*) malloc (sizeof(No_lista));
		novo->info = e;
		while(aux != *p_l && flag == 1){
			if(aux->info >= novo->info){
				novo->ant = aux->ant;
				novo->prox = aux;
				aux->ant->prox = novo;
				aux->ant = novo;
				flag = 0;
			}else
				aux = aux->prox;
		}
	}
}

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l){
	No_lista *aux;
	if(listaVazia(p_l))
		return 0;
	aux = (*p_l)->prox;
	while(aux != *p_l){
		if((aux->ant)->info > aux->info)
			return 0;
		aux = aux->prox;
	}
	return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l){
	Lista cur = *p_l;
	Lista nxt = cur->prox;

	int start = 1, i, j;
	int size = getSize(p_l);

	for(i = size - 1; i >= 1; i--){
		for(j = 0; j < i; j++){
			if(nxt->info <= cur->info){
				if(start){
					*p_l = nxt;
					start = 0;
				}
			cur->ant->prox = nxt;
			nxt->ant = cur->ant;
			cur->ant = nxt;
			cur->prox = nxt->prox;
			nxt->prox->ant = cur;
			nxt->prox = cur;
			cur = nxt->prox;
			nxt = cur->prox;
		}
		else{
			cur = cur->prox;
			nxt = nxt->prox;
			start = 0;
		}
	}
	start = 1;
	cur = *p_l;
	nxt = cur->prox;
}
}

int getSize(Lista *p_l){
	int size = 0;
	Lista aux = (*p_l)->prox;
	if(listaVazia(p_l)) return 0;
	while(aux!=*p_l){
		size++;
		aux = aux->prox;
	}
	return size+1;
}

/* Remove o elemento que esta no size da lista.
   Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l, elem_t *p_e){
	No_lista *aux = *p_l;

	if(listaVazia(p_l)) return 0;
	if ((*p_l)->prox == *p_l) // se a lista tiver apenas 1 elemento
		*p_l = NULL;
	else{
		(*p_l)->prox->ant = (*p_l)->ant;
		(*p_l)->ant->prox = (*p_l)->prox;
		*p_l = aux->prox;
	}

	*p_e = aux->info;
	free(aux);
	return 1;
}

/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia */
int removeFim(Lista *p_l, elem_t *p_e){
	No_lista *aux;

	if (listaVazia(p_l)) return 0;

	if ((*p_l)->prox == *p_l)
	{
		aux = *p_l;
		*p_l = NULL;
	}

	else
	{
		aux = (*p_l)->ant;
		(*p_l)->ant = aux->ant;
		aux->ant->prox = *p_l;
	}

	(*p_e) = aux->info;

	free(aux);
	return 1;
}

/* Remove o numero de valor e.
   Retorna 0 caso este numero n�o tenha sido encontrado */
int removeValor(Lista *p_l, elem_t e){
	if(listaVazia(p_l)) return 0;
	No_lista *aux = (*p_l);

	if(aux->info == e){
		removeInicio(p_l, &e);
		return 1;
	}

	aux = aux->prox;

	while(aux != *p_l){
		if(aux->info == e){
			aux->prox->ant = aux->ant;
			aux->ant->prox = aux->prox;
			return 1;
		}
		aux = aux->prox;
	}
	free(aux);
	return 0;
}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l){
	No_lista *f, *t;
	f = (*p_l)->prox;
	t = f->prox;
	while(f!=(*p_l)){
		f->prox = f->ant;
		f->ant = t;
		f = t;
		t = t->prox;
	}
	(*p_l)->prox = (*p_l)->ant;
	(*p_l)->ant = t;
	*p_l = (*p_l)->prox;
}

/* Remove todos os numeros da lista */
void libera(Lista *p_l){
	No_lista *aux= (*p_l)->prox;
	while(aux != *p_l){
		free(aux);
		aux = aux->prox;
	}
	free(aux);
	*p_l = NULL;
}

/* Exibe o conteudo da lista */
void exibe(Lista *p_l){
	Lista aux;
	aux = *p_l;
	if (!listaVazia(p_l)) {
		printf("%d ", aux->info);
		aux = aux->prox;
		while(aux != *p_l){
			printf("%d ", aux->info);
			aux = aux->prox;
		}
	}
}
