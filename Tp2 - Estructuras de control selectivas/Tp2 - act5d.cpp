#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	//Declaracion de variables...
	float cels;
	float fahr;
	float rldo;
	int op;
	int bcle;
	
	//Menu...
	while (bcle)
	{
		//Opciones del menu...
		printf("Que conversion desea realizar:\n");
		printf("1. Fahrenheit a Celsius\n");
		printf("2. Celsius a Fahrenheit\n");
		printf("3. Salir\n");
		
		scanf("%i",&op);
		
		//Calculo de temperatura...
		switch(op)
		{
			case 1:
			
				printf("Ingrese la temperatura\n");
				scanf("%f", &fahr);
		
				rldo = (fahr - 32.0) * 5.0/9.0;
				printf("El resultado es: %.2f\n", rldo);
				break;
		
			case 2:
			
				printf("Ingrese la temperatura\n");
				scanf("%f", &cels);
				
				rldo = 32.0 + 1.8 * cels;
				printf("El resultado es: %.2f\n", rldo);
				break;
				
			case 3:
				bcle = 0;
				break;
			
			default:
				printf("Opcion no valida\n");
				break;
		}
		
	}
	return 0;
}
