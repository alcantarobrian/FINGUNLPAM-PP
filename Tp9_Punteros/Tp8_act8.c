#include <stdio.h>
#define LONGITUD 30
#define MAX_TRAB 2


typedef struct{
	char nombre[LONGITUD];
	int legajo;
	int edad;
}t;


int carga_datos(t trabajadores[]);
t carga_uno();
void mos_uno(t trabajadores[]);
void show_datos(t trabajadores[]);


int main() {
	int bcle, op, cantidad;
	bcle = 1;
	
	t trabajadores[MAX_TRAB];
	
	while(bcle){
		printf("\n1. Cargar trabajadores");
		printf("\n2. Listar datos de trabajadores");
		printf("\n3. Mostrar datos de un determinado trabajador");
		printf("\n4. Salir");
		printf("\nSeleccion: ");
		scanf("%i", &op);
		
		switch(op){
		case 1:
			cantidad = carga_datos(trabajadores);
			break;
			
		case 2:
			show_datos(trabajadores);
			break;
			
		case 3:
			mos_uno(trabajadores);
			break;
			
		case 4:
			bcle = 0;
			printf("\nFIN DE PROGRAMA\n");
			break;
		}
	}
	
	return 0;
}

int carga_datos(t trabajadores[]){
	int i;
	
	for(i = 0; i < MAX_TRAB; i++){
		trabajadores[i] = carga_uno();
	}
	return MAX_TRAB;
}
	
t carga_uno(){
	t dato;
		
	fflush(stdin);
	printf("\nIngresa el nombre: ");
	gets(dato.nombre);
	fflush(stdin);

	printf("\nIngresa el numero de legajo: ");
	scanf("%i", &dato.legajo);
	fflush(stdin);
		
	printf("\nIngresa la edad: ");
	scanf("%i", &dato.edad);
	fflush(stdin);
	
	return dato;
}

void show_datos(t trabajadores[]){
	int i;
	for(i = 0; i < MAX_TRAB; i++){
		printf("\nnombre: %s", trabajadores[i].nombre);
		printf("\nlegajo: %i", trabajadores[i].legajo);
		printf("\nedad: %i", trabajadores[i].edad);
	}
}

void mos_uno(t trabajadores[]){
	int i, op;
	
	printf("Ingrese el numero de legajo: ");
	scanf("%i", &op);
		
	for(i = 0; i < MAX_TRAB; i++){
		if(trabajadores[i].legajo == op){
				printf("\nnombre: %s", trabajadores[i].nombre);
				printf("\nedad: %i", trabajadores[i].edad);
			}
		}
}
