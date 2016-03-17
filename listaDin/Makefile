menu:	menu.o	listaDin.o
	gcc menu.o listaDin.o -o menu 

menu.o: menu.c
	gcc -c menu.c

listaDin.o:	listaDin.c 	listaDin.h
	gcc -c listaDin.c

clean:
	rm *.o
