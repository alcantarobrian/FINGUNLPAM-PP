#include <stdio.h>
#include <conio.h>

int main(){
	int op;
	
	printf("Ingrese el c�digo del curso\n");
	scanf("%i", &op);
	
	switch (op)
	{
	case 1002:
		printf("Biolog�a");
		break;
		
	case 2031:
		printf("Qu�mica");
		break;
		
	case 3121:
		printf("Ciencias de la computaci�n");
		break;
		
	case 4421:
		printf("Geolg�a");
		break;
		
	case 5311:
		printf("Matem�tica");
		break;
		
	case 6976:
		printf("Fisica");
		break;

	default:
		printf("C�digo ingresado incorrecto");
		break;
	}
	return 0;
}
