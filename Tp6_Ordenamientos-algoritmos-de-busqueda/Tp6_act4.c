#include <stdio.h>

int buscarNota(int libretas[], int notas[], int n, int legajo) {
	int izquierda = 0, derecha = n - 1, medio;
	
	while (izquierda <= derecha) {
		medio = (izquierda + derecha) / 2;
		
		if (libretas[medio] == legajo)
			return notas[medio];  
		else if (libretas[medio] < legajo) 
			izquierda = medio + 1;
		else 
			derecha = medio - 1;
	}
	
	return -1;
}

int main() {
	
	int libretas[] = {1001, 1003, 1005, 1007, 1009}; 
	int notas[] = {8, 6, 7, 9, 10}; 
	int n = sizeof(libretas) / sizeof(libretas[0]);
	int legajo;
	
	printf("Ingrese el nmero de legajo que desea buscar: ");
	scanf("%d", &legajo);
	
	int nota = buscarNota(libretas, notas, n, legajo);
	
	if (nota != -1) {
		printf("La nota del legajo %d es: %d\n", legajo, nota);
	} else {
		printf("Legjo %d no encontrado.\n", legajo);
	}
	
	return 0;
}
