#include <stdio.h>

/*

14. Escribe un programa en C que busque un valor específico en una matriz de enteros. Las
dimensiones de la matriz y el valor a buscar serán ingresados por el usuario. Implementa las
siguientes funciones:

*/

void Ingresar(int [][30], int, int);
int BuscarValor(int [][30], int, int, int); 
void ImprimirPosiciones(int [][30], int, int, int);
void mostrar(int [][30], int, int);

int main()
{
	int a[30][30], fila, columna, elemento;
	
	printf("Ingrese las filas: ");
	scanf("%i", &fila);

	printf("Ingrese las columnas: ");
	scanf("%i", &columna);

	printf("Ingrese los elementos de la matriz: \n");
	Ingresar(a, fila, columna);

	printf("Ingrese el elemento a buscar: ");
	scanf("%i", &elemento);

	
	if(BuscarValor(a, fila, columna, elemento))
	{
		ImprimirPosiciones(a, fila, columna, elemento);
	}
	else
		printf("El elemento no se encuentra en la matriz");

	
	printf("\n");
	printf("\n");
	
	printf("La matriz es: \n");
	mostrar(a,fila,columna);
}


void Ingresar(int a[][30], int fila, int columna)
{
	int i, j;

	for (i = 0; i<fila; i++)
		for(j = 0; j<columna; j++)
			scanf("%i", &a[i][j]);
}

int BuscarValor(int a[][30], int fila, int columna, int elemento)
{
	int i, j, valor = 0;

	for (i = 0; i<fila; i++)
		for(j = 0; j<columna; j++)
			if ( elemento == a[i][j])
				valor = 1;
	
	return valor;
}

void ImprimirPosiciones(int a[][30], int fila, int columna, int elemento)
{
	int i, j;

	for (i = 0; i<fila; i++)
		for (j = 0; j<columna; j++)
		{
			if (a[i][j] == elemento)
				printf("El elemento se encuentra en la fila: %i y la columna %i\n",i+1, j+1);
		}
}

void mostrar(int a[][30], int fila, int columna)
{
	int i,j;
	
	for (i=0; i<fila; i++)
	{
		for(j=0;j<columna; j++)
			printf("%i ", a[i][j]);
	printf("\n");
	}
}
