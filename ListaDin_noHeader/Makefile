teste_lista:	teste_lista.o	lista_dinamica.o
	gcc teste_lista.o lista_dinamica.o -o teste_lista

teste_lista.o: teste_lista.c
	gcc -c teste_lista.c

lista_dinamica.o:	lista_dinamica.c 	lista_dinamica.h
	gcc -c lista_dinamica.c

clean:
	rm *.o
