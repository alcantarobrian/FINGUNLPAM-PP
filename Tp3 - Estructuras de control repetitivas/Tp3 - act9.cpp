#include <stdio.h>

int main()
{
	int bcle, num, rtdo, i, temp;
	bcle = 1;
	
	while(bcle)
	{
		printf("ingrese un numero (0 para finalizar): ");
		scanf("%i", &num);
		
		if (num == 0)
		{
			bcle = 0;
		}
		else
		{
			rtdo = 1;
			temp = num;
		
			for (i = 1; i < temp; i++)
			{
				rtdo *= num;
				num--;
			}
			printf("El resultado es: %i\n", rtdo);
		}
	}
}
