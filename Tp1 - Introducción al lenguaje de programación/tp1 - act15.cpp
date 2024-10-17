#include <stdio.h>
#include <conio.h>

int main(){
	//definicion de variables
	int nro;
	
	//inicilizacion de variables con entradas
	printf("Ingrese un número: ");
	scanf("%i", &nro);
	
	//Identificar si es par o impar
	if (nro % 2 == 0){
		printf("Es un numero par");
	}else{
		printf("Es un numero impar");
	}
	return 0;
}
