#include <stdio.h>

int det_par(int a);

int main()
{
	int nro;
	
	printf("Ingrese un n�mero: ");
	scanf("%i", &nro);
	
	if (det_par(nro) == 1)
		printf("El n�mero es par\n");
	else 
		printf("El n�mero es impar\n");
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
