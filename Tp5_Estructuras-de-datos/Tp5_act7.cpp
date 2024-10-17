#include <stdio.h>

/*

7.- Dado un número entero, descomponerlo y almacenar sus dígitos en un vector.
Ej. Nro. 347 ---> genera el vector A= (3, 4, 7)

*/

int descomponer(int);
void agregar(int, int, int []);
void mostrar(int [], int);

int main()
{
	int nro, vector[50], elemento, contador = 0, pos = 0;
	printf("Ingrese un número: ");
	scanf("%i", &nro);
	
	while(nro > 0)
	{
		elemento = descomponer(nro);
		agregar(elemento, pos, vector);
		contador++;
		pos++;
		nro = nro / 10;
	}
	mostrar(vector, contador);
	//printf("%i", contador);
	
	return 0;
}

int descomponer(int nro)
{
	int dig;
	dig = nro % 10;
	
	return dig;
}

void agregar(int a,int pos , int v[])
{
	v[pos] = a;
}

void mostrar(int l[], int j)
{
	int i;
	
	for (i = 0; i<j; i++)
		printf("%i\n", l[i]);
}
