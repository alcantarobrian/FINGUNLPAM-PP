#include <stdio.h>

int searchB(int [], int, int, int);

int main() {
	int vector[] = {1,2,3,4,5,6,7,8,9,10, 20, 30, 52, 110, 3215, 6746};
	int inicio, fin, elemento, pos;
	inicio = 0;
	fin = 16;
	elemento = 999;
	
	pos = searchB(vector, elemento, inicio, fin);
	
	if(pos != -1){
		printf("El elemento %i se encuentra en la posicion: %i", elemento, pos);
	}
	else{
		printf("El elemento no se encuentra en el arreglo");
	}
	
	return 0;
}

int searchB(int vector[], int elemento, int i, int f){
	int med, pos = -1;
	
	
	if (i <= f){
			med = i+(f-i)/2;

	
		if (vector[med] == elemento){
			pos = med;
		}

		else if(vector[med] > elemento){
			pos = searchB(vector, elemento, i, med - 1);
		}

		else{
			pos = searchB(vector, elemento, med + 1, f);
		}
	}
	return pos;
}


