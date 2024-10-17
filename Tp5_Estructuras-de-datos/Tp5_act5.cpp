#include <stdio.h>

/*

5.- Dado un arreglo de 'n' elementos, buscar un cierto elemento, contenido en el vector, e indicar 
como salida la posición que ocupa dentro del arreglo.

a) Suponer que el elemento no se halla repetido.

b) El elemento puede no estar o estar mas de una vez. En ambos casos sacar carteles 
informativos y en el segundo caso detallar la cantidad de veces que fue hallado y las 
correspondientes posiciones.
*/

void ingresar(int [], int);

int a_buscador(int [], int, int);

void b_buscador(int [], int, int);

int main()
{
	int op;
	
	printf("Ingrese un inciso: ");
	scanf("%i", &op);
	
	switch(op)
	{
	case 1:
		int a[50], j, elemento, pos;
		printf("ingresa la cantidad de elementos que deseas añadir:");
		scanf("%i", &j);
		ingresar(a,j);
		
		printf("Que elemento deseas buscar:");
		scanf("%i", &elemento);
		
		pos = a_buscador(a,elemento,j);
		printf("El elemento se encuentra en la posicion: %i", pos);
		
		break;
	
	case 2:
		int b[50], m, n;
		printf("Ingresa la cantidad de elementos que deseas añadir:");
		scanf("%i", &n);
		ingresar(b,n);
		
		printf("Que elemento deseas buscar: ");
		scanf("%i", &m);
		
		b_buscador(b,m,n);
		
		break;
	}
	
	
	return 0;
}

void ingresar(int l[], int j)
{
	int i;
	
	for (i = 0; i<j; i++)
		scanf("%i", &l[i]);
}

/*Funcion usada en inciso a)*/

int a_buscador(int a[], int n, int j)
{
	int i, pos;
	
	for (i = 0; i<j; i++)
	{
		if (a[i] == n)
			pos = i;
	}
	return pos;
}

/*Funcion usada en inciso b)*/
void b_buscador(int a[], int n, int j)
{
	int i, cont = 0;
	
	for (i = 0; i<j; i++)
	{
		if(a[i] == n)
		{
			printf("El elemento se encontro en la posicion: %i\n", i);
			cont++;
		}
	}
	if (cont != 0)
		printf("El elemento se encontro un total de: %i\n", cont);
	else
		printf("No se encontró el elemento\n");
}
