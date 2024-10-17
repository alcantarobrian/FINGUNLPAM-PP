#include <stdio.h>

/*12.- Escribir una funci�n primo que imprima todos los n�meros primos en un rango dado de n�meros.
La funci�n recibe dos valores, el valor m�nimo y el valor m�ximo del rango. */

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


