#include <stdio.h>
#include <conio.h>

int main(){
	int a, bi, c, di, op, p_r, p_i;
	int bcle = 1;
	while (bcle)
	{
		printf("Ingrese la parte de real del primer numero\n");
		scanf("%i", &a);
		
		printf("Ingrese la parte de imaginaria del primer numero\n");
		scanf("%i", &bi);
		
		printf("Ingrese la parte de real del segundo numero\n");
		scanf("%i", &c);
		
		printf("Ingrese la parte de imaginaria del segundo numero\n");
		scanf("%i", &di);
		
		printf("Que quieres hacer:\n");
		printf("1. Sumar\n");
		printf("2. Restar\n");
		printf("3. Multiplicar\n");
		printf("4. Dividir\n");
		printf("0. salir\n");
		scanf("%i", &op);
	
		switch(op){
		case 1:
			p_r = a + c;
			p_i = bi + di;
			printf("El resultado de la suma es: %i+%ii\n",p_r,p_i);
			break;
		
		case 2:
			p_r = a - c;
			p_i = bi - di;
			printf("El resultado de la resta es: %i+%ii\n",p_r,p_i);
			break;
		
		case 3:
			p_r = a*c - bi*di;
			p_i = a*di + bi*c;
			printf("El resultado de la multiplicacion es: %i+%ii\n",p_r,p_i);
			break;
		
		case 4:
			if (c == 0 && di == 0)
			{
				printf("No se puede realizar la division por 0\n");
			}
			else
			{
			p_r = (a*c + bi * di)/(c*c + di * di);
			p_i = (bi * c - a * di)/(c*c + di * di);
			printf("El resultado de la division es: %i+%ii\n",p_r,p_i);
			}
			break;
		
		case 0:
			bcle = 0;
			break;
		}
	}
	return 0;
}
