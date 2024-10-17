#include <stdio.h>

int main()
{
	int i,num,div;
	num = 1;
	div = 0;
	
	while (num <= 100)
	{
		for (i = 2; i <= num / 2; i++)
		{
			if (num % i == 0)
			{
				div++;
			}
		}
		if (div == 0)
			printf("%i\n", num);
		
		num++;
		div = 0;
	}
}
