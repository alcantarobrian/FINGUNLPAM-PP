#include <stdio.h>

int main()
{
	int a;
	
	printf("Ingrese un a�o: ");
	scanf("%i", &a);
	
	if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
		printf("El a�o es bisiesto");
	
	else
		printf("El a�o no es bisiesto");
	
	return 0;
}
