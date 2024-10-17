#include <stdio.h>
#include <conio.h>
#define PI 3.14159265

int main(){
	float d;
	float v;
	float a;
	
	printf("Ingrese el valor del diametro\n");
	scanf("%f", &d);
	if (d > 0){
		v = PI * ((d*d*d)/6);
		a = PI * ((d*d)/4);
		
		printf("El valor del volumen es: %.2f\n",v);
		printf("El valor del area es: %.2f\n",a);
	}
	else {
		printf("Ingrese un valor valido\n");
	}
	
	return 0;
}
