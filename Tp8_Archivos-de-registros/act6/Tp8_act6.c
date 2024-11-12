#include <stdio.h>
#include <string.h>
#define ARCH_HOR "horario"
#define ARCH_EMP "empleados"

typedef struct{
	int legajo;
	char fecha[20];
	char ing_hora[20];
	char eg_hora[20];
}hor;

typedef struct{
	int legajo;
	char nomApe[30];
	int dni;
	char domicilio[30];
}datos;

void set_emp(FILE *);
void del_emp(FILE *);
void mod_emp(FILE *);
void set_hor_ing(FILE *);
void set_hor_eg(FILE *);
void show_hor(FILE *, FILE *);

int main() {
	FILE *horarios;
	FILE *empleados;
	int op, bcle;
	bcle = 1;
	
	horarios = fopen(ARCH_HOR, "wb+");
	empleados = fopen(ARCH_EMP, "ab+");
	
	while(bcle){
		printf("\n1. Agregar un empleado");
		printf("\n2. Eliminar un empleado");
		printf("\n3. Modificar datos");
		printf("\n4. Ingresar horario de ingreso");
		printf("\n5. Ingresar horario de egreso");
		printf("\n6. Mostrar horas de trabajo de un empleado");
		printf("\n7. Salir");
		printf("\nIngrese opcion: ");
		scanf("%i", &op);
		
		switch(op){
		case 1:
			set_emp(empleados);
			break;
			
		case 2:
			del_emp(empleados);
			break;
			
		case 3:
			mod_emp(empleados);
			break;
			
		case 4:
			set_hor_ing(horarios);
			break;
			
		case 5:
			set_hor_eg(horarios);
			break;
			
		case 6:
			show_hor(horarios, empleados);
			break;
			
		case 7:
			bcle = 0;
			break;
		}
	}
	
	fclose(empleados);
	fclose(horarios);

	return 0;
}

void set_emp(FILE *empleados){
	int i, cantidad;
	datos empleado;
	
	printf("¿Cuantos empleados desea ingresar?");
	scanf("%i", &cantidad);
	
	for(i = 0; i < cantidad; i++){
		printf("\nIngrese el numero de legajo: ");
		scanf("%i", &empleado.legajo);
		fflush(stdin);
		
		printf("\nIngrese el apellido y nombre: ");
		scanf("%s", empleado.nomApe);
		fflush(stdin);
		
		printf("\nIngrese el dni: ");
		scanf("%i", &empleado.dni);
		fflush(stdin);
		
		printf("\nIngrese el domicilio: ");
		scanf("%s", empleado.domicilio);
		fflush(stdin);
		
		fwrite(&empleado, sizeof(datos), 1, empleados);
	}
	
}
	
void del_emp(FILE *empleados){
	int i, num, bcle;
	long tam;
	datos empleado;
	bcle = 1;
	i = 0;
	
	fseek(empleados, 0 , SEEK_END);
	tam = ftell(empleados)/sizeof(datos);
	rewind(empleados);
	
	printf("Ingrese el numero de legajo del empleado que va a eliminar: ");
	scanf("%i", &num);
	
	while(bcle && i < tam){
		
		fread(&empleado, sizeof(datos), 1, empleados);
		
		if(empleado.legajo == num){
			
			empleado.legajo = -1;
			
			fseek(empleados, sizeof(datos)*i, SEEK_SET);
			fwrite(&empleado, sizeof(datos), 1, empleados);
			
			printf("\nEmpleado eliminado");
			
			bcle = 0;
		}
		i++;
	}
	if(bcle && i >= tam){
		printf("\nNo se encontro al empleado");
	}
}
	
void mod_emp(FILE *empleados){
	int i, num, bcle, rta;
	long tam;
	datos empleado;
	bcle = 1;
	i = 0;
	
	fseek(empleados, 0, SEEK_END);
	tam = ftell(empleados)/sizeof(datos);
	rewind(empleados);
	
	printf("Ingrese el legajo del empleado que quiere modificar: ");
	scanf("%i", &num);
	
	while(bcle && i < tam){
		
		fread(&empleado, sizeof(datos), 1, empleados);
		
		if(empleado.legajo == num){
			printf("¿\nModificar nombre y apellido(0/1)?");
			scanf("%i", &rta);
			fflush(stdin);
			if(rta){
				printf("\nIngrese el nombre: ");
				gets(empleado.nomApe);
				fflush(stdin);
			}
			
			printf("¿\nModificar dni(0/1)?");
			scanf("%i", &rta);
			fflush(stdin);
			if(rta){
				printf("\nIngrese el dni: ");
				scanf("%i", &empleado.dni);
				fflush(stdin);
			}
			
			printf("¿\nModificar domicilio(0/1)?");
			scanf("%i", &rta);
			fflush(stdin);
			if(rta){
				printf("\nIngrese el domicilio: ");
				gets(empleado.domicilio);
				fflush(stdin);
			}
			
			fseek(empleados, sizeof(datos)*i, SEEK_SET);
			fwrite(&empleado, sizeof(datos), 1, empleados);
			bcle = 0;
		}
		i++;
	}
	
	if(bcle && i >= tam){
		printf("\nEmpleado no encontrado");
	}
}

void set_hor_ing(FILE *horarios){
	hor horario;
	
	printf("\nIngrese el numero de legajo: ");
	scanf("%i", &horario.legajo);
	fflush(stdin);
	
	printf("\nIngrese la fecha: ");
	gets(horario.fecha);
	fflush(stdin);
	
	printf("\nIngrese la hora de entrada: ");
	gets(horario.ing_hora);
	fflush(stdin);
	
	fwrite(&horario, sizeof(hor), 1, horarios);	
}
	
void set_hor_eg(FILE *horarios){
	hor horario;
	int i, num, bcle;
	long tam;
	bcle = 1;
	i = 0;
	
	printf("Ingrese el numero de legajo: ");
	scanf("%i", &num);
	fflush(stdin);
	
	fseek(horarios, 0, SEEK_END);
	tam = ftell(horarios)/sizeof(hor);
	rewind(horarios);
	
	while(bcle && i < tam){
		fread(&horario, sizeof(hor), 1, horarios);
		
		if(horario.legajo == num){
			printf("\nIngrese la hora de entrada: ");
			gets(horario.eg_hora);
			fflush(stdin);
		
			fseek(horarios, sizeof(hor)*i, SEEK_SET);
			fwrite(&horario, sizeof(hor), 1, horarios);	
			bcle = 0;
		}
		i++;
	}
	
	if(bcle && i >= tam){
		printf("Empleado no encontrado");
	}
}

void show_hor(FILE *horarios, FILE *empleados) {
	int i, num, encontrado, encontradoEmpleado;
	long tam;
	char fecha[20];
	hor horario;
	datos empleado;
	encontrado = 1;
	encontradoEmpleado = 0;

	fseek(horarios, 0, SEEK_END);
	tam = ftell(horarios) / sizeof(hor);
	rewind(horarios);

	printf("\nIngrese el número de legajo: ");
	scanf("%i", &num);
	fflush(stdin);


	printf("\nIngrese fecha (AAAA/MM/DD): ");
	gets(fecha);
	fflush(stdin);


	printf("%-10s %-20s %-12s %-15s %-15s\n", "Legajo", "Apellido y Nombres", "Fecha", "Hora de Ingreso", "Hora de Egreso");


	for (i = 0; i < tam; i++) {
		fread(&horario, sizeof(hor), 1, horarios);
		
		if (horario.legajo == num && strcmp(horario.fecha, fecha) >= 0) {
			rewind(empleados);
			
			while (fread(&empleado, sizeof(datos), 1, empleados) && !encontradoEmpleado) {
				if (empleado.legajo == horario.legajo) {
					if (!encontrado) {
						printf("%-10s %-20s %-12s %-15s %-15s\n", "Legajo", "Apellido y Nombres", "Fecha", "Hora de Ingreso", "Hora de Egreso");
						encontrado = 1;
					}
					printf("%-10d %-20s %-12s %-15s %-15s\n", empleado.legajo, empleado.nomApe, horario.fecha, horario.ing_hora, horario.eg_hora);
					encontradoEmpleado = 1;
				}
			}
		}
	}
}
	
	
	
	
	