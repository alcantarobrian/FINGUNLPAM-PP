#include <stdio.h>

int main()
{
	float alt;
	char cont;
	
	printf("Ingrese su altura: ");
	scanf("%f", &alt);
	
	printf("Ingrese su contextura (chica, mediana, grande)");
	scanf("%s", &cont);
	
	if (alt > 1.55 && alt < 1.65)
	{
		if (cont == 'c')
		{
			printf("Su peso ideal es entre 50.0kg - 54.0kg");
		}
		else if (cont == 'm')
		{
			printf("Su peso ideal es entre 53.0kg - 58.0kg");
		}
		else if (cont == 'g')
		{
			printf("Su peso ideal es entre 56.0kg - 63.0");
		}
		else 
			printf("Contextura ingresada no válida");
	}
	else if (alt > 1.66 && alt < 1.75)
	{
		if (cont == 'c')
		{
			printf("Su peso ideal es entre 56.5kg - 60.5kg");
		}
		else if (cont == 'm')
		{
			printf("Su peso ideal es entre 59.0kg - 65.0kg");
		}
		else if (cont == 'g')
		{
			printf("Su peso ideal es entre 63.0kg - 71.0");
		}
		else 
				 printf("Contextura ingresada no válida");
	}
	else if (alt > 1.76 && alt < 1.85)
	{
		if (cont == 'c')
		{
			printf("Su peso ideal es entre 63.5kg - 68.0kg");
		}
		else if (cont == 'm')
		{
			printf("Su peso ideal es entre 65.7kg - 73.0kg");
		}
		else if (cont == 'g')
		{
			printf("Su peso ideal es entre 70.0kg - 79.0");
		}
		else 
				 printf("Contextura ingresada no válida");
	}
	else if (alt > 1.86 && alt < 2.00)
	{
		if (cont == 'c')
		{
			printf("Su peso ideal es entre 71.0kg - 76.0kg");
		}
		else if (cont == 'm')
		{
			printf("Su peso ideal es entre 74.0kg - 82.0kg");
		}
		else if (cont == 'g')
		{
			printf("Su peso ideal es entre 79.0kg - 88.0");
		}
		else 
				 printf("Contextura ingresada no válida");
	}
	else
		printf("Altura ingresada no válida");
}
