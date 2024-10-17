#include <stdio.h>

/*12.- Escribir una función primo que imprima todos los números primos en un rango dado de números.
La función recibe dos valores, el valor mínimo y el valor máximo del rango. */

int det_primo(int a);

int main()
{
	int min, max, i, primo;
	
	printf("Ingrese un numero: ");
	scanf("%i", &min);
	
	printf("Ingrese otro numero (mayor al anterior): ");
	scanf("%i", &max);
		
	for (i = min; i <= max; i++)
	{
		primo = det_primo(i);
		if (primo == 0)
		{
			printf("%d, ", i);
		}
	}
}

int det_primo(int a)
{
	int i, primo;
	
	primo = 0;
	
	for (i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			primo = 1;
		}
	}
	return primo;
}


