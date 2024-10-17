#include <stdio.h>

#define MAX_VECTORES 100
#define MAX_ELEMENTOS 100

void cargarVectores(int [][MAX_ELEMENTOS], int, int);
void imprimirMatriz(int [][MAX_ELEMENTOS], int, int);

int main() {
	
	int vectores[MAX_VECTORES][MAX_ELEMENTOS];
	int n, m;
	
	printf("Ingrese la cantidad de vectores (N): ");
	scanf("%d", &n);
	printf("Ingrese la cantidad de elementos por vector (M): ");
	scanf("%d", &m);
	
	cargarVectores(vectores, n, m);
	
	imprimirMatriz(vectores, n, m);
	
	return 0;
}


void cargarVectores(int vectores[MAX_VECTORES][MAX_ELEMENTOS], int n, int m) {
	printf("Ingrese los elementos de los vectores:\n");
	for (int i = 0; i < n; i++) {
		printf("Vector %d:\n", i + 1);
		for (int j = 0; j < m; j++) {
			printf("Elemento [%d]: ", j);
			scanf("%d", &vectores[i][j]);
		}
	}
}

void imprimirMatriz(int vectores[MAX_VECTORES][MAX_ELEMENTOS], int n, int m) {
	printf("Matriz resultante:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", vectores[i][j]);
		}
		printf("\n");
	}
}
