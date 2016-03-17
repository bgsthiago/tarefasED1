#include <stdio.h>
#include "listaDin.h"

int main(){
	int op = 0, n;
	vet li;
	do{
		printf("Entre com a operação: \n[0] - Sair\n[1] - Inserir inicio\n[2] - Remover inicio\n[3] - Inserir fim\n[4] - Remover fim\n[5] - Verificar cheio\n[6] - Verificar vazio\n[7] - Acessar\n[8] - Ver tamanho\n[9] - Ver repeticao\n[10] - Inicializa\n[11] - Listar\n");
		scanf("%d", &op);
		switch(op){
			default:
				printf("Digite uma opcao valida\n");
			break;

			case 10:
				inicia(&li);
				printf("Iniciado.\n");
			break;

			case 1:
				printf("Digite o valor a ser inserido:\n");
				scanf("%d", &n);
				if(insereIni(&li, n))
					printf("Inserido com sucesso\n");
				else
					printf("Erro.\n");
			break;

			case 2:
				if(retiraIni(&li, &n))
					printf("Elemento %d removido com sucesso\n", n);
				else
					printf("Erro.\n");
			break;

			case 3:
				printf("Digite o valor a ser inserido:\n");
				scanf("%d", &n);
				if(insereIni(&li, n))
					printf("Inserido com sucesso\n");
				else
					printf("Erro.\n");
			break;

			case 4:
				if(retiraIni(&li, &n))
					printf("Elemento %d removido com sucesso.\n", n);
				else
					printf("Erro.\n");
			break;			

			case 5:
				if(cheio(li))
					printf("Lista cheia.\n");
				else
					printf("Lista nao cheia.\n");
			break;

			case 6:
				if(vazio(li))
					printf("Lista vazia.\n");
				else
					printf("Lista nao vazia.\n");	
			break;

			case 7:
				printf("Digite a posicao que deseja buscar:\n");
				scanf("%d", &n);
				//if(acessa(li, n))
					printf("O valor encontrado e: %d\n", acessa(li, n));
				//else
				//	printf("Erro.\n");
			break;

			case 8:
				if(tamanho(li))
					printf("O tamanho do vetor e: %d\n", tamanho(li));
				else
					printf("Lista vazia.\n");
			break;

			case 9:
				printf("Entre com o valor:\n");
				scanf("%d", &n);
				printf("O numero de ocorrencias foram: %d\n", verRepeticao(li, n));
			break;

			case 11:
				exibir(li);
			break;

			case 0:
				printf("Adios.\n");
			break;
		}
	}while(op!= 0);
	return 0;
}