#include <stdio.h>
#define M 30

/*
12) Escribe un programa en C que permita sumar dos matrices de tamaño NxM. Las dimensiones
de las matrices serán ingresadas por el usuario. Implementar las siguientes funciones:
*/

void LeerMatriz(int [][30], int , int);
void SumarMatriz(int [][30], int [][30], int [][30], int, int);
void Mostrar(int [][30], int, int);

int main()
{
	int a[M][M], b[M][M], rtdo[M][M], columnas, filas;
	
	printf("Ingrese la cantidad de filas de las matrices: ");
	scanf("%i", &filas);
	
	printf("Ingrese la cantidad de columnas de las matrices: ");
	scanf("%i", &columnas);
	
	printf("Ingrese los elementos de la Matriz A: \n");
	LeerMatriz(a, filas, columnas);
	
	printf("Ingrese los elementos de la Matriz B: \n");
	LeerMatriz(b, filas, columnas);
	
	printf("Resultado de sumar las matrices A y B es: \n");
	SumarMatriz(a, b, rtdo, filas, columnas);
	Mostrar(rtdo, filas, columnas);
	
	return 0;
	
}

void LeerMatriz(int a[30][30], int fila, int columna)
{
	int i, j;
	
	for (i = 0; i < fila; i++)
	{
		
		printf("FILA: %i\n", i+1);
		for (j = 0; j < columna; j++)
		{
			printf("COLUMNA: %i\n", j+1);
			scanf("%i", &a[i][j]);
		}
		
	}
	
	}

void SumarMatriz(int a[][30], int b[][30], int c[][30], int fila, int columna)
{
	int i,j;
	
	for (i = 0; i<fila; i++)
		for(j = 0; j<columna; j++)
			c[i][j] = a[i][j] + b[i][j]; 
}

void Mostrar(int a[][30], int fila, int columna)
{
	int i, j;
	
	for (i = 0; i<fila; i++)
	{
		for (j = 0; j < columna; j++)
			printf("%i ", a[i][j]);

	printf("\n");
	}
}
