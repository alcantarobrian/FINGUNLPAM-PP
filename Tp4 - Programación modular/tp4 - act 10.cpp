#include <stdio.h>

int fact(int a);

int main()
{
	int a, rtdo;
	
	printf("Ingrese un número: ");
	scanf("%i", &a);
	
	rtdo = fact(a);
	
	printf("El resultado es: %i", rtdo);
}

int fact(int a)
{
	int i, temp, rtdo;
	temp = a;
	rtdo = 1;
	for (i = 1; i <= temp; i++)
	{
		rtdo *= a;
		a--;
	}
	return rtdo;
}
