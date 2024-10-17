#include <stdio.h>

int main()
{
	int num1, num2, top, i;

	printf("Ingresa el primer numero: ");
	scanf("%i", &num1);
	
	printf("Ingresa el segundo numero (mayor al primero): ");
	scanf("%i", &num2);
	
	printf("Ingresa el tope: ");
	scanf("%i", &top);
	
	printf("La serie es: %i, %i",num1, num2);
	
	i = num2;
	
	while (i < top)
	{
		if (i+2 < top)
		{
			i += 2;
			printf(", %i", i);
		}
	}
	return 0;
}
