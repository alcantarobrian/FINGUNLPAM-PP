#include <stdio.h>
#include <conio.h>

int main()
{
	int num1, num2, num3;
	
	printf("Ingrese el primer número: ");
	scanf("%i", &num1);
	
	printf("Ingrese el segundo número: ");
	scanf("%i", &num2);
	
	printf("Ingrese el tercer número: ");
	scanf("%i", &num3);
	
	if (num1 > num2 && num1 > num3)
		printf("El número más grande es: %i", num1);
	
	else if (num2 > num1 && num2 > num3)
		printf("El números más grande es: %i", num2);
	
	else
		printf("El número más grande es: %i", num3);
	
	return 0;
}
