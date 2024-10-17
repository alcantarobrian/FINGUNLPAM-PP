#include <stdio.h>
#include <conio.h>

int main(){
	//Declaracion de variables
	int uni;
	int dec;
	int cent;
	int uni_de_mil;
	int resultado;
	
	//Entradas de números
	printf("Ingresa un número (representa los miles)");
	scanf("%i", &uni_de_mil);
	
	printf("Ingresa un número (representa las centenas)");
	scanf("%d", &cent);
	
	printf("Ingresa un número (representa las decenas)");
	scanf("%d", &dec);
	
	printf("Ingresa un número (representa las unidades)");
	scanf("%d", &uni);
	
	//Calculo de número
	resultado = uni_de_mil * 1000 + cent * 100 + dec * 10 + uni;
	
	//Muestra de resultado
	printf("El numero es: %i", resultado);

}
