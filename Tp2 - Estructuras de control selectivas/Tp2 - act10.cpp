#include <stdio.h>
#include <conio.h>

int main()
{
	int num1, num2, num3;
	
	printf("Ingrese el primer n�mero: ");
	scanf("%i", &num1);
	
	printf("Ingrese el segundo n�mero: ");
	scanf("%i", &num2);
	
	printf("Ingrese el tercer n�mero: ");
	scanf("%i", &num3);
	
	if (num1 > num2 && num1 > num3)
		printf("El n�mero m�s grande es: %i", num1);
	
	else if (num2 > num1 && num2 > num3)
		printf("El n�meros m�s grande es: %i", num2);
	
	else
		printf("El n�mero m�s grande es: %i", num3);
	
	return 0;
}
