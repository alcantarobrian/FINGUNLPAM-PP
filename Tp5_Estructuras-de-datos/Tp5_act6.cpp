#include <stdio.h>

/*
 
6.- Dado un vector de n elementos, realizar las siguientes operaciones:
a) Sumar el primer termino con el n-esimo, y cargarlo en un vector auxiliar como elemento
uno.
b) Sumar el segundo termino con el n-esimo menos 1 y cargarlo en la segunda posición del
auxiliar. Y así sucesivamente hasta agotar las posibilidades.
	
	Considerar n par (dimensión del vector).
	Considerar n impar   
 */

int ingresar(int [], int);	
int mostrar(int [], int);
void sumar(int [], int [], int );

int main()
{
	int a[50],c[50], j;
	printf("Ingrese la cantidad de elementos que desea agregar: ");
	scanf("%i", &j);
	ingresar(a,j);
	
	printf("El resultado es: \n");
	sumar(a, c,j);
	
	mostrar(c,j);
	return 0;
}

int ingresar(int l[], int j)
{
	int i;
	for (i = 0; i<j; i++)
		scanf("%i", &l[i]);
}

int mostrar(int l[], int j)
{
	int i;
	if (j % 2 == 0)
	{
		for (i = 0; i<j/2; i++)
			printf("%i\n", l[i]);
	}
	else
	{
		for (i = 0; i<(j/2)+1; i++)
                        printf("%i\n", l[i]);
	}
}

void sumar(int l[],int c[], int j)
{
	int i, n;
      	n = j-1;	
	for (i = 0; i<j/2; i++)
		c[i] = l[i] + l[n];

	if (j % 2 != 0)
		c[i] = l[i];
}
