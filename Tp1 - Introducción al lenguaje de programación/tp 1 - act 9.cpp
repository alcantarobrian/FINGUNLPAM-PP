#include <stdio.h>
#include <conio.h>

int main(){
	//Definicion de variables
	float dec1, dec2;
	float sum, res, prod, div;
	
	//Entradas para las variables
	printf("Ingresa el primer numero decimal: ");
	scanf("%f", &dec1);
	
	printf("Ingresa el primer numero decimal: ");
	scanf("%f", &dec2);
	
	//Inicializacion de variables y calculos
	sum = dec1 + dec2;
	res = dec1 - dec2;
	prod = dec1 * dec2;
	div = dec1 / dec2;
	
	//Imprimir resultados
	printf("El resultado de la suma es: %.0f\n El resultado de la resta es: %.0f\n El resultado del producto es: %.0f\n El resultado de la division es: %.2f", sum,res,prod,div);
	
	return 0;
}
