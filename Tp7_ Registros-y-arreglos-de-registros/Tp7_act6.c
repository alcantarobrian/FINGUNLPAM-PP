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
void ingresar(datosVuelo vuelo, int);
void ordenarVuelos(datosVuelo vuelo, int);
void mostrar(datosVuelo vuelo, int);

int main()
{
	int cantidad;
	datosVuelo vuelo;
	
	printf("Cuantos vuelos ingresara?: ");
	scanf("%i", &cantidad);

	ingresar(vuelo, cantidad);

	ordenarVuelos(vuelo, cantidad);
	mostrar(vuelo, cantidad);
}

void ingresar(datosVuelo vuelo, int cantidad)
{
	int i;
	
	for (i = 0; i < cantidad; i++)
	{
		printf("\nIngrese numero de vuelo: ");
		scanf("%i", &vuelo[i].nroVuelo);
		
		printf("\nIngrese la linea de vuelo: ");
		scanf("%s", vuelo[i].lineaAerea);
		
		printf("\nIngrese la hora de llegada: ");
		scanf("%s", vuelo[i].horaLlegada);
		
		printf("\nIngrese la procedencia: ");
		scanf("%s", vuelo[i].procedencia);
		
		printf("\nIngrese la hora de salida");
		scanf("%s", vuelo[i].horaSalida);
		
		printf("\nIngrese el destino");
		scanf("%s", vuelo[i].destino);
	}
}

void ordenarVuelos(datosVuelo vuelo, int cantidad)
{
	int i, j, bandera;
	bandera = 1;
	regvuelo temp;
	
	for(i = 0; i < cantidad-1 && bandera; i++)
	{
		for (j = 0; j < cantidad-1-i; j++)
		{
			bandera = 0;
			
			if(vuelo[j].nroVuelo > vuelo[j+1].nroVuelo)
			{
				temp = vuelo[j];
				vuelo[j] = vuelo[j+1];
				vuelo[j+1] = temp;
				bandera = 1;
			}
		}
	}
}

void mostrar(datosVuelo vuelo, int cantidad)
{
	int i;
	
	for (i = 0; i < cantidad; i++)
	{
		printf("\n\nnumero de vuelo: %i", vuelo[i].nroVuelo);
		printf("\nLinea Aerea: %s", vuelo[i].lineaAerea);
		printf("\nLinea hora de llegada: %s", vuelo[i].horaLlegada);
		printf("\nLinea procedencia: %s", vuelo[i].procedencia);
		printf("\nLinea hora de salida: %s", vuelo[i].horaSalida);
		printf("\nLinea destino: %s", vuelo[i].destino);
	}
}
