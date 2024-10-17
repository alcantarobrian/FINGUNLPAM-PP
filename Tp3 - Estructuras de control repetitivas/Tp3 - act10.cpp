#include <stdio.h>

int main()
{
	int cont, val, mayor, menor, num, bcle;
	float media;
	
	bcle = 1;
	cont = 1;
	
	while(bcle)
	{
		printf("Ingrese un numero: ");
		scanf("%i", &num);
		
		cont++;
		val += num;
		
		if (num == 0)
			bcle = 0;

		else if (num < menor)
			menor = num;

		else if (num > mayor)
			mayor = num;
		}
	
	if (cont > 0)
	{
		media = val / cont;
	
		printf("El número mayor es: %i\n", mayor);
		printf("El número menor es: %i\n", menor);
		printf("La media es: %.2f\n", media);
	}
	else
		printf("Se ingresaron números no válido");
}
