#include <stdio.h>

/* 

11. Realizar un programa que permita almacenar en un vector Número los números de la lotería y en
un vector Posicion la posición que ocupa. Se deben almacenar los 10 primeros números de la lotería.

*/

int numero(int [], int);
int posicion(int [], int);
void mostrar(int [], int []);

int main()
{
	int v_num[11], v_pos[11], cont = 0, nro;
	
	do 
	{
		cont++;
		
		printf("Ingrese un número: ");
		scanf("%i", &nro);

		v_num[cont] = nro;	
		v_pos[cont] = cont; 
	
	}while(cont < 10);
	
	printf("Posición      Número\n");
	mostrar(v_pos, v_num);
}	

void mostrar(int a[], int b[])
{
	int i;
	for (i = 1; i <= 10; i++)
	{
		printf("%5i %13i\n", a[i], b[i]);
	}
}
