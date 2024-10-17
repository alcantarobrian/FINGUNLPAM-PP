#include <stdio.h>
#include <conio.h>

int main(){
	//Definir variables
	int a,b,c;
	
	//Inicializarlas con entradas
	printf("Ingresa el primer numero: ");
	scanf("%i", &a);
	
	printf("Ingresa el segundo numero: ");
	scanf("%i", &b);
	
	printf("Ingresa el tercer numero: ");
	scanf("%i", &c);
	
	//Determinar orden de numeros
	if(a<b){
	if(b<c){
		printf("el orden es: %i, %i, %i", a,b,c);
	}else{
		if(a<c){
			printf("el orden es: %i, %i, %i", a,c,b);
		}else{
			printf("el orden es: %i, %i, %i", c,a,b);
		}
	}
	}else{
		if(a<c){
			printf("el orden es: %i, %i, %i", b,a,c);
		}else{
			if(b<c){
				printf("el orden es: %i, %i, %i", b,c,a);
			}else{
				printf("el orden es: %i, %i, %i", c,b,a);
			}
		}
	}
	return 0;
}
