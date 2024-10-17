#include <stdio.h>

/*
1.- Desarrollar un programa que permita la lectura de un vector A de 'n' números enteros, usando una
función, y luego lo imprima, con otra función, con el siguiente formato:
A [1] = x1 { x1 es el contenido de A [1] }
A [2] = x2
....
*/

void ingresar(int [], int);
void mostrar(int [], int);

int main()
{
	int j, a[100];
	
	printf("Cuantos numeros desea ingresar: ");
	scanf("%i", &j);
	
	printf("\n");
	printf("Ingresa los numeros:\n");
	ingresar(a, j);

	printf("\n");
	
	printf("Los numeros ingresados son: \n");
	mostrar(a, j);
}

void ingresar(int l[], int j)
{
	int i;
	
	for (i = 0; i<j; i++)
		scanf("%i", &l[i]);
}

void mostrar(int l[], int j)
{
	int i;
	
	for (i = 0; i<j; i++)
		printf("%i\n", l[i]);
}
