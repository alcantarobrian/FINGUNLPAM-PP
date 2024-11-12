#include <stdio.h>
#include <conio.h>

int main(){
	float num1,num2;
	char op;
	
	printf("Ingrese el primer numero\n");
	scanf("%f", &num1);
	
	printf("Ingrese el tipo de operacion ('+','-','*','/')\n");
	scanf("%s", &op);
	
	printf("Ingrese el segundo numero\n");
	scanf("%f", &num2);
	
	if (op == '+')
		printf("El resultado es: %.2f\n", num1 + num2);
	
	else if (op == '-')
		printf("El resultado es: %.2f\n", num1 - num2);
	
	else if (op == '/')
	{
		if (num2 != 0)
			printf("El resultado es: %.2f\n", num1 / num2);
		else
			printf("Error: 'Division por cero'\n");
	}
	
	else if (op == '*')
		printf("El resultado es: %.2f\n", num1 * num2);
	
	else
		printf("opción no válida");
	
	return 0;
}
