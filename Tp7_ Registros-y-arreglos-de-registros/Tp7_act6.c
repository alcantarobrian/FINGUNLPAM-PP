#include <stdio.h>

// registro
typedef struct
{
	int nroVuelo;
	char lineaAerea[20];
	char horaLlegada[20];
	char procedencia[20];
	char horaSalida[20];
	char destino[20];
}regvuelo;

// vector de registros
typedef regvuelo datosVuelo[50];

// funciones
ingresar(datosVuelo vuelo, int cantidad);

int main()
{
	
}

ingresar(datosVuelo vuelo, int cantidad)
{
	int i;
	
	for (i = 0; i < cantidad; i++)
	{
		
	}
}
