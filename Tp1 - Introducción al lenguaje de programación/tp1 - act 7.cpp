#include <stdio.h>
#include <conio.h>

int main(){
	//Declaracion de variables
	int uni;
	int dec;
	int cent;
	int uni_de_mil;
	int resultado;
	
	//Entradas de n�meros
	printf("Ingresa un n�mero (representa los miles)");
	scanf("%i", &uni_de_mil);
	
	printf("Ingresa un n�mero (representa las centenas)");
	scanf("%d", &cent);
	
	printf("Ingresa un n�mero (representa las decenas)");
	scanf("%d", &dec);
	
	printf("Ingresa un n�mero (representa las unidades)");
	scanf("%d", &uni);
	
	//Calculo de n�mero
	resultado = uni_de_mil * 1000 + cent * 100 + dec * 10 + uni;
	
	//Muestra de resultado
	printf("El numero es: %i", resultado);

}
