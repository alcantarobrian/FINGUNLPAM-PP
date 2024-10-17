#include <stdio.h>

/*

4.- Hacer un programa que lea dos vectores A y B, y realice la suma y el producto escalar de ambos

*/

void ingresar(int []);
void mostrar(int []);
void suma(int [], int [], int []);
int producto_escalar(int [], int []);

int main()
{
	int a[5], b[5], c[5], resultado_producto_escalar;
	
	printf("Ingrese el primer vector:\n");
	ingresar(a);

	printf("\n");
	
	printf("Ingrese el segundo vector:\n");
	ingresar(b);
	
	printf("\n");
	
	printf("El resultado de sumar el primer vector con el segundo es: \n");
	suma(a,b,c);
	mostrar(c);
	
	printf("\n");
	
	printf("El resultado de realizar el producto escalar es: ");
	resultado_producto_escalar = producto_escalar(a,b);
	printf("%i", resultado_producto_escalar);
	
	return 0;
}

void ingresar(int l[])
{
	int i;
	
	for (i = 0; i < 5; i++)
		scanf("%i", &l[i]);
}

void mostrar(int l[])
{
	int i;
	
	for (i = 0; i < 5; i++)
		printf("%i\n", l[i]);
}

void suma(int a[], int b[], int c[])
{
	int i;
	
	for(i = 0; i < 5; i++)
		c[i] = a[i] + b[i];
}

int producto_escalar(int a[], int b[])
{
	int rtdo = 0, i;
	
	for (i = 0; i < 5; i++)
		rtdo += a[i] * b[i];
		
	return rtdo;
}

