#include <stdio.h>

int det(char a);

int main()
{
	char a;
	
	printf("Ingresa un caracter: ");
	scanf("%c", &a);
	
	if (det(a))
		printf("El dato %c es es uno de los digitos\n", a);
	else
		printf("El dato %c no es uno de los digitos\n", a);
}

int det(char a)
{
	if (a >= '0' && a <= '9')
		return 1;
	else 
		return 0;
}
