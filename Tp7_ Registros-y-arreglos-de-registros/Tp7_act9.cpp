#include <stdio.h>
#define MAX_EQUIPOS 20;

// Registros
typedef struct
{
	int numeroEquipo;
	char nombreEquipo[30];
	char nombreRepre[30];
	
}datos;	

typedef struct
{
	int numeroEquipoA;
	int cantGolesA;
	int numeroEquipoB;
	int cantGolesB;
}partidos;

// Vectores de registros
typedef datos d_e[50];
typedef partidos r_p[50];

// Funciones
void ingresar_datos(d_e equipos, int);
void ingresar_resultados(r_p resultados, int);
void tabla(r_p resultados, int [], int);

int main()
{
	
}

void ingresar_datos(d_e equipos, int cantidad)
{
	int i;
	
	for(i = 0; i < cantidad; i++)
	{
		printf("Ingrese el numero del equipo: ");
		scanf("%i", &equipos[i].numeroEquipo);
		
		printf("Ingrese el nombre del equipo: ");
		scanf("%s", equipos[i].nombreEquipo);
		
		printf("Ingrese al representante de equipo");
		scanf("%s", equipos[i].nombreRepre);
	}
}

void ingresar_resultados(r_p resultados, int cantidad)
{
	int i;
	
	for(i = 0; i < cantidad; i++)
	{
		printf("Ingrese el numero del equipo A: ");
		scanf("%i", &resultados[i].numeroEquipoA);
		
		printf("Ingrese los goles convertidos: ");
		scanf("%i", &resultados[i].cantGolesA);
		
		pritnf("Ingrese el numero del equipo B: ");
		scanf("%i", &resultados[i].numeroEquipoB);
		
		printf("Ingrese los goles convertidos: ");
		scanf("%i", &resultados[i].cantGolesB);
	}
}

void tabla(r_p resultados, int posiciones[], int cantidad)
{
	int i;
	for(i = 0; i < cantidad; i++)
	{
		if(resultados[i].cantGolesA > resultados[i].cantGolesB)
		{
			posiciones[]
		}
	}
}
