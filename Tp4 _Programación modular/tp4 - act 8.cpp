#include <stdio.h>

int div(int a, int b);

int main()
{
	int num1, num2;
	
	printf("Ingrese el primer número: ");
	scanf("%i", &num1);
	
	printf("Ingrese el segundo número: ");
	scanf("%i", &num2);
	
	return div(num1,num2); 
}
 
int div(int a, int b)
{
	if(a % b == 0)
	{
		return 1;
	}
	else 
	   return 0;
}
