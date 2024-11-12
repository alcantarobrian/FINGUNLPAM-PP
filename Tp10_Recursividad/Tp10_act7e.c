#include <stdio.h>

int searchL(int [], int, int, int);

int main() {
	int num, indice, cant;
	int arreglo[] = {1,2,3,4,53,6,7,5,2,87,9,6,4,2,4};
	
	num = 6;
	cant = 15;
	
	indice = searchL(arreglo, num, 0, cant);
	
	printf("El elemento %i está en la posicion: %i",num,indice);
	
	return 0;
}

int searchL(int arreglo[], int num, int indice, int cant){
	int pos;
	
	
	if(indice >= cant){
		pos = -1;
	}
	
	if(arreglo[indice] == num){
		pos = indice;
	}
	else{
		pos = searchL(arreglo, num, indice+1, cant);
	}
	return pos;
}