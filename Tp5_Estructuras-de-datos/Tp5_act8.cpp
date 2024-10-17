#include <stdio.h>

/*
8.- Dados los dígitos de un número, en un vector A, calcular el número, almacenarlo en una variable
simple, y mostrarla.
 */
void ingresar(int [], int );
int calcular(int [], int);


int main()
{
	int a[5], j = 5, nro;
	
	printf("Ingresa cinco números para el vector: \n");
	ingresar(a,j);

	nro = calcular(a,j);
	printf("El número calculado es: %i\n", nro);
}


void ingresar(int l[], int j)
{
	int i;
	for (i = 0; i<j; i++)
		scanf("%i", &l[i]);
}

int calcular(int l[], int j)
{
	int i, rtdo = 0;
	for (i = 0; i<j; i++)
	{
		rtdo = rtdo * 10 + l[i];	
	}

	return rtdo;
}
