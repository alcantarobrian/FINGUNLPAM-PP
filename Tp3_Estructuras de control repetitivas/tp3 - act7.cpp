#include <stdio.h>

int main()
{
	int i;

	printf("Nro  Nro^2  Nro^3\n");
	for (i = 1; i<=100; i++)
	{
		printf("%1i%6i%8i\n", i, i*i, i*i*i);
	}
	return 0;
}
