#include <stdio.h>
#include <conio.h>

int main(){
	//definicion de variables...
	int x;
	int y;
	int z;
	
	int x2, x3, x4;
	int y2, y3, y4;
	int z2, z3, z4;
	
	char n[10] = "Nro";
	char n2[10] = "Nro^2";
	char n3[10] = "Nro^3";
	char n4[10] = "Nro^4";
	
	//ingreso de valores...
	printf("Ingrese el primer numero\n");
	scanf("%i", &x);
	
	printf("Ingrese el segundo numero\n");
	scanf("%i", &y);

	printf("Ingrese el tercer numero\n");
	scanf("%i", &z);
	
	//calc de potencias...
	x2 = x * x;
	x3 = x * x * x;
	x4 = x * x * x * x;
	
	y2 = y * y;
	y3 = y * y * y;
	y4 = y * y * y * y;
	
	z2 = z * z;
	z3 = z * z * z;
	z4 = z * z * z * z;
	
	//Imprimir cuadro...
	printf("%6s %6s %6s %6s\n", n, n2, n3, n4);
	printf("%6d %6d %6d %6d\n", x, x2, x3, x4);
	printf("%6d %6d %6d %6d\n", y, y2, y3, y4);
	printf("%6d %6d %6d %6d\n",z, z2, z3, z4);
	
	return 0;
}
