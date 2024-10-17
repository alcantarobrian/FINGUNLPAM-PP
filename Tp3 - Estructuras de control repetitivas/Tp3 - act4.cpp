#include <stdio.h>

int main()
{
	int i;
	printf("Impares     Pares\n");
	
	for(i = 1; i < 50; i++){
		if (i % 2 != 0)
			printf("%3i\n", i);

		else
			printf("%15i\n", i);
	}
	return 0;
}
/*
#include <stdio.h>

int main(){
	int i;
	
	printf("Impares      Pares\n");
	
	for (i = 1; i < 50; i++)
	{
		printf("%3i %12i\n", i+1, i);
	}
}
*/
