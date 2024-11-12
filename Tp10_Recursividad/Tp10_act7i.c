#include <stdio.h>

void inserccion(int [], int);
void mostrar(int[], int);

int main() {
	int vector[] = {1234,31,123,53467,112115,12312,5123,64577,23416};
	int cantidad = 9;
	
	printf("\nVector original: ");
	mostrar(vector, cantidad);
	
	inserccion(vector, cantidad);
	
	printf("\nVector ordenado: ");
	mostrar(vector, cantidad);
	
	return 0;
}

void inserccion(int vector[], int cant){
	int ult, j;
	
	ult = vector[cant - 1];
	j = cant - 2;
	
	if(cant > 1){
		inserccion(vector, cant - 1);
	}
	
	while (j >= 0 && vector[j] > ult) {
		vector[j + 1] = vector[j];
		j--;
	}
	
	vector[j + 1] = ult;
}

void mostrar(int a[], int n){
	int i;
	
	for(i = 0; i < n; i ++){
		printf("\nElemento(%i): %i", i+1, a[i]);
	}
}
