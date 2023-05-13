CC = gcc
CFLAGS = -g -Wall
FUNDAMENTALES = tipo_elemento.o DataEntry.o
IMPLEMENTACIONES = colas_array_circular.o colas_array_no_circular.o colas_punteros.o

main_ejercicio_2_array_no_circular: main_ejercicio_2.c ejercicio_2.h
	$(CC) $(CFLAGS) main_ejercicio_2.c $(FUNDAMENTALES) colas_array_no_circular.o -o main_ejercicio_2_array_no_circular

main_ejercicio_2_array_circular: main_ejercicio_2.c ejercicio_2.h
	$(CC) $(CFLAGS) main_ejercicio_2.c $(FUNDAMENTALES) colas_array_circular.c -o main_ejercicio_2_array_circular

main_ejercicio_2_punteros: main_ejercicio_2.c ejercicio_2.h
	$(CC) $(CFLAGS) main_ejercicio_2.c $(FUNDAMENTALES) colas_punteros.c -o main_ejercicio_2_punteros


# instruccion para compilar los fundamentales
fundamentales: $(FUNDAMENTALES)
# instruccion para compilar las implementaciones
implementaciones: $(IMPLEMENTACIONES)
colas_punteros.o: colas_punteros.c colas.h
colas_array_circular.o: colas_array_circular.c colas.h
colas_array_no_circular.o: colas_array_no_circular.c colas.h
tipo_elemento.o: tipo_elemento.c tipo_elemento.h
DataEntry.o: DataEntry.c DataEntry.h
clean:
	-rm *.o 
