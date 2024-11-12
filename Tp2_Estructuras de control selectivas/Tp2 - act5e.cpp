#include <stdio.h>
#include <math.h>
#define PI 3.1415

int main(){
	float alpha, beta;
	int gr, min, k;
	
	printf("Ingrese el valor de alpha\n");
	scanf("%f",&alpha);
	
	if (alpha > 0 && alpha < 30)
	{
		k = floor(alpha/(2 * PI));
		beta = alpha - 2 * k * PI;
		gr = floor(beta * 180/PI);
		min = floor((beta * 180/PI - gr)*60);
	
		printf("El valor de beta en gr y minutos es de: %i° %i'\n", gr, min);
	}
	return 0;
}
