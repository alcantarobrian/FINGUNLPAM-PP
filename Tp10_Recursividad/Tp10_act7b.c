#include <stdio.h>

int nSig(int);

int main() {
	int a = 235;
	
	printf("El numero mas significativo es: %i", nSig(a));
	
	return 0;
}

int nSig(int a){
	int pd;
	
	if(a < 0){
		a = -a;
	}
	if(a < 10){
		pd = a;
	}
	else{
		pd = nSig(a/10);
	}
	return pd;
}
