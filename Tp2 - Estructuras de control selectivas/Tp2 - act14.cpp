#include <stdio.h>

int main(){
	int num;
	
	printf("Ingrese un número: ");
	scanf("%i", &num);
	
	if (num % 2 == 0)
	{
		printf("Es par, su ultimo digito es: %i", num % 10);
	}
	else
	{
		printf("Es impar, su ultimo digito es: %i", num % 10);
	}
	
	return 0;
}
