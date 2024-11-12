#include <stdio.h>
#include <conio.h>
#define BASICO 1800

int main(){
	//Declaracion de variables
	float x;
	float sldo_br;
	float obr_soc;
	float jub;
	float sldo_fn;
	
	
	//Ingreso del monto
	printf("Ingrese el monto\n");
	scanf("%f", &x);
	
	//Calculo de comision para distintos valores
	if (x < 10000)
	{
		sldo_br = BASICO + (2.0/100) * x;
		
	}
	else if (x >= 10000 && x < 50000)
	{
		sldo_br = BASICO + (3.5/100) * x;
	}
	else
	{
		sldo_br = BASICO + (5.0/100) * x;
	}
	
	//Calculo de impuestos
	obr_soc = (3.5/100) * sldo_br;
	jub = (11.0/100) * sldo_br;
	sldo_fn = sldo_br - (obr_soc + jub);
	printf("Sueldo bruto: %.2f\n Obra social:%.2f\n Jubilacion: %.2f\n Sueldo Neto: %.2f\n",sldo_br,obr_soc,jub,sldo_fn);

	return 0;
}
