#include <stdio.h>

/*
2.- Hacer un programa que lea un vector A de 'n' elementos enteros, que busque el elemento de mayor valor e imprima el siguiente mensaje:
El elemento de mayor valor es: ... y ocupa la posición: ... del vector.
*/

void ingresar(int [], int);
void mayor(int [], int);

int main()
{
	int a[50], j, m;
	
	printf("Cuantos numeros desea ingresar: ");
	scanf("%i", &j);
	
	ingresar(a,j);
	
	mayor(a,j);
	
	return 0;
}

void ingresar(int a[], int j)
{
	int i;
	for (i = 0; i<j; i++)
		scanf("%i", &a[i]);
}

void mayor(int a[], int j)
{
	int i, m = 0, pos = 0, cont = 0;
	
	for (i = 0; i<j; i++)
	{
		if (a[i] > m)
		{
			m = a[i];
			pos = cont;
		}
		cont++;
	}
	
	printf("El elemento de mayor valor es: %i y ocupa la posición: %i del vector.", m, pos);
}
