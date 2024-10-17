#include <stdio.h>

#define MAX_FILAS 100
#define MAX_COLUMNAS 100

void cargarMatriz(int [][MAX_COLUMNAS], int, int);
void sumarMatrices(int [][MAX_COLUMNAS], int [][MAX_COLUMNAS], int [][MAX_COLUMNAS], int, int);
void imprimirMatriz(int [][MAX_COLUMNAS], int, int, char);

int main() {
	int A[MAX_FILAS][MAX_COLUMNAS], B[MAX_FILAS][MAX_COLUMNAS], C[MAX_FILAS][MAX_COLUMNAS];
	int filas, columnas;
	
	
	printf("Ingrese el número de filas: ");
	scanf("%d", &filas);
	printf("Ingrese el número de columnas: ");
	scanf("%d", &columnas);
	
	printf("Cargar la matriz A:\n");
	cargarMatriz(A, filas, columnas);
	printf("Cargar la matriz B:\n");
	cargarMatriz(B, filas, columnas);
	
	sumarMatrices(A, B, C, filas, columnas);
	imprimirMatriz(A, filas, columnas, 'A');
	imprimirMatriz(B, filas, columnas, 'B');
	imprimirMatriz(C, filas, columnas, 'C');
	
	return 0;
}

void cargarMatriz(int matriz[][MAX_COLUMNAS], int filas, int columnas) {
	printf("Ingrese los elementos de la matriz:\n");
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			printf("Elemento [%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
}

void sumarMatrices(int A[][MAX_COLUMNAS], int B[][MAX_COLUMNAS], int C[][MAX_COLUMNAS], int filas, int columnas) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			C[i][j] = A[i][j] + B[i][j]; 
		}
	}
}

void imprimirMatriz(int matriz[][MAX_COLUMNAS], int filas, int columnas, char nombre) {
	printf("Matriz %c:\n", nombre);
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) 
		{
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

