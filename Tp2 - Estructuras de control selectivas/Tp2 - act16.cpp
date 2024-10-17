#include <stdio.h>

int main()
{
	int a;
	
	printf("Ingrese un año: ");
	scanf("%i", &a);
	
	if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
		printf("El año es bisiesto");
	
	else
		printf("El año no es bisiesto");
	
	return 0;
}
