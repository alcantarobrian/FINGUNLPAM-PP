#include <stdio.h>

/*
Escribe un programa en C que calcule la transpuesta de una matriz cuadrada. La dimensión de la
matriz será ingresada por el usuario. Implementa las siguientes funciones:
*/


void LeerMatriz(int [][30], int);
void Transpuesta(int [][30], int);
void Mostrar(int [][30], int );

int main()
{
	int dim, a[30][30];

	printf("Ingrese la dimension de la matriz: \n");
	scanf("%i", &dim);

	printf("Ingrese los elementos de la matriz: \n");
	LeerMatriz(a,dim);
	Mostrar(a, dim);

	printf("La matriz transpuesta es: \n");
	Transpuesta(a, dim);
	Mostrar(a, dim);	
	
}

void LeerMatriz(int a[][30], int dim)
{
	int i,j;

	for (i = 0; i < dim ; i++)
	{
		printf("COLUMNA: %i \n", i+1);

		for (j = 0; j < dim; j++)
		{
			printf("FILAS: %i \n", j+1);
			scanf("%i", &a[i][j]);
		}
	}
}


void Transpuesta(int a[][30], int dim)
{
	int i, j, temp;
		for (i = 0; i<=dim/2; i++)
			for (j = i+1; j<dim; j++)
				
				if (i != j)
				{
					temp = a[i][j];
					a[i][j] = a[j][i];
					a[j][i] = temp;	
				}
}

void Mostrar(int a[][30], int dim)
{
	int i,j;

	for (i = 0; i<dim; i++)
	{
		for (j = 0; j<dim; j++)
			printf("%i ", a[i][j]);
	printf("\n");
	}
}
