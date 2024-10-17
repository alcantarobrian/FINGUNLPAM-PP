#include <stdio.h>

/*

3.- Hacer un programa que ingrese un vector de 'n' elementos y luego intercambie el primer elemento 
por el n-esimo; el segundo por n-esimo menos 1; y así sucesivamente .- No debe generarse un nuevo 
vector. Como salida debe imprimir el vector original y el vector intercambiado, con las 
especificaciones correspondientes.

*/

void ingresar(int [], int );

void mostrar(int [], int  );

void intercambiar(int [], int );

int main()
{
	int a[100], j;
	
	printf("Cuantos numeros deasea ingresar: ");
	scanf("%i", &j);
	
	ingresar(a,j);
	printf("\n\n");
	
	printf("El vector original es:\n");
	mostrar(a, j);
	
	printf("\n");
	
	printf("El vector con los elementos intercambiados es:\n");
	intercambiar(a,j);
	mostrar(a , j);
	
	return 0;
}

void ingresar(int l[], int j){
	int i;
	
	for (i = 0; i<j; i++)
	{
		scanf("%i", &l[i]);
	}	
}
void mostrar(int l[], int j)
{
	int i;
	
	for (i = 0;i<j; i++)
		printf("elemento en la posicion %i es: %i\n", i, l[i]);
}

void intercambiar(int l[], int j)
{
	int i, temp;
	j = j - 1;
	
	for (i = 0; i<=j/2; i++)
	{
		temp = l[i];
		l[i] = l[j];
		l[j] = temp;
		j--;
	}
}
