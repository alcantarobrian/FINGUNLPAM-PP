#include <stdio.h>
//15.- Escribir una función moneda que permita convertir un monto de dinero de pesos a dólares y viceversa.
#define DOL 0.0010
#define ARS 953.48
float conv_ars_dol(float pesos);
float conv_dol_ars(float dolar);

int main()
{
	float pesos, dolar, rtdo;
	int op;
	
	printf("Que quieres convertir...\n");
	printf("1. Pesos a dolares\n");
	printf("2. Dolares a pesos\n");
	scanf("%i", &op);
	
	if (op == 1)
	{
		printf("Ingrese la cantidad en pesos: ");
		scanf("%f", &pesos);
		
		rtdo = conv_ars_dol(pesos);
		printf("El resultado de la conversion son: %.2f",rtdo);
	}
	else if (op == 2)
	{
		printf("Ingrese la cantidad en dolares: ");
		scanf("%f", &dolar);
		
		rtdo = conv_dol_ars(dolar);
		printf("El resultado de la conversion son: %.2f",rtdo);
	}
	else 
		printf("Opción no válida");
	
	return 0; 
}

float conv_ars_dol(float pesos)
{
	float rtdo;
	rtdo = pesos * DOL;
	return rtdo;
}

float conv_dol_ars(float dolar)
{
	float rtdo;
	rtdo = dolar * ARS;
	return rtdo;
}




