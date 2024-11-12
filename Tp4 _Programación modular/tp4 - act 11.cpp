#include <stdio.h>

float km_mi(float a);

float mi_km(float a);


int main()
{
	float km, mi, rtdo;
	int op;
	
	printf("Que quieres hacer...?\n");
	printf("1. Convertir km a mi\n");
	printf("2. Convertir mi a km\n");
	scanf("%i", &op);
	
	if (op == 1)
	{
		printf("Ingrese la cantidad de km: ");
		scanf("%f", &km);
		rtdo = km_mi(km);
		printf("El resultado es %.2f", rtdo);
	}
	else if (op == 2)
	{
		printf("Ingrese la cantidad de mi: ");
		scanf("%f", &mi);
		rtdo = mi_km(mi);
		printf("El resultado es %.2f", rtdo);
	}
	else
		printf("Opcion ingresada no válida");
}

float km_mi(float a)
{
	float convert;
	convert = a * 0.621371;
	return convert;
}

float mi_km(float a)
{
	float convert;
	convert = a * 1.60934;
	return convert;
}
