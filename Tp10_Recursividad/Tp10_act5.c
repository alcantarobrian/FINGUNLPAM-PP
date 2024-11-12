#include <stdio.h>

int cadena (char cad[],int pi,int pf)
{
	int r;
	if (pi>=pf)
		return(0);
	else
		if (cad[pi]==cad[pf])
			r=cadena(cad,pi+1,pf-1);
	else
		r=1;
	
	return(r);
}

int main(){
	char string[] = "1111111111";
	int i, j, nro;
	i = 0;
	j = 10;
	
	nro = cadena(string,i,j);
	
	printf("%i", nro);
	
	return 0;
}