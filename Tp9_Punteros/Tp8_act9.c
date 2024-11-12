#include <stdio.h>

double *menorVector(double *v, int n);

int main() {
	double vector[5] = {3.312,3.14123,3.12415,56,31}, menorElemento;
	
	menorElemento = *menorVector(vector, 5);
	printf("El elemento menor del vector es: %lf", menorElemento);
	
	
	return 0;
}

double *menorVector(double *v, int n){
	int i;
	double *menor = v;
	
	for(i = 0; i < n; i++){
		if(*menor > *(v+i)){
			menor = v+i;
		}
	}
	
	return menor;
}

