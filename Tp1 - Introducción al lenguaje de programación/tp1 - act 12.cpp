#include <stdio.h>
#include <conio.h>

//consigna: --- Escribir un programa que lee 3 numeros y muestre el mayor y menor	

int main(){
	//Definir variables
	int nro1,nro2,nro3,mayor,menor;
	
	//Inicializarlas con entradas
	printf("Ingresa el primer numero: ");
	scanf("%i", &nro1);
	
	printf("Ingresa el segundo numero: ");
	scanf("%i", &nro2);
	
	printf("Ingresa el tercer numero: ");
	scanf("%i", &nro3);
	
	//Determinar numero mas grande
	mayor = nro1;
	
	if (mayor < nro2){
		mayor = nro2;
	}if (mayor < nro3){
		mayor = nro3;
	};
	
	//Determinar numero mas chico
	menor = nro1;
	
	if(menor > nro2){
		menor = nro2;
	}if(menor > nro3){
		menor = nro3;
	}
	
	//Imprime los resultados
	printf("El numero mayor es: %i\n El numero menor es: %i",mayor, menor);
	
	return 0;
}
