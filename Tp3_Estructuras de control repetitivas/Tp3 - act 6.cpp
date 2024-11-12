#include <stdio.h>

int main()
{
	int nro, i, par, impar;
	i = 1;
	par = 0;
	impar = 0;

	while(i)
	{
		printf("Ingrese un número (0 para finalizar): ");
		scanf("%i", &nro);
		
		if (nro == 0)
			i = 0;
		
		else if (nro % 2 != 0)
			impar++;
		
		else
			par++;
	}
	
	printf("Numeros pares: %i\nNumero impares: %i", par, impar);
	
	return 0;
}
