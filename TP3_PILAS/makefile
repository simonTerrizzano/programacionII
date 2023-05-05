CC = gcc
CFLAGS = -g -Wall
OBJS = array_pilas.o DataEntry.o punteros_pilas.o tipo_elemento.o  

main4_array: main4.c
	$(CC) $(CFLAGS)  main4.c tipo_elemento.o DataEntry.o array_pilas.o -o  main4_array
main4_punteros: main4.c
	$(CC) $(CFLAGS) main4.c  tipo_elemento.o DataEntry.o punteros_pilas.o  -o main4_punteros
#fundamentales
fundamentales: $(OBJS) 
punteros_pilas.o: punteros_pilas.c pilas.h
array_pilas.o: array_pilas.c pilas.h
tipo_elemento.o: tipo_elemento.c tipo_elemento.h
DataEntry.o: DataEntry.c DataEntry.h
%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
clean:
	-rm *.o 
