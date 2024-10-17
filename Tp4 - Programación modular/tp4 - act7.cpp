#include <stdio.h>

int det_par(int a);

int main()
{
	int nro;
	
	printf("Ingrese un número: ");
	scanf("%i", &nro);
	
	if (det_par(nro) == 1)
		printf("El número es par\n");
	else 
		printf("El número es impar\n");
}

int det_par(int a)
{
	if(a % 2 == 0)
	{
		return 1;
	}
	else
	   return 2;
}
