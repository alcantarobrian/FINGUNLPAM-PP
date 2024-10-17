#include <stdio.h>

#define MAX_FILAS 100
#define MAX_COLUMNAS 100

void cargarMatriz(int [][MAX_COLUMNAS], int, int);
void transformarAMatrices(int [][MAX_COLUMNAS], int, int, int [][MAX_COLUMNAS]);
void imprimirVectores(int [][MAX_COLUMNAS], int, int);

int main() {
	int matriz[MAX_FILAS][MAX_COLUMNAS];
	int vectores[MAX_FILAS][MAX_COLUMNAS];
	int filas, columnas;
	
	printf("Ingrese el número de filas (N): ");
	scanf("%d", &filas);
	printf("Ingrese el número de columnas (M): ");
	scanf("%d", &columnas);
	
	cargarMatriz(matriz, filas, columnas);
	
	transformarAMatrices(matriz, filas, columnas, vectores);
	
	imprimirVectores(vectores, filas, columnas);
	
	return 0;
}

void cargarMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas) {
	printf("Ingrese los elementos de la matriz:\n");
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			printf("Elemento [%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
}

void transformarAMatrices(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas, int vectores[MAX_FILAS][MAX_COLUMNAS]) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			vectores[i][j] = matriz[i][j]; 
		}
	}
}

void imprimirVectores(int vectores[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas) {
	for (int i = 0; i < filas; i++) {
		printf("Vector %d: ", i+1);
		for (int j = 0; j < columnas; j++) {
			printf("%d ", vectores[i][j]);
		}
		printf("\n");
	}
}
