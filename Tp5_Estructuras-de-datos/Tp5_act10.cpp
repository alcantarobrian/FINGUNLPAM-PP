#include <stdio.h>

/*
10. Realizar un programa que permita concatenar en un vector un conjunto de números enteros
positivos dados. Utilizar el dígito -1 en el vector resultante como separador de los números
almacenados.
*/

int invertir(int );
void ingresar(int , int *, int []);
void mostrar(int [], int j);

int main()
{
	int nro, bcle = 1, a[100], i = 0;
      	while (bcle)
	{
		printf("Ingresa un número: ");       
		scanf("%i", &nro);

		if (nro == 0)
			bcle = 0;
		
		else 
		{
			nro = invertir(nro);
			ingresar(nro, &i, a);
			if (i < 100)
			{
				a[i] = -1;
				i++;
			}
		}
	}
	mostrar(a,i);
	
	return 0;
}

int invertir(int nro)
{
	int dig, nwnro = 0;
	while (nro != 0)
	{
		dig = nro % 10;
		nwnro = (nwnro * 10) + dig;
		nro = nro / 10;
	}	
	return nwnro;
}

void ingresar(int nro, int *i, int l[])
{
	int dig;
	while (nro != 0)
	{
		dig = nro % 10;
		l[*i] = dig;
		(*i)++;
		nro = nro / 10;
	} 
}

void mostrar(int l[], int j)
{
	int i;
	for (i = 0; i<j; i++)
		printf("%i ", l[i]);
}
