#include <stdio.h>
#include <conio.h>
//Consigna: --- Escribir un programa que lea 2 n�meros y un car�cter (+ - / *) y realice la operaci�n correspondiente

int main(){
	//Definir variables
	int nro1,nro2,result;
	char op;
	
	//Inicializar variables con entradas
	printf("Ingrese el primer n�mero entero: ");
	scanf("%i", &nro1);
	
	printf("Ingrese el segundo n�mero entero: ");
	scanf("%i", &nro2);
	
	printf("Que tipo de operacion va a realizar (+ - / *): ");
	op = getch();
	
	
	//Evaluar el tipo de operacion
	if (op == '+'){
		result = nro1 + nro2;
		printf("El resultado es: %i", result);
	}else if (op == '-'){
		result = nro1 - nro2;
		printf("El resultado es: %i", result);
	}else if (op == '/'){
		if (nro2 == 0){
			printf("no se puede dividir por 0");
			return 0;
		}
		result = nro1 / nro2;
		printf("El resultado es: %i", result);
	}else if (op == '*'){
		result = nro1 * nro2;
		printf("El resultado es: %i", result);
	}
	
	//Fin de programa
	return 0;
}
