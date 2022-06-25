CFLAGS =
CC = g++

all: sid clear

#sid: main.cpp cola.h lectura.o escritor.o parser_escritores.o parser_lecturas.o novela.o novela_historica.o cuento.o genero.o poema.o
#	$(CC) $(CFLAGS) main.cpp -o sid lectura.o escritor.o parser_escritores.o parser_lecturas.o novela.o novela_historica.o cuento.o genero.o poema.o 

sid: main.cpp menu.o lectura.o escritor.o parser_escritores.o parser_lecturas.o novela.o novela_historica.o cuento.o genero.o poema.o funciones.o
	$(CC) $(CFLAGS) main.cpp -o sid menu.o lectura.o escritor.o parser_escritores.o parser_lecturas.o novela.o novela_historica.o cuento.o genero.o poema.o funciones.o

# main.o : main.cpp lecturas.cpp escritor.cpp parser_escritor.cpp parser_lectura.cpp novela.cpp novela_historica.cpp cuento.cpp genero.cpp poema.cpp lecturas.h escritor.h parser_escritor.h parser_lectura.h novela.h novela_historica.h cuento.h genero.h poema.h
# 	$(CC) $(CFLAGS) -o main.o -c main.cpp

lectura.o: lectura.cpp lectura.h genero.h
	$(CC) $(CFLAGS) -o lectura.o -c lectura.cpp

escritor.o: escritor.cpp escritor.h
	$(CC) $(CFLAGS) -o escritor.o -c escritor.cpp

parser_escritores.o: parser_escritores.cpp parser_escritores.h escritor.cpp escritor.h lista.h nodo.h
	$(CC) $(CFLAGS) -o parser_escritores.o -c parser_escritores.cpp

parser_lecturas_2.o: parser_lecturas_2.cpp parser_lecturas_2.h lectura.cpp lectura.h escritor.cpp escritor.h lista.h nodo.h cuento.cpp cuento.h poema.cpp poema.h genero.cpp genero.h novela.cpp novela.h novela_historica.cpp novela_historica.h
	$(CC) $(CFLAGS) -o parser_lecturas_2.o -c parser_lecturas_2.cpp

novela.o: novela.cpp novela.h lectura.cpp lectura.h genero.cpp genero.h escritor.cpp escritor.h
	$(CC) $(CFLAGS) -o novela.o -c novela.cpp

novela_historica.o: novela_historica.cpp novela_historica.h novela.cpp novela.h lectura.cpp lectura.h genero.cpp genero.h escritor.cpp escritor.h
	$(CC) $(CFLAGS) -o novela_historica.o -c novela_historica.cpp

cuento.o: cuento.cpp cuento.h lectura.cpp lectura.h escritor.cpp escritor.h
	$(CC) $(CFLAGS) -o cuento.o -c cuento.cpp

genero.o: genero.cpp genero.h funciones.cpp funciones.h
	$(CC) $(CFLAGS) -o genero.o -c genero.cpp

poema.o: poema.cpp poema.h lectura.cpp lectura.h escritor.cpp escritor.h
	$(CC) $(CFLAGS) -o poema.o -c poema.cpp

menu.o: menu.cpp menu.h escritor.cpp escritor.h lista.h lectura.cpp lectura.h funciones.cpp funciones.h
	$(CC) $(CFLAGS) -o menu.o -c menu.cpp

funciones.o: funciones.cpp funciones.h
	$(CC) $(CFLAGS) -o funciones.o -c funciones.cpp

clear:	
	rm *.o