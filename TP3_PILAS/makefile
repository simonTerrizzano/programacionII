CC = gcc
CFLAGS = -g -Wall
OBJS = tipo_elemento.o  

main4_array: main4.c $(OBJS)
	$(CC) $(CFLAGS)  main4.c DataEntry.c array_pilas.o $(OBJS) -o main4_array
main4_punteros: main4.c $(OBJS)
	$(CC) $(CFLAGS)  main4.c DataEntry.o punteros_pilas.o $(OBJS) -o main4_punteros
punteros_pilas.o: punteros_pilas.c pilas.h
array_pilas.o: array_pilas.c pilas.h tipo_elemento.h
tipo_elemento.o: tipo_elemento.c tipo_elemento.h
DataEntry.o: DataEntry.c DataEntry.h
clean:
	-rm *.o 
