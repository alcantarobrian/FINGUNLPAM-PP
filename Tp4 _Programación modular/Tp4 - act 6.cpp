#include <stdio.h>

int mcd(int a, int b);

int main()
{
	int a, b, c_d;
	
	printf("Ingrese el primer número");
	scanf("%i", &a);
	
	printf("Ingrese el segundo número");
	scanf("%i", &b);
	
	c_d = mcd(a, b);
	
	printf("El mcd: %i", c_d);
	
	return 0;
}

int mcd(int a, int b)
{
	int resto;
	
	resto = a % b;

	while (resto != 0)
	{
		a = b;
		b = resto;
		resto = a % b;
	}
	return b;
	}
	
