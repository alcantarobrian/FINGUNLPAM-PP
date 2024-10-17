#include <stdio.h>
#define MAX_ALUMNOS 50

void cargarPrimerParcial(int [MAX_ALUMNOS][4], int *);
void cargarSegundoParcial(int [MAX_ALUMNOS][4], int);
void calcularPromocion(int [MAX_ALUMNOS][4], int);
void ordenarPorLegajo(int [MAX_ALUMNOS][4], int);
int buscarLegajo(int [MAX_ALUMNOS][4], int, int);
void mostrarNotasPorLegajo(int [MAX_ALUMNOS][4], int);

int main() {
	int planilla[MAX_ALUMNOS][4];
	int n;
	
	cargarPrimerParcial(planilla, &n);
	cargarSegundoParcial(planilla, n);
	calcularPromocion(planilla, n);
	
	ordenarPorLegajo(planilla, n);  
	mostrarNotasPorLegajo(planilla, n);
	
	return 0;
}

void cargarPrimerParcial(int planilla[MAX_ALUMNOS][4], int *n) {
	int i = 0, legajo, nota1;
	
	printf("Ingrese la cantidad de alumnos:");
	scanf("%d", n);
	
	for (i = 0; i < *n; i++) {
		printf("Ingrese el legajo del alumno %d: ", i + 1);
		scanf("%d", &legajo);
		printf("Ingrese la nota del primer parcial: ");
		scanf("%d", &nota1);
		planilla[i][0] = legajo;
		planilla[i][1] = nota1;
		planilla[i][2] = 0; 
		planilla[i][3] = 0; 
	}
}

void cargarSegundoParcial(int planilla[MAX_ALUMNOS][4], int n) {
	int i, nota2;
	
	for (i = 0; i < n; i++) {
		printf("Ingrese la nota del segundo parcial para el legajo %d: ", planilla[i][0]);
		scanf("%d", &nota2);
		planilla[i][2] = nota2;
	}
}

void calcularPromocion(int planilla[MAX_ALUMNOS][4], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		planilla[i][3] = (planilla[i][1] + planilla[i][2]) / 2; 
	}
	
	printf("\nPlanilla de notas:\n");
	printf("Legajo\tParcial1\tParcial2\tPromocion\n");
	
	for (i = 0; i < n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", planilla[i][0], planilla[i][1], planilla[i][2], planilla[i][3]);
	}
}

void ordenarPorLegajo(int planilla[MAX_ALUMNOS][4], int n) {
	int i, j, min_idx, temp[4];
	
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (planilla[j][0] < planilla[min_idx][0]) {
				min_idx = j;
			}
		}

		for (j = 0; j < 4; j++) {
			temp[j] = planilla[i][j];
			planilla[i][j] = planilla[min_idx][j];
			planilla[min_idx][j] = temp[j];
		}
	}
}
int buscarLegajo(int planilla[MAX_ALUMNOS][4], int n, int legajo) {
	int izquierda = 0, derecha = n - 1, medio;
	
		while (izquierda <= derecha) {
			medio = (izquierda + derecha) / 2;
			if (planilla[medio][0] == legajo) 
				return medio; 
			else if (planilla[medio][0] < legajo)
				izquierda = medio + 1;
			else 
				derecha = medio - 1;
		
	}
	return -1; 
}

void mostrarNotasPorLegajo(int planilla[MAX_ALUMNOS][4], int n) {
	int legajo, indice;
	
	printf("Ingrese el legajo a buscar: ");
	scanf("%d", &legajo);
	
	indice = buscarLegajo(planilla, n, legajo);
	
	if (indice != -1) {
		printf("Notas del legajo %d:\n", legajo);
		printf("Parcial 1: %d\n", planilla[indice][1]);
		printf("Parcial 2: %d\n", planilla[indice][2]);
		printf("Promocion: %d\n", planilla[indice][3]);
	} 
	
	else 
		printf("Legajo no encontrado.\n");
}
