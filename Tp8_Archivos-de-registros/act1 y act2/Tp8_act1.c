#include <stdio.h>
#include <string.h>
#define ACT1 "Tp8_act1.dat"

typedef struct {
	int legajo;
	char apeNom[30];
	int ingreso;
	int nota1;
	int nota2;
}datos;

void menu();
void set_alumnos(FILE *archivo);
void ordenar(FILE *archivo);
void set_notas(FILE *archivo);
void show_aprobados(FILE *archivo);
void show_desaprobado(FILE *archivo);

int main() {
	int bcle, op;
	bcle = 1;
	FILE *archivo;
	archivo = fopen("ACT1", "ab+");
	
	set_alumnos(archivo);

	if (archivo != NULL){
		while(bcle){
			menu();
			scanf("%i", &op);
		
			switch(op){
				case 1:
					ordenar(archivo);
					set_notas(archivo);
					break;
		
				case 2:
					show_aprobados(archivo);
					break;
		
				case 3:
					show_desaprobado(archivo);
					break;
		
				case 4:
					bcle = 0;
					break;
			}
		}
	}
	else{
		printf("Error al abrir el archivo");
	}
	fclose(archivo);
}

void menu(){
	printf("\n1. Ingresar notas");
	printf("\n2. Mostrar aprobados");
	printf("\n3. Mostrar desaprobados");
	printf("\n4. Salir\n");
}
	
void set_alumnos(FILE *archivo){
	int i, cantidad;
	datos alumno;
	
	printf("Cuantos alumnos ingresará: ");
	scanf("%i", &cantidad);
	
	fseek(archivo, 0, SEEK_SET);
	for(i = 0; i < cantidad; i++){
		printf("Ingrese el numero de legajo: ");
		scanf("%i", &alumno.legajo);
		fflush(stdin);
		
		printf("Ingrese el nombre y apellido: ");
		gets(alumno.apeNom);
		
		printf("Ingrese el año de ingreso: ");
		scanf("%i", &alumno.ingreso);
		
		alumno.nota1 = -1;
		alumno.nota2 = -1;
		
		fwrite(&alumno, sizeof(alumno), 1, archivo);
	}
}

	
	
void ordenar(FILE *archivo){
	int i, j;
	long tam;
	datos alu1, alu2;
	
	fseek(archivo, 0, SEEK_END);
	tam = (ftell(archivo)/sizeof(datos));
	rewind(archivo);
	
	for(i = 0; i < tam - 1; i++){
		for(j = 0; j < tam-1-i; j++){
			fseek(archivo, sizeof(datos)*j,SEEK_SET);
			fread(&alu1, sizeof(datos), 1, archivo);
			
			fseek(archivo, sizeof(datos)*(j+1),SEEK_SET);
			fread(&alu2, sizeof(datos), 1, archivo);
			
			if(strcmp(alu1.apeNom, alu2.apeNom) > 0){
				fseek(archivo, sizeof(datos)*j, SEEK_SET);
				fwrite(&alu2, sizeof(datos), 1, archivo);
				
				fseek(archivo, sizeof(datos)*(j+1), SEEK_SET);
				fwrite(&alu1, sizeof(datos),1 , archivo);
			}
		}
	}
}
	
void set_notas(FILE *archivo){
	int i;
	long tam;
	datos alumno;
	
	fseek(archivo, 0, SEEK_END);
	tam = ftell(archivo)/sizeof(datos);
	rewind(archivo);
	
	for(i = 0; i < tam; i++){
		fseek(archivo, i* sizeof(datos), SEEK_SET);
		fread(&alumno, sizeof(datos), 1, archivo);
		
		printf("\nNombre: %s", alumno.apeNom);
		printf("\nIngrese nota del primer parcial: ");
		scanf("%i", &alumno.nota1);
		printf("\nIngrese nota del segundo parcial: ");
		scanf("%i", &alumno.nota2);
		
		fseek(archivo, i* sizeof(datos), SEEK_SET);
		fwrite(&alumno, sizeof(datos), 1, archivo);
	}
}
	
void show_aprobados(FILE *archivo){
	int i, op, bcle = 1;
	long tam;
	datos alumno;
	
	fseek(archivo, 0, SEEK_END);
	tam = ftell(archivo)/sizeof(datos);
	rewind(archivo);
	
	while (bcle){
		printf("\n1. Listar alumnos que aprobaron el primer parcial: ");
		printf("\n2. Listar alumnos que aprobaron el segundo parcial: ");
		printf("\n3. Salir\n");
		scanf("%i", &op);
	
		switch(op){
			case 1:
				for(i = 0; i < tam; i++){
					fread(&alumno, sizeof(datos), 1,archivo);
		
					if(alumno.nota1 >= 4){
						printf("\nNombre y apellido: %s", alumno.apeNom);
						printf("\nNota parcial 1: %i", alumno.nota1);
					}
				}
				rewind(archivo);
				break;
		
		
			case 2:
				for(i = 0; i < tam; i++){
					fread(&alumno, sizeof(datos), 1, archivo);
				
					if(alumno.nota2 >= 4){
						printf("\nNombre y apellido: %s", alumno.apeNom);
						printf("\nNotas parcial 2: %i", alumno.nota2);
					}
				}
				rewind(archivo);
				break;
			
			case 3:
				bcle = 0;
		}
	}
}
	
void show_desaprobado(FILE *archivo){
	int i, op, bcle = 1;
	long tam;
	datos alumno;
	
	fseek(archivo, 0, SEEK_END);
	tam = ftell(archivo)/sizeof(datos);
	rewind(archivo);
	
	while (bcle){
		printf("\n1. Listar alumnos que desaprobaron el primer parcial: ");
		printf("\n2. Listar alumnos que desaprobaron el segundo parcial: ");
		printf("\n3. Salir\n");
		scanf("%i", &op);
		
		switch(op){
		case 1:
			for(i = 0; i < tam; i++){
				fread(&alumno, sizeof(datos), 1,archivo);
				
				if(alumno.nota1 < 4){
					printf("\nNombre y apellido: %s", alumno.apeNom);
					printf("\nNota parcial 1: %i", alumno.nota1);
				}
			}
			rewind(archivo);
			break;
			
			
		case 2:
			for(i = 0; i < tam; i++){
				fread(&alumno, sizeof(datos), 1, archivo);
				
				if(alumno.nota2 < 4){
					printf("\nNombre y apellido: %s", alumno.apeNom);
					printf("\nNotas parcial 2: %i", alumno.nota2);
				}
			}
			rewind(archivo);
			break;
			
		case 3:
			bcle = 0;
		}
	}
}