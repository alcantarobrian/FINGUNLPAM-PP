#include <stdio.h>
#include <conio.h>

int main(){
	int d, m, a;
	
	printf("Ingresa un dia: ");
	scanf("%i",&d);
	
	printf("Ingresa un mes: ");
	scanf("%i",&m);
	
	printf("Ingresa un año: ");
	scanf("%i",&a);
	
	if (a >= 1900 && a <= 1999 && d <= 31 && d >= 1)
	{
		switch(m)
		{
		case 1: case 3: case 5: case 7: case 8: case 10:
			if (d == 31)
				{
					m = m + 1;
					d = 1;
			}
			else
				{
					d = d + 1;
			}
			printf("%i/%i/%i\n",d, m, a);
			break;

		case 4: case 6: case 9: case 11:
			if (d == 30)
				{
					m = m+1;
					d = 1;
			}
			else
				{
					d = d+1;
			}
			printf("%i/%i/%i\n",d, m, a);
			break;
			
		case 2:
			if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
			{
				if (d == 28)
				{
					d = d + 1;
				}
				else if (d == 29)
				{
					m = m + 1;
					d = 1;
				}
				else
				{
					d = d + 1;
				}
			}
			else 
			{
				if (d == 28)
				{
					m = m + 1;
					d = 1;
				}
				else 
				{
					d = d + 1;
				}
			}
			printf("%i/%i/%i\n",d, m, a);
			break;
			
		case 12:
				if (d == 31)
				{
					if (a == 1999)
					{
						printf("Fecha ingresada no válida\n");
					}
					else
					{
						d = 1;
						m = 1;
						a = a + 1;
						printf("%i/%i/%i\n",d, m, a);
					}
				}
				else
					{
					d = d + 1;
					printf("%i/%i/%i\n",d, m, a);
				}
				break;
		default:
			printf("Fecha ingresada no válida");
	return 0;
  }
 }
	else 
		printf("Fecha ingresada no válida\n");
}
