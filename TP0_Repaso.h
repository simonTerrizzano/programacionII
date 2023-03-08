#include <stdbool.h>

#ifndef TP0_Repaso
#define TP0_Repaso

// Ejercicio 1

enum Referencia
{
    INTERNO = -1,
    EN_CIRCUNFERENCIA,
    EXTERNO
};

enum Referencia dondeEstaElPunto(int xc, int yc, int rc, int xp, int yp);

// Ejercicio 2

bool digitoEnNumero(long n, short d);


// Ejercicio 3

struct Punto {
    int x, y;
};

enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p);

// Ejercicio 4

#define TAMANO_STRING 50
#define CANT_JUGADORES 11

struct Jugador {
    char nombre[TAMANO_STRING];
    int edad, partidosJugados;
};

struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[]);
struct Jugador *jugadoresOrdenadosPorEdad(struct Jugador equipo[]);
float promedioDePartidosJugados(struct Jugador equipo[], int edad);

// Ejercicio 5

#define CANT_PISOS 8
#define CANT_DEPARTAMENTOS 5

typedef struct ViviendaRep {
    short piso;
    char depto;
} Vivienda;


int pisoConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);
int cantidadDeViviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);
float promedioHabitantesPorVivienda(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);
Vivienda viviendaConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);

// Viviendas viviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);


#endif //TP0_Repaso
