CC = gcc
CFLAGS = -g -Wall
FUNDAMENTALES = tipo_elemento.o DataEntry.o
IMPLEMENTACIONES = colasApuntadores.o colasArrayCircular.o colasArrayNoCircular.o


#----------------------PUNTO 2 ----------------------------------------------------------------------
main_ejercicio_2_ArrayNoCircular: main_ejercicio_2.c
	$(CC) $(CFLAGS) main_ejercicio_2.c tipo_elemento.o DataEntry_alt.o colasArrayNoCircular.o -o main_ejercicio_2_ArrayNoCircular

main_ejercicio_2_Apuntadores: main_ejercicio_2.c
	$(CC) $(CFLAGS) main_ejercicio_2.c tipo_elemento.o DataEntry_alt.o colasApuntadores.o -o main_ejercicio_2_Apuntadores

main_ejercicio_2_ArrayCircular: main_ejercicio_2.c
	$(CC) $(CFLAGS) main_ejercicio_2.c tipo_elemento.o DataEntry_alt.o colasArrayCircular.o -o main_ejercicio_2_ArrayCircular
#----------------------PUNTO 3 ----------------------------------------------------------------------
main_ejercicio_3_ArrayNoCircular: Ejercicio_3_main.c
	$(CC) $(CFLAGS) Ejercicio_3_main.c $(FUNDAMENTALES) colasArrayNoCircular.o -o main_ejercicio_3_ArrayNoCircular

main_ejercicio_3_Apuntadores: Ejercicio_3_main.c
	$(CC) $(CFLAGS) Ejercicio_3_main.c $(FUNDAMENTALES) colasApuntadores.o -o main_ejercicio_3_Apuntadores

main_ejercicio_3_ArrayCircular: Ejercicio_3_main.c
	$(CC) $(CFLAGS) Ejercicio_3_main.c $(FUNDAMENTALES) colasArrayCircular.o -o main_ejercicio_3_ArrayCircular
#----------------------PUNTO 4 ----------------------------------------------------------------------
main_ejercicio_4_ArrayNoCircular: Ejercicio_4_main.c
	$(CC) $(CFLAGS) Ejercicio_4_main.c $(FUNDAMENTALES) colasArrayNoCircular.o -o main_ejercicio_4_ArrayNoCircular

main_ejercicio_4_Apuntadores: Ejercicio_4_main.c
	$(CC) $(CFLAGS) Ejercicio_4_main.c $(FUNDAMENTALES) colasApuntadores.o -o main_ejercicio_4_Apuntadores

main_ejercicio_4_ArrayCircular: Ejercicio_4_main.c
	$(CC) $(CFLAGS) Ejercicio_4_main.c $(FUNDAMENTALES) colasArrayCircular.o -o main_ejercicio_4_ArrayCircular
#----------------------PUNTO 5 ----------------------------------------------------------------------

fundamentales: $(FUNDAMENTALES)
implementaciones: $(IMPLEMENTACIONES)

colasApuntadores.o: colasApuntadores.c colas.h
colasArrayNoCircular.o: colasArrayNoCircular.c colas.h
colasArrayCircular.o: colasArrayCircular.c colas.h

tipo_elemento.o: tipo_elemento.c tipo_elemento.h
DataEntry_alt.o: DataEntry_alt.c DataEntry_alt.h
DataEntry.o: DataEntry.c DataEntry.h
clean:
	-rm *.o
