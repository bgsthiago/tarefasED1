#include<stdlib.h>
#include<stdio.h>
#include"listaDin.h"

// Inicializa o vetor
void inicia (vet *v){
	v->item = 0;
	v->prox = NULL;
}

// Insere um elemento no inicio do vetor. Retorna 1 se a inserçao ocorreu com sucesso ou 0 caso contrario.
int insereIni (vet *v, elem_t n){
	vet *no = (vet*) malloc(sizeof(vet));
	if(no == NULL) 
		return 0;
	no->item = n;
	no->prox = v->prox;
	v->prox = no;
	return 1;
}

// Remove um elemento do inicio do vetor. Retorna 1 se a remocao ocorreu com sucesso e 0 caso contrario
int retiraIni (vet *v, elem_t *elemRemovido){
	vet *aux;
	if (!vazio(*v)){
		aux = v->prox;
		*elemRemovido = aux->item;
		v->prox = aux->prox;
		free(aux);		
		return 1;
	}
	return 0;
}

// Insere um elemento no final do vetor. Retorna 1 se a inserçao ocorreu com sucesso ou 0 caso contrario.
int insere (vet *v, elem_t n){
	vet *novo;
	novo = (vet*) malloc(sizeof(vet));
	if(novo != NULL){
		novo->item = n;
		novo->prox = NULL;
		while(v->prox != NULL)
			v = v->prox;
		v->prox = novo;
		return 1;
	}
	return 0;
}

// Remove um elemento do final do vetor. Retorna 1 se a remocao ocorreu com sucesso e 0 caso contrario
int retira (vet *v, elem_t *elemRemovido){
	vet *aux;
	if(!vazio(*v)){
		while(v->prox != NULL){
			aux = v;
			v = v->prox;
		}
		*elemRemovido = v->item;
		aux->prox = NULL;
		free(v);
		return 1;
	}
	return 0;
}

// Verifica o numero de vezes que o elemento n se repete no vetor
int verRepeticao (vet v, elem_t n){
	int count = 0;
	vet *aux = v.prox;
	while(aux->prox != NULL){
		if(n == aux->item)
			count++;
		aux = aux->prox;
	}
	return count;
}

// Retorna 1 caso o vetor esteja cheio ou 0 caso contrario
int cheio (vet v){
	elem_t n  = 0;
	if(insere(&v, n)){
		retira(&v, &n);
		return 0;
	}
	return 1;
}

// Retorna 1 caso o vetor esteja vazio ou 0 caso contrario
int vazio (vet v){
	if(v.prox == NULL)
		return 1;
	return 0;
}


// Retorna o elemento na posicao ind
elem_t acessa (vet v, int ind){
	int i = 1;
	vet *aux;
	if(!vazio(v)){
		aux = v.prox;
		while(aux->prox != NULL && i <= ind){
			printf("%d\n", aux->item);
			aux = aux->prox;
			i++;	
		}
	}
	return aux->item;
}

// Retorna o numero de elementos do vetor
int tamanho(vet v){
	int count = 1;
	vet *aux = v.prox;
	if(vazio(v))
		return 0;
	while(aux->prox != NULL){
		aux = aux->prox;
		count++;
	}
	return count;
}

void exibir(vet v){
	vet *aux;
	aux = &v;
	if(!vazio(v)){
		while(aux->prox != NULL){
			aux = aux->prox;
			printf("%d ", aux->item);
		}
	}
	printf("\n");
}