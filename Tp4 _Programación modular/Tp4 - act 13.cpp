#include <stdio.h>

int op(int a, char b, int c);

int main()
{
	int a, b, c, rtdo;
	
	printf("Ingrese un numero: ");
	scanf("%i", &a);
	
	printf("Ingrese un operador (+,-,*,/): ");
	scanf("%s", &b);
	
	printf("Ingrese un numero: ");
	scanf("%i", &c);
	
	rtdo = op(a,b,c);
	
	if (rtdo == 'd')
		printf("Error: Division por cero");

	else
		printf("El resultado es: %i", rtdo);
}

int op(int a, char b, int c)
{
	int rtdo;
	if (b == '+')
	{
		rtdo = a + c;
	}
	else if (b == '-')
	{
		rtdo = a - c;
	}
	else if (b == '*')
	{
		rtdo = a * c;
	}
	else if (b == '/')
	{
		if (c == 0)
			rtdo = 'd';

		else
			{
			rtdo = a / c;
		}
	}
	return rtdo;
}
