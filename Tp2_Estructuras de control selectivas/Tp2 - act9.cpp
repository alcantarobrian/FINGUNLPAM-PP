#include <stdio.h>
#include <conio.h>

int main(){
	int op;
	
	printf("Ingrese el código del curso\n");
	scanf("%i", &op);
	
	switch (op)
	{
	case 1002:
		printf("Biología");
		break;
		
	case 2031:
		printf("Química");
		break;
		
	case 3121:
		printf("Ciencias de la computación");
		break;
		
	case 4421:
		printf("Geolgía");
		break;
		
	case 5311:
		printf("Matemática");
		break;
		
	case 6976:
		printf("Fisica");
		break;

	default:
		printf("Código ingresado incorrecto");
		break;
	}
	return 0;
}
