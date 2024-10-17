#include <stdio.h>
#include <math.h>


int main()
{
	int num1, num2, num3, op, bcle;
	bcle = 1;
	
	printf("Ingrese el primer número");
	scanf("%i", &num1);
	
	printf("Ingrese el segundo número");
	scanf("%i", &num2);
	
	printf("Ingrese el tercer número");
	scanf("%i", &num3);
	while (bcle)
	{
	printf("Que quieres hacer:\n");
	printf("1. Imprimir el mayor\n");
	printf("2. Imprimir el menor en valor absoluto\n");
	printf("3. Imprimirlos en orden ascendente\n");
	printf("4. Imprimirlos por orden inverso al ingresado\n");
	printf("0. Salir...\n");
	scanf("%i", &op);
	
	switch(op)
	{
	case 1:
		if (num1 > num2 && num1 > num3)
			printf("%i", num1);
		else if (num2 > num1 && num2 > num3)
			printf("%i", num2);
		else
			printf("%i", num3);
		break;
	
	case 2:
		if (abs(num1) < abs(num2) && abs(num1) < abs(num3))
			printf("%i", num1);
		else if (abs(num2) < abs(num1) && abs(num2) < abs(num3))
			printf("%i", num2);
		else
			printf("%i", num3);
		break;
	
	case 3:
		if (num1 > num2 && num1 > num3 && num2 > num3)
			printf("%i, %i, %i", num3, num2, num1);
		else if (num2 > num1 && num2 > num3 && num1 > num3)
			printf("%i, %i, %i", num3, num1, num2);
		else if (num2 > num1 && num2 > num3 && num3 > num1)
			printf("%i, %i, %i", num1, num3, num2);
		else if (num1 > num2 && num1 > num3 && num3 > num2)
			printf("%i, %i, %i", num2, num3, num1);
		else if (num3 > num1 && num3 > num2 && num1 > num2)
			printf("%i, %i, %i", num2, num1, num3);
		else
			printf("%i, %i, %i", num1, num2, num3);
		break;
	
	case 4:
		printf("%i, %i, ,%i", num3, num2, num1);
		break;
	
	case 0:
		bcle = 0;
	}
	return 0;
	}
}
